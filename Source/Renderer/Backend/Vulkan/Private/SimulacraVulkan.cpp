//
// Created by avsom on 6/5/2024.
//

#include <set>
#include <vulkan/vulkan_core.h>
#include <fstream>
#include "SimulacraVulkan.h"

void VulkanRenderer::init(void* win_hand)
{
    create_instance();
    select_physical_device();
    create_device();
    create_viewport(win_hand);
    VkCommandPool command_pool{};
    create_command_pool(&command_pool, graphics_queue_.queue_family_index_);
    VkRenderPass render_pass;
    create_render_pass(&render_pass);
    test_struct_.framebuffers_.reserve(test_struct_.swapchain_.image_views_.size());
    for(const VkImageView& image_view : test_struct_.swapchain_.image_views_)
    {
        test_struct_.framebuffers_.push_back({});
        std::vector<VkImageView> view = {image_view};
        create_framebuffer(&test_struct_.framebuffers_.back(), render_pass, view, test_struct_.viewport_.width_, test_struct_.viewport_.height_, 1);

    }

    create_shader_module();
}

void VulkanRenderer::shutdown()
{
    for(FrameContext& frame_context : test_struct_.per_frame_resources_)
    {
        release_semaphore(frame_context.image_rendered_semaphore_);
        release_semaphore(frame_context.image_acquired_semaphore_);
        release_fence(frame_context.in_flight_fence_);
        for(VkCommandPool& command_pool : frame_context.command_pools_)
        {
            free_command_pool(command_pool);
        }


    }


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
    //TODO fill this out properly (needs a reference to the test_struct_.swapchain_ handle to be filled out)
    VK_ASSERT_SUCCESS(
            vkCreateSwapchainKHR(device_.logical_device_, &swapchain_create_info, nullptr,
                                 &test_struct_.swapchain_.vk_swapchain_))

    test_struct_.swapchain_.surface_format_ = surface_format;
    test_struct_.swapchain_.vk_surface_     = surface;

    uint32 swapchain_image_count = 0;
    vkGetSwapchainImagesKHR(device_.logical_device_, test_struct_.swapchain_.vk_swapchain_, &swapchain_image_count,
                            nullptr);
    test_struct_.swapchain_.images_.resize(swapchain_image_count);
    vkGetSwapchainImagesKHR(device_.logical_device_, test_struct_.swapchain_.vk_swapchain_, &swapchain_image_count,
                            test_struct_.swapchain_.images_.data());

    for (const VkImage &swapchain_image: test_struct_.swapchain_.images_) {
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
        test_struct_.swapchain_.image_views_.push_back(image_view);
    }
}

void VulkanRenderer::recreate_swapchain()
{

}

void VulkanRenderer::release_swapchain(VulkanSwapchain &swapchain)
{
    vkDestroySwapchainKHR(device_.logical_device_, swapchain.vk_swapchain_, nullptr);
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
    VK_ASSERT_SUCCESS(
            vkCreateWin32SurfaceKHR(instance_, &surface_create_info, nullptr, &test_struct_.viewport_.surface_))


    create_swapchain(test_struct_.viewport_.surface_, test_struct_.viewport_.width_, test_struct_.viewport_.height_);

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

void VulkanRenderer::create_pipeline(const VulkanGraphicsPipelineDescription &pipeline_description)
{

    VkGraphicsPipelineCreateInfo graphics_pipeline_create_info{};
    graphics_pipeline_create_info.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    //TODO fill out members of graphics pipeline create info with proper settings

    VkViewport viewport{};
    viewport.x = 0.0f;
    viewport.y = 0.0f;
    viewport.width = test_struct_.viewport_.width_;
    viewport.height = test_struct_.viewport_.height_;
    viewport.minDepth = 0.0f;
    viewport.maxDepth = 1.0f;

    VkRect2D scissor{};
    scissor.offset = {0,0};
    scissor.extent = {test_struct_.viewport_.width_, test_struct_.viewport_.height_};

    std::vector<VkDynamicState> dynamic_states = {VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR};

    VkPipelineDynamicStateCreateInfo dynamic_state_create_info{};
    dynamic_state_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
    dynamic_state_create_info.dynamicStateCount = dynamic_states.size();

    VkPipelineViewportStateCreateInfo viewport_state_create_info{};
    viewport_state_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
    viewport_state_create_info.viewportCount = 1;
    viewport_state_create_info.pViewports = &viewport;
    viewport_state_create_info.scissorCount = 1;
    viewport_state_create_info.pScissors = &scissor;


    VkPipelineShaderStageCreateInfo vertex_shader_stage_create_info {};
    VkPipelineShaderStageCreateInfo fragment_shader_stage_create_info {};

    vertex_shader_stage_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    vertex_shader_stage_create_info.stage = VK_SHADER_STAGE_VERTEX_BIT;
    vertex_shader_stage_create_info.module = test_struct_.vertex_shader_module_;
    vertex_shader_stage_create_info.pName = "main";

    fragment_shader_stage_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    fragment_shader_stage_create_info.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
    fragment_shader_stage_create_info.module = test_struct_.fragment_shader_module_;
    fragment_shader_stage_create_info.pName = "main";

    VkPipelineShaderStageCreateInfo shader_stages[] = {vertex_shader_stage_create_info, fragment_shader_stage_create_info};

    VkPipelineVertexInputStateCreateInfo vertex_input_state_create_info{};
    vertex_input_state_create_info.sType                           = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
    vertex_input_state_create_info.vertexBindingDescriptionCount   = 0;
    vertex_input_state_create_info.pVertexBindingDescriptions      = nullptr;
    vertex_input_state_create_info.vertexAttributeDescriptionCount = 0;
    vertex_input_state_create_info.pVertexAttributeDescriptions    = nullptr;

    VkPipelineInputAssemblyStateCreateInfo input_assembly_state_create_info{};
    input_assembly_state_create_info.sType                  = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
    input_assembly_state_create_info.topology               = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
    input_assembly_state_create_info.primitiveRestartEnable = VK_FALSE;

    VkPipelineRasterizationStateCreateInfo rasterization_state_create_info{};
    rasterization_state_create_info.sType                   = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
    rasterization_state_create_info.depthClampEnable        = VK_FALSE;
    rasterization_state_create_info.rasterizerDiscardEnable = VK_FALSE;
    rasterization_state_create_info.polygonMode             = VK_POLYGON_MODE_FILL;
    rasterization_state_create_info.lineWidth               = 1.0f;
    rasterization_state_create_info.cullMode                = VK_CULL_MODE_BACK_BIT;
    rasterization_state_create_info.frontFace               = VK_FRONT_FACE_CLOCKWISE;
    rasterization_state_create_info.depthBiasEnable         = VK_FALSE;
    rasterization_state_create_info.depthBiasConstantFactor = 0.0f;
    rasterization_state_create_info.depthBiasClamp          = 0.0f;
    rasterization_state_create_info.depthBiasSlopeFactor    = 0.0f;

    VkPipelineMultisampleStateCreateInfo multisample_state_create_info{};
    multisample_state_create_info.sType                 = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    multisample_state_create_info.sampleShadingEnable   = VK_FALSE;
    multisample_state_create_info.rasterizationSamples  = VK_SAMPLE_COUNT_1_BIT;
    multisample_state_create_info.minSampleShading      = 1.0f;
    multisample_state_create_info.pSampleMask           = nullptr;
    multisample_state_create_info.alphaToCoverageEnable = VK_FALSE;
    multisample_state_create_info.alphaToOneEnable      = VK_FALSE;

    VkPipelineDepthStencilStateCreateInfo depth_stencil_state_create_info{};
    depth_stencil_state_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;

    VkPipelineColorBlendAttachmentState color_blend_attachment_state{};
    color_blend_attachment_state.colorWriteMask =
            VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
    color_blend_attachment_state.blendEnable = VK_FALSE;

    VkPipelineColorBlendStateCreateInfo color_blend_state_create_info{};
    color_blend_state_create_info.sType           = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    color_blend_state_create_info.logicOpEnable   = VK_FALSE;
    color_blend_state_create_info.logicOp         = VK_LOGIC_OP_COPY;
    color_blend_state_create_info.attachmentCount = 1;
    color_blend_state_create_info.pAttachments    = &color_blend_attachment_state;

    VkPipelineLayoutCreateInfo pipeline_layout_create_info{};
    pipeline_layout_create_info.sType                  = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipeline_layout_create_info.setLayoutCount         = 0;
    pipeline_layout_create_info.pSetLayouts            = nullptr;
    pipeline_layout_create_info.pushConstantRangeCount = 0;
    pipeline_layout_create_info.pPushConstantRanges    = nullptr;

    if (VkResult result = vkCreatePipelineLayout(device_.logical_device_, &pipeline_layout_create_info, nullptr,
                                                 &test_struct_.pipeline_.pipeline_layout_); result != VK_SUCCESS) {
        std::cerr << "Failed to create pipeline layout!\n";
        terminate();
    }
    std::cout << "Created pipeline layout\n";


    graphics_pipeline_create_info.stageCount = 2;
    graphics_pipeline_create_info.pStages = shader_stages;
    graphics_pipeline_create_info.pVertexInputState = &vertex_input_state_create_info;
    graphics_pipeline_create_info.pInputAssemblyState = &input_assembly_state_create_info;
    graphics_pipeline_create_info.pViewportState = &viewport_state_create_info;
    graphics_pipeline_create_info.pRasterizationState = &rasterization_state_create_info;
    graphics_pipeline_create_info.pMultisampleState = &multisample_state_create_info;
    graphics_pipeline_create_info.pDepthStencilState = nullptr;
    graphics_pipeline_create_info.pColorBlendState = &color_blend_state_create_info;
    graphics_pipeline_create_info.pDynamicState = &dynamic_state_create_info;
    graphics_pipeline_create_info.layout = test_struct_.pipeline_.pipeline_layout_;
    graphics_pipeline_create_info.renderPass = test_struct_.render_pass_;
    graphics_pipeline_create_info.subpass = 0;
    graphics_pipeline_create_info.basePipelineHandle = VK_NULL_HANDLE;
    graphics_pipeline_create_info.basePipelineIndex = -1;

    VK_ASSERT_SUCCESS(vkCreateGraphicsPipelines(device_.logical_device_, VK_NULL_HANDLE, 1, &graphics_pipeline_create_info,
                                                nullptr, &test_struct_.pipeline_.pipeline_))

}

void VulkanRenderer::release_pipeline()
{

}

void VulkanRenderer::create_render_pass(VkRenderPass* render_pass)
{

    VkAttachmentDescription color_attachment{};
    color_attachment.format         = test_struct_.swapchain_.surface_format_.format;
    color_attachment.samples        = VK_SAMPLE_COUNT_1_BIT;
    color_attachment.loadOp         = VK_ATTACHMENT_LOAD_OP_CLEAR;
    color_attachment.storeOp        = VK_ATTACHMENT_STORE_OP_STORE;
    color_attachment.stencilLoadOp  = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    color_attachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    color_attachment.initialLayout  = VK_IMAGE_LAYOUT_UNDEFINED;
    color_attachment.finalLayout    = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

    VkAttachmentReference color_attachment_reference{};
    color_attachment_reference.attachment = 0;
    color_attachment_reference.layout     = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkSubpassDescription subpass{};
    subpass.pipelineBindPoint    = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass.colorAttachmentCount = 1;
    subpass.pColorAttachments    = &color_attachment_reference;

    VkRenderPassCreateInfo render_pass_create_info{};
    render_pass_create_info.sType           = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    render_pass_create_info.attachmentCount = 1;
    render_pass_create_info.pAttachments    = &color_attachment;
    render_pass_create_info.subpassCount    = 1;
    render_pass_create_info.pSubpasses      = &subpass;

    VK_ASSERT_SUCCESS(vkCreateRenderPass(device_.logical_device_, &render_pass_create_info, nullptr, render_pass))
}

//TODO this shoudn't be a vector pass in ref to views and count
void VulkanRenderer::create_framebuffer(VkFramebuffer* framebuffer, VkRenderPass render_pass,
                                        const std::vector<VkImageView> &attachment_views, uint32 width, uint32 height,
                                        uint32 layers)
{
    VkFramebufferCreateInfo framebuffer_create_info{};
    framebuffer_create_info.sType           = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
    framebuffer_create_info.pAttachments    = attachment_views.data();
    framebuffer_create_info.attachmentCount = attachment_views.size();
    framebuffer_create_info.width           = width;
    framebuffer_create_info.height          = height;
    framebuffer_create_info.layers          = layers;
    framebuffer_create_info.renderPass      = render_pass;

    VK_ASSERT_SUCCESS(vkCreateFramebuffer(device_.logical_device_, &framebuffer_create_info, nullptr, framebuffer))
}

void VulkanRenderer::release_framebuffer(VkFramebuffer &framebuffer)
{
    vkDestroyFramebuffer(device_.logical_device_, framebuffer, nullptr);
}

void VulkanRenderer::create_command_pool(VkCommandPool* command_pool, uint32 queue_family_index)
{
    VkCommandPoolCreateInfo command_pool_create_info{};
    command_pool_create_info.sType            = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    command_pool_create_info.queueFamilyIndex = queue_family_index;

    VK_ASSERT_SUCCESS(vkCreateCommandPool(device_.logical_device_, &command_pool_create_info, nullptr, command_pool));
}

void VulkanRenderer::create_command_buffer(VkCommandBuffer command_buffer, VkCommandPool command_pool)
{

    VkCommandBufferAllocateInfo command_buffer_allocate_info{};
    command_buffer_allocate_info.sType              = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    command_buffer_allocate_info.commandPool        = command_pool;
    command_buffer_allocate_info.level              = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    command_buffer_allocate_info.commandBufferCount = 1;

    //TODO fill this out properly
    vkAllocateCommandBuffers(device_.logical_device_, &command_buffer_allocate_info, &command_buffer);

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

void VulkanRenderer::release_render_pass(VkRenderPass render_pass)
{
    vkDestroyRenderPass(device_.logical_device_, render_pass, nullptr);
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

void VulkanRenderer::free_command_pool(VkCommandPool &command_pool)
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


void VulkanRenderer::release_semaphore(VkSemaphore &semaphore)
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

void VulkanRenderer::release_fence(VkFence &fence)
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

void VulkanRenderer::test_draw_frame()
{
    vkWaitForFences(device_.logical_device_, 1, nullptr, VK_TRUE, UINT64_MAX);
    vkResetFences(device_.logical_device_, 1, nullptr);

    acquire_next_image_from_swapchain(test_struct_.swapchain_.vk_swapchain_);


}

void VulkanRenderer::create_shader_module()
{
    auto read_file = [](const char* file_name)
    {
        std::ifstream file(file_name, std::ios::ate | std::ios::binary);

        if(!file.is_open())
        {
            std::cerr << "failed to open file";
            terminate();
        }

        size_t file_size = (size_t ) file.tellg();

        std::vector<char> buffer(file_size);
        file.seekg(0);
        file.read(buffer.data(), file_size);
        file.close();
        return buffer;
    };

    std::vector<char> vertex_shader_code = read_file("../../Shaders/SpirV/vert.spv");
    std::vector<char> fragment_shader_code = read_file("../../Shaders/SpirV/frag.spv");

    VkShaderModuleCreateInfo vertex_shader_module_create_info {};
    VkShaderModuleCreateInfo fragment_shader_module_create_info {};

    vertex_shader_module_create_info.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    vertex_shader_module_create_info.pCode = reinterpret_cast<uint32*>(vertex_shader_code.data());
    vertex_shader_module_create_info.codeSize = vertex_shader_code.size();

    fragment_shader_module_create_info.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    fragment_shader_module_create_info.pCode = reinterpret_cast<uint32*>(fragment_shader_code.data());
    fragment_shader_module_create_info.codeSize = fragment_shader_code.size();

    VK_ASSERT_SUCCESS(vkCreateShaderModule(device_.logical_device_, &vertex_shader_module_create_info, nullptr, &test_struct_.vertex_shader_module_))
    VK_ASSERT_SUCCESS(vkCreateShaderModule(device_.logical_device_, &fragment_shader_module_create_info, nullptr, &test_struct_.fragment_shader_module_))



}




