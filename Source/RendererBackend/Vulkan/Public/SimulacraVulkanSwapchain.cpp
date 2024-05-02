//
// Created by avsom on 10/23/2023.
//





#include "SimulacraVulkanSwapchain.h"
#include "../Platforms/Windows/SimulacraVulkanWindowsPlatform.h"
#include "SimulacraVulkanDevice.h"


vulkan_swapchain::vulkan_swapchain()
{

}

vulkan_swapchain::~vulkan_swapchain()
{

}

VkSurfaceFormatKHR vulkan_swapchain::choose_surface_format() const
{
    uint32 surface_format_count = 0;


    vkGetPhysicalDeviceSurfaceFormatsKHR(device_->physical_handle(), surface_, &surface_format_count, nullptr);

    std::vector<VkSurfaceFormatKHR> surface_formats(surface_format_count);
    vkGetPhysicalDeviceSurfaceFormatsKHR(device_->physical_handle(), surface_, &surface_format_count,
                                         surface_formats.data());
    

    return surface_formats[0];
}

VkPresentModeKHR vulkan_swapchain::choose_present_mode(const VkPresentModeKHR desired_present_mode) const
{
    uint32 present_mode_count = 0;
    vkGetPhysicalDeviceSurfacePresentModesKHR(nullptr, surface_, &present_mode_count, nullptr);

    std::vector<VkPresentModeKHR> present_modes(present_mode_count);
    vkGetPhysicalDeviceSurfacePresentModesKHR(nullptr, surface_, &present_mode_count, present_modes.data());

    for (const VkPresentModeKHR &present_mode: present_modes) {
        if (present_mode == desired_present_mode) {
            return present_mode;
        }
    }

    return VK_PRESENT_MODE_FIFO_KHR;
}

VkExtent2D vulkan_swapchain::choose_extent() const
{


}
