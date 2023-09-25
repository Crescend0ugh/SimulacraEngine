//
// Created by avsom on 9/13/2023.
//


#include <windows.h>
#include "../win32/WindowsApplication.h"
#include <vulkan/vulkan.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "RenderBackend.h"
#include "../EngineDefines.h"
#include "../EngineTypes.h"


bool CreateGameWindow()
{

}

static bool VK_Init(){


    CreateGameWindow();
}

 void RenderBackend::Init()
{

    std::printf("------ RenderBackend::Init() ------\n");

    if( !VK_Init() )
    {
        std::printf("Unable to initialize Vulkan");
        std::terminate();
    }
//
//    CreateInstance();
//
//    CreateSurface();
//
//    EnumeratePhysicalDevices();
//
//    SelectPhysicalDevices();
//
//    CreateLogicalDeviceAndQueues();
//
//    CreateSemaphores();
//
//    CreatrCommandPool();
//
//    CreateCommandBuffer();
//
//    CreateSwapChain();
//
//    CreateRenderPass();
//
//    CreatePipelineCache();
//
//    CreateFrameBuffers();


}

bool RenderBackend::SetScreenParams()
{

}

bool RenderBackend::CreateWindowClasses()
{
    WNDCLASS wc;
    wc.lpfnWndProc = MainWindowProcedure;
    wc.hInstance = win32.hInstance;
}

bool RenderBackend::CreateGameWindow()
{

}

//void RenderBackend::CreateInstance()
//{
//    VkApplicationInfo ApplicationInfo = {};
//    ApplicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
//    ApplicationInfo.pApplicationName = nullptr;
//    ApplicationInfo.applicationVersion = VK_MAKE_VERSION(0, 1, 0);
//    ApplicationInfo.pEngineName = "Simulacra Engine";
//    ApplicationInfo.engineVersion = VK_MAKE_VERSION(0, 1, 0);
//    ApplicationInfo.apiVersion = VK_API_VERSION_1_0;
//
//    VkInstanceCreateInfo CreateInfo = {};
//    CreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
//    CreateInfo.pApplicationInfo = &ApplicationInfo;
//    uint32 GLFWExtensionCount = 0;
//    const char** GLFWExtensions;
//    GLFWExtensions = glfwGetRequiredInstanceExtensions(&GLFWExtensionCount);
//
//
//}
