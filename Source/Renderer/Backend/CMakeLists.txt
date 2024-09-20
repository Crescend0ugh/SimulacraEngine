find_package(Vulkan REQUIRED)
target_link_libraries(SimulacraLibrary Vulkan::Vulkan)
target_include_directories(SimulacraLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(SimulacraLibrary PUBLIC Vulkan/Public)
target_sources(SimulacraLibrary PRIVATE
        Vulkan/Private/VulkanRHI.cpp
        Vulkan/Private/VulkanMemoryAllocator.cpp
        Vulkan/Private/VulkanResources.cpp
        Vulkan/Private/VulkanSwapchain.cpp
)
if (APPLE)
    target_include_directories(SimulacraLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_sources(SimulacraLibrary PUBLIC Metal/MetalRHI.mm Metal/MetalImplementation.cpp)
    target_link_libraries(SimulacraLibrary "-framework Metal")
    target_link_libraries(SimulacraLibrary "-framework MetalKit")
    target_link_libraries(SimulacraLibrary "-framework MetalFX")
    target_link_libraries(SimulacraLibrary "-framework QuartzCore")


endif ()
