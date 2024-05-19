//
// Created by avsom on 5/7/2024.
//

#pragma once

#include "SimulacraVulkan.h"

struct vulkan_shader_module {

    vulkan_shader_module(vulkan_device *device, const std::vector<byte>& byte_code);

    ~vulkan_shader_module();

    VkShaderModule    shader_module_;
    std::vector<byte> byte_code_;
    vulkan_device    *device_;

};

