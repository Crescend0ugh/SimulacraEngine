//
// Created by avsom on 2/12/2024.
//

#pragma once

#include "SimulacraVulkan.h"

class SVulkanCommands
{

    virtual void CopyBuffer(SVulkanBuffer* SrcBuffer, SVulkanBuffer* DstBuffer, VkDeviceSize NumBytes) final;
    virtual void CopyBufferToImage() final;
    virtual void CopyImageToBuffer() final;

    virtual void DrawPrimitives();
    virtual void DrawIndexedPrimitives();


};
