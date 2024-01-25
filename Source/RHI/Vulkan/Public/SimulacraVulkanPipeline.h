//
// Created by avsom on 1/5/2024.
//

#pragma once

#include "SimulacraVulkan.h"

class SVulkanPipeline
{

public:

     SVulkanPipeline(SVulkanDevice *InDevice, SVulkanSwapchain *InSwapchain);

    ~SVulkanPipeline();

    VkPipeline GetHandle()
    { return GraphicsPipeline; }

    VkRect2D& GetScissor() {return Scissor;}



    VkViewport& GetViewport() { return Viewport; }


protected:

    void CreateShaderModule(VkShaderModule &OutShaderModule, const std::string &Filename);

    void CreateGraphicsPipeline();

    static std::vector<char> ReadFile(const std::string &Filename);


private:

    SVulkanDevice    *Device;
    SVulkanSwapchain *Swapchain;
    VkPipeline       GraphicsPipeline;
    VkViewport       Viewport;
    VkRect2D         Scissor;
    VkPipelineLayout PipelineLayout;
    VkShaderModule   VertShaderModule;
    VkShaderModule   FragShaderModule;
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

