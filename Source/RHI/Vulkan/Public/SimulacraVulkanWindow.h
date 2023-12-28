//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANWINDOW_H
#define SIMULACRAENGINE_SIMULACRAVULKANWINDOW_H

#include "SimulacraVulkan.h"
#include "SimulacraVulkanSwapchain.h"

class VulkanWindow {

public:


    VulkanDevice* Device;

    VkSurfaceKHR SurfaceKHR;
    VulkanSwapchain* Swapchain;


};


#endif //SIMULACRAENGINE_SIMULACRAVULKANWINDOW_H
