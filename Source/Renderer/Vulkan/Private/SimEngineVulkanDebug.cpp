//
// Created by avsom on 10/17/2023.
//

#include <iostream>

#include "../Public/SimEngineVulkanDebug.h"

const char *PhysicalDeviceTypeToString(VkPhysicalDeviceType DeviceType)
{
    switch (DeviceType)
    {
        case VK_PHYSICAL_DEVICE_TYPE_OTHER :
        {
            return "Other";
        }
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU :
        {
            return "Integrated GPU";
        }
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
        {
            return "Discrete GPU";
        }
        case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
        {
            return "Virtual GPU";
        }
        case VK_PHYSICAL_DEVICE_TYPE_CPU :
        {
            return "CPU";
        }
        case VK_PHYSICAL_DEVICE_TYPE_MAX_ENUM:
        {
            return nullptr;
        }
    }
    return nullptr;
}


std::string QueueFlagsToString(VkQueueFlags QueueFlags)
{


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

std::string QueueFamilyToString(VkQueueFamilyProperties QueueFamily)
{
    std::string ReturnString;

    
    ReturnString += "Queue Count: " + std::to_string(QueueFamily.queueCount) + "\n";
    ReturnString += "Queue Flags: " + QueueFlagsToString(QueueFamily.queueFlags) + "\n";
    ReturnString += "___________________________________________________________________\n";

    return ReturnString;
}

std::string QueueFamilyIndicesToString(VkPhysicalDevice PhysicalDevice, VkSurfaceKHR Surface) {
    std::string ReturnString;
    QueueFamilyIndices Indices = FindQueueFamilies(PhysicalDevice, Surface);
    ReturnString += "Graphics Index: "       + std::to_string(Indices.GraphicsQueueFamily) + "\n";
    ReturnString += "Present Index: "        + std::to_string(Indices.PresentQueueFamily) + "\n";
    ReturnString += "Compute Index: "        + std::to_string(Indices.ComputeQueueFamily) + "\n";
    ReturnString += "Transfer Index: "       + std::to_string(Indices.TransferQueueFamily) + "\n";
    ReturnString += "Sparse Binding Index: " + std::to_string(Indices.SparseBindingQueueFamily) + "\n";
    ReturnString += "Video Decode Index: "   + std::to_string(Indices.VideoDecodeQueueFamily) + "\n";

    return ReturnString;
}



