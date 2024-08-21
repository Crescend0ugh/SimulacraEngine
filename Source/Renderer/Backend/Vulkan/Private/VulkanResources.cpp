//
// Created by avsom on 8/21/2024.
//

#include "VulkanResources.h"
#include "VulkanRHI.h"

VulkanBuffer VulkanRHI::create_buffer(VkDeviceSize size, VkBufferUsageFlags usage_flags, VkMemoryPropertyFlags property_flags)
{

    VulkanBuffer buffer{};

    VkBufferCreateInfo buffer_create_info{};
    buffer_create_info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_create_info.size = size;
    buffer_create_info.usage = usage_flags;

    VK_ASSERT_SUCCESS(vkCreateBuffer(logical_device_, &buffer_create_info, nullptr, &buffer.buffer))

    VkMemoryRequirements memory_requirements;
    vkGetBufferMemoryRequirements(logical_device_, buffer.buffer, &memory_requirements);

    uint32 memory_type_index;
    memory_allocator_.find_memory_type_index(property_flags, memory_requirements.memoryTypeBits, memory_type_index);

    buffer.memory = memory_allocator_.alloc(memory_type_index, memory_requirements.size);
    vkBindBufferMemory(logical_device_, buffer.buffer, buffer.memory, 0);
    return buffer;
}