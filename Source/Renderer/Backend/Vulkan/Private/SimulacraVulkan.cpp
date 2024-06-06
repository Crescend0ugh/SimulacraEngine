//
// Created by avsom on 6/5/2024.
//

#include "SimulacraVulkan.h"


void vulkan_renderer::create_instance()
{
    VkApplicationInfo application_info{};
    application_info.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    application_info.pApplicationName   = "Vulkan Application";
    application_info.applicationVersion = VK_MAKE_VERSION(0, 1, 0);
    application_info.pEngineName        = "Simulacra Engine";
    application_info.engineVersion      = VK_MAKE_VERSION(0, 1, 0);
    application_info.apiVersion         = VK_API_VERSION_1_3;

    uint32   instance_extension_count = 0;
    VkResult result                   = vkEnumerateInstanceExtensionProperties(nullptr, &instance_extension_count,
                                                                               nullptr);

    if (instance_extension_count == 0 || result != VK_SUCCESS) {
        printf("failed to retrieve instance extensions!");
        terminate();
    }

    std::vector<VkExtensionProperties> supported_extensions(instance_extension_count);
    std::unordered_set<const char*>    supported_extension_names;

    result = vkEnumerateInstanceExtensionProperties(nullptr, &instance_extension_count,
                                                    supported_extensions.data());

    if (instance_extension_count == 0 || result != VK_SUCCESS) {
        printf("failed to retrieve instance extensions!");
        terminate();
    }

    for (const VkExtensionProperties &properties: supported_extensions) {
        supported_extension_names.emplace(properties.extensionName);
    }

    for (const char* name: requested_instance_extensions_) {
        if (supported_extension_names.find(name) == supported_extension_names.end()) {
            printf("requested extension unavailable\n ");
            terminate();
        }
    }

    VkInstanceCreateInfo instance_create_info{};
    instance_create_info.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instance_create_info.enabledExtensionCount   = requested_instance_extensions_.size();
    instance_create_info.enabledLayerCount       = 0;
    instance_create_info.ppEnabledExtensionNames = requested_instance_extensions_.data();
    instance_create_info.ppEnabledLayerNames     = nullptr;

    result = vkCreateInstance(&instance_create_info, nullptr, &instance_);

    if (result != VK_SUCCESS) {
        printf("failed to create instance!\n");
        terminate();
    }


}

void vulkan_renderer::release_instance()
{
    vkDestroyInstance(instance_, nullptr);
}

void vulkan_renderer::select_physical_device()
{
    uint32 physical_device_count;

    if (const VkResult result = vkEnumeratePhysicalDevices(instance_, &physical_device_count, nullptr);
            result != VK_SUCCESS) {
        std::cerr << "Couldn't find compatible vulkan logical_handle or driver\n";
        terminate();
    } else {
        std::cout << "======= Found " << physical_device_count << " physical devices. =======\n\n";
    }

    std::vector<VkPhysicalDevice> physical_devices(physical_device_count);
    vkEnumeratePhysicalDevices(instance_, &physical_device_count, physical_devices.data());

    VkPhysicalDevice selected_device = VK_NULL_HANDLE;

    for (const VkPhysicalDevice &i: physical_devices) {
        VkPhysicalDeviceProperties PhysicalDeviceProperties;
        vkGetPhysicalDeviceProperties(i, &PhysicalDeviceProperties);
        if (PhysicalDeviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
            selected_device = i;
        }
    }

    if (selected_device == VK_NULL_HANDLE) {
        selected_device = physical_devices[0];
    }

    device_.physical_device_ = selected_device;
}

void vulkan_renderer::create_device()
{

}

void vulkan_renderer::release_device()
{
    vkDestroyDevice(device_.logical_device_, nullptr);
}

void vulkan_renderer::create_surface()
{

}

void vulkan_renderer::release_surface()
{

}

void vulkan_renderer::create_swapchain()
{

}

void vulkan_renderer::recreate_swapchain()
{

}

void vulkan_renderer::release_swapchain()
{
    vkDestroySwapchainKHR(device_.logical_device_, swapchain_.vk_swapchain_, nullptr);
}

void vulkan_renderer::create_pipeline_manager()
{

}

void vulkan_renderer::release_pipeline_manager()
{

}

void vulkan_renderer::create_pipeline(const graphics_pipeline_description& pipeline_description)
{

}

void vulkan_renderer::release_pipeline()
{

}




