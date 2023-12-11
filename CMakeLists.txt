cmake_minimum_required(VERSION 3.25)
project(SimulacraEngine)

set(CMAKE_CXX_STANDARD 17)


find_package(Vulkan REQUIRED)

add_executable(SimulacraEngine Source/Core/Launch/Win_Main.cpp
        Source/Core/Templates/SimulacraIsPointer.h
        Source/Renderer/Vulkan/Private/SVulkanRHI.cpp
        Source/Renderer/Vulkan/Public/SVulkanRHI.h
        Source/Core/Containers/ArrayList.h Source/Renderer/Vulkan/Private/SimulacraVulkanDevice.cpp Source/Renderer/Vulkan/Private/SimulacraVulkanQueue.cpp
        Source/Renderer/Vulkan/Private/SimulacraVulkanSwapchain.cpp
        Source/Renderer/Vulkan/Private/SimulacraVulkanSurface.cpp Source/Renderer/Vulkan/Private/SimulacraVulkanPlatform.cpp Source/Renderer/Vulkan/Public/SimulacraVulkanPlatform.h Source/Renderer/Vulkan/Platforms/Windows/SimulacraVulkanWindows.cpp Source/Renderer/Vulkan/Platforms/Windows/SimulacraVulkanWindows.h)




if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-D_DEBUG=1)
endif ()
if (CMAKE_BUILD_TYPE MATCHES Release)
    add_definitions(-D_NDEBUG=1)
endif ()

target_link_libraries(SimulacraEngine
        Vulkan::Vulkan)

