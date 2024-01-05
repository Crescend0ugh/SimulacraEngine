//
// Created by avsom on 1/5/2024.
//

#pragma once

#include "SimulacraVulkan.h"

class SVulkanPipeline
{

public:

    SVulkanPipeline();
    ~SVulkanPipeline();

protected:

    void CreateShaderModule();

private:

    SVulkanDevice* Device;

    std::vector<VkShaderModule> ShaderModules;
};
