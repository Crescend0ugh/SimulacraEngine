//
// Created by avsom on 10/15/2023.
//

#include "SimEngineVulkan.h"


bool IsDeviceSuitable(VkPhysicalDevice PhysicalDevice)
{
    return true;
};

uint32 FindQueueFamilies(VkPhysicalDevice Device)
{
    return 0;
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

uint32 GetDeviceScore(VkPhysicalDevice PhysicalDevice)
{
    VkPhysicalDeviceProperties PhysicalDeviceProperties;
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








