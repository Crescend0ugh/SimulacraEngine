//
// Created by avsom on 1/5/2024.
//

#include <fstream>

#include "../Public/SimulacraVulkanPipeline.h"

SVulkanPipeline::SVulkanPipeline(SVulkanDevice *InDevice, SVulkanSwapchain* InSwapchain) : Device(InDevice), Swapchain(InSwapchain), Pipeline(VK_NULL_HANDLE),
                                                            FragShaderModule(VK_NULL_HANDLE),
                                                            VertShaderModule(VK_NULL_HANDLE)
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

    VkPipelineShaderStageCreateInfo VertShaderStageCreateInfo;
    SetZeroVulkanStruct(VertShaderStageCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO);

    VertShaderStageCreateInfo.stage  = VK_SHADER_STAGE_VERTEX_BIT;
    VertShaderStageCreateInfo.module = VertShaderModule;
    VertShaderStageCreateInfo.pName  = "main";


    VkPipelineShaderStageCreateInfo FragShaderStageCreateInfo;
    SetZeroVulkanStruct(FragShaderStageCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO);

    FragShaderStageCreateInfo.stage  = VK_SHADER_STAGE_FRAGMENT_BIT;
    FragShaderStageCreateInfo.module = FragShaderModule;
    FragShaderStageCreateInfo.pName  = "main";

    VkPipelineShaderStageCreateInfo ShaderStages[] = {VertShaderStageCreateInfo, FragShaderStageCreateInfo};

    std::vector<VkDynamicState> DynamicStates = {
            VK_DYNAMIC_STATE_VIEWPORT,
            VK_DYNAMIC_STATE_SCISSOR
    };

    VkPipelineDynamicStateCreateInfo DynamicStateCreateInfo;
    SetZeroVulkanStruct(DynamicStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO);
    DynamicStateCreateInfo.dynamicStateCount = DynamicStates.size();
    DynamicStateCreateInfo.pDynamicStates    = DynamicStates.data();

    VkPipelineVertexInputStateCreateInfo VertexInputCreationInfo;
    SetZeroVulkanStruct(VertexInputCreationInfo, VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO);
    VertexInputCreationInfo.vertexBindingDescriptionCount   = 0;
    VertexInputCreationInfo.pVertexBindingDescriptions      = nullptr;
    VertexInputCreationInfo.vertexAttributeDescriptionCount = 0;
    VertexInputCreationInfo.pVertexBindingDescriptions      = nullptr;

    VkPipelineInputAssemblyStateCreateInfo InputAssemblyCreateInfo;
    SetZeroVulkanStruct(InputAssemblyCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO);
    InputAssemblyCreateInfo.topology               = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
    InputAssemblyCreateInfo.primitiveRestartEnable = VK_FALSE;

    VkViewport Viewport;
    Viewport.x        = 0.0f;
    Viewport.y        = 0.0f;
    Viewport.width    = 100.0f;
    Viewport.height   = 100.0f;
    Viewport.minDepth = 0.0f;
    Viewport.maxDepth = 1.0f;

    VkRect2D Scissor{};
    Scissor.offset = {0, 0};
    Scissor.extent = VkExtent2D{100, 100};

    VkPipelineViewportStateCreateInfo ViewportStateCreateInfo;
    SetZeroVulkanStruct(ViewportStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO);
    ViewportStateCreateInfo.viewportCount = 1;
    ViewportStateCreateInfo.scissorCount  = 1;
    ViewportStateCreateInfo.pViewports    = &Viewport;
    ViewportStateCreateInfo.pScissors     = &Scissor;

    VkPipelineRasterizationStateCreateInfo RasterizationStateCreateInfo;
    SetZeroVulkanStruct(RasterizationStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO);
    RasterizationStateCreateInfo.depthClampEnable        = VK_FALSE;
    RasterizationStateCreateInfo.rasterizerDiscardEnable = VK_FALSE;
    RasterizationStateCreateInfo.polygonMode             = VK_POLYGON_MODE_FILL;
    RasterizationStateCreateInfo.lineWidth               = 1.0f;
    RasterizationStateCreateInfo.cullMode                = VK_CULL_MODE_BACK_BIT;
    RasterizationStateCreateInfo.frontFace               = VK_FRONT_FACE_CLOCKWISE;
    RasterizationStateCreateInfo.depthBiasEnable         = VK_FALSE;
    RasterizationStateCreateInfo.depthBiasConstantFactor = 0.0f;
    RasterizationStateCreateInfo.depthBiasClamp          = 0.0f;
    RasterizationStateCreateInfo.depthBiasSlopeFactor    = 0.0f;

    VkPipelineMultisampleStateCreateInfo MultisampleStateCreateInfo;
    SetZeroVulkanStruct(RasterizationStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO);
    MultisampleStateCreateInfo.sType                 = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    MultisampleStateCreateInfo.sampleShadingEnable   = VK_FALSE;
    MultisampleStateCreateInfo.rasterizationSamples  = VK_SAMPLE_COUNT_1_BIT;
    MultisampleStateCreateInfo.minSampleShading      = 1.0f;
    MultisampleStateCreateInfo.pSampleMask           = nullptr;
    MultisampleStateCreateInfo.alphaToCoverageEnable = VK_FALSE;
    MultisampleStateCreateInfo.alphaToOneEnable      = VK_FALSE;

    VkPipelineColorBlendAttachmentState ColorBlendAttachmentState;
    ColorBlendAttachmentState.blendEnable         = VK_TRUE;
    ColorBlendAttachmentState.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
    ColorBlendAttachmentState.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
    ColorBlendAttachmentState.colorBlendOp        = VK_BLEND_OP_ADD;
    ColorBlendAttachmentState.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE;
    ColorBlendAttachmentState.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;
    ColorBlendAttachmentState.alphaBlendOp        = VK_BLEND_OP_ADD;

    VkPipelineColorBlendStateCreateInfo ColorBlendStateCreateInfo;
    SetZeroVulkanStruct(ColorBlendStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO);
    ColorBlendStateCreateInfo.sType           = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    ColorBlendStateCreateInfo.logicOpEnable   = VK_FALSE;
    ColorBlendStateCreateInfo.logicOp         = VK_LOGIC_OP_COPY;
    ColorBlendStateCreateInfo.attachmentCount = 1;
    ColorBlendStateCreateInfo.pAttachments    = &ColorBlendAttachmentState;
    ColorBlendStateCreateInfo.blendConstants[0] = 0.0f;
    ColorBlendStateCreateInfo.blendConstants[1] = 0.0f;
    ColorBlendStateCreateInfo.blendConstants[2] = 0.0f;
    ColorBlendStateCreateInfo.blendConstants[3] = 0.0f;

    VkPipelineLayout PipelineLayout;
    VkRenderPass     RenderPass;

    VkPipelineLayoutCreateInfo PipelineLayoutCreateInfo;
    SetZeroVulkanStruct(PipelineLayoutCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO);
    PipelineLayoutCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    PipelineLayoutCreateInfo.setLayoutCount = 0; // Optional
    PipelineLayoutCreateInfo.pSetLayouts = nullptr; // Optional
    PipelineLayoutCreateInfo.pushConstantRangeCount = 0; // Optional
    PipelineLayoutCreateInfo.pPushConstantRanges = nullptr; // Optional

    VkAttachmentDescription ColorAttachment;
    ColorAttachment.format         = Swapchain->SurfaceFormat.format;
    ColorAttachment.samples        = VK_SAMPLE_COUNT_1_BIT;
    ColorAttachment.loadOp         = VK_ATTACHMENT_LOAD_OP_CLEAR;
    ColorAttachment.storeOp        = VK_ATTACHMENT_STORE_OP_STORE;
    ColorAttachment.stencilLoadOp  = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    ColorAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    ColorAttachment.initialLayout  = VK_IMAGE_LAYOUT_UNDEFINED;
    ColorAttachment.finalLayout    = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

    VkAttachmentReference ColorAttachmentReference;
    ColorAttachmentReference.attachment = 0;
    ColorAttachmentReference.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkSubpassDescription Subpass{};
    Subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
    Subpass.colorAttachmentCount = 1;
    Subpass.pColorAttachments = &ColorAttachmentReference;

    VkRenderPassCreateInfo RenderPassCreateInfo;
    SetZeroVulkanStruct(RenderPassCreateInfo, VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO);
    RenderPassCreateInfo.attachmentCount = 1;
    RenderPassCreateInfo.pAttachments = &ColorAttachment;
    RenderPassCreateInfo.subpassCount = 1;
    RenderPassCreateInfo.pSubpasses = &Subpass;


    VkResult Result = vkCreatePipelineLayout(Device->GetHandle(), &PipelineLayoutCreateInfo, nullptr, &PipelineLayout);
    if(Result != VK_SUCCESS)
    {
        std::cout << "Failed to create pipeline layout\n";
    }

    Result = vkCreateRenderPass(Device->GetHandle(), &RenderPassCreateInfo, nullptr, &RenderPass);

    if(Result != VK_SUCCESS)
    {
        std::cout << "Failed to create render pass\n";
    }

    VkGraphicsPipelineCreateInfo GraphicsPipelineCreateInfo;
    SetZeroVulkanStruct(PipelineLayoutCreateInfo, VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO);
    GraphicsPipelineCreateInfo.stageCount = 2;
    GraphicsPipelineCreateInfo.pStages = ShaderStages;
    GraphicsPipelineCreateInfo.pVertexInputState = &VertexInputCreationInfo;
    GraphicsPipelineCreateInfo.pInputAssemblyState = &InputAssemblyCreateInfo;
    GraphicsPipelineCreateInfo.pViewportState = &ViewportStateCreateInfo;
    GraphicsPipelineCreateInfo.pRasterizationState = &RasterizationStateCreateInfo;
    GraphicsPipelineCreateInfo.pMultisampleState = &MultisampleStateCreateInfo;
    GraphicsPipelineCreateInfo.pDepthStencilState = nullptr; // Optional
    GraphicsPipelineCreateInfo.pColorBlendState = &ColorBlendStateCreateInfo;
    GraphicsPipelineCreateInfo.pDynamicState = &DynamicStateCreateInfo;
    GraphicsPipelineCreateInfo.layout = PipelineLayout;
    GraphicsPipelineCreateInfo.renderPass = RenderPass;
    GraphicsPipelineCreateInfo.subpass =0;
    GraphicsPipelineCreateInfo.basePipelineHandle = VK_NULL_HANDLE;
    GraphicsPipelineCreateInfo.basePipelineIndex = -1;

    Result = vkCreateGraphicsPipelines(Device->GetHandle(), VK_NULL_HANDLE, 1, &GraphicsPipelineCreateInfo, nullptr, &Pipeline);


    vkDestroyShaderModule(Device->GetHandle(), VertShaderModule, nullptr);
    vkDestroyShaderModule(Device->GetHandle(), FragShaderModule, nullptr);
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

