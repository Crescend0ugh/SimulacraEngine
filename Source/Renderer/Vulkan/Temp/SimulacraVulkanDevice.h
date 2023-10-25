//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANDEVICE_H
#define SIMULACRAENGINE_SIMULACRAVULKANDEVICE_H


#include "SimulacraVulkanQueue.h"

class SVulkanDevice {

public:

    SVulkanDevice();

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

    VkDevice         Device;
    VkPhysicalDevice PhysicalDevice;

    SVulkanQueue* GraphicsQueue;
    SVulkanQueue* PresentQueue;
    SVulkanQueue* ComputeQueue;
    SVulkanQueue* TransferQueue;

};


#endif //SIMULACRAENGINE_SIMULACRAVULKANDEVICE_H
