//
// Created by avsom on 1/5/2024.
//


#include "SimulacraVulkanPipeline.h"

//TODO
graphics_pipeline::graphics_pipeline(vulkan_device& device, const graphics_pipeline_description& description)
{



    VkGraphicsPipelineCreateInfo graphics_pipeline_create_info{};
    graphics_pipeline_create_info.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
}

//TODO
void graphics_pipeline::fill_vertex_input_state()
{

}

//TODO add topology parameter
void graphics_pipeline::fill_input_assembly_state()
{
    VkPipelineInputAssemblyStateCreateInfo pipeline_input_assembly_state_create_info{};
    pipeline_input_assembly_state_create_info.sType                  = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
    pipeline_input_assembly_state_create_info.primitiveRestartEnable = VK_FALSE;
    pipeline_input_assembly_state_create_info.topology               = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
}

void graphics_pipeline::fill_viewport_state()
{
    VkPipelineViewportStateCreateInfo pipeline_viewport_state_create_info{};
    pipeline_viewport_state_create_info.sType         = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
    pipeline_viewport_state_create_info.scissorCount  = 1;
    pipeline_viewport_state_create_info.viewportCount = 1;
}

//TODO add poly fill mode param
void graphics_pipeline::fill_rasterization_state()
{
    VkPipelineRasterizationStateCreateInfo pipeline_rasterization_state_create_info{};
    pipeline_rasterization_state_create_info.sType                   = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
    pipeline_rasterization_state_create_info.depthClampEnable        = VK_FALSE;
    pipeline_rasterization_state_create_info.rasterizerDiscardEnable = VK_FALSE;
    pipeline_rasterization_state_create_info.polygonMode             = VK_POLYGON_MODE_FILL;
    pipeline_rasterization_state_create_info.lineWidth               = 1.0f;
    pipeline_rasterization_state_create_info.cullMode                = VK_CULL_MODE_BACK_BIT;
    pipeline_rasterization_state_create_info.frontFace               = VK_FRONT_FACE_CLOCKWISE;
    pipeline_rasterization_state_create_info.depthBiasEnable         = VK_FALSE;
    pipeline_rasterization_state_create_info.depthBiasConstantFactor = 0.0f;
    pipeline_rasterization_state_create_info.depthBiasClamp          = 0.0f;
    pipeline_rasterization_state_create_info.depthBiasSlopeFactor    = 0.0f;

}

void graphics_pipeline::fill_multisample_state()
{
    VkPipelineMultisampleStateCreateInfo pipeline_multisample_state_create_info{};
    pipeline_multisample_state_create_info.sType                 = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    pipeline_multisample_state_create_info.sampleShadingEnable   = VK_FALSE;
    pipeline_multisample_state_create_info.rasterizationSamples  = VK_SAMPLE_COUNT_1_BIT;
    pipeline_multisample_state_create_info.minSampleShading      = 1.0f;
    pipeline_multisample_state_create_info.pSampleMask           = nullptr;
    pipeline_multisample_state_create_info.alphaToCoverageEnable = VK_FALSE;
    pipeline_multisample_state_create_info.alphaToOneEnable      = VK_FALSE;

}

void graphics_pipeline::fill_depth_stencil_state()
{
    VkPipelineDepthStencilStateCreateInfo pipeline_depth_stencil_state_create_info{};
    pipeline_depth_stencil_state_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;


}

void graphics_pipeline::fill_blend_attachment()
{
    VkPipelineColorBlendAttachmentState pipeline_color_blend_attachment_state{};
    pipeline_color_blend_attachment_state.blendEnable;
}

void graphics_pipeline::fill_color_blend_state()
{
    VkPipelineColorBlendStateCreateInfo pipeline_color_blend_create_info{};
    pipeline_color_blend_create_info.sType         = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    pipeline_color_blend_create_info.logicOpEnable = VK_FALSE;
    pipeline_color_blend_create_info.logicOp       = VK_LOGIC_OP_SET;

    pipeline_color_blend_create_info.pAttachments = nullptr;
    pipeline_color_blend_create_info.blendConstants[0] = 0.0f;
    pipeline_color_blend_create_info.blendConstants[1] = 0.0f;
    pipeline_color_blend_create_info.blendConstants[2] = 0.0f;
    pipeline_color_blend_create_info.blendConstants[3] = 0.0f;

}

void graphics_pipeline::fill_dynamic_state_state()
{
    std::vector<VkDynamicState>      dynamic_states = {VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR};
    VkPipelineDynamicStateCreateInfo dynamic_state_create_info{};
    dynamic_state_create_info.sType             = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
    dynamic_state_create_info.dynamicStateCount = dynamic_states.size();
    dynamic_state_create_info.pDynamicStates    = dynamic_states.data();

}

