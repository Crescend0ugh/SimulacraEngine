//
// Created by avsom on 10/15/2023.
//

#ifndef SIMULACRAENGINE_SIMENGINEVULKAN_H
#define SIMULACRAENGINE_SIMENGINEVULKAN_H

#include <vulkan/vulkan.h>
#include "../../Core/Sys/Precompiled.h"
#include "SimEngineVulkanDebug.h"

struct QueueFamilyIndices
{
    uint32 GraphicsQueueFamily      = -1;
    uint32 ComputeQueueFamily       = -1;
    uint32 TransferQueueFamily      = -1;
    uint32 SparseBindingQueueFamily = -1;
    uint32 ProtectedQueueFamily     = -1;
    uint32 VideoDecodeQueueFamily   = -1;

    uint32 PresentQueueFamily       = -1;

};


//================================                 =======================================



QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice PhysicalDevice, VkSurfaceKHR Surface);

/**
 * @param PhysicalDevice
 * @return If the device can be used
 */
bool IsDeviceSuitable(VkPhysicalDevice PhysicalDevice);


/**
 * @param PhysicalDevice
 * @return The suitability score of the device
 * @brief Gives the device a score based on how well suited it is for running the program
 */
uint32 GetDeviceScore(VkPhysicalDevice PhysicalDevice);

/**
 * @param PhysicalDevices
 * @return Returns the most suitable device available on the machine
 */
VkPhysicalDevice PickMostSuitableDevice(std::vector<VkPhysicalDevice> PhysicalDevices);










#endif //SIMULACRAENGINE_SIMENGINEVULKAN_H
