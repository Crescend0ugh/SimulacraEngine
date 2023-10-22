//
// Created by avsom on 10/22/2023.
//

#ifndef SIMULACRAENGINE_SVKQUEUES_H
#define SIMULACRAENGINE_SVKQUEUES_H
#include <vulkan/vulkan.h>
#include "../../Core/Sys/SimEngineTypes.h"
#include "../../Core/Containers/Array.h"

struct VulkanDevice
{


    VkPhysicalDevice PhysicalDevice;
    VkDevice         Device;

    VkQueue              PresentQueue;
    VkQueue              GraphicsQueue;
    VkQueue              VideoQueue;
    SimArray<VkQueue, 3> ComputeQueues;
    SimArray<VkQueue, 3> TransferQueue;

    VkPhysicalDeviceProperties           DeviceProperties;
    VkPhysicalDeviceFeatures             DeviceFeatures;
    std::vector<VkQueueFamilyProperties> QueueProperties;

public:
    VulkanDevice(VkInstance Instance, uint32 PhysicalDeviceIndex);
    ~VulkanDevice();

};
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


QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice PhysicalDevice, VkSurfaceKHR Surface);


#endif //SIMULACRAENGINE_SVKQUEUES_H
