//
// Created by avsom on 10/23/2023.
//





#include "SimulacraVulkanSwapchain.h"
#include "../Platforms/Windows/SimulacraVulkanWindowsPlatform.h"


vulkan_swapchain::vulkan_swapchain()
{

}

vulkan_swapchain::~vulkan_swapchain()
{
    vkDestroySwapchainKHR(device_, swapchain_, nullptr);
}
