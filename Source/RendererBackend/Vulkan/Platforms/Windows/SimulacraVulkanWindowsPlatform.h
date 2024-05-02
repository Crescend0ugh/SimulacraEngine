//
// Created by avsom on 12/9/2023.
//

#pragma once


#include "../../Public/SimulacraVulkan.h"
#include "../../../../Core/Platform/SimulacraWindowsWindow.h"
#include "../../Public/SimulacraVulkanExtensions.h"

namespace simulacra::vulkan::windows
{
    VkSurfaceKHR create_surface(VkInstance instance, simulacra::windows::window& window);
    std::vector<vulkan_instance_extension> get_platform_extensions();
}