//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANDEVICE_H
#define SIMULACRAENGINE_SIMULACRAVULKANDEVICE_H


#include "SVkQueue.h"

class SimulacraVulkanDevice {


private:

    VkDevice Device;
    VkPhysicalDevice PhysicalDevice;

    SVulkanQueue GraphicsQueue;
    SVulkanQueue PresentQueue;
    SVulkanQueue ComputeQueue;
    SVulkanQueue TransferQueue;

};


#endif //SIMULACRAENGINE_SIMULACRAVULKANDEVICE_H