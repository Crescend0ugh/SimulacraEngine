//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANCOMMON_H
#define SIMULACRAENGINE_SIMULACRAVULKANCOMMON_H


#include "../../../Core/Sys/Precompiled.h"




template <class T>
static void CreateZeroVulkanStruct(T& Struct, int32 VkStructureType)
{
    static_assert(!TIsPointer<T>::Value);
    static_assert(__builtin_offsetof(T, sType) == 0);
    static_assert(sizeof(T::sType) == sizeof(uint32));
    (int32&)Struct.sType = VkStructureType;
    memset((uint8*)&Struct + sizeof(VkStructureType), 0, sizeof(T)-sizeof(VkStructureType));
}


#endif //SIMULACRAENGINE_SIMULACRAVULKANCOMMON_H
