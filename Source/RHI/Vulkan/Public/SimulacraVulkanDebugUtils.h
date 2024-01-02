//
// Created by avsom on 1/1/2024.
//

#pragma once


#include <string>

/**
 * @brief Queries the Queue Flags and returns the queue operations that are supported
 * @param QueueFlags The Queue Flags of the Queue Family to be printed
 * @return Debug string for the queue operations supported by a Queue Family
 */
SIM_FORCE_INLINE std::string QueueFlagsToString(VkQueueFlags QueueFlags) {


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

/**
 * @brief Returns the queue count and the queue operations supported by the inputted Queue Family
 * @param QueueFamily The Queue Family being debugged
 * @return The debug string of the Queue Family
 */
SIM_FORCE_INLINE std::string QueueFamilyToString(VkQueueFamilyProperties QueueFamily) {
    std::string ReturnString;


    ReturnString += "Queue Count: " + std::to_string(QueueFamily.queueCount) + "\n";
    ReturnString += "Queue Flags: " + QueueFlagsToString(QueueFamily.queueFlags) + "\n";
    ReturnString += "___________________________________________________________________\n";

    return ReturnString;
}

