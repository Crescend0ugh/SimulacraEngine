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

void VulkanMemoryAllocator::init(VkPhysicalDevice physical_device)
{
    VkPhysicalDeviceMemoryProperties2 memory_properties_2{};
    VkPhysicalDeviceMemoryBudgetPropertiesEXT memory_budget{};
    memory_properties_2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2;
    memory_properties_2.pNext = &memory_budget;
    memory_budget.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT;
    vkGetPhysicalDeviceMemoryProperties2(physical_device, &memory_properties_2);

}

void shutdown()
{
}

void VulkanMemoryAllocator::alloc()
{

}

void VulkanMemoryAllocator::free()
{

}

void VulkanMemoryAllocator::realloc()
{

}

