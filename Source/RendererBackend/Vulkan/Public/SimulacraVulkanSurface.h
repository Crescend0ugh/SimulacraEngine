//
// Created by avsom on 5/1/2024.
//

#pragma once

#include "SimulacraVulkan.h"
#include "../../../Core/Platform/SimulacraWindowsWindow.h"

class vulkan_surface
{

public:

    vulkan_surface(VkInstance instance, simulacra::windows::window& window);

    ~vulkan_surface();

    [[nodiscard]] inline VkSurfaceKHR get_handle() const { return surface_; }

private:

    VkSurfaceKHR surface_;
    VkInstance   instance_;
};


