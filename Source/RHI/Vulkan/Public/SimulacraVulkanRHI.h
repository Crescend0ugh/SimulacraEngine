//
// Created by avsom on 10/23/2023.
//

#pragma once


#include "SimulacraVulkan.h"

class SVulkanRHI
{



public:
    SVulkanRHI();

    void Init();

    void Shutdown();


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





    VkPhysicalDevice SelectPhysicalDevice(VkInstance InInstance);

private:

    SVulkanInstance    *Instance;
    SVulkanDevice      *Device;
    SVulkanSwapchain   *Swapchain;
    SVulkanPipeline    *Pipeline;
    SVulkanCommandPool *CommandPool;
    SVulkanCommandBuffer* ActiveCommandBuffer;

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
