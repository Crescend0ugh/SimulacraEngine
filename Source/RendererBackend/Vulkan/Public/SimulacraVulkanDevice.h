//
// Created by avsom on 10/23/2023.
//

#pragma once


#include "SimulacraVulkan.h"
#include "SimulacraVulkanQueue.h"
#include "SimulacraVulkanInstance.h"

class vulkan_device
{

public:
    vulkan_device();
    ~vulkan_device();

    void query_supported_extensions();
    void query_supported_features();

    vulkan_queue graphics_queue_;
    vulkan_queue present_queue_;
    vulkan_queue compute_queue_;
    vulkan_queue transfer_queue_;

    void select_phsyical_device(const vulkan_instance& instance);
    void intialize_logical_device();

private:

    VkDevice device_;
    VkPhysicalDevice physical_device_;

};


