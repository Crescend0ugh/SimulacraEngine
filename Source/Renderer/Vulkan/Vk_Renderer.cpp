//
// Created by avsom on 10/11/2023.
//


#include <vector>
#include "Vk_Renderer.h"
#include <windows.h>
#include <vulkan/vulkan_win32.h>
#include <iostream>
#include "../../Core/Sys/Precompiled.h"
#include "SimEngineVulkan.h"
#include "../../Core/Platforms/Windows/SimEngineWindows.h"

#define APPLICATION_NAME "TestApplicationName"
#define ENGINE_NAME "SimulacraEngine"



void Vk_Renderer::CreateInstance()
{
    VkApplicationInfo ApplicationInfo{};
    ApplicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    ApplicationInfo.pApplicationName = APPLICATION_NAME;
    ApplicationInfo.applicationVersion = VK_MAKE_VERSION(1,0,0);
    ApplicationInfo.pEngineName = ENGINE_NAME;
    ApplicationInfo.engineVersion = VK_MAKE_VERSION(1,0,0);
    ApplicationInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo CreateInfo{};
    CreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    CreateInfo.pApplicationInfo = &ApplicationInfo;
    std::vector<const char*> EnabledExtensions = { VK_KHR_SURFACE_EXTENSION_NAME };
    EnabledExtensions.push_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
    CreateInfo.enabledExtensionCount = EnabledExtensions.size();
    CreateInfo.ppEnabledExtensionNames = EnabledExtensions.data();

    VkResult Result = vkCreateInstance(&CreateInfo, NULL, &Instance);


    if(Result != VK_SUCCESS)
    {
        std::cout << "XXXXXXXXXXXXXXXX Failed to create Vulkan Instance XXXXXXXXXXXXXXXX\n";
        assert(Result == VK_SUCCESS);
    }

    else
    {
        std::cout << "==================== Successfully created Vulkan Instance ====================\n\n";
    }

}

void Vk_Renderer::CreatePhysicalDevice()
{

    uint32 DeviceCount = 0;
    VkResult Result = vkEnumeratePhysicalDevices(Instance, &DeviceCount, nullptr);


    if(Result != VK_SUCCESS)
    {
        std::cout << "Failed to find Physical Device\n";
        assert(Result == VK_SUCCESS);
    }

    std::cout << "Successfully found " << DeviceCount << " Physical Device(s):\n";

    std::vector<VkPhysicalDevice> PhysicalDevices(DeviceCount);
    Result = vkEnumeratePhysicalDevices(Instance, &DeviceCount, PhysicalDevices.data());

    for(auto& i : PhysicalDevices)
    {

        VkPhysicalDeviceProperties Properties{};
        vkGetPhysicalDeviceProperties(i, &Properties);

        std::cout << "-------------------------------------------------\n";

        std::cout << "Device Name: " << Properties.deviceName << "\n";
        std::cout << "Device Type: " << PhysicalDeviceTypeToString(Properties.deviceType) << "\n";



    }

    std::cout << "-------------------------------------------------\n\n";


    std::cout << "Selected Device: \n";
    PhysicalDevice = PickMostSuitableDevice(PhysicalDevices);

    VkPhysicalDeviceProperties PhysicalDeviceProperties{};
    vkGetPhysicalDeviceProperties(PhysicalDevice, &PhysicalDeviceProperties);

    std::cout << "-------------------------------------------------\n";
    std::cout << "Device Name: " << PhysicalDeviceProperties.deviceName << "\n";
    std::cout << "Device Type: " << PhysicalDeviceTypeToString(PhysicalDeviceProperties.deviceType) << "\n";
    std::cout << "-------------------------------------------------\n";



}

void Vk_Renderer::CreateSurface()
{


    VkWin32SurfaceCreateInfoKHR CreateInfo {};
    CreateInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
    CreateInfo.hwnd = Win32Vars.Hwnd;
    CreateInfo.hinstance = Win32Vars.HInstance;

    VkResult Result = vkCreateWin32SurfaceKHR(Instance, &CreateInfo, nullptr, &Surface);

    if(Result != VK_SUCCESS)
    {
        std::cout << "Failed to create Surface\n";
    }

    std::cout << "Successfully created Win32 Surface\n\n";
}


void Vk_Renderer::CreateLogicalDevice()
{
    QueueFamilyIndices Indices = FindQueueFamilies(PhysicalDevice);


    VkDeviceQueueCreateInfo QueueCreateInfo{};
    QueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    QueueCreateInfo.queueFamilyIndex = Indices.GraphicsQueueFamily;
    QueueCreateInfo.queueCount = 1;

    float QueuePriority = 1.0f;
    QueueCreateInfo.pQueuePriorities = &QueuePriority;

    VkPhysicalDeviceFeatures DeviceFeatures{};

    VkDeviceCreateInfo CreateInfo {};
    CreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    CreateInfo.pQueueCreateInfos = &QueueCreateInfo;
    CreateInfo.queueCreateInfoCount = 1;
    CreateInfo.pEnabledFeatures = &DeviceFeatures;


    vkCreateDevice(PhysicalDevice, &CreateInfo, nullptr, &Device);


}

bool Vk_Renderer::Initialize()
{
    CreateInstance();
    CreateSurface();
    CreatePhysicalDevice();
    CreateLogicalDevice();
    return true;
}

bool Vk_Renderer::Deintialize()
{


    vkDestroyDevice(Device, nullptr);
    vkDestroySurfaceKHR(Instance, Surface, nullptr);
    vkDestroyInstance(Instance, nullptr);

    return false;
}

