//
// Created by avsom on 10/23/2023.
//

#pragma once


#include <vector>
#include "SimulacraVulkanQueue.h"
#include "SimulacraVulkanRHI.h"

class SVulkanRHI;
class VulkanQueue;

class SVulkanDevice {

public:

    SVulkanDevice(SVulkanRHI* RHI, VkPhysicalDevice InPhysicalDevice);

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

    SVulkanRHI* RHI;

    VkDevice         Device;
    VkPhysicalDevice PhysicalDevice;


    std::vector<VkQueueFamilyProperties> QueueFamilyProperties;
    VulkanQueue*                        GraphicsQueue;
    VulkanQueue*                        PresentQueue;
    VulkanQueue*                        ComputeQueue;
    VulkanQueue*                        TransferQueue;
    bool HasAsyncComputeQueue = false;
    bool PresentOnComputeQueue = false;

};


