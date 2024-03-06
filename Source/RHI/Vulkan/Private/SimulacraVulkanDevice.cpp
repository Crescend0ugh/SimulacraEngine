//
// Created by avsom on 10/23/2023.
//



#include <vector>
#include "../Public/SimulacraVulkanDevice.h"


class SVulkanDevice;


SVulkanDevice::SVulkanDevice(SVulkanRHI *InRHI, VkPhysicalDevice InPhysicalDevice) :
        PhysicalDevice(InPhysicalDevice),
        RHI(InRHI)
{
}

SVulkanDevice::~SVulkanDevice()
{
    vkDestroyDevice(Device, nullptr);
}

void SVulkanDevice::CreatePhysicalDevice()
{
    uint32 QueueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(PhysicalDevice, &QueueFamilyCount, nullptr);

    std::vector<VkQueueFamilyProperties> Temp(QueueFamilyCount);
    QueueFamilyProperties.resize(QueueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(PhysicalDevice, &QueueFamilyCount, QueueFamilyProperties.data());


}

void SVulkanDevice::CreateLogicalDevice()
{

    VkDeviceCreateInfo DeviceCreateInfo;
    SetZeroVulkanStruct(DeviceCreateInfo, VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO);

    std::vector<VkDeviceQueueCreateInfo> QueueFamilyInfos;
    int32                                GraphicsQueueFamilyIndex = -1;
    int32                                ComputeQueueFamilyIndex  = -1;
    int32                                TransferQueueFamilyIndex = -1;
    uint32                               NumPriorities            = 0;

    for (int CurrentFamilyIndex = 0; CurrentFamilyIndex < QueueFamilyProperties.size(); CurrentFamilyIndex++)
    {
        VkQueueFamilyProperties &CurrentFamilyProperties = QueueFamilyProperties[CurrentFamilyIndex];

        std::cout << SVulkanDebug::QueueFamilyToString(CurrentFamilyProperties);


        bool FoundValidQueue = false;
        if ((CurrentFamilyProperties.queueFlags & VK_QUEUE_GRAPHICS_BIT) == VK_QUEUE_GRAPHICS_BIT)
        {

            if (GraphicsQueueFamilyIndex == -1)
            {
                GraphicsQueueFamilyIndex = CurrentFamilyIndex;
                FoundValidQueue          = true;
            }
        }

        if ((CurrentFamilyProperties.queueFlags & VK_QUEUE_COMPUTE_BIT) == VK_QUEUE_COMPUTE_BIT)
        {
            if (ComputeQueueFamilyIndex == -1 &&
                (CurrentFamilyProperties.queueFlags & VK_QUEUE_GRAPHICS_BIT) != VK_QUEUE_GRAPHICS_BIT)
            {
                ComputeQueueFamilyIndex = CurrentFamilyIndex;
                FoundValidQueue         = true;
            }
        }

        if ((CurrentFamilyProperties.queueFlags & VK_QUEUE_TRANSFER_BIT) == VK_QUEUE_TRANSFER_BIT)
        {
            if (TransferQueueFamilyIndex == -1 &&
                (CurrentFamilyProperties.queueFlags & VK_QUEUE_COMPUTE_BIT) != VK_QUEUE_COMPUTE_BIT &&
                (CurrentFamilyProperties.queueFlags & VK_QUEUE_GRAPHICS_BIT) != VK_QUEUE_GRAPHICS_BIT)
            {
                TransferQueueFamilyIndex = CurrentFamilyIndex;
                FoundValidQueue          = true;
            }
        }

        if (!FoundValidQueue)
        {
            continue;
        }

        uint32 QueueIndex = QueueFamilyInfos.size();

        QueueFamilyInfos.push_back({});

        VkDeviceQueueCreateInfo &CurrentQueue = QueueFamilyInfos[QueueIndex];

        SetZeroVulkanStruct(CurrentQueue, VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO);

        CurrentQueue.queueFamilyIndex = CurrentFamilyIndex;
        CurrentQueue.queueCount       = CurrentFamilyProperties.queueCount;

        NumPriorities += CurrentFamilyProperties.queueCount;

    }


    std::cout << "\n";
    std::vector<float> QueuePriorities(NumPriorities);
    float              *CurrentPriority = QueuePriorities.data();

    for (int32 Index = 0; Index < QueueFamilyInfos.size(); ++Index)
    {
        VkDeviceQueueCreateInfo &CurrentQueue = QueueFamilyInfos[Index];
        CurrentQueue.pQueuePriorities = CurrentPriority;

        VkQueueFamilyProperties &CurrentProperties = QueueFamilyProperties[CurrentQueue.queueFamilyIndex];

        for (int32 QueueIndex = 0; QueueIndex < (int32)CurrentProperties.queueCount; ++QueueIndex)
        {
            *CurrentPriority++ = 1.0f;
        }
    }

    SVulkanDeviceExtension::GetRequiredExtensions(DeviceExtensions);

    const char *EnabledExtensionNames[DeviceExtensions.size()];

    for (int i = 0; i < DeviceExtensions.size(); ++i)
    {
        EnabledExtensionNames[i] = DeviceExtensions[i].GetExtensionName();
    }

    DeviceCreateInfo.enabledExtensionCount   = DeviceExtensions.size();
    DeviceCreateInfo.ppEnabledExtensionNames = EnabledExtensionNames;
    DeviceCreateInfo.pQueueCreateInfos       = QueueFamilyInfos.data();
    DeviceCreateInfo.queueCreateInfoCount    = QueueFamilyInfos.size();
    VkResult Result = vkCreateDevice(PhysicalDevice, &DeviceCreateInfo, nullptr, &Device);
    if (Result != VK_SUCCESS)
    {
        std::cout << "Couldn't create Vulkan Device\n";
    } else
    {
        std::cout << "Created Vulkan Device\n";
    }


    GraphicsQueue = new SVulkanQueue(this, GraphicsQueueFamilyIndex);
    std::cout << "Created Graphics Queue\n--------------------\n";
    PresentQueue = GraphicsQueue;
    std::cout << SVulkanDebug::GetQueueDebugString(PresentQueue) << "\n";


    ComputeQueueFamilyIndex = ComputeQueueFamilyIndex == -1 ? GraphicsQueueFamilyIndex : ComputeQueueFamilyIndex;

        ComputeQueue = new SVulkanQueue(this, ComputeQueueFamilyIndex);
        std::cout << "Created Compute Queue\n--------------------\n";
        std::cout << SVulkanDebug::GetQueueDebugString(ComputeQueue) << "\n";

    TransferQueueFamilyIndex = TransferQueueFamilyIndex == -1 ? ComputeQueueFamilyIndex : TransferQueueFamilyIndex;


        TransferQueue = new SVulkanQueue(this, TransferQueueFamilyIndex);
        std::cout << "Created Transfer Queue\n--------------------\n";
        std::cout << SVulkanDebug::GetQueueDebugString(TransferQueue) << "\n";


}

