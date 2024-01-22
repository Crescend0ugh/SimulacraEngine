//
// Created by avsom on 1/19/2024.
//

#pragma once

#include "SimulacraVulkan.h"

class SVulkanCommandBuffer;

class SVulkanCommandPool;

class SVulkanCommandBuffer
{
public:
    SVulkanCommandBuffer(SVulkanDevice *InDevice, SVulkanCommandPool *InCommandPool);

    ~SVulkanCommandBuffer();

    SVulkanDevice *GetDevice()
    { return Device; }

    SVulkanCommandPool *GetCommandPool()
    { return CommandPool; }

    VkCommandBuffer GetHandle()
    { return CommandBuffer; }

    void Begin();

    void End();

    void BeginRenderPass(VkRenderPass InRenderPass, VkFramebuffer InFrameBuffer, VkExtent2D InSwapchainExtent);

    void EndRenderPass();

private:

    std::vector<SVulkanSemaphore *> WaitSemaphore;
    SVulkanDevice                   *Device;
    SVulkanCommandPool              *CommandPool;
    VkCommandBuffer                 CommandBuffer;


};

class SVulkanCommandPool
{
public:

    SVulkanCommandPool(SVulkanDevice *InDevice, uint32 InQueueFamilyIndex);

    ~SVulkanCommandPool();

    VkCommandPool GetHandle()
    { return CommandPool; }

private:

    SVulkanDevice *Device;
    VkCommandPool CommandPool;
};


