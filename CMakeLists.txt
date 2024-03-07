cmake_minimum_required(VERSION 3.25)
project(SimulacraEngine)

set(CMAKE_CXX_STANDARD 17)



find_package(Vulkan REQUIRED)


add_executable(SimulacraEngine WIN32 Source/Core/Launcher/Win_Main.cpp Source/RHI/Vulkan/Private/SimulacraVulkanDevice.cpp Source/RHI/Vulkan/Private/SimulacraVulkanExtensions.cpp Source/RHI/Vulkan/Private/SimulacraVulkanPipeline.cpp Source/RHI/Vulkan/Private/SimulacraVulkanPlatform.cpp Source/RHI/Vulkan/Private/SimulacraVulkanQueue.cpp Source/RHI/Vulkan/Private/SimulacraVulkanResource.cpp Source/RHI/Vulkan/Private/SimulacraVulkanRHI.cpp Source/RHI/Vulkan/Private/SimulacraVulkanShader.cpp Source/RHI/Vulkan/Private/SimulacraVulkanSwapchain.cpp Source/RHI/Vulkan/Platforms/Windows/SimulacraVulkanWindowsPlatform.cpp Source/RHI/Vulkan/Platforms/Linux/SimulacraVulkanLinuxPlatform.cpp Source/Application/Windows/SimulacraWindowsWindow.cpp Source/Application/Windows/SimulacraWindowsApplication.cpp Source/Application/SimulacraApplication.cpp Source/Application/SimulacraWindow.cpp Source/Core/SimulacraGameViewport.cpp Source/RHI/Vulkan/Private/SimulacraVulkanInstance.cpp Source/RHI/Vulkan/Public/SimulacraVulkanInstance.h
        Source/Core/Containers/SimulacraContainerAllocators.h
        Source/Core/Containers/SimulacraArray.h
        Source/RHI/Vulkan/Public/SimulacraVulkanCommandBuffer.h
        Source/RHI/Vulkan/Private/SimulacraVulkanCommandBuffer.cpp
        Source/RHI/Vulkan/Private/SimulacraVulkanDebugUtils.cpp
        Source/RHI/Vulkan/Private/SimulacraVulkanCommands.cpp
        Source/RHI/Vulkan/Public/SimulacraVulkanCommands.h
        Source/Core/Logging/SimulacraInternalLogging.cpp
        Source/Core/Logging/SimulacraInternalLogging.h
        Source/Core/Logging/SimulacraLogging.cpp
        Source/Core/Logging/SimulacraLogging.h
        Source/Core/Logging/SimulacraLogSeverity.h
        Source/Core/Globals.h
        Source/Core/Globals.h
        Source/Misc/SimulacraDirectedAcyclic.cpp
)
if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-D_DEBUG=1)
endif ()
if (CMAKE_BUILD_TYPE MATCHES Release)
    add_definitions(-D_NDEBUG=1)
endif ()

target_link_libraries(SimulacraEngine
        Vulkan::Vulkan)

