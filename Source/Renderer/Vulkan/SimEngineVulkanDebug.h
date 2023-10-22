//
// Created by avsom on 10/17/2023.
//

#ifndef SIMULACRAENGINE_SIMENGINEVULKANDEBUG_H
#define SIMULACRAENGINE_SIMENGINEVULKANDEBUG_H

#include <vulkan/vulkan.h>
#include "../../Core/Sys/Precompiled.h"
#include "SimEngineVulkan.h"


//================================ Debug Utilities =======================================

/**
 *
 * @param DeviceType
 * @return A const char array describing the device type
 */
const char* PhysicalDeviceTypeToString(VkPhysicalDeviceType DeviceType);

std::string QueueFlagsToString(VkQueueFlags QueueFlags);

std::string QueueFamilyToString(VkQueueFamilyProperties QueueFamily);

std::string QueueFamilyIndicesToString(VkPhysicalDevice PhysicalDevice, VkSurfaceKHR Surface);

#endif //SIMULACRAENGINE_SIMENGINEVULKANDEBUG_H
