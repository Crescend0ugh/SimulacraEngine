//
// Created by avsom on 10/15/2023.
//

#pragma once

//TODO purge this file of dirty std types
// Include Vulkan and Core includes
#include "Core.h"
#include "VulkanCommon.h"
#include "VulkanMemoryAllocator.h"
#include "VulkanResources.h"
#include "Mesh.h"



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
    VkSurfaceKHR    surface_;
    VulkanSwapchain swapchain_;
    void*           window_handle;
    uint32          width_;
    uint32          height_;
};

struct VulkanPipeline
{
    VkPipeline       pipeline_;
    VkPipelineLayout pipeline_layout_;
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
    VkCommandPool              command_pool;
    VkFramebuffer              framebuffer_;
    VkSemaphore                image_acquired_semaphore_;
    VkSemaphore                image_rendered_semaphore_;
    VkFence                    in_flight_fence_;
    VkCommandBuffer            command_buffer_;
    VulkanBuffer               uniform_buffer_;
    void*                      uniformed_buffer_mapped_;
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
    void submit_to_queue(VulkanQueue queue,
                         span<const VkSemaphore> wait_semaphores,
                         span<const VkSemaphore> signal_semaphores,
                         span<const VkPipelineStageFlags> wait_dst_stage_mask,
                         span<const VkCommandBuffer> command_buffers,
                         VkFence fence = VK_NULL_HANDLE);

    void   create_swapchain(VkSurfaceKHR surface, uint32 &width, uint32 &height, VkSwapchainKHR old_swapchain);
    void   recreate_swapchain();
    void   release_swapchain(VulkanSwapchain &swapchain);
    uint32 acquire_next_image_from_swapchain(VkSwapchainKHR swapchain);
    void   present_image(VkSwapchainKHR swapchain, uint32 image_index, span<const VkSemaphore> wait_semaphores);

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

    VkCommandPool create_command_pool(uint32 queue_family_index, VkCommandPoolCreateFlags flags = 0);
    void          reset_command_pool(VkCommandPool command_pool);
    void          free_command_pool(VkCommandPool &command_pool);

    VkCommandBuffer create_command_buffer(VkCommandPool command_pool, VkCommandBufferLevel level = VK_COMMAND_BUFFER_LEVEL_PRIMARY);
    void            free_command_buffer(VkCommandPool command_pool, VkCommandBuffer& command_buffer);
    VkCommandBuffer create_and_begin_scratch_buffer();
    void            end_and_free_scratch_buffer(VkCommandBuffer command_buffer);
    void            begin_command_buffer(VkCommandBuffer command_buffer, VkCommandBufferUsageFlags usage_flags = 0);
    void            end_command_buffer(VkCommandBuffer command_buffer);
    void            reset_command_buffer(VkCommandBuffer command_buffer);



    void command_draw();
    void command_draw_indexed();
    void command_draw_indirect();
    void command_draw_indexed_indirect();

    VulkanBuffer create_buffer(VkDeviceSize size, VkBufferUsageFlags usage_flags, VkMemoryPropertyFlags property_flags);
    void release_buffer(VkCommandPool command_pool, VkCommandBuffer &command_buffer);

    VulkanImage create_image(uint32 width, uint32 height, VkFormat format, VkImageTiling image_tiling,
                             VkImageUsageFlags usage, VkMemoryPropertyFlags properties);
    VkImageView create_image_view(VkImage image, VkFormat format, VkImageAspectFlags aspect);
    void        release_image(VulkanImage& image);

    void* buffer_map(VulkanBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags memory_map_flags);
    void  buffer_unmap(VulkanBuffer buffer);

    void command_copy_buffer(VkCommandBuffer command_buffer, VulkanBuffer src, VulkanBuffer dst, VkDeviceSize size);
    void command_copy_image();
    void command_copy_buffer_to_image(VkCommandBuffer command_buffer, VulkanBuffer buffer, VulkanImage image,
                                      uint32 width, uint32 height);
    void command_copy_image_to_buffer();

    void transition_image_layout(VulkanImage image, VkFormat format, VkImageLayout old_layout, VkImageLayout new_layout);

    VkSemaphore create_semaphore();
    void        release_semaphore(VkSemaphore &semaphore);

    VkFence create_fence(bool signaled);
    void    release_fence(VkFence &fence);
    void    wait_for_fences();
    void    reset_fence();

    void create_shader_module();

    void test_record_command_buffers(VkCommandBuffer buffer, uint32 frame_index);
    //TODO get rid of this later
    void test_draw_frame();
    //TODO get rid of this later
    void test_create_vertex_buffer();
    //TODO get rid of this later
    void test_create_index_buffer();
    //TODO get rid of this later
    void test_create_texture_image();
    //TODO get rid of this later
    void test_create_texture_image_view();
    //TODO get rid of this later
    void test_create_texture_sampler();
    //TODO get rid of this later
    void test_create_depth_resources();
    //TODO get rid of this later
    VkFormat find_supported_format(const std::vector<VkFormat> &desired_formats,
                                   VkImageTiling tiling,
                                   VkFormatFeatureFlags features
                                   );
    bool has_stencil_component(VkFormat format);



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
    //TODO consider encapsulating device information
    VkDevice                     logical_device_;
    VkPhysicalDevice             physical_device_;

    //TODO need to figure how to properly initialize this
    VulkanMemoryAllocator        memory_allocator_;

    //TODO consider having these in an array and using enums to select desired queue type
    VulkanQueue                  graphics_queue;
    VulkanQueue                  transfer_queue;
    VulkanQueue                  compute_queue;

    VkCommandPool                scratch_pool;

    uint32                       frame_ = 0;
    std::vector<FrameContext>    frame_resources_;
    //TODO get rid of this later
    VulkanViewport               viewport_;
    //TODO get rid of this later
     VkDescriptorSetLayout       descriptor_set_layout;
     //TODO get rid of this later
     VkDescriptorPool            descriptor_pool;
    //TODO get rid of this later
    VulkanPipeline               pipeline_;
    //TODO get rid of this later
    VkRenderPass                 render_pass_;
    //TODO get rid of this later
    VkShaderModule               vertex_shader_module_;
    //TODO get rid of this later
    VkShaderModule               fragment_shader_module_;
    //TODO make a better way to use instance extensions than just declaring an array of names
    std::vector<const char*> requested_instance_extensions_ = {VK_KHR_WIN32_SURFACE_EXTENSION_NAME,
                                                               VK_KHR_SURFACE_EXTENSION_NAME,
                                                               VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME, };
    //TODO make this work...at all
    std::vector<const char*> instance_layers;
    //TODO make a better way to use device extensions than just declaring an array of names
    std::vector<const char*> requested_device_extensions_ = { VK_KHR_SWAPCHAIN_EXTENSION_NAME,
                                                              VK_EXT_MEMORY_BUDGET_EXTENSION_NAME,
                                                              VK_KHR_MAINTENANCE1_EXTENSION_NAME
    };
    //TODO get rid of this later
    VulkanBuffer vertex_buffer_;
    //TODO get rid of this later
    VulkanBuffer                 index_buffer_;
    //TODO get rid of this later
    std::vector<VkDescriptorSet> descriptor_sets;
    //TODO get rid of this later
    VulkanImage texture_image;
    //TODO get rid of this later
    VkSampler sampler;
    //TODO add a vector for device features
    VkPhysicalDeviceFeatures features;

    VulkanImage depth_image;

    void create_descriptor_set_layout()
    {
        VkDescriptorSetLayoutBinding descriptor_set_layout_binding{};
        descriptor_set_layout_binding.binding = 0;
        descriptor_set_layout_binding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        descriptor_set_layout_binding.descriptorCount = 1;
        descriptor_set_layout_binding.stageFlags = VK_SHADER_STAGE_VERTEX_BIT;
        descriptor_set_layout_binding.pImmutableSamplers = nullptr;

        VkDescriptorSetLayoutBinding sampler_layout_binding{};
        sampler_layout_binding.binding = 1;
        sampler_layout_binding.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        sampler_layout_binding.descriptorCount = 1;
        sampler_layout_binding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
        sampler_layout_binding.pImmutableSamplers = nullptr;

        VkDescriptorSetLayoutBinding bindings[] = {descriptor_set_layout_binding, sampler_layout_binding};

        VkDescriptorSetLayoutCreateInfo descriptor_set_layout_create_info{};
        descriptor_set_layout_create_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
        descriptor_set_layout_create_info.bindingCount = 2;
        descriptor_set_layout_create_info.pBindings = bindings;

        VK_ASSERT_SUCCESS(vkCreateDescriptorSetLayout(logical_device_, &descriptor_set_layout_create_info, nullptr, &descriptor_set_layout))

    }

    //TODO get rid of this later
    void update_uniform_buffer(uint32 current_frame_index);
    void create_descriptor_pool();
    void create_descriptor_sets();


    //TODO get rid of this later
    void load_mesh();



    std::vector<Vertex> vertices;
    std::vector<uint32> indices;    

};

//TODO figure out a way to properly declare positions types




struct UniformBufferObject
{
    Matrix4F model;
    Matrix4F view;
    Matrix4F projection;
};

