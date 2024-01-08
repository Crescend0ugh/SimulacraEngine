//
// Created by avsom on 10/23/2023.
//

#pragma once


#include "SimulacraVulkan.h"

class SVulkanRHI;
class SVulkanQueue;


struct SVulkanPhysicalDeviceFeatures
{

};

class SVulkanDevice
{

public:

    SVulkanDevice(SVulkanRHI *RHI, VkPhysicalDevice InPhysicalDevice);
    ~SVulkanDevice();

    void CreatePhysicalDevice();
    void CreateLogicalDevice();


    const VkDevice GetHandle() const
    {
        return Device;
    }

    const VkPhysicalDevice GetPhysicalHandle() const
    {
        return PhysicalDevice;
    }

    SVulkanQueue *GetGraphicsQueue() const
    {
        return GraphicsQueue;
    }

    SVulkanQueue *GetPresentQueue() const
    {
        return PresentQueue;
    }

    SVulkanQueue *GetComputeQueue() const
    {
        return ComputeQueue;
    }

    SVulkanQueue *GetTransferQueue() const
    {
        return TransferQueue;
    }


private:

    void QuerySupportedExtensions();
    void QuerySupportedFeatures();

    SVulkanRHI *RHI;

    VkPhysicalDevice PhysicalDevice;
    VkDevice         Device;

    SVulkanDeviceExtensions DeviceExtensions;
    SVulkanDeviceLayers     DeviceLayers;

    std::vector<VkQueueFamilyProperties> QueueFamilyProperties;

    SVulkanQueue *GraphicsQueue;
    SVulkanQueue *PresentQueue;
    SVulkanQueue *ComputeQueue;
    SVulkanQueue *TransferQueue;

    bool HasAsyncComputeQueue  = false;
    bool PresentOnComputeQueue = false;

};


