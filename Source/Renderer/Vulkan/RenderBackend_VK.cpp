//
// Created by avsom on 9/13/2023.
//

#include "RenderBackend_VK.h"

static void CreateInstance()
{
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Simulacra Engine";
    appInfo.applicationVersion = VK_MAKE_VERSION(0,1, 0);
    appInfo.pEngineName = "Simulacra Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(0,1,0);
    appInfo.apiVersion = VK_API_VERSION_1_0;


    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;


}

static void CreateSurface()
{
    VkWin32SurfaceCreateInfoKHR createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;

}

static void EnumeratePhysicalDevices() {
    uint32_t numDevices = 0;
    vkEnumeratePhysicalDevices()
}


