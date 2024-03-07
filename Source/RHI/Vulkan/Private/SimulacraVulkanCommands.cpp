//
// Created by avsom on 2/12/2024.
//

#include "../Public/SimulacraVulkanCommands.h"


void SVulkanCommands::BindVertexBuffer(SVulkanBuffer *InBuffer, SVulkanCommandBuffer *InCommandBuffer)
{
    VkDeviceSize Offsets[] = {0};
    vkCmdBindVertexBuffers(InCommandBuffer->GetHandle(), 0, 1, &InBuffer->GetHandle(), Offsets);
}

void
SVulkanCommands::BindIndexBuffer(SVulkanBuffer *InBuffer, SVulkanCommandBuffer *InCommandBuffer,
                                 VkIndexType InIndexType)
{
    vkCmdBindIndexBuffer(InCommandBuffer->GetHandle(), InBuffer->GetHandle(), 0, InIndexType);
}

void SVulkanCommands::CopyBuffer(SVulkanBuffer *SrcBuffer, SVulkanBuffer *DstBuffer, VkDeviceSize NumBytes)
{
    
}

void SVulkanCommands::CopyBufferToImage()
{

}

void SVulkanCommands::CopyImageToBuffer()
{

}

void SVulkanCommands::BindPipeline()
{

}

void SVulkanCommands::DrawPrimitive()
{

}

void SVulkanCommands::DrawIndexedPrimitive()
{

}

void SVulkanCommands::DrawPrimitivesIndirect()
{

}

void SVulkanCommands::DrawIndexedPrimitiveIndirect()
{

}
