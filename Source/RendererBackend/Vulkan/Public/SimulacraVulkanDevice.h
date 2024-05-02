//
// Created by avsom on 10/23/2023.
//

#pragma once


#include <optional>
#include <functional>
#include "SimulacraVulkanQueue.h"


class vulkan_device {

public:

    vulkan_device();
    ~vulkan_device();

    vulkan_device(const vulkan_device&) = delete;
    vulkan_device& operator=(const vulkan_device&) = delete;

    void query_supported_extensions();

    void query_supported_features();

    void select_physical_device(const vulkan_instance &instance);

    void initialize_logical_device(VkSurfaceKHR surface);

    [[nodiscard]] VkDevice logical_handle() const
    { return logical_device_; };

    [[nodiscard]] VkPhysicalDevice physical_handle() const
    { return physical_device_; }

    [[nodiscard]] const vulkan_queue &graphics_queue() const
    { return graphics_queue_; }

    [[nodiscard]] const vulkan_queue &present_queue() const
    { return present_queue_; }

    [[nodiscard]] const vulkan_queue &compute_queue() const
    { return compute_queue_; }

    [[nodiscard]] const vulkan_queue &transfer_queue() const
    { return transfer_queue_; }

private:

    std::optional<uint32> find_queue_family_index(const std::function<bool(const uint32&, const VkQueueFamilyProperties&)> &criteria);

    VkDevice         logical_device_;
    VkPhysicalDevice physical_device_;
    vulkan_queue     graphics_queue_;
    vulkan_queue     present_queue_;
    vulkan_queue     compute_queue_;
    vulkan_queue     transfer_queue_;

};


