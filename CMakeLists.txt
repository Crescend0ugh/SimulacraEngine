cmake_minimum_required(VERSION 3.25)
project(SimulacraEngine)

set(CMAKE_CXX_STANDARD 17)


find_package(Vulkan REQUIRED)

add_executable(SimulacraEngine Source/Core/Launch/Win_Main.cpp
        Source/Core/Templates/SimulacraIsPointer.h
        Source/Renderer/Vulkan/Temp/SVulkanRHI.cpp
        Source/Renderer/Vulkan/Temp/SVulkanRHI.h
        Source/Core/Containers/ArrayList.h Source/Renderer/Vulkan/Temp/SimulacraVulkanDevice.cpp Source/Renderer/Vulkan/Temp/SimulacraVulkanQueue.cpp
        Source/Renderer/Vulkan/Temp/SimulacraVulkanSwapchain.cpp
        Source/Renderer/Vulkan/Temp/SimulacraVulkanSurface.cpp)




if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-D_DEBUG=1)
endif ()
if (CMAKE_BUILD_TYPE MATCHES Release)
    add_definitions(-D_NDEBUG=1)
endif ()

target_link_libraries(SimulacraEngine
        Vulkan::Vulkan)

