//
// Created by avsom on 10/23/2023.
//

#pragma once



#include "SimulacraVulkan.h"

class SVulkanViewport;


class SVulkanSwapchain;

class SVulkanDevice;

class SVulkanRHI {

    void Shutdown();

public:
    SVulkanRHI();

    void Init();

protected:

    VkInstance                Instance;
    std::vector<const char *> InstanceExtensions;
    std::vector<const char*>  InstanceLayers;


    void CreateInstance();
    void CreateDevice();
    void CreateSwapchain();
    void CreateViewport();
    void CreatePipeline();

    VkPhysicalDevice SelectPhysicalDevice(VkInstance InInstance);

private:

    SVulkanDevice* Device;
    SVulkanSwapchain* Swapchain;
    SVulkanViewport* Viewport;
};



