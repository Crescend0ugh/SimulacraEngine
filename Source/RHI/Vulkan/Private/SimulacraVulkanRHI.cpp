//
// Created by avsom on 10/23/2023.
//


#include "../Public/SimulacraVulkan.h"
#include "../../../../Source/Core/SimulacraGameViewport.h"


void SVulkanRHI::CreateInstance() {

  Instance = new SVulkanInstance();
  }

VkPhysicalDevice SVulkanRHI::SelectPhysicalDevice(VkInstance InInstance)
{
    VkResult Result;
    uint32 PhysicalDeviceCount = 0;
    Result = vkEnumeratePhysicalDevices(InInstance, &PhysicalDeviceCount, nullptr );
    if(Result != VK_SUCCESS)
    {
        std::cout << "Could not find a compatible Vulkan device or driver\n";
    }

    else
    {
        std::cout << "======= Found " << PhysicalDeviceCount << " Vulkan Devices. =======\n\n";
    }
    std::vector<VkPhysicalDevice> PhysicalDevices(PhysicalDeviceCount);
    vkEnumeratePhysicalDevices(InInstance, &PhysicalDeviceCount, PhysicalDevices.data());
    return PhysicalDevices[0];

}

//TODO move physical device creation to the SVulkanDevice class
void SVulkanRHI::CreateDevice()
{

    VkPhysicalDevice PhysicalDevice = SelectPhysicalDevice(Instance->GetHandle());

    Device = new SVulkanDevice(this, PhysicalDevice);

    Device->CreatePhysicalDevice();
    Device->CreateLogicalDevice();
    

}

void SVulkanRHI::CreateSwapchain()
{
    Swapchain = new SVulkanSwapchain(Instance->GetHandle(), Device, SGameViewport::GetWindow()->GetHandle());

}


void SVulkanRHI::CreateViewport()
{
    Viewport = new SVulkanViewport(Device, Swapchain);
}


SVulkanRHI::SVulkanRHI(): Instance(VK_NULL_HANDLE),
                          Device(nullptr)
{

}

void SVulkanRHI::Init() {

    CreateInstance();
    CreateDevice();
    CreateSwapchain();
    CreateViewport();
    CreatePipeline();
    

}

void SVulkanRHI::Shutdown() {

}

void SVulkanRHI::CreatePipeline()
{
    Pipeline = new SVulkanPipeline(Device);
}


