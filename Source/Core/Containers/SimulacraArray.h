//
// Created by avsom on 10/23/2023.
//

#pragma once

#include "../Core.h"

template<typename ElementType>
class SArray
{


    SArray()
    {

    }

    ~SArray()
    {

    }





    //Modifiers

    inline void Add()
    {

    }

    inline void Emplace()
    {

    }

    inline void Push()
    {

    }

    inline void Pop()
    {

    }

    inline void Swap()
    {

    }

    //Capacity

    inline void Empty()
    {

    }

    inline int  GetSize()
    {
        return Size;
    }

    inline void Reserve()
    {

    }

    inline int  GetCapacity()
    {
        return Capacity;
    }

    inline void Shrink()
    {

    }


private:


    ElementType *ArrayData;

    int Size;
    int Capacity;
};



