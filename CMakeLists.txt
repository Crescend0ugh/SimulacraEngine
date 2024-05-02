cmake_minimum_required(VERSION 3.25)
project(SimulacraEngine)

set(CMAKE_CXX_STANDARD 17)



find_package(Vulkan REQUIRED)


add_library(SimulacraLibrary Source/RendererBackend/Vulkan/Public/SimulacraVulkanDevice.cpp
        Source/RendererBackend/Vulkan/Public/SimulacraVulkanExtensions.cpp
        Source/RendererBackend/Vulkan/Public/SimulacraVulkanInstance.cpp
        Source/RendererBackend/Vulkan/Public/SimulacraVulkanPipeline.cpp
        Source/RendererBackend/Vulkan/Public/SimulacraVulkanPipeline.h
        Source/RendererBackend/Vulkan/Public/SimulacraVulkanQueue.cpp
        Source/RendererBackend/Vulkan/Public/SimulacraVulkanRHI.cpp
        Source/RendererBackend/Vulkan/Public/SimulacraVulkanSwapchain.cpp
        Source/RendererBackend/Vulkan/Public/SimulacraVulkanSwapchain.h
        Source/Core/Platform/SimulacraWindowsWindow.h
        Source/Core/Platform/SimulacraWindows.h
        Source/RendererBackend/Vulkan/Platforms/Windows/SimulacraVulkanWindowsPlatform.h
        Source/Core/Platform/SimulacraWindowsWindow.cpp
        Source/RendererBackend/Vulkan/Public/SimulacraVulkanSurface.h
        Source/RendererBackend/Vulkan/Public/SimulacraVulkanSurface.cpp
        Source/RendererBackend/Vulkan/Platforms/Windows/SimulacraVulkanWindowsPlatform.cpp
        Source/RendererBackend/Vulkan/Public/SimulacraVulkanWindow.cpp
        Source/RendererBackend/Vulkan/Public/SimulacraVulkanWindow.h

)

add_executable(SimulacraEngine WIN32 Source/Core/Launcher/Win_Main.cpp)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-D_DEBUG=1)
endif ()
if (CMAKE_BUILD_TYPE MATCHES Release)
    add_definitions(-D_NDEBUG=1)
endif ()

target_link_libraries(SimulacraLibrary
        Vulkan::Vulkan)

target_link_libraries(SimulacraEngine SimulacraLibrary)
