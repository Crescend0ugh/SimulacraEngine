//
// Created by avsom on 12/31/2023.
//

#pragma once


#include "SimulacraVulkan.h"
#include <array>

struct SVertex
{
    struct SPosition
    {

        float X;
        float Y;
    };

    struct SColor
    {
        float R;
        float G;
        float B;
    };

    static VkVertexInputBindingDescription GetBindingDescription()
    {
        VkVertexInputBindingDescription BindingDescription{};

        BindingDescription.binding   = 0;
        BindingDescription.stride    = sizeof(SVertex);
        BindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
        return BindingDescription;


    }

    static std::array<VkVertexInputAttributeDescription, 2> GetAttributeDescriptions()
    {
        std::array<VkVertexInputAttributeDescription, 2> AttributeDescriptions{};

        AttributeDescriptions[0].binding  = 0;
        AttributeDescriptions[0].location = 0;
        AttributeDescriptions[0].format   = VK_FORMAT_R32G32_SFLOAT;
        AttributeDescriptions[0].offset   = offsetof(SVertex, Position);

        AttributeDescriptions[1].binding  = 0;
        AttributeDescriptions[1].location = 1;
        AttributeDescriptions[1].format   = VK_FORMAT_R32G32B32_SFLOAT;
        AttributeDescriptions[1].offset   = offsetof(SVertex, Color);

        return AttributeDescriptions;
    }

    SPosition Position;
    SColor    Color;


};

const std::vector<SVertex> Vertices = {
        {{-0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
        {{0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
        {{0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
        {{-0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}}
};

const std::vector<uint16> Indices = {
        0, 1, 2, 2, 3, 0
};

class SVulkanBuffer
{
public:

    SVulkanBuffer(SVulkanDevice *InDevice, VkDeviceSize InSize, VkMemoryPropertyFlags Properties,
                  VkBufferUsageFlags InUsage);

    SVulkanBuffer(SVulkanDevice *InDevice);

    ~SVulkanBuffer();

    VkBuffer& GetHandle()
    { return Buffer; }

    VkDeviceMemory& GetMemory() { return BufferMemory; }

    void AllocateMemory(uint32 Type, VkMemoryPropertyFlags Properties);

    static void BindBuffer(SVulkanBuffer *Buffer, SVulkanCommandBuffer *CommandBuffer);
    static void CopyBuffer(SVulkanBuffer *SrcBuffer, SVulkanBuffer *DstBuffer, VkDeviceSize Size,
                           SVulkanCommandPool *CommandPool);

    static SVulkanBuffer* IndexBuffer;
    static SVulkanBuffer* VertBuffer;
private:

    SVulkanDevice* Device;
    VkBuffer Buffer;
    VkDeviceMemory BufferMemory;

};


class VulkanBuffer
{

    VulkanBuffer(SVulkanDevice *InDevice, VkDeviceSize InSize, VkMemoryPropertyFlags InProperties, VkBufferUsageFlags InUsage);

    SIM_INLINE VkBuffer& GetHandle() { return Buffer; }
    SIM_INLINE VkDeviceMemory& GetMemory() { return BufferMemory; }
    SIM_INLINE VkDeviceSize GetSize() const { return Size; }

    void Map(void*& OutData);
    void Unmap();

private:

    SVulkanDevice* Device;
    VkBuffer Buffer;
    VkDeviceMemory BufferMemory;
    VkDeviceSize Size;

};

