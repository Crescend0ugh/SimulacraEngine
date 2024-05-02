//
// Created by avsom on 10/23/2023.
//

#pragma once

#include "SimulacraVulkan.h"


struct vulkan_swapchain
{

    vulkan_swapchain();
    ~vulkan_swapchain();



private:

    [[nodiscard]] VkSurfaceFormatKHR choose_surface_format() const;
    [[nodiscard]] VkPresentModeKHR   choose_present_mode(const VkPresentModeKHR desired_present_mode) const;
    [[nodiscard]] VkExtent2D         choose_extent() const;

    VkSwapchainKHR swapchain_;
    VkSurfaceKHR   surface_;
    vulkan_device* device_;
};
