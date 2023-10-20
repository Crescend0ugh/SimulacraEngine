//
// Created by avsom on 10/15/2023.
//

#include "SimEngineVulkan.h"





QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice PhysicalDevice, VkSurfaceKHR Surface)
{
    QueueFamilyIndices Indices;

    uint32 QueueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(PhysicalDevice, &QueueFamilyCount, nullptr );

    std::vector<VkQueueFamilyProperties> QueueFamilies(QueueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(PhysicalDevice, &QueueFamilyCount, QueueFamilies.data() );

    std::cout << "\nQueue Families available on device: \n\n";

    uint32 CurrentIndex = 0;
    for(const auto& QueueFamily : QueueFamilies )
    {
        std::cout << QueueFamilyToString(QueueFamily);


        if (QueueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
        {
            Indices.GraphicsQueueFamily = CurrentIndex ;
            VkBool32 HasSurfaceSupport;
            vkGetPhysicalDeviceSurfaceSupportKHR(PhysicalDevice, CurrentIndex, Surface, &HasSurfaceSupport);
            if(HasSurfaceSupport)
            {
                Indices.PresentQueueFamily = CurrentIndex;
            }
        }

        if (QueueFamily.queueFlags & VK_QUEUE_COMPUTE_BIT)
        { Indices.ComputeQueueFamily = CurrentIndex ; }
        if (QueueFamily.queueFlags & VK_QUEUE_TRANSFER_BIT)
        { Indices.TransferQueueFamily = CurrentIndex ; }
        if (QueueFamily.queueFlags & VK_QUEUE_SPARSE_BINDING_BIT)
        { Indices.SparseBindingQueueFamily = CurrentIndex ; }
        if (QueueFamily.queueFlags & VK_QUEUE_PROTECTED_BIT)
        { Indices.ProtectedQueueFamily = CurrentIndex ; }
        if (QueueFamily.queueFlags & VK_QUEUE_VIDEO_DECODE_BIT_KHR)
        { Indices.VideoDecodeQueueFamily = CurrentIndex ; }

        CurrentIndex++;
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









