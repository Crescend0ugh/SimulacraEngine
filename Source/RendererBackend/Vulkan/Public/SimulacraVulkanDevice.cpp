//
// Created by avsom on 10/23/2023.
//

#include "SimulacraVulkanDevice.h"
#include "SimulacraVulkanInstance.h"
#include <optional>

vulkan_device::vulkan_device()
        : graphics_queue_(), present_queue_(), compute_queue_(), transfer_queue_(), device_(VK_NULL_HANDLE),
          physical_device_(VK_NULL_HANDLE)
{

}

vulkan_device::~vulkan_device()
{
    vkDestroyDevice(device_, nullptr);
}

void vulkan_device::query_supported_extensions()
{
}

void vulkan_device::query_supported_features()
{
}

void vulkan_device::select_physical_device(const vulkan_instance &instance)
{
    uint32 physical_device_count;

    if (const VkResult result = vkEnumeratePhysicalDevices(instance.get_handle(), &physical_device_count, nullptr);
            result != VK_SUCCESS) {
        std::cerr << "Couldn't find compatible vulkan device or driver\n";
    } else {
        std::cout << "======= Found " << physical_device_count << " physical devices. =======\n\n";
    }

    std::vector<VkPhysicalDevice> physical_devices(physical_device_count);
    vkEnumeratePhysicalDevices(instance.get_handle(), &physical_device_count, physical_devices.data());

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

    physical_device_ = selected_device;
}

void vulkan_device::initialize_logical_device()
{
    uint32 queue_family_count;
    vkGetPhysicalDeviceQueueFamilyProperties(physical_device_, &queue_family_count, nullptr);

    std::vector<VkQueueFamilyProperties> queue_families(queue_family_count);

    vkGetPhysicalDeviceQueueFamilyProperties(physical_device_, &queue_family_count, queue_families.data());

    std::vector<VkDeviceQueueCreateInfo> queue_create_infos;

    std::optional<uint32> graphics_queue_family_index = find_queue_family_index([](const int& index, const VkQueueFamilyProperties& properties)
                                                                                 {
        return true;
                                                                                 });
    std::optional<uint32> compute_queue_family_index;
    std::optional<uint32> transfer_queue_family_index;





    std::vector<float> queue_priorities(queue_create_infos.size());

    for (uint32 i = 0; i < queue_create_infos.size(); i++) {
        float &queue_priority = queue_priorities[i];
        queue_priority = 1.0f;
        queue_create_infos[i].pQueuePriorities = &queue_priority;
    }

    std::vector<const char *> enabled_extension_names;

    VkDeviceCreateInfo device_create_info{};
    device_create_info.sType                   = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    device_create_info.enabledExtensionCount   = enabled_extension_names.size();
    device_create_info.enabledLayerCount       = 0;
    device_create_info.pEnabledFeatures        = nullptr;
    device_create_info.ppEnabledExtensionNames = enabled_extension_names.data();
    device_create_info.pQueueCreateInfos       = queue_create_infos.data();
    device_create_info.queueCreateInfoCount    = queue_create_infos.size();


    if (const VkResult result = vkCreateDevice(physical_device_, &device_create_info, nullptr, &device_); result !=
                                                                                                          VK_SUCCESS) {
        std::cerr << "Couldn't create Vulkan device.\n";
        terminate();
    } else {
        std::cout << "======= Created Vulkan device! =======\n\n";
    }

    compute_queue_family_index = compute_queue_family_index.has_value() ? compute_queue_family_index
                                                                        : graphics_queue_family_index;

    transfer_queue_family_index = transfer_queue_family_index.has_value() ? transfer_queue_family_index
                                                                          : graphics_queue_family_index;

    graphics_queue_ = vulkan_queue(device_, graphics_queue_family_index.value(), 0);
    present_queue_  = graphics_queue_;
    compute_queue_  = vulkan_queue(device_, compute_queue_family_index.value(), 0);
    transfer_queue_ = vulkan_queue(device_, transfer_queue_family_index.value(), 0);


}


std::optional<uint32> vulkan_device::find_queue_family_index(const std::function<bool(const uint32&, const VkQueueFamilyProperties&)> &criteria)
{
    uint32 queue_family_count;
    vkGetPhysicalDeviceQueueFamilyProperties(physical_device_, &queue_family_count, nullptr);
    std::vector<VkQueueFamilyProperties> queue_families(queue_family_count);
    vkGetPhysicalDeviceQueueFamilyProperties(physical_device_, &queue_family_count, queue_families.data());

    for (int current_index = 0; current_index < queue_families.size(); current_index++)
    {
        VkQueueFamilyProperties &current_index_family = queue_families[current_index];
        if(criteria(current_index, current_index_family))
        {
            return current_index;
        }
    }

    return std::nullopt;
}