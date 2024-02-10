//
// Created by avsom on 12/31/2023.
//

#include "../Public/SimulacraVulkanResource.h"


SVulkanBuffer::SVulkanBuffer(SVulkanDevice *InDevice) : Device(InDevice), BufferMemory(VK_NULL_HANDLE), Buffer(VK_NULL_HANDLE)
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

SVulkanBuffer::~SVulkanBuffer()
{
    vkDestroyBuffer(Device->GetHandle(), Buffer, nullptr);
}

void SVulkanBuffer::AllocateMemory(uint32 Type, VkMemoryPropertyFlags Properties)
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

    vkBindBufferMemory(Device->GetHandle(), Buffer, BufferMemory, 0);

    void* Data;
    vkMapMemory(Device->GetHandle(), BufferMemory, 0,   sizeof(SVertex)*Vertices.size(), 0, &Data);
    memcpy(Data, Vertices.data(), (size_t) sizeof(SVertex)*Vertices.size());
    vkUnmapMemory(Device->GetHandle(), BufferMemory);

}

void SVulkanBuffer::BindBuffer(SVulkanBuffer *Buffer, SVulkanCommandBuffer *CommandBuffer)
{
    VkBuffer VertexBuffer[] = {Buffer->GetHandle()};
    VkDeviceSize offsets[] = {0};
    vkCmdBindVertexBuffers(CommandBuffer->GetHandle(), 0, 1, VertexBuffer, offsets);
}
