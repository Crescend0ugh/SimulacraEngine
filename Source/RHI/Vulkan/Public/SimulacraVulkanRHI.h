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

    void DrawFrame();


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

    void CreateVertexBuffer();

    void CreateIndexBuffer();

    //Creates the graphics pipeline
    void CreatePipeline();







    VkPhysicalDevice SelectPhysicalDevice(VkInstance InInstance);

private:

    SVulkanInstance    *Instance;
    SVulkanDevice      *Device;
    SVulkanSwapchain   *Swapchain;
    SVulkanPipeline    *Pipeline;


};

struct SVulkanSemaphore
{
public:
    explicit SVulkanSemaphore(SVulkanDevice* InDevice);
    ~SVulkanSemaphore();

    VkSemaphore& GetHandle() { return Semaphore; }

private:
    VkSemaphore Semaphore;
    SVulkanDevice* Device;
};

struct SVulkanFence
{

public:
    SVulkanFence(SVulkanDevice *InDevice, VkFenceCreateFlags InFenceCreateFlags);
    ~SVulkanFence();

    VkFence& GetHandle() { return Fence; }
private:

    VkFence Fence;
    SVulkanDevice* Device;


};
