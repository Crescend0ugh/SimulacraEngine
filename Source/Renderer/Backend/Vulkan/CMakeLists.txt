target_link_libraries(SimulacraLibrary
        Vulkan::Vulkan)
target_include_directories(SimulacraLibrary PUBLIC Public)
target_include_directories(SimulacraLibrary PUBLIC Platforms)
target_sources(SimulacraLibrary PRIVATE
        Platforms/Windows/SimulacraVulkanWindowsPlatform.cpp
        Private/VulkanRHI.cpp
        Private/VulkanMemoryAllocator.cpp
        Private/VulkanResources.cpp
)
