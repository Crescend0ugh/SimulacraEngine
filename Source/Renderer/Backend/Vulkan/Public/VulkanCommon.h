//
// Created by avsom on 8/20/2024.
//

#pragma once

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>
#ifdef MACOS
#include "Vulkan/Platforms/Mac/VulkanMacPlatform.h"
#endif
#ifdef WIN32
#include "VulkanWindowsPlatform.h"
#endif

