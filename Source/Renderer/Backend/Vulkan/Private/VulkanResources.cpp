//
// Created by avsom on 8/21/2024.
//

#include "VulkanRHI.h"
#include "VulkanResources.h"

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

VulkanImage VulkanRHI::create_image(uint32 width, uint32 height, VkFormat format, VkImageTiling image_tiling,
                                    VkImageUsageFlags usage, VkMemoryPropertyFlags properties)
{

    VulkanImage image{};
    VkImageCreateInfo image_create_info{};
    image_create_info.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    image_create_info.imageType = VK_IMAGE_TYPE_2D;
    image_create_info.extent.width = width;
    image_create_info.extent.height = height;
    image_create_info.extent.depth = 1;
    image_create_info.mipLevels = 1;
    image_create_info.arrayLayers = 1;
    image_create_info.format = format;
    image_create_info.tiling = image_tiling;
    image_create_info.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    image_create_info.usage = usage;
    image_create_info.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    image_create_info.samples = VK_SAMPLE_COUNT_1_BIT;
    image_create_info.flags = 0;
    VK_ASSERT_SUCCESS(vkCreateImage(logical_device_, &image_create_info, nullptr, &image.image))

    VkMemoryRequirements memory_requirements{};
    vkGetImageMemoryRequirements(logical_device_, image.image, &memory_requirements);

    uint32 memory_type_index;
    memory_allocator_.find_memory_type_index(properties, memory_requirements.memoryTypeBits, memory_type_index);

    image.memory = memory_allocator_.alloc(memory_type_index, memory_requirements.size);
    vkBindImageMemory(logical_device_, image.image, image.memory, 0);

    return image;
}