//
// Created by avsom on 10/11/2023.
//

#include <vulkan/vulkan.h>
#include <vector>
#include "Vk_Renderer.h"
#if defined(_WIN32)
#include <windows.h>
#include <vulkan/vulkan_win32.h>
#endif

#ifdef APPLICATION_NAME

#else
#define APPLICATION_NAME "TestApplicationName"

#endif

#ifdef ENGINE_NAME

#else
#define ENGINE_NAME "SimulacraEngine"

#endif


void Vk_Renderer::CreateInstance()
{
    VkApplicationInfo ApplicationInfo{};
    ApplicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    ApplicationInfo.pApplicationName = APPLICATION_NAME;
    ApplicationInfo.applicationVersion = VK_MAKE_VERSION(0,1,0);
    ApplicationInfo.pEngineName = ENGINE_NAME;
    ApplicationInfo.engineVersion = VK_MAKE_VERSION(0,1,0);
    ApplicationInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo CreateInfo{};
    CreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    CreateInfo.pApplicationInfo = &ApplicationInfo;
   // std::vector<const char*> EnabledExtensions = { VK_KHR_SURFACE_EXTENSION_NAME };
    #ifdef WIN32
    //EnabledExtensions.push_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
    #endif


}

void Vk_Renderer::CreateSurface()
{

}

void Vk_Renderer::CreatePhysicalDevice()
{

}

void Vk_Renderer::CreateLogicalDevice()
{

}

bool Vk_Renderer::Initialize()
{
    return false;
}

bool Vk_Renderer::Deintialize()
{
    return false;
}

