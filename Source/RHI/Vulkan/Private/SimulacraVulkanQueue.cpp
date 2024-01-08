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
