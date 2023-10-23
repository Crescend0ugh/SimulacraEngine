//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANQUEUE_H
#define SIMULACRAENGINE_SIMULACRAVULKANQUEUE_H


#include "SimEngineVulkan.h"

class SVulkanQueue
{

public:






private:

    VkQueue       Queue;
    uint32        FamilyIndex;
    uint32        QueueIndex;
    SVulkanDevice* Device;

};


#endif //SIMULACRAENGINE_SIMULACRAVULKANQUEUE_H
