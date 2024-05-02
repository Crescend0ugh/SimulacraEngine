//
// Created by avsom on 10/23/2023.
//

#pragma once

#include <functional>
#include "SimulacraVulkan.h"
#include "../../../Core/Platform/SimulacraWindowsWindow.h"


struct vulkan_swapchain
{

    vulkan_swapchain(const vulkan_device* device, simulacra::windows::window window);

    ~vulkan_swapchain();

    vulkan_swapchain(const vulkan_swapchain&) = delete;

    vulkan_swapchain& operator=(const vulkan_swapchain&) = delete;

    vulkan_swapchain& operator=(vulkan_swapchain&& other) noexcept;

    uint64 acquire_next_image_index();

    void present();

private:

    [[nodiscard]] VkSurfaceFormatKHR choose_surface_format() const;

    [[nodiscard]] VkPresentModeKHR choose_present_mode() const;

    [[nodiscard]] VkExtent2D choose_extent() const;


    VkSwapchainKHR swapchain_;
    VkSurfaceKHR   surface_;
    vulkan_device* device_;
};
