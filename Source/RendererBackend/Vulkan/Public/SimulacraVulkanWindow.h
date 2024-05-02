//
// Created by avsom on 5/1/2024.
//

#pragma once


#include "../../../Core/Platform/SimulacraWindowsWindow.h"
#include "SimulacraVulkanSurface.h"

class vulkan_window
{

public:

    vulkan_window(simulacra::windows::window& window);

    ~vulkan_window();

    vulkan_window(const vulkan_window&) = delete;

    vulkan_window& operator=(const vulkan_window&) = delete;

    [[nodiscard]] simulacra::windows::window& native_window() const
    { return window_; }

    [[nodiscard]] const vulkan_surface& surface() const
    { return surface_; }

private:

    vulkan_surface surface_;
    simulacra::windows::window& window_;
};
