//
// Created by avsom on 10/23/2023.
//

#include "SimulacraVulkanQueue.h"



vulkan_queue::vulkan_queue(VkDevice device, uint32 family_index, uint32 queue_index) : queue_(VK_NULL_HANDLE), family_index_(family_index), queue_index_(queue_index)
{
    vkGetDeviceQueue(device, family_index_, queue_index_, &queue_);
}



