//
// Created by avsom on 1/8/2024.
//

#include "SimulacraVulkanInstance.h"









vulkan_instance::vulkan_instance() : instance_(VK_NULL_HANDLE)
{
    VkApplicationInfo application_info {};
    application_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    application_info.pApplicationName   = "Vulkan Application";
    application_info.applicationVersion = VK_MAKE_VERSION(0, 1, 0);
    application_info.pEngineName        = "Simulacra Engine";
    application_info.engineVersion      = VK_MAKE_VERSION(0, 1, 0);
    application_info.apiVersion         = VK_API_VERSION_1_3;

    std::vector<const char *> enabled_extension_names;
    std::vector<vulkan_instance_extension> required_extensions = vulkan_instance_extension::required_extensions();

    for (vulkan_instance_extension &required_extension: required_extensions)
    {
        enabled_extension_names.emplace_back(required_extension.get_name());
    }

    VkInstanceCreateInfo instance_create_info {};
    instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instance_create_info.enabledExtensionCount   = enabled_extension_names.size();
    instance_create_info.enabledLayerCount       = 0;
    instance_create_info.ppEnabledExtensionNames = enabled_extension_names.data();
    instance_create_info.ppEnabledLayerNames     = nullptr;

    if (const VkResult result = vkCreateInstance(&instance_create_info, nullptr, &instance_); result != VK_SUCCESS)
    {
        std::cout << "Couldn't create Vulkan Instance.\n";
    } else
    {
        std::cout << "======= Created Vulkan Instance! =======\n\n";
    }
}

vulkan_instance::~vulkan_instance()
{
    vkDestroyInstance(instance_, nullptr);
}

std::vector<vulkan_instance_extension> vulkan_instance::query_extension_support()
{
    uint32 extension_properties_count;
    VkResult result = vkEnumerateInstanceExtensionProperties(nullptr, &extension_properties_count, nullptr);

    if (result != VK_SUCCESS)
    {
        std::cout << "Unable to query instance extension properties\n";
    }

    std::vector<VkExtensionProperties> supported_instance_extension_properties(extension_properties_count);
    result = vkEnumerateInstanceExtensionProperties(nullptr, &extension_properties_count,
                                                    supported_instance_extension_properties.data());
    if (result != VK_SUCCESS)
    {
        std::cout << "Unable to query instance extension properties\n";
    }

    std::vector<vulkan_instance_extension> supported_extensions;
    for (VkExtensionProperties &extension_properties: supported_instance_extension_properties)
    {
        supported_extensions.emplace_back(extension_properties.extensionName);
    }

    return supported_extensions;
}

