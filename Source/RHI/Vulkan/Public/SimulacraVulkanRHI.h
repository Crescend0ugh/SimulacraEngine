//
// Created by avsom on 10/23/2023.
//

#pragma once


#include "SimulacraVulkan.h"

class SVulkanRHI
{

    void Shutdown();

public:
    SVulkanRHI();

    void Init();

protected:

    void QuerySupportedExtensions();


    SVulkanInstanceExtensions InstanceExtensions;
    SVulkanInstanceLayers     InstanceLayers;


    // Creates the VkInstance
    void CreateInstance();

    // Creates a VkDevice and VkPhysicalDevice
    void CreateDevice();

    // Creates the swap chain
    void CreateSwapchain();

    // Creates the viewport
    void CreateViewport();

    //Creates the graphics pipeline
    void CreatePipeline();


    VkPhysicalDevice SelectPhysicalDevice(VkInstance InInstance);

private:

    SVulkanInstance  *Instance;
    SVulkanDevice    *Device;
    SVulkanSwapchain *Swapchain;
    SVulkanViewport  *Viewport;
    SVulkanPipeline  *Pipeline;
};



