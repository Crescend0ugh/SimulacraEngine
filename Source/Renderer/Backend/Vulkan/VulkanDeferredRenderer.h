//
// Created by avsom on 9/23/2024.
//

#pragma once
#include <VulkanRHI.h>

class VulkanDeferredRenderer
{
    VulkanDeferredRenderer();
    ~VulkanDeferredRenderer();

    VulkanRHI rhi;
    Framebuffer fb;

};