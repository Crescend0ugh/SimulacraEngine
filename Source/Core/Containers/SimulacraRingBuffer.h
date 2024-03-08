//
// Created by avsom on 3/7/2024.
//

#pragma once

#include <mutex>

template<typename ElementType, size_t QueueSize>
struct SRingBuffer
{

    SRingBuffer() = default;

    ~SRingBuffer()
    {
        for (ElementType& Element : Data)
        {
            delete Element;

        }
    }


    void Enqueue()
    {

    };

    void Dequeue()
    {

    };

    bool IsEmpty()
    {

    }

    bool IsFull()
    {

    }

    void Reset()
    {

        std::lock_guard<std::mutex> lock(Mutex);
        Head = Tail;
        Filled = false;

    }

    ElementType& operator[](size_t Index)
    {
        
    }


private:


    ElementType Data[QueueSize];
    std::mutex Mutex;
    size_t Head = 0;
    size_t Tail = 0;
    const size_t MaxLength = QueueSize;
    bool Filled;

};

