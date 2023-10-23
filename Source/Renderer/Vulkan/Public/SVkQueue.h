//
// Created by avsom on 10/22/2023.
//

#ifndef SIMULACRAENGINE_SVKQUEUE_H
#define SIMULACRAENGINE_SVKQUEUE_H
#include "SimEngineVulkan.h"


class SVulkanQueue
{

public:






private:
    VkQueue Queue;
   // QueueFamily Family;
    uint32 FamilyIndex;
    uint32 QueueIndex;
    VulkanDevice* Device;





};












































QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice PhysicalDevice, VkSurfaceKHR Surface);


#endif //SIMULACRAENGINE_SVKQUEUE_H
