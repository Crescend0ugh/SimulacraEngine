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
SVulkanCommands::BindIndexBuffer(SVulkanBuffer *InBuffer, SVulkanCommandBuffer *InCommandBuffer, VkIndexType InIndexType)
{
    vkCmdBindIndexBuffer(InCommandBuffer->GetHandle(), InBuffer->GetHandle(), 0, InIndexType);
}
