//
// Created by avsom on 5/7/2024.
//

#pragma once

#include "SimulacraVulkan.h"

struct vulkan_shader
{

    vulkan_shader();
    ~vulkan_shader();

    VkShaderModule shader_module_;
    std::vector<char> byte_code_;


};

