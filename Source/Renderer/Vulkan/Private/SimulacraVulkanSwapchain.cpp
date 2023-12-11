//
// Created by avsom on 10/23/2023.
//

#include "../Public/SimulacraVulkanSwapchain.h"

VkSurfaceFormatKHR SVulkanSwapchain::ChooseSurfaceFormat() {

    uint32 NumFormats = 0;


    //TODO Pass actual phyical device
    vkGetPhysicalDeviceSurfaceFormatsKHR(nullptr,Surface, &NumFormats, nullptr);



    std::vector<VkSurfaceFormatKHR> SurfaceFormats(NumFormats);
    vkGetPhysicalDeviceSurfaceFormatsKHR(nullptr, Surface, &NumFormats, SurfaceFormats.data());




 //   return VkSurfaceFormatKHR();
}

VkPresentModeKHR SVulkanSwapchain::ChoosePresentMode() {
    return VK_PRESENT_MODE_MAILBOX_KHR;
}

VkExtent2D SVulkanSwapchain::ChooseExtent() {
    return VkExtent2D();
}

void SVulkanSwapchain::TestCreateVulkanWindow()
{

}
