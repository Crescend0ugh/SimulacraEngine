//
// Created by avsom on 10/23/2023.
//


#include "../Public/SimulacraVulkan.h"
#include "../Public/SimulacraVulkanRHI.h"
#include "../Platforms/Windows/SimulacraVulkanWindowsPlatform.h"
#include "../Public/SimulacraVulkanSwapchain.h"
#include "../../../../Source/Core/SimulacraGameViewport.h"
#include <windows.h>


void SVulkanRHI::CreateInstance() {

    VkApplicationInfo ApplicationInfo;
    SetZeroVulkanStruct(ApplicationInfo, VK_STRUCTURE_TYPE_APPLICATION_INFO);
    ApplicationInfo.pApplicationName = "Vulkan Application";
    ApplicationInfo.applicationVersion = VK_MAKE_VERSION(0,1,0);
    ApplicationInfo.pEngineName = "Simulacra Engine";
    ApplicationInfo.engineVersion = VK_MAKE_VERSION(0,1,0);
    ApplicationInfo.apiVersion = VK_API_VERSION_1_3;

    SVulkanPlatform::GetPlatformExtensions(InstanceExtensions);

    VkInstanceCreateInfo InstanceCreateInfo;
    SetZeroVulkanStruct(InstanceCreateInfo, VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO);
    InstanceCreateInfo.enabledExtensionCount = InstanceExtensions.size();
    InstanceCreateInfo.enabledLayerCount = 0;
    InstanceCreateInfo.ppEnabledExtensionNames = InstanceExtensions.data();
    InstanceCreateInfo.ppEnabledLayerNames = nullptr;

    VkResult Result =  vkCreateInstance(&InstanceCreateInfo, nullptr, &Instance);

    if(Result != VK_SUCCESS)
    {
        std::cout << "Couldn't create Vulkan Instance.\n";
    }

    else
    {
        std::cout << "======= Created Vulkan Instance! =======\n\n";
    }


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

void SVulkanRHI::CreateDevice()
{

    VkPhysicalDevice PhysicalDevice = SelectPhysicalDevice(Instance);

    Device = new SVulkanDevice(this, PhysicalDevice);

    Device->CreatePhysicalDevice();
    Device->CreateDevice();
    

}

void SVulkanRHI::CreateSwapchain()
{
    Swapchain = new SVulkanSwapchain(Instance, Device, SGameViewport::GetWindow()->GetHandle());

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


}

void SVulkanRHI::Shutdown() {

}


void SVulkanRHI::CreateViewport()
{

}

