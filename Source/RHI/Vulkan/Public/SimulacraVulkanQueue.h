//
// Created by avsom on 10/23/2023.
//

#pragma once



#include "SimulacraVulkan.h"

struct SVulkanDevice;

class VulkanQueue
{

public:
    VulkanQueue(SVulkanDevice* InDevice, uint32 InFamilyIndex);
    ~VulkanQueue();




    VkQueue GetHandle() const {
        return Queue;
    }

    uint32 GetFamilyIndex() const {
        return FamilyIndex;
    }

    uint32 GetQueueIndex() const {
        return QueueIndex;
    }




private:

    VkQueue        Queue;
    uint32         FamilyIndex;
    uint32         QueueIndex;
    SVulkanDevice* Device;

};


