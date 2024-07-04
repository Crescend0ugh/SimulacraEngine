//
// Created by avsom on 6/5/2024.
//

#include <set>
#include <vulkan/vulkan_core.h>
#include "SimulacraVulkan.h"

void VulkanRenderer::init()
{
    create_instance();
    select_physical_device();
    create_device();
    create_command_pool(graphics_queue_.queue_family_index_);

}

void VulkanRenderer::shutdown()
{

    release_device();
    release_instance();
}

void VulkanRenderer::create_instance()
{
    VkApplicationInfo application_info{};
    application_info.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    application_info.pApplicationName   = "Vulkan Application";
    application_info.applicationVersion = VK_MAKE_VERSION(0, 1, 0);
    application_info.pEngineName        = "Simulacra Engine";
    application_info.engineVersion      = VK_MAKE_VERSION(0, 1, 0);
    application_info.apiVersion         = VK_API_VERSION_1_3;

    uint32 instance_extension_count = 0;
    VK_ASSERT_SUCCESS(vkEnumerateInstanceExtensionProperties(nullptr, &instance_extension_count, nullptr))

    if (instance_extension_count == 0) {
        printf("failed to retrieve instance extensions!");
        terminate();
    }

    std::vector<VkExtensionProperties> supported_extensions(instance_extension_count);
    std::unordered_set<const char*>    supported_extension_names;

    VK_ASSERT_SUCCESS(
            vkEnumerateInstanceExtensionProperties(nullptr, &instance_extension_count, supported_extensions.data()));


    for (const VkExtensionProperties &properties: supported_extensions) {
        supported_extension_names.emplace(properties.extensionName);
    }


    VkInstanceCreateInfo instance_create_info{};
    instance_create_info.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instance_create_info.enabledExtensionCount   = requested_instance_extensions_.size();
    instance_create_info.enabledLayerCount       = 0;
    instance_create_info.ppEnabledExtensionNames = requested_instance_extensions_.data();
    instance_create_info.ppEnabledLayerNames     = nullptr;

    VK_ASSERT_SUCCESS(vkCreateInstance(&instance_create_info, nullptr, &instance_))
}

void VulkanRenderer::release_instance()
{
    vkDestroyInstance(instance_, nullptr);
}

void VulkanRenderer::select_physical_device()
{
    uint32 physical_device_count;
    VK_ASSERT_SUCCESS(vkEnumeratePhysicalDevices(instance_, &physical_device_count, nullptr))

    std::vector<VkPhysicalDevice> physical_devices(physical_device_count);
    VK_ASSERT_SUCCESS(vkEnumeratePhysicalDevices(instance_, &physical_device_count, physical_devices.data()))

    VkPhysicalDevice selected_device = VK_NULL_HANDLE;

    for (const VkPhysicalDevice &physical_device: physical_devices) {
        VkPhysicalDeviceProperties PhysicalDeviceProperties;
        vkGetPhysicalDeviceProperties(physical_device, &PhysicalDeviceProperties);
        if (PhysicalDeviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
            selected_device = physical_device;
        }
    }

    if (selected_device == VK_NULL_HANDLE) {
        selected_device = physical_devices[0];
    }

    device_.physical_device_ = selected_device;
}

void VulkanRenderer::create_device()
{

    std::optional<uint32> graphics_queue_family_index;
    std::optional<uint32> present_queue_family_index;
    std::optional<uint32> compute_queue_family_index;
    std::optional<uint32> transfer_queue_family_index;

    uint32 queue_family_count = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device_.physical_device_, &queue_family_count, nullptr);

    std::vector<VkQueueFamilyProperties> queue_families(queue_family_count);

    vkGetPhysicalDeviceQueueFamilyProperties(device_.physical_device_, &queue_family_count, queue_families.data());

    for (int index = 0; index < queue_families.size(); index++) {
        VkQueueFamilyProperties queue_family = queue_families[index];

        if ((queue_family.queueFlags & VK_QUEUE_GRAPHICS_BIT) == VK_QUEUE_GRAPHICS_BIT) {
            graphics_queue_family_index = index;
        } else if ((queue_family.queueFlags & VK_QUEUE_COMPUTE_BIT) == VK_QUEUE_COMPUTE_BIT) {
            compute_queue_family_index = index;
        } else if ((queue_family.queueFlags & VK_QUEUE_TRANSFER_BIT) == VK_QUEUE_TRANSFER_BIT) {
            transfer_queue_family_index = index;
        }

    }

    assert(graphics_queue_family_index.has_value());

    compute_queue_family_index  = compute_queue_family_index.has_value() ? compute_queue_family_index
                                                                         : graphics_queue_family_index;
    transfer_queue_family_index = transfer_queue_family_index.has_value() ? transfer_queue_family_index
                                                                          : graphics_queue_family_index;

    std::set<uint32> queue_family_indices = {graphics_queue_family_index.value(), compute_queue_family_index.value(),
                                             transfer_queue_family_index.value()};

    std::vector<VkDeviceQueueCreateInfo> queue_create_infos;
    std::vector<float>                   queue_priorities;

    for (const uint32 &queue_family_index: queue_family_indices) {
        queue_create_infos.push_back({});
        queue_priorities.push_back(1);
        queue_create_infos.back().sType            = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queue_create_infos.back().queueFamilyIndex = queue_family_index;
        queue_create_infos.back().pQueuePriorities = &queue_priorities.back();
        queue_create_infos.back().queueCount       = 1;
    }

    std::vector<const char*> enabled_extension_names;

//    for (const vulkan_device_extension& device_extension : vulkan_device_extension::required_extensions())
//    {
//        enabled_extension_names.push_back(device_extension.get_name());
//    }

    VkDeviceCreateInfo device_create_info{};
    device_create_info.sType                   = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    device_create_info.enabledExtensionCount   = requested_device_extensions_.size();
    device_create_info.enabledLayerCount       = 0;
    device_create_info.pEnabledFeatures        = nullptr;
    device_create_info.ppEnabledExtensionNames = requested_device_extensions_.data();
    device_create_info.pQueueCreateInfos       = queue_create_infos.data();
    device_create_info.queueCreateInfoCount    = queue_create_infos.size();
    VK_ASSERT_SUCCESS(vkCreateDevice(device_.physical_device_, &device_create_info, nullptr, &device_.logical_device_))


    vkGetDeviceQueue(device_.logical_device_, graphics_queue_family_index.value(), 0, &graphics_queue_.queue_);
    graphics_queue_.queue_family_index_ = graphics_queue_family_index.value();
    graphics_queue_.queue_index_        = 0;
    present_queue_ = graphics_queue_;

    vkGetDeviceQueue(device_.logical_device_, compute_queue_family_index.value(), 0, &compute_queue_.queue_);
    compute_queue_.queue_family_index_ = compute_queue_family_index.value();
    compute_queue_.queue_index_        = 0;

    vkGetDeviceQueue(device_.logical_device_, transfer_queue_family_index.value(), 0, &transfer_queue_.queue_);
    transfer_queue_.queue_family_index_ = transfer_queue_family_index.value();
    transfer_queue_.queue_index_        = 0;
}

void VulkanRenderer::release_device()
{
    vkDestroyDevice(device_.logical_device_, nullptr);
}


void VulkanRenderer::create_swapchain(VkSurfaceKHR surface, uint32 width, uint32 height)
{


    VkSurfaceCapabilitiesKHR surface_capabilities{};
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device_.physical_device_, surface, &surface_capabilities);

    uint32 desired_image_count = 3;

    uint32 image_count =
                   surface_capabilities.maxImageCount == 0 ? desired_image_count : std::clamp(desired_image_count,
                                                                                              surface_capabilities.minImageCount,
                                                                                              surface_capabilities.maxImageCount);

    uint32 surface_format_count = 0;

    vkGetPhysicalDeviceSurfaceFormatsKHR(device_.physical_device_, surface, &surface_format_count, nullptr);

    std::vector<VkSurfaceFormatKHR> surface_formats(surface_format_count);
    vkGetPhysicalDeviceSurfaceFormatsKHR(device_.physical_device_, surface, &surface_format_count,
                                         surface_formats.data());

    VkSurfaceFormatKHR surface_format{};

    bool found_desired_surface_format = false;

    for (const VkSurfaceFormatKHR &format: surface_formats) {
        if ((format.colorSpace == VK_COLORSPACE_SRGB_NONLINEAR_KHR) &&
            (format.format == VK_FORMAT_B8G8R8A8_SRGB)) {
            surface_format               = format;
            found_desired_surface_format = true;
        }
    }

    surface_format = found_desired_surface_format ? surface_format : surface_formats[0];

    VkExtent2D image_extent;

    image_extent =
            surface_capabilities.currentExtent.width != UINT32_MAX ? surface_capabilities.currentExtent : VkExtent2D{
                    width, height};

    VkSurfaceTransformFlagBitsKHR pre_transform = surface_capabilities.supportedTransforms &
                                                  VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR
                                                  ? VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR
                                                  : surface_capabilities.currentTransform;

    VkCompositeAlphaFlagBitsKHR composite_alpha =
                                        surface_capabilities.supportedCompositeAlpha & VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR
                                        ? VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR : VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR;

    VkPresentModeKHR present_mode;

    uint32 present_mode_count = 0;
    vkGetPhysicalDeviceSurfacePresentModesKHR(device_.physical_device_, surface, &present_mode_count, nullptr);

    std::vector<VkPresentModeKHR> present_modes(present_mode_count);
    vkGetPhysicalDeviceSurfacePresentModesKHR(device_.physical_device_, surface, &present_mode_count,
                                              present_modes.data());

    bool found_desired_present_mode = false;

    for (const VkPresentModeKHR &mode: present_modes) {
        if (mode == VK_PRESENT_MODE_MAILBOX_KHR) {
            present_mode               = mode;
            found_desired_present_mode = true;
        }
    }

    present_mode = found_desired_present_mode ? present_mode : VK_PRESENT_MODE_FIFO_KHR;

    VkSwapchainCreateInfoKHR swapchain_create_info{};
    swapchain_create_info.sType            = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    swapchain_create_info.surface          = surface;
    swapchain_create_info.minImageCount    = image_count;
    swapchain_create_info.imageFormat      = surface_format.format;
    swapchain_create_info.imageColorSpace  = surface_format.colorSpace;
    swapchain_create_info.imageExtent      = image_extent;
    swapchain_create_info.imageArrayLayers = 1;
    swapchain_create_info.imageUsage       = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
    swapchain_create_info.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
    swapchain_create_info.preTransform     = pre_transform;
    swapchain_create_info.compositeAlpha   = composite_alpha;
    swapchain_create_info.presentMode      = present_mode;
    swapchain_create_info.clipped          = VK_TRUE;
    swapchain_create_info.oldSwapchain     = VK_NULL_HANDLE;
    //TODO fill this out properly (needs a reference to the swapchain handle to be filled out)
    VK_ASSERT_SUCCESS(
            vkCreateSwapchainKHR(device_.logical_device_, &swapchain_create_info, nullptr, &swapchain.vk_swapchain_))

    swapchain.surface_format_ = surface_format;
    swapchain.vk_surface_     = surface;

    uint32 swapchain_image_count = 0;
    vkGetSwapchainImagesKHR(device_.logical_device_, swapchain.vk_swapchain_, &swapchain_image_count, nullptr);
    swapchain.images_.resize(swapchain_image_count);
    vkGetSwapchainImagesKHR(device_.logical_device_, swapchain.vk_swapchain_, &swapchain_image_count,
                            swapchain.images_.data());

    for (const VkImage &swapchain_image: swapchain.images_) {
        VkImageViewCreateInfo image_view_create_info{};
        image_view_create_info.sType                           = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        image_view_create_info.image                           = swapchain_image;
        image_view_create_info.viewType                        = VK_IMAGE_VIEW_TYPE_2D;
        image_view_create_info.format                          = surface_format.format;
        image_view_create_info.components.r                    = VK_COMPONENT_SWIZZLE_IDENTITY;
        image_view_create_info.components.g                    = VK_COMPONENT_SWIZZLE_IDENTITY;
        image_view_create_info.components.b                    = VK_COMPONENT_SWIZZLE_IDENTITY;
        image_view_create_info.components.a                    = VK_COMPONENT_SWIZZLE_IDENTITY;
        image_view_create_info.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
        image_view_create_info.subresourceRange.baseMipLevel   = 0;
        image_view_create_info.subresourceRange.levelCount     = 1;
        image_view_create_info.subresourceRange.baseArrayLayer = 0;
        image_view_create_info.subresourceRange.layerCount     = 1;

        VkImageView image_view;

        VK_ASSERT_SUCCESS(vkCreateImageView(device_.logical_device_, &image_view_create_info, nullptr, &image_view))
        swapchain.image_views_.push_back(image_view);
    }
}

void VulkanRenderer::recreate_swapchain()
{
    VkSwapchainCreateInfoKHR swapchain_create_info_khr{};
    swapchain_create_info_khr.sType        = VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR;
    //TODO pass in old VulkanSwapchain
    swapchain_create_info_khr.oldSwapchain = VK_NULL_HANDLE;

}

void VulkanRenderer::release_swapchain(VulkanSwapchain &swapchain)
{

}

void VulkanRenderer::acquire_next_image_from_swapchain(VkSwapchainKHR swapchain)
{
    //TODO fill out with reference to this frames semaphore and frame index to be updates
    vkAcquireNextImageKHR(device_.logical_device_, swapchain, UINT64_MAX, nullptr, nullptr, 0);
}

void VulkanRenderer::present_image(VkSwapchainKHR swapchain)
{
    VkPresentInfoKHR present_info{};
    present_info.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
}

void VulkanRenderer::create_viewport(void* window_handle)
{

    VkWin32SurfaceCreateInfoKHR surface_create_info{};
    surface_create_info.sType     = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
    surface_create_info.hwnd      = static_cast<HWND>(window_handle);
    surface_create_info.hinstance = GetModuleHandle(nullptr);
    VK_ASSERT_SUCCESS(vkCreateWin32SurfaceKHR(instance_, &surface_create_info, nullptr, &viewport.surface_))


    create_swapchain(viewport.surface_, viewport.width_, viewport.height_);

}

void VulkanRenderer::release_viewport(uint32 viewport_index)
{

}

void VulkanRenderer::create_pipeline_manager()
{

}

void VulkanRenderer::release_pipeline_manager()
{

}

void VulkanRenderer::create_pipeline(const VulkanGraphicsPipelineDesc &pipeline_description)
{
}

void VulkanRenderer::release_pipeline()
{

}

void VulkanRenderer::create_render_pass()
{
    VkRenderPassCreateInfo render_pass_create_info {};
    render_pass_create_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    render_pass_create_info.attachmentCount;
    render_pass_create_info.pAttachments;
    render_pass_create_info.dependencyCount;
    render_pass_create_info.pDependencies;
    render_pass_create_info.subpassCount;
    render_pass_create_info.pSubpasses;
}

void VulkanRenderer::create_framebuffer(VkRenderPass render_pass, const std::vector<VkImageView> &attachment_views,
                                        uint32 width, uint32 height, uint32 layers)
{
    VkFramebufferCreateInfo framebuffer_create_info{};
    framebuffer_create_info.sType           = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
    framebuffer_create_info.pAttachments    = attachment_views.data();
    framebuffer_create_info.attachmentCount = attachment_views.size();
    framebuffer_create_info.width           = width;
    framebuffer_create_info.height          = height;
    framebuffer_create_info.layers          = layers;
    framebuffer_create_info.renderPass      = render_pass;

    //TODO fill this out propertly
    vkCreateFramebuffer(device_.logical_device_, &framebuffer_create_info, nullptr, nullptr);
}

void VulkanRenderer::release_framebuffer(VkFramebuffer &framebuffer)
{
    vkDestroyFramebuffer(device_.logical_device_, framebuffer, nullptr);
}

void VulkanRenderer::create_command_pool(uint32 queue_family_index)
{
    VkCommandPoolCreateInfo command_pool_create_info{};
    command_pool_create_info.sType            = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    command_pool_create_info.queueFamilyIndex = queue_family_index;

    VkCommandPool command_pool{};
    VK_ASSERT_SUCCESS(vkCreateCommandPool(device_.logical_device_, &command_pool_create_info, nullptr, &command_pool));
}

void VulkanRenderer::create_command_buffer(VkCommandPool command_pool)
{

    VkCommandBufferAllocateInfo command_buffer_allocate_info{};
    command_buffer_allocate_info.sType              = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    command_buffer_allocate_info.commandPool        = command_pool;
    command_buffer_allocate_info.level              = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    command_buffer_allocate_info.commandBufferCount = 1;

    //TODO fill this out properly
    vkAllocateCommandBuffers(device_.logical_device_, &command_buffer_allocate_info, nullptr);

}

void VulkanRenderer::begin_command_buffer(VkCommandBuffer command_buffer)
{
    VkCommandBufferBeginInfo command_buffer_begin_info{};
    command_buffer_begin_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

    vkBeginCommandBuffer(command_buffer, &command_buffer_begin_info);

}

void VulkanRenderer::end_command_buffer(const VkCommandBuffer command_buffer)
{
    vkEndCommandBuffer(command_buffer);
}

void VulkanRenderer::reset_command_buffer(VkCommandBuffer command_buffer)
{
    //TODO come back to this to check flags
    vkResetCommandBuffer(command_buffer, 0);
}

void VulkanRenderer::create_queue(uint32 queue_family_index, uint32 queue_index)
{
    vkGetDeviceQueue(device_.logical_device_, queue_family_index, queue_index, nullptr);
}

void VulkanRenderer::submit_to_queue()
{
    VkSubmitInfo submit_info{};
    submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
}

void VulkanRenderer::release_render_pass()
{

}

void VulkanRenderer::begin_render_pass()
{
    VkRenderPassBeginInfo render_pass_begin_info{};
    render_pass_begin_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
}

void VulkanRenderer::end_render_pass()
{
//    vkCmdEndRenderPass();
}

void VulkanRenderer::reset_command_pool(VkCommandPool command_pool)
{
    vkResetCommandPool(device_.logical_device_, command_pool, 0);
}

void VulkanRenderer::free_command_pool()
{

}

void VulkanRenderer::command_draw()
{
}

void VulkanRenderer::command_draw_indexed()
{
//    vkCmdDrawIndexed()
}

void VulkanRenderer::command_draw_indirect()
{
//    vkCmdDrawIndirect()
}

void VulkanRenderer::command_draw_indexed_indirect()
{
//    vkCmdDrawIndexedIndirect()
}

void VulkanRenderer::create_buffer()
{
}

void VulkanRenderer::release_buffer()
{
}

void* VulkanRenderer::buffer_map()
{
//    vkMapMemory()
    return nullptr;
}

void VulkanRenderer::buffer_unmap()
{
//    vkUnmapMemory()
}

void VulkanRenderer::command_copy_buffer()
{
//    vkCmdCopyBuffer()
}

void VulkanRenderer::command_copy_image()
{
//    vkCmdCopyImage()
}

void VulkanRenderer::command_copy_buffer_to_image()
{
//    vkCmdCopyBufferToImage()
}

void VulkanRenderer::command_copy_image_to_buffer()
{
//    vkCmdCopyImageToBuffer()
}

void VulkanRenderer::create_semaphore()
{
    VkSemaphoreCreateInfo semaphore_create_info{};
    semaphore_create_info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    VkSemaphore semaphore;
    VK_ASSERT_SUCCESS(vkCreateSemaphore(device_.logical_device_, &semaphore_create_info, nullptr, &semaphore));
}


void VulkanRenderer::release_semaphore()
{
//    vkDestroySemaphore()
}

void VulkanRenderer::create_fence(bool signaled)
{
    VkFenceCreateInfo fence_create_info{};
    fence_create_info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    fence_create_info.flags = signaled ? VK_FENCE_CREATE_SIGNALED_BIT : 0;

    VkFence fence;
    VK_ASSERT_SUCCESS(vkCreateFence(device_.logical_device_, &fence_create_info, nullptr, &fence));

}

void VulkanRenderer::release_fence()
{
//    vkDestroyFence()
}

void VulkanRenderer::wait_for_fences()
{
//    vkWaitForFences()
}

void VulkanRenderer::reset_fence()
{
//    vkResetFences()
}




