//
// Created by avsom on 8/21/2024.
//

#pragma once

#include "Sys/Precompiled.h"

/**
 *
 * @tparam T
 * @tparam QueueSize Max
 */
template<typename T, uint32 QueueCapacity>
class WorkStealingQueue
{
    void push(T item)
    {
        uint32 index_head = head.load(std::memory_order_relaxed) % QueueCapacity;
        /* Ensure that the store is last operation done in this function as we don't want to signal a job being
         added before the new job is actually stored in the queue */
        head.store(index_head+1, std::memory_order_release);
    }

    bool pop()
    {
        uint32 index_tail = tail.load()-1;
        uint32
    };


    bool give()
    {

    };

private:


    std::atomic<uint32> head;
    alignas(std::hardware_constructive_interference_size) std::atomic<uint32> tail;

    alignas(std::hardware_constructive_interference_size) T items[QueueCapacity];
};