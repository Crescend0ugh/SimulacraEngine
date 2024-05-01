//
// Created by avsom on 1/8/2024.
//

#pragma once

#include "SimulacraVulkan.h"
#include "SimulacraVulkanExtensions.h"



struct vulkan_instance
{

    vulkan_instance();
    ~vulkan_instance();

    [[nodiscard]] std::vector<vulkan_instance_extension> query_extension_support();
    [[nodiscard]] VkInstance get_handle() const { return instance_; }
private:

    VkInstance instance_;
    std::vector<const char*> instance_extensions;
    std::vector<const char*> instance_layers;
};