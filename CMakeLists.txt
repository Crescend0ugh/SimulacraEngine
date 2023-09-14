cmake_minimum_required(VERSION 3.25)
project(SimulacraEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(Vulkan REQUIRED)

add_executable(SimulacraEngine main.cpp Source/vec3.h Source/color.h Source/ray.h Source/hittable.h Source/Renderer/Vulkan/RenderBackend_VK.cpp Source/Renderer/Vulkan/RenderBackend_VK.h Source/Renderer/RenderBackend.cpp Source/Renderer/RenderBackend.h)
target_link_libraries(SimulacraEngine Vulkan::Vulkan)
