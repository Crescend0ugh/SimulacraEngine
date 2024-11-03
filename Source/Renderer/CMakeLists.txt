
find_package(Vulkan REQUIRED)
target_link_libraries(SimulacraLibrary Vulkan::Vulkan)


target_include_directories(SimulacraLibrary PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(SimulacraLibrary PUBLIC ForwardRenderer.mm)

target_include_directories(SimulacraLibrary PUBLIC Backend/Vulkan/Public)
target_include_directories(SimulacraLibrary PUBLIC Backend/Vulkan/Platforms/Windows)
target_sources(SimulacraLibrary PUBLIC
        Backend/Vulkan/Private/VulkanRHI.cpp
        Backend/Vulkan/Private/VulkanMemoryAllocator.cpp
        Backend/Vulkan/Private/VulkanResources.cpp
        Backend/Vulkan/Private/VulkanSwapchain.cpp
        Backend/Vulkan/VulkanDeferredRenderer.cpp
)
if (APPLE)
    target_include_directories(SimulacraLibrary PUBLIC Backend)
    target_sources(SimulacraLibrary PUBLIC
            Backend/Metal/MetalRHI.mm
            Backend/Metal/MetalImplementation.cpp
            Backend/Metal/MetalManager.mm
            Backend/Metal/MetalResources.mm
            Backend/Metal/MetalPipeline.mm)
    target_link_libraries(SimulacraLibrary "-framework Metal")
    target_link_libraries(SimulacraLibrary "-framework MetalKit")
    target_link_libraries(SimulacraLibrary "-framework MetalFX")
    target_link_libraries(SimulacraLibrary "-framework QuartzCore")
endif ()
