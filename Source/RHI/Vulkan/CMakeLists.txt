
find_package(Vulkan REQUIRED FATAL_ERROR)
add_library(SimulacraVulkan STATIC Private/SimulacraVulkanPlatform.cpp)
target_include_directories(SimulacraVulkan PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Public)
set_target_properties(SimulacraVulkan PROPERTIES PUBLIC_HEADER Public)
target_link_libraries(SimulacraVulkan Vulkan::Vulkan)