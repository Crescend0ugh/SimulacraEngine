cmake_minimum_required(VERSION 3.25)
project(SimulacraEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(Vulkan REQUIRED)
add_subdirectory("C:/glfw-3.3.8" ${PROJECT_SOURCE_DIR}/Binaries)

add_executable(SimulacraEngine Source/Core/Platforms/Windows/WinMain.cpp Source/Core/Sys/Precompiled.cpp Source/Core/Sys/SimEngineTypes.h Source/Core/Sys/SimEngineAsserts.h Source/Core/Sys/SimEngineDefines.h Source/Core/Sys/Precompiled.h
        Source/Core/Sys/SimEngineIncludes.h
        Source/Core/Math/Vector.inl
)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-D_DEBUG=1)
endif()
if (CMAKE_BUILD_TYPE MATCHES Release)
    add_definitions(-D_NDEBUG=1)
endif()

target_link_libraries(SimulacraEngine
        glfw
        Vulkan::Vulkan )
