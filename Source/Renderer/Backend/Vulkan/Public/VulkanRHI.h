//
// Created by avsom on 10/15/2023.
//

#pragma once


// Include Vulkan and Core includes
#include "../../../../Core/Sys/Precompiled.h"
#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>
#include "VulkanMemoryAllocator.h"

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
    uint32  family_index_;
    uint32  index_;
};

struct VulkanSwapchain
{
    VkSwapchainKHR             vk_swapchain_;
    VkSurfaceKHR               vk_surface_;
    VkSurfaceFormatKHR         surface_format_;
    std::vector<VkImage>       images_;
    std::vector<VkImageView>   image_views_;
};

struct VulkanViewport
{
    VkSurfaceKHR surface_;
    VulkanSwapchain swapchain_;
    void*        window_handle;
    uint32       width_;
    uint32       height_;
    uint32      frame_;
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

struct FrameContext
{
    std::vector<VkCommandPool> command_pools_;
    VkFramebuffer              framebuffer_;
    VkSemaphore                image_acquired_semaphore_;
    VkSemaphore                image_rendered_semaphore_;
    VkFence                    in_flight_fence_;
};

enum QueueIndex
{
    Graphics,
    Compute,
    Transfer,
    Max
};

enum class ShaderStages
{
    Vertex,
    Pixel,
    Compute,
    Max
};

struct VertexAttribute
{
    uint32   offset_;
    uint32   attribute_index_;
    VkFormat vertex_format_;
    uint32   binding_index_;
};


class VulkanRHI
{

public:
    
    void init(void* win_hand);
    void shutdown();

    void create_queue(uint32 queue_family_index, uint32 queue_index);
    void submit_to_queue();

    void   create_swapchain(VkSurfaceKHR surface, uint32 &width, uint32 &height, VkSwapchainKHR old_swapchain);
    void   recreate_swapchain();
    void   release_swapchain(VulkanSwapchain &swapchain);
    uint32 acquire_next_image_from_swapchain(VkSwapchainKHR swapchain);
    void   present_image(VkSwapchainKHR swapchain);

    void create_viewport(void* window_handle);
    void release_viewport(uint32 viewport_index);

    void create_pipeline(const VulkanGraphicsPipelineDescription &pipeline_description);
    void release_pipeline();

    void create_render_pass(VkRenderPass * render_pass);
    void release_render_pass(VkRenderPass render_pass);
    void command_begin_render_pass(VkCommandBuffer command_buffer,
                                   VkRenderPass render_pass,
                                   VkFramebuffer framebuffer,
                                   VkExtent2D extent);
    void command_end_render_pass(VkCommandBuffer command_buffer);

    VkFramebuffer create_framebuffer(VkRenderPass render_pass,
                                     const std::vector<VkImageView> &attachment_views,
                                     uint32 width,
                                     uint32 height,
                                     uint32 layers);
    void          release_framebuffer(VkFramebuffer &framebuffer);

    VkCommandPool create_command_pool(uint32 queue_family_index);
    void          reset_command_pool(VkCommandPool command_pool);
    void          free_command_pool(VkCommandPool &command_pool);

    VkCommandBuffer create_command_buffer(VkCommandPool command_pool);
    void            begin_command_buffer(VkCommandBuffer command_buffer);
    void            end_command_buffer(VkCommandBuffer command_buffer);
    void            reset_command_buffer(VkCommandBuffer command_buffer);

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

    VkSemaphore create_semaphore();
    void        release_semaphore(VkSemaphore &semaphore);

    VkFence create_fence(bool signaled);
    void    release_fence(VkFence &fence);
    void    wait_for_fences();
    void    reset_fence();

    void create_shader_module();

    void test_record_command_buffers(VkCommandBuffer buffer, uint32 frame_index);
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

    VkInstance                   instance_;
    VkDevice                     logical_device_;
    VkPhysicalDevice             physical_device_;
    VulkanMemoryAllocator        memory_allocator_;
    VulkanQueue                  graphics_queue;
    VulkanQueue                  transfer_queue;
    VulkanQueue                  compute_queue;
    std::vector<FrameContext>    frame_resources_;
    std::vector<VkCommandBuffer> command_buffers_;
    VulkanViewport               viewport_;
    VulkanPipeline               pipeline_;
    VkRenderPass                 render_pass_;
    VkShaderModule               vertex_shader_module_;
    VkShaderModule               fragment_shader_module_;

    std::vector<const char*> requested_instance_extensions_ = {VK_KHR_WIN32_SURFACE_EXTENSION_NAME, VK_KHR_SURFACE_EXTENSION_NAME, VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME};
    std::vector<const char*> instance_layers;
    std::vector<const char*> requested_device_extensions_ = { VK_KHR_SWAPCHAIN_EXTENSION_NAME, VK_EXT_MEMORY_BUDGET_EXTENSION_NAME};

};

struct Vertex
{
    Vector2F position_;
    Vector3F color_;

    static VkVertexInputBindingDescription get_binding_description()
    {
        VkVertexInputBindingDescription binding_description{};
        binding_description.binding = 0;
        binding_description.stride = sizeof(Vertex);
        binding_description.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
        return binding_description;
    }

    static std::vector<VkVertexInputAttributeDescription> get_attribute_descriptions()
    {
        std::vector<VkVertexInputAttributeDescription> attribute_descriptions{};
        attribute_descriptions.reserve(2);
        attribute_descriptions.resize(2);
        attribute_descriptions[0].binding = 0;
        attribute_descriptions[0].location = 0;
        attribute_descriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
        attribute_descriptions[0].offset = offsetof(Vertex, position_);
        attribute_descriptions[1].binding = 0;
        attribute_descriptions[1].location = 1;
        attribute_descriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
        attribute_descriptions[1].offset = offsetof(Vertex, color_);
        return attribute_descriptions;
    }

};
//TODO get rid of this later
const std::vector<Vertex> vertices = {
        {{0.0f, -0.5f}, {1.0f, 0.0f, 0.0f}},
        {{0.5f, 0.5f}, {0.0f, 1.0f, 0.0f}},
        {{-0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}}
};

