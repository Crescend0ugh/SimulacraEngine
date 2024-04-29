cmake_minimum_required(VERSION 3.25)
project(SimulacraEngine)

set(CMAKE_CXX_STANDARD 17)



find_package(Vulkan REQUIRED)


add_executable(SimulacraEngine Source/Core/Launcher/Win_Main.cpp Source/RendererBackend/Vulkan/Private/SimulacraVulkanDevice.cpp Source/RendererBackend/Vulkan/Private/SimulacraVulkanExtensions.cpp Source/RendererBackend/Vulkan/Private/SimulacraVulkanPipeline.cpp Source/RendererBackend/Vulkan/Private/SimulacraVulkanQueue.cpp  Source/RendererBackend/Vulkan/Private/SimulacraVulkanRHI.cpp Source/RendererBackend/Vulkan/Private/SimulacraVulkanSwapchain.cpp Source/RendererBackend/Vulkan/Platforms/Windows/SimulacraVulkanWindowsPlatform.cpp Source/RendererBackend/Vulkan/Platforms/Linux/SimulacraVulkanLinuxPlatform.cpp Source/Application/Windows/SimulacraWindowsWindow.cpp Source/Application/Windows/SimulacraWindowsApplication.cpp Source/Application/SimulacraApplication.cpp Source/Application/SimulacraWindow.cpp Source/Core/SimulacraGameViewport.cpp Source/RendererBackend/Vulkan/Private/SimulacraVulkanInstance.cpp Source/RendererBackend/Vulkan/Public/SimulacraVulkanInstance.h Source/RendererBackend/Vulkan/Public/SimulacraVulkanDevice.h
)
if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-D_DEBUG=1)
endif ()
if (CMAKE_BUILD_TYPE MATCHES Release)
    add_definitions(-D_NDEBUG=1)
endif ()

target_link_libraries(SimulacraEngine
        Vulkan::Vulkan)

