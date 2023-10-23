//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANSURFACE_H
#define SIMULACRAENGINE_SIMULACRAVULKANSURFACE_H

#include "SimEngineVulkan.h"

class SVulkanSurface {

public:

    SVulkanDevice* Device;

    VkSurfaceKHR SurfaceKHR;
    VkSwapchainKHR SwapchainKHR;


};


#endif //SIMULACRAENGINE_SIMULACRAVULKANSURFACE_H
