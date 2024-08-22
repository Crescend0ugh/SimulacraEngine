//
// Created by avsom on 8/21/2024.
//

#pragma once

#include "Sys/Precompiled.h"

template<typename T, uint32 QueueSize>
class WorkStealingQueue
{
    void push(T item)
    {
        uint32 index = head.load(std::memory_order_relaxed) % QueueSize;

        head.store(head+1, std::memory_order_release);
    }

    bool pop()
    {
3    };

    bool give()
    {

    };

private:

    std::atomic<uint32> head;
    alignas(std::hardware_constructive_interference_size) std::atomic<uint32> tail;

    alignas(std::hardware_constructive_interference_size) T items[QueueSize];
};