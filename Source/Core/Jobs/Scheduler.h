//
// Created by avsom on 8/21/2024.
//

#pragma once
#include "Sys/Precompiled.h"
#include "JobQueue.h"
#include <thread>

struct Scheduler
{

private:



private:
    std::vector<std::thread> workers;
    //TODO change the tyep of item in the queue from void*
    std::vector<WorkStealingQueue<void*, 256>> worker_queues;
};