cmake_minimum_required(VERSION 3.25)
project(SimulacraEngine)

set(CMAKE_CXX_STANDARD 17)



find_package(Vulkan REQUIRED)

add_executable(SimulacraEngine Source/Core/Launcher/Win_Main.cpp Source/Application/Windows/SimulacraWindowsApplication.cpp Source/Application/Windows/SimulacraWindowsWindow.cpp Source/Application/SimulacraApplication.cpp Source/Application/SimulacraWindow.cpp Source/Core/Math/SimulacraMathSSE.h Source/Core/Math/SimulacraMathUtils.h Source/RHI/Vulkan/Private/SimulacraVulkanSwapchain.cpp)
if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-D_DEBUG=1)
endif ()
if (CMAKE_BUILD_TYPE MATCHES Release)
    add_definitions(-D_NDEBUG=1)
endif ()

target_link_libraries(SimulacraEngine
        Vulkan::Vulkan)

