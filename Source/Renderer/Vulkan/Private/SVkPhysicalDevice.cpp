//
// Created by avsom on 10/18/2023.
//


#include "../Public/SVkPhysicalDevice.h"



bool IsDeviceSuitable(VkPhysicalDevice PhysicalDevice, VkSurfaceKHR Surface)
{
    QueueFamilyIndices Indices = FindQueueFamilies(PhysicalDevice, Surface);

    bool ExtensionsSupported = CheckDeviceExtensionSupport(PhysicalDevice);




    return true;
}

bool CheckDeviceExtensionSupport(VkPhysicalDevice PhysicalDevice)
{
    return true;

}

uint32 GetDeviceScore(VkPhysicalDevice PhysicalDevice)
{
    VkPhysicalDeviceProperties PhysicalDeviceProperties;
    vkGetPhysicalDeviceProperties(PhysicalDevice, &PhysicalDeviceProperties);
    uint32 Score = 0;


    if (!IsDeviceSuitable(PhysicalDevice, nullptr))
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

