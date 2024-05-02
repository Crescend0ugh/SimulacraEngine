//
// Created by avsom on 10/23/2023.
//





#include "SimulacraVulkanSwapchain.h"

#include <utility>
#include "SimulacraVulkanDevice.h"


vulkan_swapchain::vulkan_swapchain(const vulkan_device* device, const simulacra::windows::window window)
{

    VkSurfaceFormatKHR surface_format = choose_surface_format();
    VkExtent2D         extent         = choose_extent();

    VkSwapchainCreateInfoKHR swapchain_create_info{};
    swapchain_create_info.sType           = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    swapchain_create_info.surface         = surface_;
    swapchain_create_info.oldSwapchain    = VK_NULL_HANDLE;
    swapchain_create_info.imageFormat     = surface_format.format;
    swapchain_create_info.imageColorSpace = surface_format.colorSpace;
}

vulkan_swapchain& vulkan_swapchain::operator=(vulkan_swapchain&& other) noexcept
{
    this->surface_   = other.surface_;
    this->device_    = other.device_;
    this->swapchain_ = other.swapchain_;
    other.surface_   = VK_NULL_HANDLE;
    other.device_    = nullptr;
    other.swapchain_ = VK_NULL_HANDLE;
    return *this;
}

VkSurfaceFormatKHR
vulkan_swapchain::choose_surface_format() const
{
    uint32 surface_format_count = 0;

    vkGetPhysicalDeviceSurfaceFormatsKHR(device_->physical_handle(), surface_, &surface_format_count, nullptr);

    std::vector<VkSurfaceFormatKHR> surface_formats(surface_format_count);
    vkGetPhysicalDeviceSurfaceFormatsKHR(device_->physical_handle(), surface_, &surface_format_count,
                                         surface_formats.data());

    for (const VkSurfaceFormatKHR& surface_format: surface_formats)
    {

    }

    return surface_formats[0];
}

VkPresentModeKHR
vulkan_swapchain::choose_present_mode() const
{
    uint32 present_mode_count = 0;
    vkGetPhysicalDeviceSurfacePresentModesKHR(nullptr, surface_, &present_mode_count, nullptr);

    std::vector<VkPresentModeKHR> present_modes(present_mode_count);
    vkGetPhysicalDeviceSurfacePresentModesKHR(nullptr, surface_, &present_mode_count, present_modes.data());

    for (const VkPresentModeKHR& present_mode: present_modes)
    {
        if (present_mode == VK_PRESENT_MODE_MAILBOX_KHR)
        {
            return present_mode;
        }
    }

    return VK_PRESENT_MODE_FIFO_KHR;
}

VkExtent2D vulkan_swapchain::choose_extent() const
{
    return {};
}

uint64 vulkan_swapchain::acquire_next_image_index()
{
    uint32 image_index = 0;

    if (VkResult result = vkAcquireNextImageKHR(device_->logical_handle(), swapchain_, UINT_FAST64_MAX,
                                                VK_NULL_HANDLE, VK_NULL_HANDLE,
                                                &image_index); result != VK_SUCCESS)
    {
        if(result == VK_SUBOPTIMAL_KHR || result == VK_ERROR_OUT_OF_DATE_KHR)
        {
            std::cerr << "Failed to acquire next image\n";
            terminate();
        }
    }
    return image_index;
}
