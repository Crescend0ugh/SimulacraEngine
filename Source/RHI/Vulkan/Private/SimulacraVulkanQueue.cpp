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

void SVulkanQueue::Submit(SVulkanCommandBuffer *CommandBuffer, uint32 NumWaitSemaphores,
                          SVulkanSemaphore *InOutWaitSemaphores, uint32 NumSignalSemaphores,
                          SVulkanSemaphore *InOutSignalSemaphores, SVulkanFence *InOutFence)
{

    VkSubmitInfo SubmitInfo;
    SetZeroVulkanStruct(SubmitInfo, VK_STRUCTURE_TYPE_SUBMIT_INFO);
    VkPipelineStageFlags WaitStages[] = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
    SubmitInfo.waitSemaphoreCount = 1;
    SubmitInfo.pWaitSemaphores = &InOutWaitSemaphores->GetHandle();
    SubmitInfo.pWaitDstStageMask = WaitStages;

    SubmitInfo.commandBufferCount = 1;
    SubmitInfo.pCommandBuffers = &CommandBuffer->GetHandle();

    SubmitInfo.signalSemaphoreCount = 1;
    SubmitInfo.pSignalSemaphores = &InOutSignalSemaphores->GetHandle();

    if (vkQueueSubmit(Device->GetGraphicsQueue()->GetHandle(), 1, &SubmitInfo, InOutFence->GetHandle()) != VK_SUCCESS) {
        throw std::runtime_error("failed to submit draw command buffer!");
    }

}
