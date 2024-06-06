//
// Created by avsom on 10/15/2023.
//

#pragma once


#define VK_USE_PLATFORM_WIN32_KHR


// Include Vulkan and Core includes
#include "../../../../Core/Sys/Precompiled.h"
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
    vertex,
    pixel,
    count = 2
};


class vulkan_renderer
{
public:

private:
    VkInstance               instance_;
    uint32                   api_version_;
    std::vector<const char*> requested_instance_extensions_;

    struct device
    {
        VkDevice         logical_device_;
        VkPhysicalDevice physical_device_;

    };

    device                   device_;
    std::vector<const char*> requested_device_extensions_;

    struct vulkan_queue
    {
        VkQueue queue_;
        uint32  queue_family_index_;
        uint32  queue_index_;
    };

    vulkan_queue present_queue_;
    vulkan_queue graphics_queue_;
    vulkan_queue compute_queue_;
    vulkan_queue transfer_queue_;

    void create_instance();

    void release_instance();

    void select_physical_device();

    void create_device();

    void release_device();

    struct surface
    {
        VkSurfaceKHR surface_;

    };

    void create_surface();

    void release_surface();

    struct swapchain
    {

        VkSwapchainKHR             vk_swapchain_;
        VkSurfaceKHR               vk_surface_;
        VkSurfaceFormatKHR         surface_format_;
        std::vector<VkImage>       images_;
        std::vector<VkImageView>   image_views_;
        std::vector<VkFramebuffer> frame_buffers_;
    };

    swapchain swapchain_;

    void create_swapchain();

    void recreate_swapchain();

    void release_swapchain();


    struct pipeline
    {
        VkPipeline       pipeline_;
        VkPipelineLayout pipeline_layout_;
    };

    struct pipeline_manager
    {
        struct pipeline_cache
        {
            std::string        file_name_;
            size_t             pipeline_cache_size_ = 0;
            std::vector<uint8> data_;
            VkPipelineCache    pipeline_cache_;
        };

        std::unordered_map<uint32, pipeline> pipelines_;
        std::vector<pipeline_cache>          pipeline_caches_;
        size_t                               total_size_ = 0;
    };

    pipeline_manager pipeline_manager_;

    void create_pipeline_manager(std::vector<const char*> pipeline_cache_file_names);

    void release_pipeline_manager();

    struct graphics_pipeline_description
    {
        VkPrimitiveTopology                            topology_;
        VkPolygonMode                                  polygon_mode_;
        bool                                           blend_enable_;
        bool                                           depth_write_enable_;
        bool                                           depth_test_enable_;
        std::vector<VkVertexInputAttributeDescription> vertex_input_attributes_descriptions_;
        std::vector<VkVertexInputBindingDescription>   vertex_input_binding_descriptions_;
    };

    void create_pipeline(const graphics_pipeline_description &pipeline_description);

    void release_pipeline();


};
