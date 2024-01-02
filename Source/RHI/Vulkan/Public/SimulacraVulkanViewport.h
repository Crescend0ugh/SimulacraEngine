//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANVIEWPORT_H
#define SIMULACRAENGINE_SIMULACRAVULKANVIEWPORT_H

#include "SimulacraVulkan.h"
#include "SimulacraVulkanSwapchain.h"

class SVulkanViewport {

public:



private:

    SVulkanDevice*    Device;
    VkSurfaceKHR      SurfaceKHR;
    SVulkanSwapchain* Swapchain;
    void*             WindowHandle;


};


#endif //SIMULACRAENGINE_SIMULACRAVULKANVIEWPORT_H
