//
// Created by avsom on 1/5/2024.
//

#include <fstream>

#include "../Public/SimulacraVulkanPipeline.h"

SVulkanPipeline::SVulkanPipeline(SVulkanDevice *InDevice, SVulkanSwapchain *InSwapchain) : Device(InDevice),
                                                                                           Swapchain(InSwapchain),
                                                                                           GraphicsPipeline(VK_NULL_HANDLE),
                                                                                           FragShaderModule(
                                                                                                   VK_NULL_HANDLE),
                                                                                           VertShaderModule(
                                                                                                   VK_NULL_HANDLE)
{

    CreateGraphicsPipeline();
}

SVulkanPipeline::~SVulkanPipeline()
{

}

void SVulkanPipeline::CreateShaderModule(VkShaderModule &OutShaderModule, const std::string &Filename)
{
    std::vector<char> ShaderCode = SVulkanPipeline::ReadFile(Filename);

    VkShaderModuleCreateInfo ShaderModuleCreateInfo;
    SetZeroVulkanStruct(ShaderModuleCreateInfo, VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO);

    ShaderModuleCreateInfo.codeSize = ShaderCode.size();
    ShaderModuleCreateInfo.pCode    = reinterpret_cast<const uint32_t *>(ShaderCode.data());
    VkResult Result = vkCreateShaderModule(Device->GetHandle(), &ShaderModuleCreateInfo, nullptr, &OutShaderModule);
    if (Result != VK_SUCCESS)
    {
        std::cout << "Failed to create shader module\n";
    } else
    {
        std::cout << "Created shader module\n";
    }

}

void SVulkanPipeline::CreateGraphicsPipeline()
{
    CreateShaderModule(VertShaderModule, "../Shaders/vert.spv");
    CreateShaderModule(FragShaderModule, "../Shaders/frag.spv");

    VkPipelineShaderStageCreateInfo VertShaderStageInfo{};
    VertShaderStageInfo.sType  = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    VertShaderStageInfo.stage  = VK_SHADER_STAGE_VERTEX_BIT;
    VertShaderStageInfo.module = VertShaderModule;
    VertShaderStageInfo.pName  = "main";

    VkPipelineShaderStageCreateInfo fragShaderStageInfo{};
    fragShaderStageInfo.sType  = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    fragShaderStageInfo.stage  = VK_SHADER_STAGE_FRAGMENT_BIT;
    fragShaderStageInfo.module = FragShaderModule;
    fragShaderStageInfo.pName  = "main";

    VkPipelineShaderStageCreateInfo ShaderStages[] = {VertShaderStageInfo, fragShaderStageInfo};

    VkPipelineVertexInputStateCreateInfo VertexInputInfo{};
    VertexInputInfo.sType                           = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
    VertexInputInfo.vertexBindingDescriptionCount   = 0;
    VertexInputInfo.vertexAttributeDescriptionCount = 0;

    VkPipelineInputAssemblyStateCreateInfo InputAssembly{};
    InputAssembly.sType                  = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
    InputAssembly.topology               = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
    InputAssembly.primitiveRestartEnable = VK_FALSE;

    VkPipelineViewportStateCreateInfo ViewportState{};
    ViewportState.sType         = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
    ViewportState.viewportCount = 1;
    ViewportState.scissorCount  = 1;

    VkPipelineRasterizationStateCreateInfo Rasterizer{};
    Rasterizer.sType                   = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
    Rasterizer.depthClampEnable        = VK_FALSE;
    Rasterizer.rasterizerDiscardEnable = VK_FALSE;
    Rasterizer.polygonMode             = VK_POLYGON_MODE_FILL;
    Rasterizer.lineWidth               = 1.0f;
    Rasterizer.cullMode                = VK_CULL_MODE_BACK_BIT;
    Rasterizer.frontFace               = VK_FRONT_FACE_CLOCKWISE;
    Rasterizer.depthBiasEnable         = VK_FALSE;

    VkPipelineMultisampleStateCreateInfo Multisampling{};
    Multisampling.sType                = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    Multisampling.sampleShadingEnable  = VK_FALSE;
    Multisampling.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;

    VkPipelineColorBlendAttachmentState ColorBlendAttachment{};
    ColorBlendAttachment.colorWriteMask =
            VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
    ColorBlendAttachment.blendEnable    = VK_FALSE;

    VkPipelineColorBlendStateCreateInfo ColorBlending{};
    ColorBlending.sType           = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    ColorBlending.logicOpEnable   = VK_FALSE;
    ColorBlending.logicOp         = VK_LOGIC_OP_COPY;
    ColorBlending.attachmentCount = 1;
    ColorBlending.pAttachments    = &ColorBlendAttachment;
    ColorBlending.blendConstants[0] = 0.0f;
    ColorBlending.blendConstants[1] = 0.0f;
    ColorBlending.blendConstants[2] = 0.0f;
    ColorBlending.blendConstants[3] = 0.0f;

    std::vector<VkDynamicState>      DynamicStates = {
            VK_DYNAMIC_STATE_VIEWPORT,
            VK_DYNAMIC_STATE_SCISSOR
    };
    VkPipelineDynamicStateCreateInfo DynamicState{};
    DynamicState.sType             = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
    DynamicState.dynamicStateCount = static_cast<uint32_t>(DynamicStates.size());
    DynamicState.pDynamicStates    = DynamicStates.data();

    VkPipelineLayoutCreateInfo PipelineLayoutInfo{};
    PipelineLayoutInfo.sType                  = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    PipelineLayoutInfo.setLayoutCount         = 0;
    PipelineLayoutInfo.pushConstantRangeCount = 0;

    if (vkCreatePipelineLayout(Device->GetHandle(), &PipelineLayoutInfo, nullptr, &PipelineLayout) != VK_SUCCESS)
    {
        throw std::runtime_error("failed to create pipeline layout!");
    }

    VkGraphicsPipelineCreateInfo PipelineInfo{};
    PipelineInfo.sType               = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    PipelineInfo.stageCount          = 2;
    PipelineInfo.pStages             = ShaderStages;
    PipelineInfo.pVertexInputState   = &VertexInputInfo;
    PipelineInfo.pInputAssemblyState = &InputAssembly;
    PipelineInfo.pViewportState      = &ViewportState;
    PipelineInfo.pRasterizationState = &Rasterizer;
    PipelineInfo.pMultisampleState   = &Multisampling;
    PipelineInfo.pDepthStencilState  = nullptr; // Optional
    PipelineInfo.pColorBlendState    = &ColorBlending;
    PipelineInfo.pDynamicState       = &DynamicState;
    PipelineInfo.layout              = PipelineLayout;
    PipelineInfo.renderPass          = Swapchain->RenderPass;
    PipelineInfo.subpass             = 0;
    PipelineInfo.basePipelineHandle  = VK_NULL_HANDLE;
    PipelineInfo.basePipelineIndex   = -1;

    if (vkCreateGraphicsPipelines(Device->GetHandle(), VK_NULL_HANDLE, 1, &PipelineInfo, nullptr, &GraphicsPipeline) != VK_SUCCESS) {
        throw std::runtime_error("failed to create graphics pipeline!");
    }


    vkDestroyShaderModule(Device->GetHandle(), FragShaderModule, nullptr);
    vkDestroyShaderModule(Device->GetHandle(), VertShaderModule, nullptr);
}

std::vector<char> SVulkanPipeline::ReadFile(const std::string &Filename)
{
    std::ifstream File(Filename, std::ios::ate | std::ios::binary);

    if (!File.is_open())
    {
        throw std::runtime_error("failed to open file: !" + Filename);
    }

    uint32            FileSize = (uint32) File.tellg();
    std::vector<char> Buffer(FileSize);

    File.seekg(0);
    File.read(Buffer.data(), FileSize);
    File.close();
    return Buffer;
}

void SVulkanPipeline::Bind(VkCommandBuffer CommandBuffer)
{
    vkCmdBindPipeline(CommandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, GraphicsPipeline);
    VkViewport viewport{};
    viewport.x = 0.0f;
    viewport.y = 0.0f;
    viewport.width = static_cast<float>(Swapchain->ImageExtent.width);
    viewport.height = static_cast<float>(Swapchain->ImageExtent.height);
    viewport.minDepth = 0.0f;
    viewport.maxDepth = 1.0f;
    vkCmdSetViewport(CommandBuffer, 0, 1, &viewport);

    VkRect2D scissor{};
    scissor.offset = {0, 0};
    scissor.extent = Swapchain->ImageExtent;
    vkCmdSetScissor(CommandBuffer, 0, 1, &scissor);

    vkCmdDraw(CommandBuffer, 3, 1, 0, 0);

}





