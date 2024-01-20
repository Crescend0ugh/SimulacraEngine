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

    //Creates the graphics pipeline
    void CreatePipeline();

    //Creates the command pool
    void CreateCommandPool();

    void DrawFrame();


    VkPhysicalDevice SelectPhysicalDevice(VkInstance InInstance);

private:

    SVulkanInstance    *Instance;
    SVulkanDevice      *Device;
    SVulkanSwapchain   *Swapchain;
    SVulkanPipeline    *Pipeline;
    SVulkanCommandPool *CommandPool;

};

struct SVulkanSemaphore
{
public:
    SVulkanSemaphore(SVulkanDevice* InDevice);
    ~SVulkanSemaphore();

    VkSemaphore GetHandle() { return Semaphore; }

private:
    VkSemaphore Semaphore;
    SVulkanDevice* Device;
};

struct SVulkanFence
{

public:
    SVulkanFence(SVulkanDevice* InDevice);
    ~SVulkanFence();

    VkFence GetHandle() { return Fence; }
private:

    VkFence Fence;
    SVulkanDevice* Device;


};
