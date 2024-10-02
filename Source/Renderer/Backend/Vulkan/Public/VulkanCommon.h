//
// Created by avsom on 8/20/2024.
//

#pragma once

#include <vulkan/vulkan.h>
#ifdef __APPLE__
#include "Vulkan/Platforms/Mac/VulkanMacPlatform.h"
#endif
#ifdef WIN32
#define VK_USE_PLATFORM_WIN32_KHR
#include "VulkanWindowsPlatform.h"
#endif

