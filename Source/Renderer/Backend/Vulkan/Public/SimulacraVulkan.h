//
// Created by avsom on 10/15/2023.
//

#pragma once


#define VK_USE_PLATFORM_WIN32_KHR


// Include Vulkan and Core includes
#include "../../../../Core/Sys/Precompiled.h"
#include <vulkan/vulkan.h>


// Forward declarations
struct vulkan_instance;
struct vulkan_device;
struct vulkan_queue;
struct vulkan_surface;
struct vulkan_swapchain;

enum shader_stages
{
    vertex,
    pixel,
    count = 2
};