//
// Created by avsom on 10/23/2023.
//

#pragma once


#include "SimulacraVulkan.h"


struct vulkan_queue
{
    vulkan_queue() = default;
    vulkan_queue(VkDevice device, uint32 family_index, uint32 queue_index);
    ~vulkan_queue() = default;

    [[nodiscard]] VkQueue handle()       const { return queue_; }
    [[nodiscard]] uint32  family_index() const { return family_index_; }
    [[nodiscard]] uint32  queue_index()  const { return queue_index_; }

private:
    VkQueue queue_;
    uint32  family_index_;
    uint32  queue_index_;
    //TODO add device get_handle
};
