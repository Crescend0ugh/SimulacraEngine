//
// Created by avsom on 10/23/2023.
//

#pragma once



#include "SimulacraVulkan.h"

class SVulkanDevice;

class SVulkanQueue
{

public:
    SVulkanQueue(SVulkanDevice* InDevice, uint32 InFamilyIndex);
    ~SVulkanQueue();




    VkQueue GetHandle() const {
        return Queue;
    }

    uint32 GetFamilyIndex() const {
        return FamilyIndex;
    }

    uint32 GetQueueIndex() const {
        return QueueIndex;
    }

    void Submit(SVulkanCommandBuffer* CommandBuffer, uint32 NumWaitSemaphores, VkSemaphore WaitSemaphores, uint32 NumSignalSemaphores, VkSemaphore SignalSemaphores);



private:

    VkQueue        Queue;
    uint32         FamilyIndex;
    uint32         QueueIndex;
    SVulkanDevice* Device;

};


