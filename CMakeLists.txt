cmake_minimum_required(VERSION 3.25)
project(SimulacraEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)




find_package(Vulkan REQUIRED)


add_library(SimulacraLibrary)
add_subdirectory(Source/Renderer/Backend/Vulkan)
add_subdirectory(Source/Renderer/Backend/DirectX)

add_subdirectory(Source/Core/Platform)
add_subdirectory(Source/Core)
add_subdirectory(Source/ThirdParty)

add_executable(SimulacraEngine WIN32 Source/Core/Launcher/Win_Main.cpp)


if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-D_DEBUG=1)
endif ()
if (CMAKE_BUILD_TYPE MATCHES Release)
    add_definitions(-D_NDEBUG=1)
endif ()



target_link_libraries(SimulacraEngine SimulacraLibrary)
