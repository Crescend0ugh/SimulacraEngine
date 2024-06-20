#include "SimulacraVulkan.h"



void vulkan_renderer::init()
{

}

void vulkan_renderer::shutdown()
{

}

void vulkan_renderer::create_queue(uint32 queue_family_index, uint32 queue_index)
{

}

void vulkan_renderer::submit_to_queue()
{

}

void vulkan_renderer::create_surface()
{

}

void vulkan_renderer::release_surface()
{

}

void vulkan_renderer::create_swapchain()
{

}

void vulkan_renderer::recreate_swapchain()
{

}

void vulkan_renderer::release_swapchain(vulkan_swapchain &swapchain)
{

}

void vulkan_renderer::acquire_next_image_from_swapchain()
{

}

void vulkan_renderer::present_image_from_swapchain()
{

}

void vulkan_renderer::create_pipeline( const vulkan_graphics_pipeline_description &pipeline_description)
{

}

void vulkan_renderer::release_pipeline()
{

}

void vulkan_renderer::create_render_pass()
{

}

void vulkan_renderer::release_render_pass()
{

}

void vulkan_renderer::begin_render_pass()
{

}

void vulkan_renderer::end_render_pass()
{

}

void vulkan_renderer::create_framebuffer(VkRenderPass render_pass,
                          const std::vector<VkImageView> &attachment_views,
                          uint32 width, uint32 height, uint32 layers)
{

}

void vulkan_renderer::release_framebuffer(VkFramebuffer &framebuffer)
{

}

void vulkan_renderer::create_command_pool(uint32 queue_family_index)
{

}

void vulkan_renderer::reset_command_pool()
{

}

void vulkan_renderer::free_command_pool()
{

}

void vulkan_renderer::create_command_buffer(VkCommandPool command_pool)
{

}

void vulkan_renderer::reset_command_buffer(VkCommandBuffer command_buffer)
{

}

void vulkan_renderer::begin_command_buffer(VkCommandBuffer command_buffer)
{

}

void vulkan_renderer::end_command_buffer(VkCommandBuffer command_buffer)
{

}

void vulkan_renderer::command_draw()
{

}

void vulkan_renderer::command_draw_indexed()
{

}

void vulkan_renderer::command_draw_indirect()
{

}

void vulkan_renderer::command_draw_indexed_indirect()
{

}

void vulkan_renderer::create_buffer()
{

}

void vulkan_renderer::release_buffer()
{

}

void vulkan_renderer::buffer_unmap()
{

}

void vulkan_renderer::command_copy_buffer()
{

}

void vulkan_renderer::command_copy_image()
{

}

void vulkan_renderer::command_copy_buffer_to_image()
{

}

void vulkan_renderer::command_copy_image_to_buffer()
{

}

void vulkan_renderer::create_semaphore()
{

}

void vulkan_renderer::release_semaphore()
{

}

void vulkan_renderer::create_fence()
{

}

void vulkan_renderer::release_fence()
{

}

void vulkan_renderer::wait_for_fences()
{

}

void vulkan_renderer::reset_fence()
{

}

void vulkan_renderer::create_texture()
{

}

void vulkan_renderer::create_instance()
{

}

void vulkan_renderer::release_instance()
{

}

void vulkan_renderer::select_physical_device()
{

}

void vulkan_renderer::create_device()
{

}

void vulkan_renderer::release_device()
{

}

void vulkan_renderer::create_pipeline_manager()
{

}

void vulkan_renderer::release_pipeline_manager()
{

}

