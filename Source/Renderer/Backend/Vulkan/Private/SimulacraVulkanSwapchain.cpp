//
// Created by avsom on 10/23/2023.
//





#include "SimulacraVulkanSwapchain.h"
#include <algorithm>
#include "SimulacraVulkanDevice.h"
#include "SimulacraVulkanRenderpass.h"


vulkan_swapchain::vulkan_swapchain(vulkan_device* device, VkSurfaceKHR surface, uint32 width, uint32 height,
                                   VkSwapchainKHR old_swapchain) : device_(device), surface_(surface),
                                                                   swapchain_(VK_NULL_HANDLE),
                                                                   surface_format_({}), extent_({})
{


    VkSwapchainCreateInfoKHR swapchain_create_info{};

    swapchain_create_info.sType            = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    swapchain_create_info.surface          = surface_;
    swapchain_create_info.minImageCount    = choose_min_image_count();
    swapchain_create_info.imageFormat      = choose_surface_format().format;
    swapchain_create_info.imageColorSpace  = choose_surface_format().colorSpace;
    swapchain_create_info.imageExtent      = choose_extent(width, height);
    swapchain_create_info.imageArrayLayers = 1;
    swapchain_create_info.imageUsage       = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
    swapchain_create_info.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
    swapchain_create_info.preTransform     = choose_pre_transform();
    swapchain_create_info.compositeAlpha   = choose_composite_alpha();
    swapchain_create_info.presentMode      = choose_present_mode();
    swapchain_create_info.clipped          = VK_TRUE;
    swapchain_create_info.oldSwapchain     = old_swapchain;

    VkResult result = vkCreateSwapchainKHR(device_->logical_handle(), &swapchain_create_info, nullptr, &swapchain_);
    std::cout<<(result != VK_SUCCESS ? "Failed to create swapchain\n" : "Created swapchain\n");

    images_ = get_swapchain_images();
    image_views_ = create_image_views();

    VkAttachmentDescription attachment_description;
    attachment_description.format = surface_format_.format;
    attachment_description.samples = VK_SAMPLE_COUNT_1_BIT;
    attachment_description.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
    attachment_description.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
    attachment_description.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    attachment_description.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    attachment_description.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    attachment_description.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

    VkAttachmentReference color_attachment_reference {};
    color_attachment_reference.attachment = 0;
    color_attachment_reference.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkSubpassDescription subpass_description {};
    subpass_description.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass_description.colorAttachmentCount = 1;
    subpass_description.pColorAttachments = &color_attachment_reference;

    VkRenderPassCreateInfo render_pass_create_info {};
    render_pass_create_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    render_pass_create_info.attachmentCount = 1;
    render_pass_create_info.pAttachments = &attachment_description;
    render_pass_create_info.subpassCount = 1;
    render_pass_create_info.pSubpasses = &subpass_description;

    VkRenderPass render_pass {};

    if(VK_SUCCESS != vkCreateRenderPass(device_->logical_handle(), &render_pass_create_info, nullptr, &render_pass))
    {
        std::cout << "failed to create render pass\n";
    }

    else
    {
        std::cout << "Created render pass\n";
    }

}

vulkan_swapchain& vulkan_swapchain::operator=(vulkan_swapchain&& other) noexcept
{
    this->surface_   = other.surface_;
    this->device_    = other.device_;
    this->swapchain_ = other.swapchain_;
    other.surface_   = VK_NULL_HANDLE;
    other.device_    = nullptr;
    other.swapchain_ = VK_NULL_HANDLE;
    return *this;
}

VkSurfaceFormatKHR
vulkan_swapchain::choose_surface_format() const
{
    uint32 surface_format_count = 0;

    vkGetPhysicalDeviceSurfaceFormatsKHR(device_->physical_handle(), surface_, &surface_format_count, nullptr);

    std::vector<VkSurfaceFormatKHR> surface_formats(surface_format_count);
    vkGetPhysicalDeviceSurfaceFormatsKHR(device_->physical_handle(), surface_, &surface_format_count,
                                         surface_formats.data());

    for (const VkSurfaceFormatKHR& surface_format: surface_formats)
    {
        if ((surface_format.colorSpace == VK_COLORSPACE_SRGB_NONLINEAR_KHR) &&
            (surface_format.format == VK_FORMAT_B8G8R8A8_SRGB))
        {
            return surface_format;
        }
    }

    return surface_formats[0];
}

VkPresentModeKHR
vulkan_swapchain::choose_present_mode() const
{
    uint32 present_mode_count = 0;
    vkGetPhysicalDeviceSurfacePresentModesKHR(device_->physical_handle(), surface_, &present_mode_count, nullptr);

    std::vector<VkPresentModeKHR> present_modes(present_mode_count);
    vkGetPhysicalDeviceSurfacePresentModesKHR(device_->physical_handle(), surface_, &present_mode_count,
                                              present_modes.data());

    for (const VkPresentModeKHR& present_mode: present_modes)
    {
        if (present_mode == VK_PRESENT_MODE_MAILBOX_KHR)
        {
            return present_mode;
        }
    }

    return VK_PRESENT_MODE_FIFO_KHR;
}

VkExtent2D vulkan_swapchain::choose_extent(uint32 width, uint32 height) const
{
    VkSurfaceCapabilitiesKHR surface_capabilities{};
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device_->physical_handle(), surface_, &surface_capabilities);

    return surface_capabilities.currentExtent.width != UINT32_MAX ? surface_capabilities.currentExtent : VkExtent2D{
            width, height};
}

uint64 vulkan_swapchain::acquire_next_image_index()
{
    uint32 image_index = 0;

    if (VkResult result = vkAcquireNextImageKHR(device_->logical_handle(), swapchain_, UINT_FAST64_MAX,
                                                VK_NULL_HANDLE, VK_NULL_HANDLE,
                                                &image_index); result != VK_SUCCESS)
    {
        if (result == VK_SUBOPTIMAL_KHR || result == VK_ERROR_OUT_OF_DATE_KHR)
        {
            std::cerr<<"Failed to acquire next image\n";
            terminate();
        }
    }
    return image_index;
}

uint32 vulkan_swapchain::choose_min_image_count() const
{

    uint32                   desired_image_count = 3;
    VkSurfaceCapabilitiesKHR surface_capabilities{};
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device_->physical_handle(), surface_, &surface_capabilities);

    return surface_capabilities.maxImageCount == 0 ? desired_image_count : std::clamp(desired_image_count,
                                                                                      surface_capabilities.minImageCount,
                                                                                      surface_capabilities.maxImageCount);
}

VkSurfaceTransformFlagBitsKHR vulkan_swapchain::choose_pre_transform() const
{
    VkSurfaceCapabilitiesKHR surface_capabilities{};
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device_->physical_handle(), surface_, &surface_capabilities);

    return surface_capabilities.supportedTransforms & VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR
           ? VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR : surface_capabilities.currentTransform;

}

VkCompositeAlphaFlagBitsKHR vulkan_swapchain::choose_composite_alpha() const
{
    VkSurfaceCapabilitiesKHR surface_capabilities;
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device_->physical_handle(), surface_, &surface_capabilities);

    return surface_capabilities.supportedCompositeAlpha & VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR
           ? VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR : VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR;
}

vulkan_swapchain::~vulkan_swapchain()
{
    vkDestroySwapchainKHR(device_->logical_handle(), swapchain_, nullptr);
}

void vulkan_swapchain::present()
{

}

std::vector<VkImage> vulkan_swapchain::get_swapchain_images()
{
    uint32 swapchain_image_count = 0;

    VkResult result = vkGetSwapchainImagesKHR(device_->logical_handle(), swapchain_,
                                              &swapchain_image_count, nullptr);

    if (swapchain_image_count == 0 || result != VK_SUCCESS)
    {
        std::cerr<<"Failed to get swapchain images\n";
        terminate();
    }
    std::vector<VkImage> swapchain_images(swapchain_image_count);
    result = vkGetSwapchainImagesKHR(device_->logical_handle(), swapchain_, &swapchain_image_count,
                                     swapchain_images.data());

    if (swapchain_image_count == 0 || result != VK_SUCCESS)
    {
        std::cerr<<"Failed to get swapchain images\n";
        terminate();
    } else
    {
        std::cout<<"Obtained swapchain images\n";
    }
    return swapchain_images;
}

std::vector<VkImageView> vulkan_swapchain::create_image_views()
{
    std::vector<VkImageView> image_views(images_.size());
    image_views.resize(images_.size());

    for (int i = 0; i < image_views.size(); i++)
    {
        VkImage    & image      = images_[i];
        VkImageView& image_view = image_views[i];

        VkImageViewCreateInfo image_view_create_info{};
        image_view_create_info.sType    = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        image_view_create_info.image    = image;
        image_view_create_info.viewType = VK_IMAGE_VIEW_TYPE_2D;
        image_view_create_info.format   = surface_format_.format;
        image_view_create_info.components =
                {
                        VK_COMPONENT_SWIZZLE_IDENTITY,
                        VK_COMPONENT_SWIZZLE_IDENTITY,
                        VK_COMPONENT_SWIZZLE_IDENTITY,
                        VK_COMPONENT_SWIZZLE_IDENTITY
                };
        image_view_create_info.subresourceRange =
                {
                        VK_IMAGE_ASPECT_COLOR_BIT,
                        0,
                        1,
                        0,
                        1
                };

        VkResult result = vkCreateImageView(device_->logical_handle(), &image_view_create_info, nullptr, &image_view);

        if(result != VK_SUCCESS)
        {
            std::cerr << "Failed to create image view\n";
            terminate();
        }

    }
    std::cout << "Created image views\n";
    return image_views;
}