//
// Created by avsom on 10/15/2023.
//

#ifndef SIMULACRAENGINE_SIMENGINEVULKAN_H
#define SIMULACRAENGINE_SIMENGINEVULKAN_H



struct QueueFamilyIndices
{
    uint32 GraphicsQueueFamily      = -1;
    uint32 ComputeQueueFamily       = -1;
    uint32 TransferQueueFamily      = -1;
    uint32 SparseBindingQueueFamily = -1;
    uint32 ProtectedQueueFamily     = -1;
    uint32 VideoDecodeQueueFamily   = -1;

    uint32 PresentQueueFamily       = -1;

    bool IsComplete() const
    {
        return ((GraphicsQueueFamily != UINT32_MAX) &
                (ComputeQueueFamily != UINT32_MAX) &
                (TransferQueueFamily != UINT32_MAX) &
                (SparseBindingQueueFamily != UINT32_MAX) &
                (ProtectedQueueFamily != UINT32_MAX) &
                (VideoDecodeQueueFamily != UINT32_MAX) &
                (PresentQueueFamily != UINT32_MAX) );
    }
};



#include "SVkPhysicalDevice.h"
#include "SVkQueue.h"
#include "SVkDevices.h"
#include "SVkSwapChain.h"

#endif //SIMULACRAENGINE_SIMENGINEVULKAN_H
