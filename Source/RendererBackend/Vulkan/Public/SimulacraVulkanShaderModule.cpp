//
// Created by avsom on 5/7/2024.
//

#include "SimulacraVulkanShaderModule.h"
#include "SimulacraVulkanDevice.h"

vulkan_shader_module::vulkan_shader_module(vulkan_device *device, const std::vector<byte>& byte_code) : device_(device), byte_code_(byte_code), shader_module_(VK_NULL_HANDLE)
{
    VkShaderModuleCreateInfo shader_module_create_info {};
    shader_module_create_info.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    shader_module_create_info.codeSize = byte_code_.size();
    shader_module_create_info.pCode = reinterpret_cast<uint32*>(byte_code_.data());

    VkResult result = vkCreateShaderModule(device_->logical_handle(), &shader_module_create_info, nullptr, &shader_module_);

    if(result != VK_SUCCESS)
    {
        std::cerr << "Failed to create shader module\n";
        terminate();
    }

    else
    {
        std::cout << "created shader module\n";
    }

}

vulkan_shader_module::~vulkan_shader_module() {

    //TODO ADD DEVICE REF
    vkDestroyShaderModule(nullptr, shader_module_, nullptr);
}
    