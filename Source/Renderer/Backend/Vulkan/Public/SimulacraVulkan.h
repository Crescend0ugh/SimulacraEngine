//
// Created by avsom on 10/15/2023.
//

#pragma once


// Include Vulkan and Core includes
#include "../../../../Core/Sys/Precompiled.h"
#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>

// Forward declarations
struct vulkan_instance;
struct vulkan_device;
struct vulkan_queue;
struct vulkan_surface;
struct vulkan_swapchain;
struct graphics_pipeline;

enum shader_stages
{
    vertex, pixel, count = 2
};

class vulkan_renderer
{

private:
    struct vulkan_queue
    {
        VkQueue queue_;
        uint32  queue_family_index_;
        uint32  queue_index_;
    };

    struct vulkan_surface
    {
        VkSurfaceKHR surface_;
    };

    struct vulkan_swapchain
    {
        VkSwapchainKHR             vk_swapchain_;
        VkSurfaceKHR               vk_surface_;
        VkSurfaceFormatKHR         surface_format_;
        std::vector<VkImage>       images_;
        std::vector<VkImageView>   image_views_;
        uint32                     frame_index;
    };

    struct vulkan_pipeline
    {
        VkPipeline       pipeline_;
        VkPipelineLayout pipeline_layout_;
    };

    struct vulkan_pipeline_manager
    {
        struct pipeline_cache
        {
            std::string        file_name_;
            size_t             pipeline_cache_size_ = 0;
            std::vector<uint8> data_;
            VkPipelineCache    pipeline_cache_;
        };

        std::unordered_map<uint32, vulkan_pipeline> pipelines_;
        std::vector<pipeline_cache>                 pipeline_caches_;
        size_t                                      total_size_ = 0;
    };

    struct vulkan_graphics_pipeline_description
    {
        VkPrimitiveTopology topology_;
        VkPolygonMode       polygon_mode_;
        bool                blend_enable_;
        bool                depth_write_enable_;
        bool                depth_test_enable_;
        std::vector<VkVertexInputAttributeDescription>
                            vertex_input_attributes_descriptions_;
        std::vector<VkVertexInputBindingDescription>
                            vertex_input_binding_descriptions_;
    };

    struct vulkan_device
    {
        VkDevice         logical_device_;
        VkPhysicalDevice physical_device_;
    };

   struct frame_data
   {
       VkSemaphore image_acquired_semaphore_;
       VkSemaphore image_rendered_semaphore_;
       VkFence     in_flight_fence_;
   };

public:
    void init();
    void shutdown();

    void create_queue(uint32 queue_family_index, uint32 queue_index);
    void submit_to_queue();

    void create_surface(void* window_handle);
    void release_surface();

    void create_swapchain(VkSurfaceKHR surface, uint32 width, uint32 height);
    void recreate_swapchain();
    void release_swapchain(vulkan_swapchain &swapchain);
    void acquire_next_image(VkSwapchainKHR swapchain);
    void present_image(VkSwapchainKHR swapchain);

    void create_pipeline(const vulkan_graphics_pipeline_description &pipeline_description);
    void release_pipeline();

    void create_render_pass();
    void release_render_pass();
    void begin_render_pass();
    void end_render_pass();

    void create_framebuffer(VkRenderPass render_pass, const std::vector<VkImageView> &attachment_views, uint32 width, uint32 height, uint32 layers);
    void release_framebuffer(VkFramebuffer &framebuffer);

    void create_command_pool(uint32 queue_family_index);
    void reset_command_pool(VkCommandPool command_pool);
    void free_command_pool();

    void create_command_buffer(VkCommandPool command_pool);
    void reset_command_buffer(VkCommandBuffer command_buffer);
    void begin_command_buffer(VkCommandBuffer command_buffer);
    void end_command_buffer(VkCommandBuffer command_buffer);

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
    void release_semaphore();

    void create_fence();
    void release_fence();
    void wait_for_fences();
    void reset_fence();

private:
    void create_instance();
    void release_instance();

    void select_physical_device();
    void create_device();
    void release_device();

    void create_pipeline_manager();
    void release_pipeline_manager();

private:

    VkInstance               instance_;
    uint32                   api_version_;
    std::vector<const char*> requested_instance_extensions_;

    vulkan_device            device_;
    std::vector<const char*> requested_device_extensions_;

    std::vector<vulkan_swapchain> swapchains_;
    std::vector<vulkan_surface> surfaces_;

    vulkan_queue present_queue_;
    vulkan_queue graphics_queue_;
    vulkan_queue compute_queue_;
    vulkan_queue transfer_queue_;

    bool has_async_compute_queue;
    bool has_dedicated_transfer_queue;

    vulkan_pipeline_manager pipeline_manager_;
};
