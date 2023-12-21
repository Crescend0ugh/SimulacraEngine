//
// Created by avsom on 10/23/2023.
//



#include "../Public/SimulacraVulkanDevice.h"


class SVulkanDevice;

std::string QueueFlagsToString(VkQueueFlags QueueFlags) {


    std::string ReturnString;

    if (QueueFlags & VK_QUEUE_GRAPHICS_BIT)
        ReturnString += "| Graphics | ";
    if (QueueFlags & VK_QUEUE_COMPUTE_BIT)
        ReturnString += "| Compute | ";
    if (QueueFlags & VK_QUEUE_TRANSFER_BIT)
        ReturnString += "| Transfer | ";
    if (QueueFlags & VK_QUEUE_SPARSE_BINDING_BIT)
        ReturnString += "| Sparse Binding | ";
    if (QueueFlags & VK_QUEUE_PROTECTED_BIT)
        ReturnString += "| Protected | ";
    if (QueueFlags & VK_QUEUE_VIDEO_DECODE_BIT_KHR)
        ReturnString += "| Video Decode | ";

    return ReturnString;
}

std::string QueueFamilyToString(VkQueueFamilyProperties QueueFamily) {
    std::string ReturnString;


    ReturnString += "Queue Count: " + std::to_string(QueueFamily.queueCount) + "\n";
    ReturnString += "Queue Flags: " + QueueFlagsToString(QueueFamily.queueFlags) + "\n";
    ReturnString += "___________________________________________________________________\n";

    return ReturnString;
}


SVulkanDevice::SVulkanDevice(SVulkanRHI *InRHI, VkPhysicalDevice InPhysicalDevice) :
        PhysicalDevice(InPhysicalDevice),
        RHI(InRHI) {
}

SVulkanDevice::~SVulkanDevice() {

}

void SVulkanDevice::CreatePhysicalDevice() {
    uint32 QueueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(PhysicalDevice, &QueueFamilyCount, nullptr);

    std::vector<VkQueueFamilyProperties> Temp(QueueFamilyCount);
    QueueFamilyProperties.resize(QueueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(PhysicalDevice, &QueueFamilyCount, QueueFamilyProperties.data());

//    for (const auto &i: QueueFamilyProperties)
//    {
//        std::cout << QueueFamilyToString(i) << "\n";
//    }

}

void SVulkanDevice::CreateDevice() {
    VkDeviceCreateInfo DeviceCreateInfo;
    SetZeroVulkanStruct(DeviceCreateInfo, VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO);

    std::vector<VkDeviceQueueCreateInfo> QueueFamilyInfos;
    int32 GraphicsQueueFamilyIndex = -1;
    int32 ComputeQueueFamilyIndex = -1;
    int32 TransferQueueFamilyIndex = -1;
    uint32 NumPriorities = 0;

    for (int CurrentFamilyIndex = 0; CurrentFamilyIndex < QueueFamilyProperties.size(); CurrentFamilyIndex++) {
        VkQueueFamilyProperties &CurrentFamilyProperties = QueueFamilyProperties[CurrentFamilyIndex];


        bool CanUseQueue = false;
        if ((CurrentFamilyProperties.queueFlags & VK_QUEUE_GRAPHICS_BIT) == VK_QUEUE_GRAPHICS_BIT) {

            if (GraphicsQueueFamilyIndex == -1) {
                GraphicsQueueFamilyIndex = CurrentFamilyIndex;
                CanUseQueue = true;
            }
        }

        if ((CurrentFamilyProperties.queueFlags & VK_QUEUE_COMPUTE_BIT) == VK_QUEUE_COMPUTE_BIT) {
            if (ComputeQueueFamilyIndex == -1) {
                ComputeQueueFamilyIndex = CurrentFamilyIndex;
                CanUseQueue = true;
            }
        }

        if ((CurrentFamilyProperties.queueFlags & VK_QUEUE_TRANSFER_BIT) == VK_QUEUE_TRANSFER_BIT) {
            if (TransferQueueFamilyIndex == -1) {
                TransferQueueFamilyIndex = CurrentFamilyIndex;
                CanUseQueue = true;
            }
        }


        uint32 QueueIndex = QueueFamilyInfos.size();
        QueueFamilyInfos.push_back({});
        VkDeviceQueueCreateInfo &CurrentQueue = QueueFamilyInfos[QueueIndex];
        SetZeroVulkanStruct(CurrentQueue, VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO);
        CurrentQueue.queueFamilyIndex = CurrentFamilyIndex;
        CurrentQueue.queueCount = CurrentFamilyProperties.queueCount;
        NumPriorities += CurrentFamilyProperties.queueCount;

    }


    std::cout << "\n";
    std::vector<float> QueuePriorities(NumPriorities);
    float *CurrentPriority = QueuePriorities.data();
    for (int32 Index = 0; Index < QueueFamilyInfos.size(); ++Index) {
        VkDeviceQueueCreateInfo &CurrentQueue = QueueFamilyInfos[Index];
        CurrentQueue.pQueuePriorities = CurrentPriority;

        VkQueueFamilyProperties &CurrentProperties = QueueFamilyProperties[CurrentQueue.queueFamilyIndex];


    }

    VkResult Result = vkCreateDevice(PhysicalDevice, &DeviceCreateInfo, nullptr, &Device);
    if (Result != VK_SUCCESS) {
        std::cout << "Couldn't create Vulkan Device\n";
    } else {
        std::cout << "Created Vulkan Device\n";
    }


    GraphicsQueue = new SVulkanQueue(this, GraphicsQueueFamilyIndex);
    std::cout << "Created Graphics Queue\n";

    if (ComputeQueueFamilyIndex != -1) {
        ComputeQueue = new SVulkanQueue(this, ComputeQueueFamilyIndex);
        std::cout << "Created Compute Queue\n";

    }


    if (TransferQueueFamilyIndex != -1) {
        TransferQueue = new SVulkanQueue(this, TransferQueueFamilyIndex);
        std::cout << "Created Transfer Queue\n";

    }
}

