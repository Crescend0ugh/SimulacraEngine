//
// Created by avsom on 1/5/2024.
//

#pragma once

#include "SimulacraVulkan.h"

struct graphics_pipeline_description
{


    VkPrimitiveTopology topology_;

    VkPolygonMode polygon_mode_;

    bool blend_enable_;

    bool depth_write_enable_;
    bool depth_test_enable_;

    std::vector<VkVertexInputAttributeDescription> vertex_input_attributes_;
    std::vector<VkVertexInputBindingDescription>   vertex_input_binding_descriptions_;

};


struct vulkan_pipeline_key
{
};

class graphics_pipeline
{

public:

    graphics_pipeline(vulkan_device &device);

    ~graphics_pipeline();

    graphics_pipeline(const graphics_pipeline &) = delete;

    graphics_pipeline &operator=(const graphics_pipeline &) = delete;




protected:


private:

    vulkan_device* device_;
    VkPipeline pipeline_;
};


class compute_pipeline
{

};

class pipeline_manager
{

    VkPipelineCache pipeline_cache_;
};