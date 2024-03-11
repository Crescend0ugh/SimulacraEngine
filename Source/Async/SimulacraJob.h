//
// Created by avsom on 3/7/2024.
//

#pragma once


#include <atomic>
#include <thread>
#include "../Core/Sys/Precompiled.h"
#include "../Core/Containers/SimulacraRingBuffer.h"
#include <windows.h>



 const size_t StackSize     = 3;
 const size_t FiberPoolSize = 160;
 const size_t JobQueueSize  = 256;


struct Fiber
{
    typedef LPVOID PFIBER;
    PFIBER         Handle;
};


class JobSystem
{

public:

    void Startup();

    void Shutdown();

    typedef void EntryPoint(void *Params);

    enum class EPriority : int8
    {
        LOW,
        NORMAL,
        HIGH,
        CRITICAL
    };

    struct Counter
    {
        std::atomic<int32> Count;
    };


    void FreeCounter(Counter *Counter);


    struct JobDeclaration
    {
        EntryPoint *StartAddress;
        void       *Params;
        Counter    *Counter;
        EPriority  Priority;
    };

    void KickJob(const JobDeclaration &Decl);

    inline void KickJobs(int Count, const JobDeclaration *Decls)
    {
        for (int i = 0; i < Count; i++)
        {
            KickJob(Decls[i]);
        }
    };

    void WaitForCounter();

    void KickJobAndWait(const JobDeclaration &Decl);

    void KickJobsAndWait(int Count, const JobDeclaration *Decls);

private:

    SRingBuffer<JobDeclaration, JobQueueSize> *QueueLowPriority      = nullptr;
    SRingBuffer<JobDeclaration, JobQueueSize> *QueueNormalPriority   = nullptr;
    SRingBuffer<JobDeclaration, JobQueueSize> *QueueHighPriority     = nullptr;
    SRingBuffer<JobDeclaration, JobQueueSize> *QueueCriticalPriority = nullptr;
    SRingBuffer<Fiber, FiberPoolSize>         *FiberPool             = nullptr;
    std::vector<std::thread>                  WorkerThreads;
    std::unordered_map<Counter*, Fiber*>        WaitList;


};