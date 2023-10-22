//
// Created by avsom on 10/18/2023.
//

#ifndef SIMULACRAENGINE_SVKPHYSICALDEVICE_H
#define SIMULACRAENGINE_SVKPHYSICALDEVICE_H
#include "SimEngineVulkan.h"



bool IsDeviceSuitable(VkPhysicalDevice PhysicalDevice, VkSurfaceKHR Surface);

bool CheckDeviceExtensionSupport(VkPhysicalDevice PhysicalDevice);

uint32 GetDeviceScore(VkPhysicalDevice PhysicalDevice);

VkPhysicalDevice PickMostSuitableDevice(std::vector<VkPhysicalDevice> PhysicalDevices);

VkPhysicalDevice PickSuitableDevice(std::vector<VkPhysicalDevice> PhysicalDevices);

#endif //SIMULACRAENGINE_SVKPHYSICALDEVICE_H
