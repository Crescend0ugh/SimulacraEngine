//
// Created by avsom on 10/22/2023.
//

#include <vector>
#include <iostream>
#include "SVkQueues.h"
#include "SimEngineVulkanDebug.h"

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