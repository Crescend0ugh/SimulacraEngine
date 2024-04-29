//
// Created by avsom on 10/23/2023.
//

#pragma once


#include "SimulacraVulkanQueue.h"


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

    void select_physical_device(const vulkan_instance& instance);
    void initialize_logical_device();

private:

    VkDevice device_;
    VkPhysicalDevice physical_device_;

};


