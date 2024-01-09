//
// Created by avsom on 10/23/2023.
//

#pragma once



#include "../../../Core/Sys/Precompiled.h"
#include "../../../Core/Core.h"



//Fills out the structure type field of a vulkan struct and zeros the rest of the memory
template <class T>
static void SetZeroVulkanStruct(T& Struct, VkStructureType VkStructureType)
{
    static_assert(!TIsPointer<T>::Value);
    static_assert(__builtin_offsetof(T, sType) == 0);
    static_assert(sizeof(T::sType) == sizeof(VkStructureType));

    //Zero the struct memory
    memset((uint8*)&Struct, 0, sizeof(T));

    //Set the structure type field
    Struct.sType = VkStructureType;

}


