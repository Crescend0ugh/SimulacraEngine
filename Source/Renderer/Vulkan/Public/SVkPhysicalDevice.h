//
// Created by avsom on 10/18/2023.
//

#ifndef SIMULACRAENGINE_SVKPHYSICALDEVICE_H
#define SIMULACRAENGINE_SVKPHYSICALDEVICE_H
#include "SimEngineVulkan.h"

struct VulkanDevice
{


    VkPhysicalDevice PhysicalDevice;
    VkDevice         Device;

    VkQueue              PresentQueue;
    VkQueue              GraphicsQueue;
    VkQueue              VideoQueue;
    SimArray<VkQueue, 3> ComputeQueues;
    SimArray<VkQueue, 3> TransferQueue;

    VkPhysicalDeviceProperties           DeviceProperties;
    VkPhysicalDeviceFeatures             DeviceFeatures;
    std::vector<VkQueueFamilyProperties> QueueProperties;

public:

    VulkanDevice(VkInstance Instance, uint32 PhysicalDeviceIndex);
    ~VulkanDevice();

    void CreatePhysicalDevice( uint32 DeviceIndex );
    void CreateLogicalDevice();

    void CreateQueues();


};


bool IsDeviceSuitable(VkPhysicalDevice PhysicalDevice, VkSurfaceKHR Surface);

bool CheckDeviceExtensionSupport(VkPhysicalDevice PhysicalDevice);

uint32 GetDeviceScore(VkPhysicalDevice PhysicalDevice);

VkPhysicalDevice PickMostSuitableDevice(std::vector<VkPhysicalDevice> PhysicalDevices);

VkPhysicalDevice PickSuitableDevice(std::vector<VkPhysicalDevice> PhysicalDevices);

#endif //SIMULACRAENGINE_SVKPHYSICALDEVICE_H
