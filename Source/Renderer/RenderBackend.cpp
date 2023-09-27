//
// Created by avsom on 9/13/2023.
//


#include <windows.h>
#include "../win32/WindowsApplication.h"
#include <vulkan/vulkan.h>
#include <iostream>
#include "../win32/win32Defines.h"
#include "RenderBackend.h"

#include "../Core/Sys/SimEngineDefines.h"
#include "../Core/Sys/SimEngineTypes.h"


static bool VK_Init(){


    return true;
}



 void RenderBackend::Init()
{

    std::printf("------ RenderBackend::Init() ------\n");

    if( !VK_Init() )
    {
        std::printf("Unable to initialize Vulkan");
        std::terminate();
    }
    CreateWindowClasses();
    CreateGameWindow();
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



bool RenderBackend::CreateWindowClasses()
{

    WNDCLASS wc;
    wc.lpfnWndProc = MainWindowProcedure;
    wc.hInstance = win32.hInstance;
    wc.lpszClassName = WIN32_WINDOW_CLASS_NAME;

    if( RegisterClass(&wc))
    {
        return true;
    }

    else
    {
        std::cout << "Failed to register class!\n";
        return false;
    }
}

void RenderBackend::CreateGameWindow()
{
    win32.hWnd = CreateWindowEx(
            0,
            WIN32_WINDOW_CLASS_NAME,
            "Hello Window!",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
            nullptr,
            nullptr,
            win32.hInstance,
            nullptr
            );

  //  ShowWindow( Windows.hWnd, SW_SHOW );
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
