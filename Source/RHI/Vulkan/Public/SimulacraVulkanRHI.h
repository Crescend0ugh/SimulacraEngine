//
// Created by avsom on 10/23/2023.
//

#pragma once



#include "SimulacraVulkanDevice.h"
#include "SimulacraVulkanSwapchain.h"

class SVulkanSwapchain;

class SVulkanDevice;

class SVulkanRHI {

    void Shutdown();

public:
    SVulkanRHI();

    void Init();

protected:

    VkInstance         Instance;
    std::vector<char*> InstanceExtensions;
    std::vector<char*> InstanceLayers;


    void CreateInstance();
    void InitInstance();
    void CreateDevice();
    void CreateSwapchain();
    void InitDevice();

    VkPhysicalDevice SelectPhysicalDevice(VkInstance InInstance);

private:
    SVulkanDevice* Device;
    SVulkanSwapchain* Swapchain;
};



