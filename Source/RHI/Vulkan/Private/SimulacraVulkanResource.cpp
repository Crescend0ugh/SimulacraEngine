//
// Created by avsom on 12/31/2023.
//

#include "../Public/SimulacraVulkanResource.h"


SVulkanBuffer::SVulkanBuffer(SVulkanDevice *InDevice) : Device(InDevice), BufferMemory(VK_NULL_HANDLE),
                                                        Buffer(VK_NULL_HANDLE)
{

    uint32             QueueFamilyIndices[] = {Device->GetGraphicsQueue()->GetFamilyIndex(),
                                               Device->GetTransferQueue()->GetFamilyIndex()};
    VkBufferCreateInfo BufferCreateInfo;
    SetZeroVulkanStruct(BufferCreateInfo, VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO);
    BufferCreateInfo.size                  = sizeof(SVertex) * Vertices.size();
    BufferCreateInfo.usage                 = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
    BufferCreateInfo.sharingMode           = VK_SHARING_MODE_CONCURRENT;
    BufferCreateInfo.queueFamilyIndexCount = 2;
    BufferCreateInfo.pQueueFamilyIndices   = QueueFamilyIndices;

    if (vkCreateBuffer(InDevice->GetHandle(), &BufferCreateInfo, nullptr, &Buffer) != VK_SUCCESS)
    {
        throw std::runtime_error("Failed to create vertex buffer!\n");
    } else
    {
        std::cout << "Created vertex buffer\n";
    }
}

SVulkanBuffer::SVulkanBuffer(SVulkanDevice *InDevice, VkDeviceSize InSize, VkMemoryPropertyFlags Properties,
                             VkBufferUsageFlags InUsage)
{

    std::vector<uint32> QueueFamilyIndices;
    QueueFamilyIndices.push_back(Device->GetGraphicsQueue()->GetFamilyIndex());

    if (((InUsage & VK_BUFFER_USAGE_TRANSFER_SRC_BIT) == VK_BUFFER_USAGE_TRANSFER_SRC_BIT ||
        (InUsage & VK_BUFFER_USAGE_TRANSFER_DST_BIT) == VK_BUFFER_USAGE_TRANSFER_DST_BIT) &&
        Device->GetGraphicsQueue()->GetFamilyIndex() != Device->GetTransferQueue()->GetFamilyIndex())
    {
        QueueFamilyIndices.push_back(Device->GetTransferQueue()->GetFamilyIndex());
    }
    QueueFamilyIndices.shrink_to_fit();


    VkBufferCreateInfo BufferCreateInfo;
    SetZeroVulkanStruct(BufferCreateInfo, VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO);

    BufferCreateInfo.size                  = InSize;
    BufferCreateInfo.usage                 = InUsage;
    BufferCreateInfo.sharingMode           = QueueFamilyIndices.size() > 1 ? VK_SHARING_MODE_CONCURRENT : VK_SHARING_MODE_EXCLUSIVE;
    BufferCreateInfo.queueFamilyIndexCount = QueueFamilyIndices.size();
    BufferCreateInfo.pQueueFamilyIndices   = QueueFamilyIndices.data();


    if (vkCreateBuffer(Device->GetHandle(), &BufferCreateInfo, nullptr, &Buffer) != VK_SUCCESS)
    {
        throw std::runtime_error("failed to create buffer!");
    } else
    {
        std::cout << "Created Buffer\n----------\n";
    }

    VkMemoryRequirements MemoryRequirements;
    vkGetBufferMemoryRequirements(Device->GetHandle(), Buffer, &MemoryRequirements);


    AllocateMemory(MemoryRequirements.memoryTypeBits, Properties);

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
    } else
    {
        std::cout << "Allocated buffer memory\n";
    }

    vkBindBufferMemory(Device->GetHandle(), Buffer, BufferMemory, 0);

    void *Data;
    vkMapMemory(Device->GetHandle(), BufferMemory, 0, sizeof(SVertex) * Vertices.size(), 0, &Data);
    memcpy(Data, Vertices.data(), (size_t) sizeof(SVertex) * Vertices.size());
    vkUnmapMemory(Device->GetHandle(), BufferMemory);

}

void SVulkanBuffer::BindBuffer(SVulkanBuffer *Buffer, SVulkanCommandBuffer *CommandBuffer)
{
    VkBuffer     VertexBuffer[] = {Buffer->GetHandle()};
    VkDeviceSize offsets[]      = {0};
    vkCmdBindVertexBuffers(CommandBuffer->GetHandle(), 0, 1, VertexBuffer, offsets);
}

