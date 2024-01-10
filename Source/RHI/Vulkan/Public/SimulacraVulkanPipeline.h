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

    static std::vector<char> ReadFile(const std::string &Filename);

private:

    SVulkanDevice   *Device;
    SVulkanSwapchain *Swapchain;
    VkPipeline     Pipeline;
    VkShaderModule VertShaderModule;
    VkShaderModule FragShaderModule;
};
