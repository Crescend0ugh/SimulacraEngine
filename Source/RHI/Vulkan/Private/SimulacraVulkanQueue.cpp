//
// Created by avsom on 10/23/2023.
//

#include "../Public/SimulacraVulkanQueue.h"

SVulkanQueue::SVulkanQueue(SVulkanDevice *InDevice, uint32 InFamilyIndex)
{

    Queue       = VK_NULL_HANDLE;
    FamilyIndex = InFamilyIndex;
    QueueIndex  = 0;
    Device      = InDevice;
    vkGetDeviceQueue(InDevice->GetHandle(), FamilyIndex, QueueIndex, &Queue);
}

SVulkanQueue::~SVulkanQueue() {

}

void SVulkanQueue::Submit(SVulkanCommandBuffer *CommandBuffer, uint32 NumWaitSemaphores, VkSemaphore WaitSemaphores, uint32 NumSignalSemaphores, VkSemaphore SignalSemaphores)
{

    const VkCommandBuffer CommandBuffers[] = {CommandBuffer->GetHandle()};
    VkSubmitInfo SubmitInfo;
    SetZeroVulkanStruct(SubmitInfo, VK_STRUCTURE_TYPE_SUBMIT_INFO);
    VkPipelineStageFlags waitStages[] = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};

    SubmitInfo.commandBufferCount = 1;
    SubmitInfo.pCommandBuffers = CommandBuffers;
    SubmitInfo.pWaitSemaphores = &WaitSemaphores;
    SubmitInfo.waitSemaphoreCount = NumWaitSemaphores;
    SubmitInfo.pWaitDstStageMask = waitStages;
    SubmitInfo.signalSemaphoreCount = NumSignalSemaphores;
    SubmitInfo.pSignalSemaphores = &SignalSemaphores;
    vkQueueSubmit(Queue, 1, &SubmitInfo, VK_NULL_HANDLE);

}
