//
// Created by avsom on 9/23/2024.
//

#include "VulkanDeferredRenderer.h"

VulkanDeferredRenderer::VulkanDeferredRenderer()
{
    Simulacra::windows::Window window = Simulacra::windows::create_window(1000,800, "Vulkan Test Deferred Renderer Window");
    rhi.init(window.hwnd_);
}

VulkanDeferredRenderer::~VulkanDeferredRenderer()
{
    rhi.shutdown();
}
