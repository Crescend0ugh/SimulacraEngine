//
// Created by avsom on 5/7/2024.
//

#include "SimulacraVulkanShader.h"

vulkan_shader::vulkan_shader() {

}

vulkan_shader::~vulkan_shader() {

    //TODO ADD DEVICE REF
    vkDestroyShaderModule(nullptr, shader_module_, nullptr);
}
