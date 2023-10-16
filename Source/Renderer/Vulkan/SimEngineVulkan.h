//
// Created by avsom on 10/15/2023.
//

#ifndef SIMULACRAENGINE_SIMENGINEVULKAN_H
#define SIMULACRAENGINE_SIMENGINEVULKAN_H

#include <vulkan/vulkan.h>
#include "../../Core/Sys/Precompiled.h"



//================================                 =======================================

const char* PhysicalDeviceTypeToString(VkPhysicalDeviceType DeviceType);
bool IsDeviceSuitable(VkPhysicalDevice PhysicalDevice);
uint32 GetDeviceScore(VkPhysicalDevice PhysicalDevice);
uint32 FindQueueFamilies(VkPhysicalDevice Device);
VkPhysicalDevice PickMostSuitableDevice(std::vector<VkPhysicalDevice> PhysicalDevices);




//================================ Debug Utilities =======================================






#endif //SIMULACRAENGINE_SIMENGINEVULKAN_H
