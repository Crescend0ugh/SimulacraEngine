//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANVIEWPORT_H
#define SIMULACRAENGINE_SIMULACRAVULKANVIEWPORT_H

#include "SimulacraVulkan.h"
#include "SimulacraVulkanSwapchain.h"

class SVulkanViewport
{

public:


private:

    SVulkanDevice    *Device;
    SVulkanSwapchain *Swapchain;
    void             *WindowHandle;
    VkSurfaceKHR     SurfaceKHR;

    std::vector<VkImage>     Images;
    std::vector<VkImageView> ImageViews;


};


#endif //SIMULACRAENGINE_SIMULACRAVULKANVIEWPORT_H
