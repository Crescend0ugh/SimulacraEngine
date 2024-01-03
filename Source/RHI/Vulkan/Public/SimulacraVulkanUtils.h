//
// Created by avsom on 10/23/2023.
//

#pragma once



#include "../../../Core/Sys/Precompiled.h"
#include "../../../Core/Core.h"




template <class T>
static void SetZeroVulkanStruct(T& Struct, VkStructureType VkStructureType)
{
    static_assert(!TIsPointer<T>::Value);
    static_assert(__builtin_offsetof(T, sType) == 0);
    static_assert(sizeof(T::sType) == sizeof(VkStructureType));
    Struct.sType = VkStructureType;

    //The pointer to the mem address after the structure type
    memset((uint8*)&Struct + sizeof(VkStructureType), 0, sizeof(T)-sizeof(VkStructureType));
}


