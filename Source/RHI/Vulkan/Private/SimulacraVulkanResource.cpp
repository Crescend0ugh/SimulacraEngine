//
// Created by avsom on 12/31/2023.
//

#include "../Public/SimulacraVulkanResource.h"


SBuffer::SBuffer(SVulkanDevice *InDevice)
{
    VkBufferCreateInfo BufferCreateInfo;
    SetZeroVulkanStruct(BufferCreateInfo, VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO);
    BufferCreateInfo.size        = sizeof(SVertex) * Vertices.size();
    BufferCreateInfo.usage       = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
    BufferCreateInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

    if (vkCreateBuffer(InDevice->GetHandle(), &BufferCreateInfo, nullptr, &Buffer) != VK_SUCCESS)
    {
        throw std::runtime_error("Failed to create vertex buffer!\n");
    } else
    {
        std::cout << "Created vertex buffer\n";
    }
}

SBuffer::~SBuffer()
{
    vkDestroyBuffer(Device->GetHandle(), Buffer, nullptr);
}

void SBuffer::AllocateMemory(uint32 Type, VkMemoryPropertyFlags Properties)
{
    VkMemoryRequirements MemoryRequirements;
    vkGetBufferMemoryRequirements(Device->GetHandle(), Buffer, &MemoryRequirements);

    VkPhysicalDeviceMemoryProperties PhysicalDeviceMemoryProperties;
    vkGetPhysicalDeviceMemoryProperties(Device->GetPhysicalHandle(), &PhysicalDeviceMemoryProperties);

    uint32      MemoryTypeIndex;
    for (uint32 i = 0; i < PhysicalDeviceMemoryProperties.memoryTypeCount; i++)
    {
        if (Type & (1 << i) && (PhysicalDeviceMemoryProperties.memoryTypes[i].propertyFlags & Properties) == Properties)
        {
            MemoryTypeIndex = i;
        }
    }

    VkMemoryAllocateInfo MemoryAllocateInfo;
    SetZeroVulkanStruct(MemoryAllocateInfo, VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO);

    MemoryAllocateInfo.allocationSize  = MemoryRequirements.size;
    MemoryAllocateInfo.memoryTypeIndex = MemoryTypeIndex;


    if (vkAllocateMemory(Device->GetHandle(), &MemoryAllocateInfo, nullptr, &BufferMemory) != VK_SUCCESS)
    {
        throw std::runtime_error("failed to allocate buffer memory!\n");
    }
    else
    {
        std::cout << "Allocated buffer memory\n";
    }

}
