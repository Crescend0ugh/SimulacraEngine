//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANDEVICE_H
#define SIMULACRAENGINE_SIMULACRAVULKANDEVICE_H

#include <vector>
#include "SimulacraVulkanQueue.h"
#include "SimulacraVulkanRHI.h"

class VulkanRHI;
class VulkanQueue;

class VulkanDevice {

public:

    VulkanDevice(VulkanRHI* RHI, VkPhysicalDevice InPhysicalDevice);

    ~VulkanDevice();

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

    VulkanRHI* RHI;

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


#endif //SIMULACRAENGINE_SIMULACRAVULKANDEVICE_H
