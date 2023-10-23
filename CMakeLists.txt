cmake_minimum_required(VERSION 3.25)
project(SimulacraEngine)

set(CMAKE_CXX_STANDARD 17)


find_package(Vulkan REQUIRED)

add_executable(SimulacraEngine Source/Core/Launch/Win_Main.cpp Source/Renderer/Renderer.cpp Source/Renderer/Vulkan/Private/Vk_Renderer.cpp Source/Renderer/Vulkan/Private/SVkPhysicalDevice.cpp Source/Renderer/Vulkan/Private/SimEngineVulkanDebug.cpp Source/Renderer/Vulkan/Private/SVkQueue.cpp Source/Renderer/Vulkan/Private/SVkSwapChain.cpp Source/Core/Platforms/Windows/WindowsProcedure.cpp Source/Core/Platforms/SimulacraPlatforms.h Source/Renderer/Vulkan/Private/SimulacraVulkanSurface.cpp Source/Renderer/Vulkan/Public/SimulacraVulkanSurface.h Source/Renderer/Vulkan/Private/SimulacraVulkanDevice.cpp Source/Renderer/Vulkan/Public/SimulacraVulkanDevice.h)




if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-D_DEBUG=1)
endif ()
if (CMAKE_BUILD_TYPE MATCHES Release)
    add_definitions(-D_NDEBUG=1)
endif ()

target_link_libraries(SimulacraEngine
        Vulkan::Vulkan)

