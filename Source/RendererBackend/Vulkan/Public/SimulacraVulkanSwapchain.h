//
// Created by avsom on 10/23/2023.
//

#pragma once

#include "SimulacraVulkan.h"




struct vulkan_swapchain
{

    uint32 acquire_next_image();


    VkPresentModeKHR present_mode_;
    VkSurfaceFormatKHR surface_format_;
    VkExtent2D extent_;
};
