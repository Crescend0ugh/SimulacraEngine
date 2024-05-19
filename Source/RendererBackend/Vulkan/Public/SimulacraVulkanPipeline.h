//
// Created by avsom on 1/5/2024.
//

#pragma once

#include "SimulacraVulkan.h"



class graphics_pipeline
{

public:

    graphics_pipeline();

    void fill_vertex_input_state();
    void fill_input_assembly_state();
    void fill_viewport_state();
    void fill_rasterization_state();
    void fill_multisample_state();
    void fill_depth_stencil_state();
    void fill_blend_attachment();
    void fill_color_blend_state();
    void fill_dynamic_state_state();



protected:


private:

    vulkan_device* device_;
    VkPipeline pipeline_;
};
