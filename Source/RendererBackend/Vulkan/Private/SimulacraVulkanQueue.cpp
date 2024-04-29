//
// Created by avsom on 10/23/2023.
//

#include "../Public/SimulacraVulkanQueue.h"


vulkan_queue::vulkan_queue() : queue_(VK_NULL_HANDLE), family_index_(0), queue_index_(0)
{
}

vulkan_queue::vulkan_queue( VkDevice const device ,const  uint32 family_index,const  uint32 queue_index) : queue_(VK_NULL_HANDLE), family_index_(family_index), queue_index_(queue_index)
{
    vkGetDeviceQueue(device, family_index, queue_index, &queue_);
}

