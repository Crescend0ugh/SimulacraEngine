//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANWINDOW_H
#define SIMULACRAENGINE_SIMULACRAVULKANWINDOW_H

#include "SimulacraVulkan.h"
#include "SimulacraVulkanSwapchain.h"

class SVulkanWindow {

public:

    
    SVulkanDevice* Device;

    VkSurfaceKHR SurfaceKHR;
    SVulkanSwapchain* Swapchain;


};


#endif //SIMULACRAENGINE_SIMULACRAVULKANWINDOW_H
