//
// Created by avsom on 10/23/2023.
//

#include "SimulacraVulkanDevice.h"
#include "SimulacraVulkanInstance.h"
#include <optional>
#include <set>

vulkan_device::vulkan_device()
        : graphics_queue_(), present_queue_(), compute_queue_(), transfer_queue_(), logical_device_(VK_NULL_HANDLE),
          physical_device_(VK_NULL_HANDLE)
{

}

vulkan_device::~vulkan_device()
{
    vkDestroyDevice(logical_device_, nullptr);
}

void vulkan_device:: query_supported_extensions()
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
        std::cerr << "Couldn't find compatible vulkan logical_handle or driver\n";
        terminate();
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

void vulkan_device::initialize_logical_device(VkSurfaceKHR surface)
{
    std::optional<uint32> graphics_queue_family_index = find_queue_family_index(
            [&](const int &index, const VkQueueFamilyProperties &properties)
            {
                VkBool32 supported;
                vkGetPhysicalDeviceSurfaceSupportKHR(physical_device_, index,
                                                     surface, &supported);

                return (properties.queueFlags & VK_QUEUE_GRAPHICS_BIT) == VK_QUEUE_GRAPHICS_BIT && supported == VK_TRUE;
            });

    std::optional<uint32> compute_queue_family_index = find_queue_family_index(
            [&](const int &index, const VkQueueFamilyProperties &properties)
            {
                return (properties.queueFlags & VK_QUEUE_COMPUTE_BIT) == VK_QUEUE_COMPUTE_BIT &&
                       (properties.queueFlags & VK_QUEUE_GRAPHICS_BIT) != VK_QUEUE_GRAPHICS_BIT;
            });

    std::optional<uint32> transfer_queue_family_index = find_queue_family_index(
            [&](const int &index, const VkQueueFamilyProperties &properties)
            {
                return (properties.queueFlags & VK_QUEUE_TRANSFER_BIT) == VK_QUEUE_TRANSFER_BIT &&
                       (properties.queueFlags & VK_QUEUE_COMPUTE_BIT) != VK_QUEUE_COMPUTE_BIT &&
                       (properties.queueFlags & VK_QUEUE_GRAPHICS_BIT) != VK_QUEUE_GRAPHICS_BIT;
            });

    assert(graphics_queue_family_index.has_value());

    compute_queue_family_index = compute_queue_family_index.has_value() ? compute_queue_family_index
                                                                        : graphics_queue_family_index;

    transfer_queue_family_index = transfer_queue_family_index.has_value() ? transfer_queue_family_index
                                                                          : graphics_queue_family_index;

    std::set<uint32> queue_family_indices = {graphics_queue_family_index.value(), compute_queue_family_index.value(),
                                             transfer_queue_family_index.value()};

    std::vector<VkDeviceQueueCreateInfo> queue_create_infos;

    std::vector<float> queue_priorities;

    for (const uint32 &queue_family_index: queue_family_indices) {
        queue_create_infos.push_back({});
        queue_priorities.push_back(1);
        queue_create_infos.back().sType            = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queue_create_infos.back().queueFamilyIndex = queue_family_index;
        queue_create_infos.back().pQueuePriorities = &queue_priorities.back();
        queue_create_infos.back().queueCount       = 1;
    }

    std::vector<const char *> enabled_extension_names;

    for (const vulkan_device_extension& device_extension : vulkan_device_extension::required_extensions())
    {
        enabled_extension_names.push_back(device_extension.get_name());
    }

    VkDeviceCreateInfo device_create_info{};
    device_create_info.sType                   = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    device_create_info.enabledExtensionCount   = enabled_extension_names.size();
    device_create_info.enabledLayerCount       = 0;
    device_create_info.pEnabledFeatures        = nullptr;
    device_create_info.ppEnabledExtensionNames = enabled_extension_names.data();
    device_create_info.pQueueCreateInfos       = queue_create_infos.data();
    device_create_info.queueCreateInfoCount    = queue_create_infos.size();

    if (const VkResult result = vkCreateDevice(physical_device_, &device_create_info, nullptr, &logical_device_); result !=
                                                                                                                  VK_SUCCESS) {
        std::cerr << "Couldn't create Vulkan logical_handle.\n";
        terminate();
    } else {
        std::cout << "======= Created Vulkan logical_handle! =======\n\n";
    }

    graphics_queue_ = vulkan_queue(logical_device_, graphics_queue_family_index.value(), 0);
    present_queue_  = graphics_queue_;
    compute_queue_  = vulkan_queue(logical_device_, compute_queue_family_index.value(), 0);
    transfer_queue_ = vulkan_queue(logical_device_, transfer_queue_family_index.value(), 0);
}


std::optional<uint32> vulkan_device::find_queue_family_index(
        const std::function<bool(const uint32 &, const VkQueueFamilyProperties &)> &criteria)
{
    uint32 queue_family_count;
    vkGetPhysicalDeviceQueueFamilyProperties(physical_device_, &queue_family_count, nullptr);
    std::vector<VkQueueFamilyProperties> queue_families(queue_family_count);
    vkGetPhysicalDeviceQueueFamilyProperties(physical_device_, &queue_family_count, queue_families.data());

    for (int current_index = 0; current_index < queue_families.size(); current_index++) {
        VkQueueFamilyProperties &current_index_family = queue_families[current_index];
        if (criteria(current_index, current_index_family)) {
            return current_index;
        }
    }

    return std::nullopt;
}