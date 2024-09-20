//
// Created by avsom on 8/21/2024.
//

#pragma once

#include "Core.h"


/**
 *
 * @tparam T
 * @tparam QueueCapacity
 */
template<typename T, size_t QueueCapacity>
class WorkStealingQueue
{
    /**
     *
     * @param item Item to be pushed into the queue
     * @note This function may only be called from a single thread
     */
    bool push(const T &item)
    {
        //signal new item
        uint64 bottom_index = bottom.load();
        items[bottom_index] = item;
        bottom.store(bottom_index + 1);
        return true;
    }


    //TODO ensure optimal memory order
    /**
     *
     * @param item
     * @return
     * @note This function may only be called from a single thread
     */
    bool pop(T &item)
    {
        // Reserve item
        uint64 b = bottom.load() - 1;
        bottom.store(b);
        uint64 t = top.load();

        //Not empty
        if (t <= b) {

            item = items[b % QueueCapacity];

            //One item left
            if(t == b)
            {
                if(std::atomic_compare_exchange_strong(&top, &t, t+1))
                {
                    bottom.store(b+1);
                    return true;
                }
                else
                {
                    return false;
                }
            }

            else
            {
                bottom.store(b+1);
                return false;
            }
        }
    };

    /**
     *
     * @param item Reference to item being given by this queue
     * @return Whether or not this queue was able to successfully give an item
     */
    bool give(T &item)
    {
        uint64 top_index    = top.load();
        uint64 bottom_index = bottom.load();
        //Check if the queue is empty
        if (top_index < bottom_index) {
            item = items[top_index];
            if (std::atomic_compare_exchange_strong(&top, &top_index, top_index + 1)) {
                return true;
            }
        }

        return false;
    };

private:


    // Index where items get pushed and popped from
    std::atomic<uint64>                                                       bottom;
    // Index where items get stolen from by other threads
    alignas(std::hardware_constructive_interference_size) std::atomic<uint64> top;
    // Buffer storing items in the queue
    alignas(std::hardware_constructive_interference_size) T                   items[QueueCapacity];
};