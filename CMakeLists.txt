cmake_minimum_required(VERSION 3.25)
project(SimulacraEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(Vulkan REQUIRED)
add_subdirectory("C:/glfw-3.3.8" ${PROJECT_SOURCE_DIR}/Binaries)

add_executable(SimulacraEngine Source/Core/Platforms/Windows/WinMain.cpp Source/Core/Memory/Private/LinearAllocator.cpp Source/Core/Memory/AllocatorTests.cpp Source/Core/Memory/AllocatorTests.h)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-D_DEBUG=1)
endif ()
if (CMAKE_BUILD_TYPE MATCHES Release)
    add_definitions(-D_NDEBUG=1)
endif ()

target_link_libraries(SimulacraEngine
        glfw
        Vulkan::Vulkan)
