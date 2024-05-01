//
// Created by avsom on 1/6/2024.
//

#include "SimulacraVulkanExtensions.h"
#include "SimulacraVulkanInstance.h"




vulkan_instance_extension::vulkan_instance_extension(const char *extension_name) : extension_name_(extension_name)
{
}

vulkan_instance_extension::~vulkan_instance_extension()
{
}

bool vulkan_instance_extension::is_supported() const
{


    return false;
}

std::vector<vulkan_instance_extension> vulkan_instance_extension::required_extensions()
{
    std::vector<vulkan_instance_extension> required_extensions;
    //TODO get platform extensions
    required_extensions.emplace_back(VK_KHR_SURFACE_EXTENSION_NAME);
    required_extensions.emplace_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
    return required_extensions;
}

vulkan_device_extension::vulkan_device_extension(const char *extension_name) : extension_name_(extension_name)
{
}

vulkan_device_extension::~vulkan_device_extension()
{
}

bool vulkan_device_extension::is_supported()
{
    return true;
}

std::vector<vulkan_device_extension> vulkan_device_extension::required_extensions()
{
    std::vector<vulkan_device_extension> required_extensions;
    required_extensions.emplace_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);
    //TODO get platform extensions

    return required_extensions;
}
