//
// Created by avsom on 10/15/2023.
//

#pragma once


// Include Vulkan and Core includes
#include "../../../../Core/Sys/Precompiled.h"
#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>


#define VK_ASSERT_SUCCESS(statement) \
{VkResult result = statement;  \
if(result == VK_SUCCESS)     \
{                            \
}                            \
                             \
else                         \
{                            \
    std::cout << #statement << " failed\n";   \
}}\


struct VulkanQueue
{
    VkQueue queue_;
    uint32  queue_family_index_;
    uint32  queue_index_;
};

struct VulkanSwapchain
{
    VkSwapchainKHR             vk_swapchain_;
    VkSurfaceKHR               vk_surface_;
    VkSurfaceFormatKHR         surface_format_;
    std::vector<VkImage>       images_;
    std::vector<VkImageView>   image_views_;
    uint32                     frame_index;
};

struct VulkanViewport
{
    VkSurfaceKHR surface_;
    void*        window_handle;
    uint32 width_;
    uint32 height_;
};

struct VulkanPipeline
{
    VkPipeline       pipeline_;
    VkPipelineLayout pipeline_layout_;
};

struct VulkanPipelineManager
{
    struct pipeline_cache
    {
        std::string        file_name_;
        size_t             pipeline_cache_size_ = 0;
        std::vector<uint8> data_;
        VkPipelineCache    pipeline_cache_;
    };

    std::unordered_map<uint32, VulkanPipeline> pipelines_;
    std::vector<pipeline_cache>                pipeline_caches_;
    size_t                                      total_size_ = 0;
};

struct VulkanGraphicsPipelineDescription
{
    VkPrimitiveTopology                            topology_;
    VkPolygonMode                                  polygon_mode_;
    bool                                           blend_enable_;
    bool                                           depth_write_enable_;
    bool                                           depth_test_enable_;
    std::vector<VkVertexInputAttributeDescription> vertex_input_attributes_descriptions_;
    std::vector<VkVertexInputBindingDescription>   vertex_input_binding_descriptions_;
    VkRenderPass                                   render_pass_;

};

struct VulkanDevice
{
    VkDevice         logical_device_;
    VkPhysicalDevice physical_device_;
};

struct FrameContext
{
    std::vector<VkCommandPool> command_pools_;
    VkFramebuffer              framebuffer_;
    VkSemaphore                image_acquired_semaphore_;
    VkSemaphore                image_rendered_semaphore_;
    VkFence                    in_flight_fence_;
};


class VulkanRenderer
{

public:
    void init(void* win_hand);
    void shutdown();

    void create_queue(uint32 queue_family_index, uint32 queue_index);
    void submit_to_queue();

    void create_swapchain(VkSurfaceKHR surface, uint32 width, uint32 height);
    void recreate_swapchain();
    void release_swapchain(VulkanSwapchain &swapchain);
    void acquire_next_image_from_swapchain(VkSwapchainKHR swapchain);
    void present_image(VkSwapchainKHR swapchain);

    void create_viewport(void* window_handle);
    void release_viewport(uint32 viewport_index);

    void create_pipeline(const VulkanGraphicsPipelineDescription &pipeline_description);
    void release_pipeline();

    void create_render_pass(VkRenderPass * render_pass);
    void release_render_pass(VkRenderPass render_pass);
    void begin_render_pass();
    void end_render_pass();

    void create_framebuffer(VkFramebuffer* framebuffer, VkRenderPass render_pass,
                            const std::vector<VkImageView> &attachment_views, uint32 width, uint32 height,
                            uint32 layers);
    void release_framebuffer(VkFramebuffer &framebuffer);

    void create_command_pool(VkCommandPool * command_pool, uint32 queue_family_index);
    void reset_command_pool(VkCommandPool command_pool);
    void free_command_pool(VkCommandPool &command_pool);

    void create_command_buffer(VkCommandBuffer command_buffer, VkCommandPool command_pool);
    void begin_command_buffer(VkCommandBuffer command_buffer);
    void end_command_buffer(VkCommandBuffer command_buffer);
    void reset_command_buffer(VkCommandBuffer command_buffer);

    void command_draw();
    void command_draw_indexed();
    void command_draw_indirect();
    void command_draw_indexed_indirect();

    void create_buffer();
    void release_buffer();

    void* buffer_map();
    void  buffer_unmap();

    void command_copy_buffer();
    void command_copy_image();
    void command_copy_buffer_to_image();
    void command_copy_image_to_buffer();

    void create_semaphore();
    void release_semaphore(VkSemaphore &semaphore);

    void create_fence(bool signaled);
    void release_fence(VkFence &fence);
    void wait_for_fences();
    void reset_fence();

    void create_shader_module();

    void test_draw_frame();
protected:
    void create_instance();
    void release_instance();

    void select_physical_device();
    void create_device();
    void release_device();

    void create_pipeline_manager();
    void release_pipeline_manager();

protected:

    struct RendererTestStruct
    {
        VulkanSwapchain            swapchain_;
        VulkanViewport             viewport_;
        std::vector<FrameContext>  per_frame_resources_;
        VkRenderPass               render_pass_;
        std::vector<VkFramebuffer> framebuffers_;
        VulkanPipeline             pipeline_;
        VkShaderModule             vertex_shader_module_;
        VkShaderModule             fragment_shader_module_;
        VkCommandPool              command_pool;

    };

    VkInstance               instance_;
    uint32                   api_version_;
    std::vector<const char*> requested_instance_extensions_ = {VK_KHR_WIN32_SURFACE_EXTENSION_NAME, VK_KHR_SURFACE_EXTENSION_NAME};
    std::vector<const char*> instance_layers_;

    VulkanDevice             device_;
    std::vector<const char*> requested_device_extensions_ = { VK_KHR_SWAPCHAIN_EXTENSION_NAME};

    RendererTestStruct test_struct_;

    VulkanQueue present_queue_;
    VulkanQueue graphics_queue_;
    VulkanQueue compute_queue_;
    VulkanQueue transfer_queue_;

    bool has_async_compute_queue_;
    bool has_dedicated_transfer_queue_;

    VulkanPipelineManager pipeline_manager_;
};
