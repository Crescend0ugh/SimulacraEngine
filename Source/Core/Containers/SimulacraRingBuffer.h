//
// Created by avsom on 3/7/2024.
//

#pragma once

#include <mutex>
#include <cassert>
#include <optional>

template<typename InElementType, size_t InCapacity>
struct SRingBuffer
{
    typedef InElementType ElementType;

    void Enqueue(ElementType InElement)
    {
        std::lock_guard<std::mutex> Guard(Mutex);
        size_t Next = (Head + 1) % Capacity;
        assert(!IsFull());
        Data[Head] = (InElement);
        Head = Next;
        Filled = Head == Tail;
    }

    std::optional<ElementType> Dequeue()
    {
        Filled = false;

        if (Head != Tail || IsFull())
        {
            std::lock_guard<std::mutex> Guard(Mutex);
            ElementType ReturnElement = Data[Tail];
            Tail = (Tail + 1) % Capacity;
            return ReturnElement;
        }

        return std::nullopt;
    }

    size_t Size() const
    { return Head - Tail; }

    bool IsFull()
    {
        return Filled;
    }

private:


    ElementType &operator[](size_t Index)
    { return Data[Index]; }


    ElementType  Data[InCapacity];
    size_t       Head     = 0;
    size_t       Tail     = 0;
    std::mutex   Mutex;
    const size_t Capacity = InCapacity;
    bool         Filled   = false;

};

