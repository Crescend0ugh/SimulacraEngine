//
// Created by avsom on 1/5/2024.
//

#pragma once

#include "SimulacraVulkan.h"

class SVulkanPipeline
{

public:

    SVulkanPipeline(SVulkanDevice* InDevice);
    ~SVulkanPipeline();

protected:

    void CreateShaderModule(VkShaderModule& OutShaderModule, const std::string &Filename);
    void CreateGraphicsPipeline();
    static std::vector<char> ReadFile(const std::string& Filename);

private:

    SVulkanDevice* Device;
    VkPipeline     Pipeline;
    VkShaderModule VertShaderModule;
    VkShaderModule FragShaderModule;
};
