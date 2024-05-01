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

    VkSurfaceFormatKHR choose_surface_format();
    VkPresentModeKHR   choose_present_mode();
    VkExtent2D         choose_extent();

    VkSwapchainKHR swapchain_;
    VkSurfaceKHR   surface_;

};
