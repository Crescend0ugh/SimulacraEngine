//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANSWAPCHAIN_H
#define SIMULACRAENGINE_SIMULACRAVULKANSWAPCHAIN_H
#include "SimulacraVulkan.h"
#include "../Platforms/Windows/SimulacraVulkanWindowsPlatform.h"


class VulkanSwapchain {

public:
    VulkanSwapchain(VkInstance InInstance, VulkanDevice *InDevice, void *InWindowHandle);


    VkSurfaceFormatKHR            ChooseSurfaceFormat();
    VkPresentModeKHR              ChoosePresentMode();
    VkExtent2D                    ChooseExtent(VkSurfaceCapabilitiesKHR InCapabilities);
    VkSurfaceTransformFlagBitsKHR ChoosePreTransform(VkSurfaceCapabilitiesKHR InCapabilities);
    VkCompositeAlphaFlagBitsKHR   ChooseAlphaCompositingMode(VkSurfaceCapabilitiesKHR InCapabilities);
    uint32                        ChooseMinImageCount(VkSurfaceCapabilitiesKHR InCapabilities, uint32 DesiredMinImageCount);




private:

    VkSwapchainKHR Swapchain;
    VulkanDevice*  Device;
    VkSurfaceKHR   Surface;
    void*          WindowHandle;
    

};


#endif //SIMULACRAENGINE_SIMULACRAVULKANSWAPCHAIN_H
