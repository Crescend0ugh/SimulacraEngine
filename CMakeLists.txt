cmake_minimum_required(VERSION 3.25)
project(SimulacraEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(Vulkan REQUIRED)
add_subdirectory("C:/glfw-3.3.8" ${PROJECT_SOURCE_DIR}/Binaries)

add_executable(SimulacraEngine main.cpp Source/vec3.h Source/color.h Source/ray.h Source/hittable.h Source/Renderer/Vulkan/RenderBackend_VK.cpp Source/Renderer/Vulkan/RenderBackend_VK.h Source/Renderer/RenderBackend.cpp Source/Renderer/RenderBackend.h Source/Math/Matrix.h Source/EngineTypes.h Source/Math/Vector.h Source/EngineDefines.h Source/Math/Matrix.inl Source/Math/Vector.inl Source/win32/WindowProcedure.cpp Source/win32/WindowsApplication.h)
target_link_libraries(SimulacraEngine
        glfw
        Vulkan::Vulkan )
