//
// Created by avsom on 2/12/2024.
//

#pragma once

#include "SimulacraVulkan.h"


class SVulkanCommands
{

public:
    virtual void CopyBuffer(SVulkanBuffer* SrcBuffer, SVulkanBuffer* DstBuffer, VkDeviceSize NumBytes) final;
    virtual void CopyBufferToImage() final;
    virtual void CopyImageToBuffer() final;


    virtual void BindPipeline() final;
    static void BindVertexBuffer(SVulkanBuffer* InBuffer, SVulkanCommandBuffer* InCommandBuffer);
    static void BindIndexBuffer(SVulkanBuffer *InBuffer, SVulkanCommandBuffer *InCommandBuffer, VkIndexType InIndexType);


    virtual void DrawPrimitive() final;
    virtual void DrawIndexedPrimitive() final;
    virtual void DrawPrimitivesIndirect() final;
    virtual void DrawIndexedPrimitiveIndirect() final;



};
