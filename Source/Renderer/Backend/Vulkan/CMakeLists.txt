target_link_libraries(SimulacraLibrary
        Vulkan::Vulkan)
target_include_directories(SimulacraLibrary PUBLIC Public)
target_include_directories(SimulacraLibrary PUBLIC Platforms)
target_sources(SimulacraLibrary PRIVATE

        Platforms/Windows/SimulacraVulkanWindowsPlatform.cpp
        Private/SimulacraVulkanExtensions.cpp
        Private/SimulacraVulkanInstance.cpp
        Private/SimulacraVulkanDevice.cpp
        Private/SimulacraVulkanQueue.cpp
        Private/SimulacraVulkanSurface.cpp
        Private/SimulacraVulkanSwapchain.cpp
        Private/SimulacraVulkanPipeline.cpp

)
