//
// Created by avsom on 1/19/2024.
//

#include "../Public/SimulacraVulkanCommandBuffer.h"


SVulkanCommandBuffer::SVulkanCommandBuffer(SVulkanDevice *InDevice, SVulkanCommandPool* InCommandPool) : Device(InDevice), CommandPool(InCommandPool), CommandBuffer(VK_NULL_HANDLE)
{
    VkCommandBufferAllocateInfo CommandBufferAllocateInfo;
    SetZeroVulkanStruct(CommandBufferAllocateInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO);
    CommandBufferAllocateInfo.commandPool = CommandPool->GetHandle();
    CommandBufferAllocateInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    CommandBufferAllocateInfo.commandBufferCount = 1;


    if (vkAllocateCommandBuffers(Device->GetHandle(), &CommandBufferAllocateInfo, &CommandBuffer) != VK_SUCCESS) {
        throw std::runtime_error("failed to allocate command buffers!");
    }

}

SVulkanCommandBuffer::~SVulkanCommandBuffer()
{

}

void SVulkanCommandBuffer::Begin()
{
    VkCommandBufferBeginInfo CommandBufferBeginInfo;
    SetZeroVulkanStruct(CommandBufferBeginInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO);

    if (vkBeginCommandBuffer(CommandBuffer, &CommandBufferBeginInfo) != VK_SUCCESS) {
        throw std::runtime_error("failed to begin recording command buffer!");
    }

}

void SVulkanCommandBuffer::End()
{
    if (vkEndCommandBuffer(CommandBuffer) != VK_SUCCESS) {
        throw std::runtime_error("failed to record command buffer!");
    }
}

void SVulkanCommandBuffer::BeginRenderPass(VkRenderPass InRenderPass, VkFramebuffer InFrameBuffer, VkExtent2D InSwapchainExtent)
{
    VkRenderPassBeginInfo RenderPassBeginInfo;
    SetZeroVulkanStruct(RenderPassBeginInfo, VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO);
    RenderPassBeginInfo.renderPass = InRenderPass;
    RenderPassBeginInfo.framebuffer = InFrameBuffer;
    RenderPassBeginInfo.renderArea.offset = {0,0};
    RenderPassBeginInfo.renderArea.extent = InSwapchainExtent;

    VkClearValue ClearColor = {{{0.0f, 0.0f, 0.0f, 1.0f}}};
    RenderPassBeginInfo.clearValueCount = 1;
    RenderPassBeginInfo.pClearValues = &ClearColor;

    vkCmdBeginRenderPass(CommandBuffer, &RenderPassBeginInfo, VK_SUBPASS_CONTENTS_INLINE );
}

void SVulkanCommandBuffer::EndRenderPass()
{
    vkCmdEndRenderPass(CommandBuffer);
}

SVulkanCommandPool::SVulkanCommandPool(SVulkanDevice* InDevice, uint32 InQueueFamilyIndex) : Device(InDevice), CommandPool(VK_NULL_HANDLE)
{
    VkCommandPoolCreateInfo CommandPoolCreateInfo;
    SetZeroVulkanStruct(CommandPoolCreateInfo, VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO);
    CommandPoolCreateInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    CommandPoolCreateInfo.queueFamilyIndex = InQueueFamilyIndex;
    if (vkCreateCommandPool(Device->GetHandle(), &CommandPoolCreateInfo, nullptr, &CommandPool) != VK_SUCCESS) {
        throw std::runtime_error("failed to create command pool!");
    }
}

SVulkanCommandPool::~SVulkanCommandPool()
{
    vkDestroyCommandPool(Device->GetHandle(), CommandPool, nullptr);
}
