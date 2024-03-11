//
// Created by avsom on 3/7/2024.
//

#include "SimulacraJob.h"

thread_local  uint32 ID = -1;


void WorkerLoop()
{
    printf("Stupid function %i\n", ID);
    
}


void JobSystem::Startup()
{
    uint32 NumberOfThreads = std::thread::hardware_concurrency();
    WorkerThreads.reserve(NumberOfThreads);
    WaitList.reserve(FiberPoolSize);

    for(int i = 0; i < NumberOfThreads; i++)
    {
        WorkerThreads.emplace_back([this, i]{ID = i;
            WorkerLoop();});

    }

}

void JobSystem::Shutdown()
{
    for(auto& i : WorkerThreads)
    {
        i.join();
    }
}
