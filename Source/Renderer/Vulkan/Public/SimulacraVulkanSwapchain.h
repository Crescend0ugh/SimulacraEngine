//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANSWAPCHAIN_H
#define SIMULACRAENGINE_SIMULACRAVULKANSWAPCHAIN_H
#include "SimulacraVulkan.h"

class SVulkanSwapchain {


    VkSurfaceFormatKHR ChooseSurfaceFormat();
    VkPresentModeKHR ChoosePresentMode();
    VkExtent2D ChooseExtent();


    void TestCreateVulkanWindow();
private:

    VkSwapchainKHR Swapchain;
    SVulkanDevice* Device;
    VkSurfaceKHR Surface;
    void* WindowHandle;
    

};


#endif //SIMULACRAENGINE_SIMULACRAVULKANSWAPCHAIN_H
