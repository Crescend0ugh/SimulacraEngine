//
// Created by avsom on 10/11/2023.
//


#include <vector>
#include "Vk_Renderer.h"
#include <windows.h>
#include <vulkan/vulkan_win32.h>
#include <iostream>
#include <set>
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
    std::vector<const char*> EnabledExtensions;
    EnabledExtensions.push_back(VK_KHR_SURFACE_EXTENSION_NAME);
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
    QueueFamilyIndices Indices = FindQueueFamilies(PhysicalDevice, Surface);

    std::set<uint32> UniqueQueueFamilyIndices = {Indices.GraphicsQueueFamily, Indices.PresentQueueFamily };
    std::vector<VkDeviceQueueCreateInfo> QueueCreateInfos;
    std::cout << "Graphics Index: "       + std::to_string(Indices.GraphicsQueueFamily) << "\n";
    std::cout << "Present Index: "        + std::to_string(Indices.PresentQueueFamily) << "\n";
    std::cout << "Compute Index: "        + std::to_string(Indices.ComputeQueueFamily) << "\n";
    std::cout << "Transfer Index: "       + std::to_string(Indices.TransferQueueFamily) << "\n";
    std::cout << "Sparse Binding Index: " + std::to_string(Indices.SparseBindingQueueFamily) << "\n";
    std::cout << "Video Decode Index: "   + std::to_string(Indices.VideoDecodeQueueFamily) << "\n";

    float QueuePriority = 1.0f;

    for (uint32 QueueFamily : UniqueQueueFamilyIndices) {
        VkDeviceQueueCreateInfo QueueCreateInfo{};
        QueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        QueueCreateInfo.queueFamilyIndex = QueueFamily ;
        QueueCreateInfo.queueCount = 1;
        QueueCreateInfo.pQueuePriorities = &QueuePriority;
        QueueCreateInfos.push_back(QueueCreateInfo);
    }

    VkPhysicalDeviceFeatures DeviceFeatures{};


    VkDeviceCreateInfo CreateInfo {};
    CreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    CreateInfo.queueCreateInfoCount = QueueCreateInfos.size();
    CreateInfo.pQueueCreateInfos = QueueCreateInfos.data();
    CreateInfo.pEnabledFeatures = &DeviceFeatures;
    CreateInfo.enabledExtensionCount = 0;

    VkResult Result = vkCreateDevice(PhysicalDevice, &CreateInfo, nullptr, &Device);

    if(Result != VK_SUCCESS)
    {
        std::cout << "\nFailed to create device\n\n";
    }

    std::cout << "\nSuccessfully created device\n\n";

    vkGetDeviceQueue(Device, Indices.GraphicsQueueFamily, 0, &GraphicsQueue);
    vkGetDeviceQueue(Device, Indices.PresentQueueFamily, 0, &PresentQueue);

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

void Vk_Renderer::CreateSwapChain()
{
    VkSwapchainCreateInfoKHR CreateInfo {};
    CreateInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    CreateInfo.pNext = nullptr;

}

