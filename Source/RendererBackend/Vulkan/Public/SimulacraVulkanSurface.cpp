//
// Created by avsom on 5/1/2024.
//

#include "SimulacraVulkanSurface.h"
#include "../Platforms/Windows/SimulacraVulkanWindowsPlatform.h"

vulkan_surface::vulkan_surface(VkInstance instance, simulacra::windows::window& window) : instance_(instance)
{
    surface_ = simulacra::vulkan::windows::create_surface(instance_, window);
}

vulkan_surface::~vulkan_surface()
{
    vkDestroySurfaceKHR(instance_, surface_, nullptr);
}
