//
// Created by avsom on 5/31/2024.
//

#pragma once

#include "SimulacraVulkan.h"

struct attachment
{
    VkFormat              format_;
    VkSampleCountFlagBits sample_count_;
    VkAttachmentLoadOp    load_op_;
    VkAttachmentStoreOp   store_op_;
    VkAttachmentLoadOp    stencil_load_op_;
    VkAttachmentStoreOp   stencil_store_op_;
    VkImageLayout         initial_layout_;
    VkImageLayout         final_layout_;
};


struct render_pass
{
    VkRenderPass render_pass;
};