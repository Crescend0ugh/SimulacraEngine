cmake_minimum_required(VERSION 3.25)
project(SimulacraEngine)

set(CMAKE_CXX_STANDARD 17)



find_package(Vulkan REQUIRED)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(SimulacraEngine WIN32 Source/Core/Launcher/Win_Main.cpp
        Source/Core/Logging/SimulacraLogging.cpp)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-D_DEBUG=1)
endif ()
if (CMAKE_BUILD_TYPE MATCHES Release)
    add_definitions(-D_NDEBUG=1)
endif ()

target_link_libraries(SimulacraEngine
        Vulkan::Vulkan)

