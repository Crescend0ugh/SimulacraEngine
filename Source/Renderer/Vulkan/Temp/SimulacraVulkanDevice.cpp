//
// Created by avsom on 10/23/2023.
//



#include "SimulacraVulkanDevice.h"


class SVulkanDevice;

SVulkanDevice::SVulkanDevice(SVulkanRHI* InRHI, VkPhysicalDevice InPhysicalDevice):
PhysicalDevice(InPhysicalDevice),
RHI(InRHI)
{

}

SVulkanDevice::~SVulkanDevice() {

}

void SVulkanDevice::CreatePhysicalDevice()
{
    uint32 QueueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(PhysicalDevice, &QueueFamilyCount, nullptr);

    QueueFamilyProperties.reserve(QueueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(PhysicalDevice, &QueueFamilyCount, QueueFamilyProperties.data());

}

void SVulkanDevice::CreateDevice()
{
    VkDeviceCreateInfo DeviceCreateInfo;
    SetZeroVulkanStruct(DeviceCreateInfo, VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO);

    std::vector<VkDeviceQueueCreateInfo> QueueFamilyInfos;
    int32 GraphicsQueueFamilyIndex = -1;
    int32 ComputeQueueFamilyIndex = -1;
    int32 TransferQueueFamilyIndex = -1;
    std::cout<< "Found %d Queue Families \n", QueueFamilyProperties.size();
    uint32 NumPriorities = 0;

    for(int CurrentFamilyIndex = 0; CurrentFamilyIndex < QueueFamilyProperties.size(); CurrentFamilyIndex++)
    {
        VkQueueFamilyProperties& CurrentFamilyProperties = QueueFamilyProperties[CurrentFamilyIndex];


        bool CanUseQueue = false;
        if ((CurrentFamilyProperties.queueFlags & VK_QUEUE_GRAPHICS_BIT) == VK_QUEUE_GRAPHICS_BIT)
        {
            if(GraphicsQueueFamilyIndex == -1)
            {
                GraphicsQueueFamilyIndex = CurrentFamilyIndex;
                CanUseQueue = true;
            }
        }

        if ((CurrentFamilyProperties.queueFlags & VK_QUEUE_COMPUTE_BIT) == VK_QUEUE_COMPUTE_BIT)
        {
            if(ComputeQueueFamilyIndex == -1)
            {
                ComputeQueueFamilyIndex = CurrentFamilyIndex;
                CanUseQueue = true;
            }
        }

        if ((CurrentFamilyProperties.queueFlags & VK_QUEUE_TRANSFER_BIT) == VK_QUEUE_TRANSFER_BIT)
        {
            if(TransferQueueFamilyIndex == -1)
            {
                TransferQueueFamilyIndex = CurrentFamilyIndex;
                CanUseQueue = true;
            }
        }

        uint32 QueueIndex = QueueFamilyInfos.size();
        QueueFamilyInfos.push_back({});
        VkDeviceQueueCreateInfo& CurrentQueue = QueueFamilyInfos[QueueIndex];
        SetZeroVulkanStruct(CurrentQueue, VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO);
        CurrentQueue.queueFamilyIndex = CurrentFamilyIndex;
        CurrentQueue.queueCount = CurrentFamilyProperties.queueCount;
        NumPriorities += CurrentFamilyProperties.queueCount;

    }



    std::vector<float> QueuePriorities(NumPriorities);
    float* CurrentPriority = QueuePriorities.data();
    for (int32 Index = 0;  Index < QueueFamilyInfos.size() ; ++Index)
    {
        VkDeviceQueueCreateInfo& CurrentQueue = QueueFamilyInfos[Index];
        CurrentQueue.pQueuePriorities = CurrentPriority;

        VkQueueFamilyProperties& CurrentProperties = QueueFamilyProperties[CurrentQueue.queueFamilyIndex];
        

    }

    VkResult Result = vkCreateDevice(PhysicalDevice, &DeviceCreateInfo, nullptr, &Device);


    GraphicsQueue = new SVulkanQueue(this, GraphicsQueueFamilyIndex);

    if(ComputeQueueFamilyIndex != -1)
    {
        ComputeQueue = new SVulkanQueue(this, ComputeQueueFamilyIndex);
    }



    if(TransferQueueFamilyIndex != -1)
    {
        TransferQueue = new SVulkanQueue(this, TransferQueueFamilyIndex);
    }
}

