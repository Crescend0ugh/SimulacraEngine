//
// Created by avsom on 10/23/2023.
//

#pragma once

#include <functional>
#include "SimulacraVulkan.h"


struct vulkan_swapchain {

    vulkan_swapchain(vulkan_device* device, VkSurfaceKHR surface, uint32 width, uint32 height,
                     VkSwapchainKHR old_swapchain = VK_NULL_HANDLE);

    ~vulkan_swapchain();

    vulkan_swapchain(const vulkan_swapchain &) = delete;

    vulkan_swapchain &operator=(const vulkan_swapchain &) = delete;

    vulkan_swapchain &operator=(vulkan_swapchain &&other) noexcept;

    uint64 acquire_next_image_index();

    void present();

private:
    [[nodiscard]] VkSurfaceFormatKHR choose_surface_format() const;

    [[nodiscard]] VkPresentModeKHR choose_present_mode() const;

    [[nodiscard]] VkExtent2D choose_extent(uint32 width, uint32 height) const;

    [[nodiscard]] uint32 choose_min_image_count() const;

    [[nodiscard]] VkSurfaceTransformFlagBitsKHR choose_pre_transform() const;

    [[nodiscard]] VkCompositeAlphaFlagBitsKHR choose_composite_alpha() const;

    [[nodiscard]] std::vector<VkImage> get_swapchain_images();

    [[nodiscard]] std::vector<VkImageView> create_image_views();

    VkSwapchainKHR swapchain_;
    VkSurfaceKHR surface_;
    vulkan_device* device_;
    VkExtent2D extent_;
    VkSurfaceFormatKHR surface_format_;
    std::vector<VkImage> images_;
    std::vector<VkImageView> image_views_;

};
