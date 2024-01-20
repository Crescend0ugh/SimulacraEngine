//
// Created by avsom on 1/5/2024.
//

#pragma once

#include "SimulacraVulkan.h"

class SVulkanPipeline
{

public:

    explicit SVulkanPipeline(SVulkanDevice *InDevice, SVulkanSwapchain *InSwapchain);

    ~SVulkanPipeline();

protected:

    void CreateShaderModule(VkShaderModule &OutShaderModule, const std::string &Filename);

    void CreateGraphicsPipeline();

    void Bind(VkCommandBuffer CommandBuffer);

    static std::vector<char> ReadFile(const std::string &Filename);

private:

    SVulkanDevice   *Device;
    SVulkanSwapchain *Swapchain;
    VkPipeline       GraphicsPipeline;
    VkRenderPass     RenderPass;
    VkPipelineLayout PipelineLayout;
    VkShaderModule VertShaderModule;
    VkShaderModule FragShaderModule;
};


struct SVulkanPipelineVertexInput
{
};

struct SVulkanPipelineInputAssembly
{
    VkPrimitiveTopology Topology;
    VkBool32            PrimitiveRestartEnable;

};


class SVulkanGraphicsPipelineDescription
{


};

