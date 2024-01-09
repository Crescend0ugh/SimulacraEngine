//
// Created by avsom on 10/23/2023.
//

#pragma once



#include "SimulacraVulkan.h"

class SVulkanRHI {

    void Shutdown();

public:
    SVulkanRHI();

    void Init();

protected:

    void QuerySupportedExtensions();


    SVulkanInstanceExtensions InstanceExtensions;
    SVulkanInstanceLayers     InstanceLayers;


    void CreateInstance();
    void CreateDevice();
    void CreateSwapchain();
    void CreateViewport();
    void CreatePipeline();


    VkPhysicalDevice SelectPhysicalDevice(VkInstance InInstance);

private:

    SVulkanInstance* Instance;
    SVulkanDevice* Device;
    SVulkanSwapchain* Swapchain;
    SVulkanViewport* Viewport;
    SVulkanPipeline* Pipeline;
};



