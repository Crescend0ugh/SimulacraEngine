//
// Created by avsom on 1/5/2024.
//

#include "../Public/SimulacraVulkanPipeline.h"

SVulkanPipeline::SVulkanPipeline()
{

}

SVulkanPipeline::~SVulkanPipeline()
{

}

void SVulkanPipeline::CreateShaderModule()
{
    VkShaderModuleCreateInfo CreateInfo;
    SetZeroVulkanStruct(CreateInfo, VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO);

    VkResult Result = vkCreateShaderModule(Device->GetHandle(), )
}
