//
// Created by avsom on 1/1/2024.
//

#pragma once


#include "SimulacraVulkan.h"


namespace SVulkanDebug
{
/**
 * @brief Queries the Queue Flags and returns the queue operations that are supported
 * @param QueueFlags The Queue Flags of the Queue Family to be printed
 * @return Debug string for the queue operations supported by a Queue Family
 */
    SIM_FORCE_INLINE std::string QueueFlagsToString(VkQueueFlags QueueFlags)
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

    SIM_FORCE_INLINE std::string PhysicalDeviceTypeToString(VkPhysicalDeviceType DeviceType)
    {
        std::string ReturnString;

        switch (DeviceType)
        {

            case VK_PHYSICAL_DEVICE_TYPE_OTHER:
                ReturnString = "OTHER";
                break;
            case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
                ReturnString = "INTEGRATED";
                break;
            case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
                ReturnString = "DISCRETE";
                break;
            case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
                ReturnString = "VIRTUAL";
                break;
            case VK_PHYSICAL_DEVICE_TYPE_CPU:
                ReturnString = "CPU";
                break;
            case VK_PHYSICAL_DEVICE_TYPE_MAX_ENUM:
                ReturnString = "ERROR";
                break;
        }

        return ReturnString;
    }
/**
 * @brief Returns the queue count and the queue operations supported by the inputted Queue Family
 * @param QueueFamily The Queue Family being debugged
 * @return The debug string of the Queue Family
 */
    SIM_FORCE_INLINE std::string QueueFamilyToString(VkQueueFamilyProperties QueueFamily)
    {
        std::string ReturnString;


        ReturnString += "Queue Count: " + std::to_string(QueueFamily.queueCount) + "\n";
        ReturnString += "Queue Flags: " + QueueFlagsToString(QueueFamily.queueFlags) + "\n";
        ReturnString += "___________________________________________________________________\n";

        return ReturnString;
    }

    std::string GetQueueDebugString(SVulkanQueue *Queue);

    SIM_FORCE_INLINE std::string PhysicalDeviceToString(VkPhysicalDevice PhysicalDevice)
    {
        std::string ReturnString;

        VkPhysicalDeviceProperties PhysicalDeviceProperties;
        vkGetPhysicalDeviceProperties(PhysicalDevice, &PhysicalDeviceProperties);

        ReturnString += "Device: ";
        ReturnString += PhysicalDeviceProperties.deviceName;
        ReturnString += "\n--------------------\n";
        ReturnString += "Device Type: ";
        ReturnString += PhysicalDeviceTypeToString(PhysicalDeviceProperties.deviceType);
        return ReturnString;
    }

}