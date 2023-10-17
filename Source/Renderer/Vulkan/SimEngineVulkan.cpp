//
// Created by avsom on 10/15/2023.
//

#include "SimEngineVulkan.h"



const char* PhysicalDeviceTypeToString(VkPhysicalDeviceType DeviceType)
{
    switch (DeviceType)
    {
        case VK_PHYSICAL_DEVICE_TYPE_OTHER :
            { return "Other"; }
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU :
            { return "Integrated GPU"; }
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
            { return "Discrete GPU"; }
        case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
            { return "Virtual GPU"; }
        case VK_PHYSICAL_DEVICE_TYPE_CPU :
            { return "CPU"; }
        case VK_PHYSICAL_DEVICE_TYPE_MAX_ENUM:
            { return nullptr; }
    }
    return nullptr;
}


QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice PhysicalDevice)
{
    QueueFamilyIndices Indices;

    uint32 QueueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(PhysicalDevice, &QueueFamilyCount, nullptr );

    std::vector<VkQueueFamilyProperties> QueueFamilyProperties(QueueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(PhysicalDevice, &QueueFamilyCount, QueueFamilyProperties.data() );

    int Index = 0;
    for(const auto& QueueFamily : QueueFamilyProperties )
    {
        switch (QueueFamily.queueFlags)
        {
            case VK_QUEUE_GRAPHICS_BIT:
            { Indices.GraphicsQueueFamily = Index; }

            case VK_QUEUE_COMPUTE_BIT:
            { Indices.ComputeQueueFamily = Index; }

            case VK_QUEUE_TRANSFER_BIT:
            { Indices.TransferQueueFamily = Index; }

            case VK_QUEUE_SPARSE_BINDING_BIT:
            { Indices.SparseBindingQueueFamily = Index; }

            case VK_QUEUE_PROTECTED_BIT:
            { Indices.ProtectedQueueFamily = Index; }

            case VK_QUEUE_VIDEO_DECODE_BIT_KHR:
            { Indices.VideoDecodeQueueFamily = Index; }
        }
    }


    return Indices;
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









