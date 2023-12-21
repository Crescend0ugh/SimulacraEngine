//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANSWAPCHAIN_H
#define SIMULACRAENGINE_SIMULACRAVULKANSWAPCHAIN_H
#include "SimulacraVulkan.h"

class SVulkanSwapchain {

public:
    SVulkanSwapchain(SVulkanDevice* InDevice, void* InWinowHandle);


    VkSurfaceFormatKHR            ChooseSurfaceFormat();
    VkPresentModeKHR              ChoosePresentMode();
    VkExtent2D                    ChooseExtent(VkSurfaceCapabilitiesKHR InCapabilities);
    VkSurfaceTransformFlagBitsKHR ChoosePreTransform(VkSurfaceCapabilitiesKHR InCapabilities);
    VkCompositeAlphaFlagBitsKHR   ChooseAlphaCompositingMode(VkSurfaceCapabilitiesKHR InCapabilities);
    uint32                        ChooseMinImageCount(VkSurfaceCapabilitiesKHR InCapabilities, uint32 DesiredMinImageCount);




private:

    VkSwapchainKHR Swapchain;
    SVulkanDevice* Device;
    void*          WindowHandle;
    

};


#endif //SIMULACRAENGINE_SIMULACRAVULKANSWAPCHAIN_H
