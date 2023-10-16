cmake_minimum_required(VERSION 3.25)
project(SimulacraEngine)

set(CMAKE_CXX_STANDARD 17)


find_package(Vulkan REQUIRED)

add_executable(SimulacraEngine Source/Core/Launch/WinMain.cpp Source/Core/Memory/Private/LinearAllocator.cpp Source/Core/Memory/AllocatorTests.cpp Source/Core/Memory/AllocatorTests.h Source/Core/Memory/Private/StackAllocator.cpp Source/Renderer/Vulkan/Vk_Renderer.h Source/Renderer/Vulkan/Vk_Renderer.cpp Source/Renderer/Renderer.cpp Source/Renderer/Renderer.h
        Source/Core/Platforms/Windows/WindowsProcedure.cpp Source/Core/Platforms/Windows/SimEngineWindows.h Source/Renderer/Vulkan/Vk_Renderer.cpp Source/Renderer/Vulkan/SimEngineVulkan.h Source/Renderer/Vulkan/SimEngineVulkan.cpp)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-D_DEBUG=1)
endif ()
if (CMAKE_BUILD_TYPE MATCHES Release)
    add_definitions(-D_NDEBUG=1)
endif ()

target_link_libraries(SimulacraEngine
        Vulkan::Vulkan)
