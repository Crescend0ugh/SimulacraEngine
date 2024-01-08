//
// Created by avsom on 1/5/2024.
//

#pragma once

#include "SimulacraVulkan.h"

class SVulkanShader
{

public:

    SVulkanShader(const void* ShaderCode, uint32 ShaderCodeSize);
    ~SVulkanShader();


private:

    VkShaderModule ShaderModule;


};
