cmake_minimum_required(VERSION 3.25)
project(SimulacraEngine)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Vulkan REQUIRED)


add_library(SimulacraLibrary
        Source/Renderer/Backend/Vulkan/Private/VulkanRHI.cpp)
add_subdirectory(Source/Renderer/Backend/Vulkan)
add_subdirectory(Source/Renderer/Backend/DirectX)

add_subdirectory(Source/Core/Platform)
add_subdirectory(Source/Core)

add_executable(SimulacraEngine WIN32 Source/Core/Launcher/Win_Main.cpp
        Source/Renderer/Backend/Vulkan/Private/VulkanMemoryAllocator.cpp
        Source/Renderer/Backend/Vulkan/Public/VulkanMemoryAllocator.h
        Source/Core/Math/Math.h)

include(FetchContent)

FetchContent_Declare(
        glm
        GIT_REPOSITORY	https://github.com/g-truc/glm.git
        GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/1.0.1
)

FetchContent_MakeAvailable(glm)


if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-D_DEBUG=1)
endif ()
if (CMAKE_BUILD_TYPE MATCHES Release)
    add_definitions(-D_NDEBUG=1)
endif ()



target_link_libraries(SimulacraEngine SimulacraLibrary glm::glm)
