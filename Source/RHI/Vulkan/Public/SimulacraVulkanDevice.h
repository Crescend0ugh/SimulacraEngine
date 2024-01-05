//
// Created by avsom on 10/23/2023.
//

#pragma once


#include "SimulacraVulkanQueue.h"
#include "SimulacraVulkanRHI.h"

class SVulkanRHI;
class VulkanQueue;

class SVulkanDevice
{

public:

    SVulkanDevice(SVulkanRHI *RHI, VkPhysicalDevice InPhysicalDevice);
    ~SVulkanDevice();

    void CreatePhysicalDevice();
    void CreateDevice();


    const VkDevice GetHandle() const
    {
        return Device;
    }

    const VkPhysicalDevice GetPhysicalHandle() const
    {
        return PhysicalDevice;
    }

    VulkanQueue *GetGraphicsQueue() const
    {
        return GraphicsQueue;
    }

    VulkanQueue *GetPresentQueue() const
    {
        return PresentQueue;
    }

    VulkanQueue *GetComputeQueue() const
    {
        return ComputeQueue;
    }

    VulkanQueue *GetTransferQueue() const
    {
        return TransferQueue;
    }


private:

    SVulkanRHI *RHI;

    VkPhysicalDevice PhysicalDevice;
    VkDevice         Device;

    std::vector<const char *> DeviceExtensions;
    std::vector<const char *> DeviceLayers;

    std::vector<VkQueueFamilyProperties> QueueFamilyProperties;

    VulkanQueue *GraphicsQueue;
    VulkanQueue *PresentQueue;
    VulkanQueue *ComputeQueue;
    VulkanQueue *TransferQueue;

    bool HasAsyncComputeQueue  = false;
    bool PresentOnComputeQueue = false;

};


