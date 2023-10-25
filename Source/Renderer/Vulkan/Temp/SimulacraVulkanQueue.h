//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANQUEUE_H
#define SIMULACRAENGINE_SIMULACRAVULKANQUEUE_H


#include "SimEngineVulkan.h"

struct SVulkanDevice;

class SVulkanQueue
{

public:
    SVulkanQueue(SVulkanDevice* InDevice, uint32 InFamilyIndex);
    ~SVulkanQueue();




    const VkQueue GetHandle() const {
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


#endif //SIMULACRAENGINE_SIMULACRAVULKANQUEUE_H
