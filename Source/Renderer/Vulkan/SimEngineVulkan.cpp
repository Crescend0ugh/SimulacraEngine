//
// Created by avsom on 10/15/2023.
//

#include "SimEngineVulkan.h"

struct QueueFamilyIndices
{
    uint32 GraphicsQueue      = -1;
    uint32 ComputeQueue       = -1;
    uint32 TransferQueue      = -1;
    uint32 SparseBindingQueue = -1;
    uint32 ProtectedQueue     = -1;
    uint32 VideoDecodeQueue   = -1;
};


const char* PhysicalDeviceTypeToString(VkPhysicalDeviceType DeviceType)
{
    switch (DeviceType)
    {
        case VK_PHYSICAL_DEVICE_TYPE_OTHER :
            return "Other";
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU :
            return "Integrated GPU";
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
            return "Discrete GPU";
        case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
            return "Virtual GPU";
        case VK_PHYSICAL_DEVICE_TYPE_CPU :
            return "CPU";
        case VK_PHYSICAL_DEVICE_TYPE_MAX_ENUM:
            return nullptr;
    }
    return nullptr;
}

uint32 FindQueueFamilies(VkPhysicalDevice Device)
{



    return 0;
}

bool IsDeviceSuitable(VkPhysicalDevice PhysicalDevice)
{
    VkPhysicalDeviceProperties PhysicalDeviceProperties;
    vkGetPhysicalDeviceProperties(PhysicalDevice, &PhysicalDeviceProperties);

    VkPhysicalDeviceFeatures PhysicalDeviceFeatures;
    vkGetPhysicalDeviceFeatures(PhysicalDevice, &PhysicalDeviceFeatures);

    

    return true;
};

uint32 GetDeviceScore(VkPhysicalDevice PhysicalDevice)
{
    VkPhysicalDeviceProperties PhysicalDeviceProperties;
    vkGetPhysicalDeviceProperties(PhysicalDevice, &PhysicalDeviceProperties);
    uint32 Score = 0;


    if (!IsDeviceSuitable(PhysicalDevice))
    {
        return 0;

    }

    if(PhysicalDeviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
    {
        Score += 10;
    }

    return Score;


}

VkPhysicalDevice PickMostSuitableDevice(std::vector<VkPhysicalDevice> PhysicalDevices)
{

    uint32 DeviceCount = PhysicalDevices.size();
    uint32 MostSuitableDeviceIndex = 0;
    uint32 CurrentMostSuitableScore = 0;

    for(int i = 0; i < DeviceCount; i++)
    {
        uint32 Score = GetDeviceScore(PhysicalDevices[i]);
        if(Score>CurrentMostSuitableScore)
        {
            CurrentMostSuitableScore = Score;
            MostSuitableDeviceIndex = i;
        }
    }

    return PhysicalDevices[MostSuitableDeviceIndex];

}









