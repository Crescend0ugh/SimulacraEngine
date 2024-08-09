//
// Created by avsom on 7/26/2024.
//

#include "VulkanMemoryAllocator.h"

VulkanMemoryAllocator::VulkanMemoryAllocator()
{
}

VulkanMemoryAllocator::~VulkanMemoryAllocator()
{
}

void VulkanMemoryAllocator::init(VkPhysicalDevice physical_device, VkDevice device)
{
    physical_device_ = physical_device;
    device_          = device;
    VkPhysicalDeviceMemoryProperties2         memory_properties_2{};
    VkPhysicalDeviceMemoryBudgetPropertiesEXT memory_budget{};
    memory_properties_2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2;
    memory_properties_2.pNext = &memory_budget;
    memory_budget.sType       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT;
    vkGetPhysicalDeviceMemoryProperties2(physical_device, &memory_properties_2);
    memory_properties_ = memory_properties_2.memoryProperties;
    uint32 device_local_heaps_count = 0;
    uint32 non_local_heaps_count    = 0;

    for (VkMemoryHeap &memory_heap: memory_properties_2.memoryProperties.memoryHeaps) {
        if (memory_heap.size != 0) {
            if (memory_heap.flags & VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT) {
                device_local_heaps_count++;
            } else {
                non_local_heaps_count++;
            }
        }
    }


}

void shutdown()
{
}

VkDeviceMemory VulkanMemoryAllocator::alloc(uint32 memory_type_index, VkDeviceSize size)
{
    VkMemoryAllocateInfo memory_allocate_info{};
    memory_allocate_info.sType           = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    memory_allocate_info.memoryTypeIndex = memory_type_index;
    memory_allocate_info.allocationSize  = size;

    VkDeviceMemory device_memory;
    vkAllocateMemory(device_, &memory_allocate_info, nullptr, &device_memory);
    return device_memory;
}

bool VulkanMemoryAllocator::find_memory_type_index(VkMemoryPropertyFlags desired_memory_properties,
                                                   uint32 desired_memory_type_bits, uint32 &memory_type_index)
{
    for (uint32 index = 0; index < memory_properties_.memoryTypeCount; ++index) {
        const uint32 is_required_type        = (1 << index) & desired_memory_type_bits;
        const bool   has_required_properties =
                             (memory_properties_.memoryTypes[index].propertyFlags & desired_memory_properties) ==
                             desired_memory_properties;

        if (is_required_type && has_required_properties) {
            memory_type_index = index;
            return true;
        }
    }
    return false;
}


