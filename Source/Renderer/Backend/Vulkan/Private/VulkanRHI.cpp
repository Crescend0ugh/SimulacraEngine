//
// Created by avsom on 6/5/2024.
//

#include <set>
#include <fstream>
#include "VulkanRHI.h"
#include "Platform/SimulacraWindowsWindow.h"
#include "Math/Vector.h"
#include <chrono>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

void VulkanRHI::init(void* win_hand)
{
    create_instance();
    select_physical_device();
    create_device();
    memory_allocator_.init(physical_device_, logical_device_);
    create_viewport(win_hand);
    create_shader_module();
    create_render_pass(&render_pass_);
    VulkanGraphicsPipelineDescription description;
    description.vertex_input_binding_descriptions_.push_back(Vertex::get_binding_description());
    description.vertex_input_attributes_descriptions_ = Vertex::get_attribute_descriptions();
    for (int i = 0; i < frame_resources_.size(); i++) {
        FrameContext& frame_resource = frame_resources_[i];
        std::vector<VkImageView> image_view = {viewport_.swapchain_.image_views_[i]};
        frame_resource.framebuffer_ = create_framebuffer(
                render_pass_,
                image_view,
                viewport_.width_,
                viewport_.height_,
                1);
        frame_resource.image_acquired_semaphore_ = create_semaphore();
        frame_resource.image_rendered_semaphore_ = create_semaphore();
        frame_resource.in_flight_fence_          = create_fence(true);
        frame_resource.command_pool = create_command_pool(graphics_queue.family_index_);
        frame_resource.command_buffer_ = create_command_buffer(frame_resource.command_pool,
                                                               VK_COMMAND_BUFFER_LEVEL_PRIMARY);

    }

    test_create_vertex_buffer();
    test_create_index_buffer();
    for (auto & frame_resource : frame_resources_) {
        frame_resource.uniform_buffer_ = create_buffer(sizeof(UniformBufferObject),
                                                               VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
                                                               VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
                                                               VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
        frame_resource.uniformed_buffer_mapped_ = buffer_map(frame_resource.uniform_buffer_, 0,
                                                             sizeof(UniformBufferObject), 0);
    }

    create_descriptor_set_layout();
    create_descriptor_pool();
    create_descriptor_sets();
    create_pipeline(description);
}

void VulkanRHI::shutdown()
{


    release_device();
    release_instance();
}

void VulkanRHI::create_instance()
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
            vkEnumerateInstanceExtensionProperties(nullptr, &instance_extension_count, supported_extensions.data()))


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

void VulkanRHI::release_instance()
{
    vkDestroyInstance(instance_, nullptr);
}

void VulkanRHI::select_physical_device()
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

    physical_device_ = selected_device;
}

void VulkanRHI::create_device()
{
    uint32 queue_family_count = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(physical_device_, &queue_family_count, nullptr);

    std::vector<VkQueueFamilyProperties> queue_families(queue_family_count);
    std::vector<uint32>                  queue_offsets(queue_family_count);
    std::vector<std::vector<float>>      queue_priorities(queue_family_count);

    vkGetPhysicalDeviceQueueFamilyProperties(physical_device_, &queue_family_count, queue_families.data());
    auto find_valid_queue = [&](
            VulkanQueue &queue,
            VkQueueFlags require_bits,
            VkQueueFlags exclude_bits,
            float priority,
            bool should_support_present) -> bool {
        for (int index = 0; index < queue_families.size(); index++) {
            VkQueueFamilyProperties &queue_family = queue_families[index];
            if ((queue_family.queueFlags & require_bits) != 0 && (queue_family.queueFlags & exclude_bits) == 0) {
                queue.index_        = queue_offsets[index];
                queue.family_index_ = index;
                queue_offsets[index]++;
                queue_priorities[index].push_back(priority);
                return true;
            }
        }
        return false;
    };

    if(!find_valid_queue(graphics_queue, VK_QUEUE_GRAPHICS_BIT, 0, 1.0f, true))
    {
        std::cerr << "Failed to find graphics queue family";
    }

    if(!find_valid_queue(compute_queue, VK_QUEUE_COMPUTE_BIT, VK_QUEUE_GRAPHICS_BIT, 1.0f, false) &&
       !find_valid_queue(compute_queue, VK_QUEUE_COMPUTE_BIT | VK_QUEUE_GRAPHICS_BIT, 0, 1.0f, false))
    {
        compute_queue = graphics_queue;
    }

    if(!find_valid_queue(transfer_queue, VK_QUEUE_TRANSFER_BIT, VK_QUEUE_COMPUTE_BIT | VK_QUEUE_GRAPHICS_BIT, 1.0f, false) &&
       !find_valid_queue(transfer_queue, VK_QUEUE_TRANSFER_BIT | VK_QUEUE_COMPUTE_BIT, VK_QUEUE_GRAPHICS_BIT, 1.0f, false))
    {
        transfer_queue = compute_queue;
    }

    std::vector<VkDeviceQueueCreateInfo> queue_create_infos;
    for (int queue_family_index = 0; queue_family_index < queue_family_count; queue_family_index++) {
        if(queue_offsets[queue_family_index] != 0)
        {
            VkDeviceQueueCreateInfo queue_create_info {};
            queue_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
            queue_create_info.queueFamilyIndex = queue_family_index;
            queue_create_info.pQueuePriorities = queue_priorities[queue_family_index].data();
            queue_create_info.queueCount = queue_offsets[queue_family_index];
            queue_create_infos.push_back(queue_create_info);
        }
    }

    VkDeviceCreateInfo device_create_info{};
    device_create_info.sType                   = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    device_create_info.enabledExtensionCount   = requested_device_extensions_.size();
    device_create_info.ppEnabledExtensionNames = requested_device_extensions_.data();
    device_create_info.enabledLayerCount       = 0;
    device_create_info.pEnabledFeatures        = nullptr;
    device_create_info.pQueueCreateInfos       = queue_create_infos.data();
    device_create_info.queueCreateInfoCount    = queue_create_infos.size();
    VK_ASSERT_SUCCESS(vkCreateDevice(physical_device_, &device_create_info, nullptr, &logical_device_))

    vkGetDeviceQueue(logical_device_, graphics_queue.family_index_, graphics_queue.index_, &graphics_queue.queue_);
    vkGetDeviceQueue(logical_device_, compute_queue.family_index_,  compute_queue.index_,  &compute_queue.queue_);
    vkGetDeviceQueue(logical_device_, transfer_queue.family_index_, transfer_queue.index_, &transfer_queue.queue_);
}

void VulkanRHI::release_device()
{
    vkDestroyDevice(logical_device_, nullptr);
    logical_device_ = VK_NULL_HANDLE;
}

void VulkanRHI::create_swapchain(VkSurfaceKHR surface, uint32 &width, uint32 &height, VkSwapchainKHR old_swapchain)
{

    VulkanSwapchain          swapchain{};
    VkSurfaceCapabilitiesKHR surface_capabilities{};
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physical_device_, surface, &surface_capabilities);

    uint32 desired_image_count = 3;

    uint32 image_count =
                   surface_capabilities.maxImageCount == 0 ? desired_image_count : std::clamp(desired_image_count,
                                                                                              surface_capabilities.minImageCount,
                                                                                              surface_capabilities.maxImageCount);

    uint32 surface_format_count = 0;

    vkGetPhysicalDeviceSurfaceFormatsKHR(physical_device_, surface, &surface_format_count, nullptr);

    std::vector<VkSurfaceFormatKHR> surface_formats(surface_format_count);
    vkGetPhysicalDeviceSurfaceFormatsKHR(physical_device_, surface, &surface_format_count,
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

    width  = image_extent.width;
    height = image_extent.height;
    VkSurfaceTransformFlagBitsKHR pre_transform = surface_capabilities.supportedTransforms &
                                                  VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR
                                                  ? VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR
                                                  : surface_capabilities.currentTransform;

    VkCompositeAlphaFlagBitsKHR composite_alpha =
                                        surface_capabilities.supportedCompositeAlpha & VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR
                                        ? VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR : VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR;

    VkPresentModeKHR present_mode;

    uint32 present_mode_count = 0;
    vkGetPhysicalDeviceSurfacePresentModesKHR(physical_device_, surface, &present_mode_count, nullptr);

    std::vector<VkPresentModeKHR> present_modes(present_mode_count);
    vkGetPhysicalDeviceSurfacePresentModesKHR(physical_device_, surface, &present_mode_count,
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
    swapchain_create_info.oldSwapchain     = old_swapchain;

    VK_ASSERT_SUCCESS(vkCreateSwapchainKHR(logical_device_, &swapchain_create_info, nullptr, &swapchain.vk_swapchain_))

    swapchain.surface_format_ = surface_format;
    swapchain.vk_surface_     = surface;

    uint32 swapchain_image_count = 0;
    vkGetSwapchainImagesKHR(logical_device_, swapchain.vk_swapchain_, &swapchain_image_count, nullptr);
    swapchain.images_.resize(swapchain_image_count);
    vkGetSwapchainImagesKHR(logical_device_, swapchain.vk_swapchain_, &swapchain_image_count, swapchain.images_.data());

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

        VK_ASSERT_SUCCESS(vkCreateImageView(logical_device_, &image_view_create_info, nullptr, &image_view))
        swapchain.image_views_.push_back(image_view);
    }
    frame_resources_.resize(swapchain.images_.size());
    viewport_.swapchain_ = swapchain;
}

void VulkanRHI::recreate_swapchain()
{
    vkDeviceWaitIdle(logical_device_);
    Simulacra::windows::get_window_dimensions((HWND)viewport_.window_handle, viewport_.width_,viewport_.height_);
    create_swapchain(viewport_.surface_, viewport_.width_, viewport_.height_, viewport_.swapchain_.vk_swapchain_);
    release_swapchain(viewport_.swapchain_);
    for (int i = 0; i < frame_resources_.size(); i++) {
        FrameContext &frame_resource = frame_resources_[i];
        std::vector<VkImageView> image_view = {viewport_.swapchain_.image_views_[i]};
        frame_resource.framebuffer_ = create_framebuffer(
                render_pass_,
                image_view,
                viewport_.width_,
                viewport_.height_,
                1);
    }
}

void VulkanRHI::release_swapchain(VulkanSwapchain &swapchain)
{
    for(FrameContext & frame_resource : frame_resources_)
    {
        vkDestroyFramebuffer(logical_device_, frame_resource.framebuffer_, nullptr);
    }

    for(VkImageView& image_view : viewport_.swapchain_.image_views_)
    {
        vkDestroyImageView(logical_device_, image_view, nullptr);
    }

    vkDestroySwapchainKHR(logical_device_, swapchain.vk_swapchain_, nullptr);
    swapchain.vk_swapchain_ = VK_NULL_HANDLE;
}

uint32 VulkanRHI::acquire_next_image_from_swapchain(VkSwapchainKHR swapchain)
{
    //TODO fill out with reference to this frames semaphore and frame index to be updates
    uint32 image_index;
    VK_ASSERT_SUCCESS(vkAcquireNextImageKHR(logical_device_, swapchain, UINT64_MAX, frame_resources_[frame_].image_acquired_semaphore_, nullptr, &image_index));

    return image_index;
}

void
VulkanRHI::present_image(VkSwapchainKHR swapchain, uint32 image_index, VkSemaphore* wait_semaphores,
                         uint32 wait_semaphore_count)
{
    VkPresentInfoKHR present_info{};
    present_info.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
    present_info.waitSemaphoreCount = wait_semaphore_count;
    present_info.pWaitSemaphores = wait_semaphores;
    present_info.pSwapchains = &swapchain;
    present_info.swapchainCount = 1;
    present_info.pImageIndices = &image_index;
    present_info.pResults = VK_NULL_HANDLE;
    VK_ASSERT_SUCCESS(vkQueuePresentKHR(graphics_queue.queue_, &present_info))
}

void VulkanRHI::create_viewport(void* window_handle)
{

    viewport_.window_handle = window_handle;
    VkWin32SurfaceCreateInfoKHR surface_create_info{};
    surface_create_info.sType     = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
    surface_create_info.hwnd      = static_cast<HWND>(window_handle);
    surface_create_info.hinstance = GetModuleHandle(nullptr);

    Simulacra::windows::get_window_dimensions((HWND) window_handle, viewport_.width_, viewport_.height_);

    VK_ASSERT_SUCCESS(vkCreateWin32SurfaceKHR(instance_, &surface_create_info, nullptr, &viewport_.surface_))
    create_swapchain(viewport_.surface_, viewport_.width_, viewport_.height_, nullptr);


}

void VulkanRHI::release_viewport(uint32 viewport_index)
{

}

void VulkanRHI::create_pipeline_manager()
{

}

void VulkanRHI::release_pipeline_manager()
{

}

void VulkanRHI::create_pipeline(const VulkanGraphicsPipelineDescription &pipeline_description)
{


    //TODO fill out members of graphics pipeline create info with proper settings

    VkViewport viewport{};
    viewport.x        = 0.0f;
    viewport.y        = 0.0f;
    viewport.width    = viewport_.width_;
    viewport.height   = viewport_.height_;
    viewport.minDepth = 0.0f;
    viewport.maxDepth = 1.0f;

    VkRect2D scissor{};
    scissor.offset = {0, 0};
    scissor.extent = {viewport_.width_, viewport_.height_};

    std::vector<VkDynamicState> dynamic_states = {VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR};

    VkPipelineDynamicStateCreateInfo dynamic_state_create_info{};
    dynamic_state_create_info.sType             = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
    dynamic_state_create_info.dynamicStateCount = dynamic_states.size();
    dynamic_state_create_info.pDynamicStates    = dynamic_states.data();

    VkPipelineViewportStateCreateInfo viewport_state_create_info{};
    viewport_state_create_info.sType         = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
    viewport_state_create_info.viewportCount = 1;
    viewport_state_create_info.pViewports    = &viewport;
    viewport_state_create_info.scissorCount  = 1;
    viewport_state_create_info.pScissors     = &scissor;

    VkPipelineShaderStageCreateInfo vertex_shader_stage_create_info{};
    VkPipelineShaderStageCreateInfo fragment_shader_stage_create_info{};

    vertex_shader_stage_create_info.sType  = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    vertex_shader_stage_create_info.stage  = VK_SHADER_STAGE_VERTEX_BIT;
    vertex_shader_stage_create_info.module = vertex_shader_module_;
    vertex_shader_stage_create_info.pName  = "main";

    fragment_shader_stage_create_info.sType  = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    fragment_shader_stage_create_info.stage  = VK_SHADER_STAGE_FRAGMENT_BIT;
    fragment_shader_stage_create_info.module = fragment_shader_module_;
    fragment_shader_stage_create_info.pName  = "main";

    VkPipelineShaderStageCreateInfo shader_stages[] = {vertex_shader_stage_create_info,
                                                       fragment_shader_stage_create_info};

    VkPipelineVertexInputStateCreateInfo vertex_input_state_create_info{};
    vertex_input_state_create_info.sType                           = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
    vertex_input_state_create_info.vertexBindingDescriptionCount   = pipeline_description.vertex_input_binding_descriptions_.size();
    vertex_input_state_create_info.pVertexBindingDescriptions      = pipeline_description.vertex_input_binding_descriptions_.data();
    vertex_input_state_create_info.vertexAttributeDescriptionCount = pipeline_description.vertex_input_attributes_descriptions_.size();
    vertex_input_state_create_info.pVertexAttributeDescriptions    = pipeline_description.vertex_input_attributes_descriptions_.data();

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
    rasterization_state_create_info.frontFace               = VK_FRONT_FACE_COUNTER_CLOCKWISE;
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
    pipeline_layout_create_info.setLayoutCount         = 1;
    pipeline_layout_create_info.pSetLayouts            = &descriptor_set_layout;
    pipeline_layout_create_info.pushConstantRangeCount = 0;
    pipeline_layout_create_info.pPushConstantRanges    = nullptr;

    if (VkResult result = vkCreatePipelineLayout(logical_device_, &pipeline_layout_create_info, nullptr,
                                                 &pipeline_.pipeline_layout_); result != VK_SUCCESS) {
        std::cerr << "Failed to create pipeline layout!\n";
        terminate();
    }
    std::cout << "Created pipeline layout\n";

    VkGraphicsPipelineCreateInfo graphics_pipeline_create_info{};
    graphics_pipeline_create_info.sType               = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    graphics_pipeline_create_info.stageCount          = 2;
    graphics_pipeline_create_info.pStages             = shader_stages;
    graphics_pipeline_create_info.pVertexInputState   = &vertex_input_state_create_info;
    graphics_pipeline_create_info.pInputAssemblyState = &input_assembly_state_create_info;
    graphics_pipeline_create_info.pViewportState      = &viewport_state_create_info;
    graphics_pipeline_create_info.pRasterizationState = &rasterization_state_create_info;
    graphics_pipeline_create_info.pMultisampleState   = &multisample_state_create_info;
    graphics_pipeline_create_info.pDepthStencilState  = nullptr;
    graphics_pipeline_create_info.pColorBlendState    = &color_blend_state_create_info;
    graphics_pipeline_create_info.pDynamicState       = &dynamic_state_create_info;
    graphics_pipeline_create_info.layout              = pipeline_.pipeline_layout_;
    graphics_pipeline_create_info.renderPass          = render_pass_;
    graphics_pipeline_create_info.subpass             = 0;
    graphics_pipeline_create_info.basePipelineHandle  = VK_NULL_HANDLE;
    graphics_pipeline_create_info.basePipelineIndex   = -1;

    vkCreateGraphicsPipelines(logical_device_, VK_NULL_HANDLE, 1, &graphics_pipeline_create_info, nullptr,
                              &pipeline_.pipeline_);

}

void VulkanRHI::release_pipeline()
{

}

void VulkanRHI::create_render_pass(VkRenderPass* render_pass)
{

    VkAttachmentDescription color_attachment{};
    color_attachment.format         = viewport_.swapchain_.surface_format_.format;
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

    VkSubpassDependency dependency{};
    dependency.srcSubpass = VK_SUBPASS_EXTERNAL;
    dependency.dstSubpass = 0;
    dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    dependency.srcAccessMask = 0;
    dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;


    VkRenderPassCreateInfo render_pass_create_info{};
    render_pass_create_info.sType           = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    render_pass_create_info.attachmentCount = 1;
    render_pass_create_info.pAttachments    = &color_attachment;
    render_pass_create_info.subpassCount    = 1;
    render_pass_create_info.pSubpasses      = &subpass;
    render_pass_create_info.dependencyCount = 1;
    render_pass_create_info.pDependencies = &dependency;

    VK_ASSERT_SUCCESS(vkCreateRenderPass(logical_device_, &render_pass_create_info, nullptr, render_pass))
}

//TODO this shoudn't be a vector pass in ref to views and count
VkFramebuffer
VulkanRHI::create_framebuffer(VkRenderPass render_pass, const std::vector<VkImageView> &attachment_views, uint32 width,
                              uint32 height, uint32 layers)
{
    VkFramebufferCreateInfo framebuffer_create_info{};
    framebuffer_create_info.sType           = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
    framebuffer_create_info.pAttachments    = attachment_views.data();
    framebuffer_create_info.attachmentCount = attachment_views.size();
    framebuffer_create_info.width           = width;
    framebuffer_create_info.height          = height;
    framebuffer_create_info.layers          = layers;
    framebuffer_create_info.renderPass      = render_pass;

    VkFramebuffer framebuffer;
    VK_ASSERT_SUCCESS(vkCreateFramebuffer(logical_device_, &framebuffer_create_info, nullptr, &framebuffer))
    return framebuffer;
}

void VulkanRHI::release_framebuffer(VkFramebuffer &framebuffer)
{
    vkDestroyFramebuffer(logical_device_, framebuffer, nullptr);
}

VkCommandPool VulkanRHI::create_command_pool(uint32 queue_family_index)
{
    VkCommandPoolCreateInfo command_pool_create_info{};
    command_pool_create_info.sType            = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    command_pool_create_info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    command_pool_create_info.queueFamilyIndex = queue_family_index;

    VkCommandPool command_pool;
    VK_ASSERT_SUCCESS(vkCreateCommandPool(logical_device_, &command_pool_create_info, nullptr, &command_pool));
    return command_pool;
}

VkCommandBuffer VulkanRHI::create_command_buffer(VkCommandPool command_pool, VkCommandBufferLevel level)
{

    VkCommandBufferAllocateInfo command_buffer_allocate_info{};
    command_buffer_allocate_info.sType              = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    command_buffer_allocate_info.commandPool        = command_pool;
    command_buffer_allocate_info.level              = level;
    command_buffer_allocate_info.commandBufferCount = 1;

    VkCommandBuffer command_buffer;
    vkAllocateCommandBuffers(logical_device_, &command_buffer_allocate_info, &command_buffer);
    return command_buffer;
}

void VulkanRHI::free_command_buffer(VkCommandPool command_pool, VkCommandBuffer &command_buffer)
{
    vkFreeCommandBuffers(logical_device_, command_pool, 1, &command_buffer);
    command_buffer = VK_NULL_HANDLE;
}

void VulkanRHI::begin_command_buffer(VkCommandBuffer command_buffer, VkCommandBufferUsageFlags usage_flags)
{
    VkCommandBufferBeginInfo command_buffer_begin_info{};
    command_buffer_begin_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    command_buffer_begin_info.flags =

    vkBeginCommandBuffer(command_buffer, &command_buffer_begin_info);

}

void VulkanRHI::end_command_buffer(const VkCommandBuffer command_buffer)
{
    vkEndCommandBuffer(command_buffer);
}

void VulkanRHI::reset_command_buffer(VkCommandBuffer command_buffer)
{
    //TODO come back to this to check flags
    vkResetCommandBuffer(command_buffer, 0);
}

void VulkanRHI::create_queue(uint32 queue_family_index, uint32 queue_index)
{
    vkGetDeviceQueue(logical_device_, queue_family_index, queue_index, nullptr);
}

void VulkanRHI::submit_to_queue(VulkanQueue queue, const std::vector<VkSemaphore> &wait_semaphores,
                                const std::vector<VkSemaphore> &signal_semaphores,
                                const std::vector<VkPipelineStageFlags> &wait_dst_stage_mask,
                                const std::vector<VkCommandBuffer> &command_buffers, VkFence fence)
{

    VkSubmitInfo submit_info{};
    submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.pCommandBuffers = command_buffers.data();
    submit_info.commandBufferCount = command_buffers.size();
    submit_info.pWaitSemaphores = wait_semaphores.data();
    submit_info.waitSemaphoreCount = wait_semaphores.size();
    submit_info.pWaitDstStageMask = wait_dst_stage_mask.data();
    submit_info.pSignalSemaphores = signal_semaphores.data();
    submit_info.signalSemaphoreCount = signal_semaphores.size();

    VK_ASSERT_SUCCESS(vkQueueSubmit(queue.queue_, 1, &submit_info, fence))
}

void VulkanRHI::release_render_pass(VkRenderPass render_pass)
{
    vkDestroyRenderPass(logical_device_, render_pass, nullptr);
}

void VulkanRHI::command_begin_render_pass(VkCommandBuffer command_buffer, VkRenderPass render_pass,
                                          VkFramebuffer framebuffer, VkExtent2D extent)
{
    VkClearValue clear_color = {{{0.0f, 0.0f, 0.0f, 1.0f}}};
    VkRenderPassBeginInfo render_pass_begin_info{};
    render_pass_begin_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    render_pass_begin_info.renderPass = render_pass;
    render_pass_begin_info.framebuffer = framebuffer;
    render_pass_begin_info.renderArea.extent = extent;
    render_pass_begin_info.renderArea.offset = {0,0};
    render_pass_begin_info.clearValueCount = 1;
    render_pass_begin_info.pClearValues = &clear_color;
    vkCmdBeginRenderPass(command_buffer, &render_pass_begin_info, VK_SUBPASS_CONTENTS_INLINE);
}

void VulkanRHI::command_end_render_pass(VkCommandBuffer command_buffer)
{
    vkCmdEndRenderPass(command_buffer);
}

void VulkanRHI::reset_command_pool(VkCommandPool command_pool)
{
    vkResetCommandPool(logical_device_, command_pool, 0);
}

void VulkanRHI::free_command_pool(VkCommandPool &command_pool)
{
    vkDestroyCommandPool(logical_device_, command_pool, nullptr);
}

void VulkanRHI::command_draw()
{
}

void VulkanRHI::command_draw_indexed()
{
//    vkCmdDrawIndexed()
}

void VulkanRHI::command_draw_indirect()
{
//    vkCmdDrawIndirect()
}

void VulkanRHI::command_draw_indexed_indirect()
{
//    vkCmdDrawIndexedIndirect()
}



void VulkanRHI::release_buffer()
{
}

void* VulkanRHI::buffer_map(VulkanBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags memory_map_flags)
{
    void* data;
    VK_ASSERT_SUCCESS(vkMapMemory(logical_device_, buffer.memory, offset, size, memory_map_flags, &data))
    return data;
}

void VulkanRHI::buffer_unmap(VulkanBuffer buffer)
{
    vkUnmapMemory(logical_device_, buffer.memory);
}

VulkanImage VulkanRHI::create_image(uint32 width, uint32 height, VkFormat format, VkImageTiling image_tiling,
                                    VkImageUsageFlags usage, VkMemoryPropertyFlags properties)
{

    VulkanImage image{};
    VkImageCreateInfo image_create_info{};
    image_create_info.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    image_create_info.imageType = VK_IMAGE_TYPE_2D;
    image_create_info.extent.width = width;
    image_create_info.extent.height = height;
    image_create_info.extent.depth = 1;
    image_create_info.mipLevels = 1;
    image_create_info.arrayLayers = 1;
    image_create_info.format = format;
    image_create_info.tiling = image_tiling;
    image_create_info.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    image_create_info.usage = usage;
    image_create_info.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    image_create_info.samples = VK_SAMPLE_COUNT_1_BIT;
    image_create_info.flags = 0;
    VK_ASSERT_SUCCESS(vkCreateImage(logical_device_, &image_create_info, nullptr, &image.image))
    return {};
}

void VulkanRHI::release_image(VulkanImage &image)
{

}

void VulkanRHI::command_copy_buffer(VkCommandBuffer command_buffer, VulkanBuffer src, VulkanBuffer dst, VkDeviceSize size)
{

    VkBufferCopy buffer_copy;
    buffer_copy.srcOffset = 0;
    buffer_copy.dstOffset = 0;
    buffer_copy.size = size;
    vkCmdCopyBuffer(command_buffer, src.buffer, dst.buffer, 1, &buffer_copy);
}

void VulkanRHI::command_copy_image()
{
//    vkCmdCopyImage()
}

void VulkanRHI::command_copy_buffer_to_image()
{
//    vkCmdCopyBufferToImage()
}

void VulkanRHI::command_copy_image_to_buffer()
{
//    vkCmdCopyImageToBuffer()
}

VkSemaphore VulkanRHI::create_semaphore()
{
    VkSemaphoreCreateInfo semaphore_create_info{};
    semaphore_create_info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    VkSemaphore semaphore;
    VK_ASSERT_SUCCESS(vkCreateSemaphore(logical_device_, &semaphore_create_info, nullptr, &semaphore));
    return semaphore;
}


void VulkanRHI::release_semaphore(VkSemaphore &semaphore)
{
//    vkDestroySemaphore()
}

VkFence VulkanRHI::create_fence(bool signaled)
{
    VkFenceCreateInfo fence_create_info{};
    fence_create_info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    fence_create_info.flags = signaled ? VK_FENCE_CREATE_SIGNALED_BIT : 0;

    VkFence fence;
    VK_ASSERT_SUCCESS(vkCreateFence(logical_device_, &fence_create_info, nullptr, &fence));
    return fence;
}

void VulkanRHI::release_fence(VkFence &fence)
{
//    vkDestroyFence()
}

void VulkanRHI::wait_for_fences()
{
//    vkWaitForFences()
}

void VulkanRHI::reset_fence()
{
//    vkResetFences()
}

void VulkanRHI::create_shader_module()
{
    auto read_file = [](const char* file_name) {
        std::ifstream file(file_name, std::ios::ate | std::ios::binary);

        if (!file.is_open()) {
            std::cerr << "failed to open file";
            terminate();
        }

        size_t file_size = (size_t) file.tellg();

        std::vector<char> buffer(file_size);
        file.seekg(0);
        file.read(buffer.data(), file_size);
        file.close();
        return buffer;
    };

    std::vector<char> vertex_shader_code   = read_file("../../Shaders/SpirV/vert.spv");
    std::vector<char> fragment_shader_code = read_file("../../Shaders/SpirV/frag.spv");

    VkShaderModuleCreateInfo vertex_shader_module_create_info{};
    VkShaderModuleCreateInfo fragment_shader_module_create_info{};

    vertex_shader_module_create_info.sType    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    vertex_shader_module_create_info.pCode    = reinterpret_cast<uint32*>(vertex_shader_code.data());
    vertex_shader_module_create_info.codeSize = vertex_shader_code.size();

    fragment_shader_module_create_info.sType    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    fragment_shader_module_create_info.pCode    = reinterpret_cast<uint32*>(fragment_shader_code.data());
    fragment_shader_module_create_info.codeSize = fragment_shader_code.size();

    VK_ASSERT_SUCCESS(
            vkCreateShaderModule(logical_device_, &vertex_shader_module_create_info, nullptr, &vertex_shader_module_))
    VK_ASSERT_SUCCESS(vkCreateShaderModule(logical_device_, &fragment_shader_module_create_info, nullptr,
                                           &fragment_shader_module_))


}

void VulkanRHI::test_record_command_buffers(VkCommandBuffer buffer, uint32 frame_index)
{
    begin_command_buffer(buffer);
    command_begin_render_pass(buffer, render_pass_, frame_resources_[frame_index].framebuffer_, {viewport_.width_, viewport_.height_});
    vkCmdBindPipeline(buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline_.pipeline_);

    VkBuffer vertex_buffers[] = {vertex_buffer_.buffer};
    VkDeviceSize offsets[] = {0};
    vkCmdBindVertexBuffers(buffer, 0, 1, vertex_buffers, offsets);
    vkCmdBindIndexBuffer(buffer, index_buffer_.buffer, 0, VK_INDEX_TYPE_UINT16);

    VkViewport viewport{};
    viewport.x = 0.0f;
    viewport.y = static_cast<float>(viewport_.height_);
    viewport.width = static_cast<float>(viewport_.width_);
    viewport.height = -static_cast<float>(viewport_.height_);
    viewport.minDepth = 0.0f;
    viewport.maxDepth = 1.0f;
    vkCmdSetViewport(buffer, 0, 1, &viewport);

    VkRect2D scissor{};
    scissor.offset = {0,0};
    scissor.extent = {viewport_.width_, viewport_.height_};
    vkCmdSetScissor(buffer, 0, 1, &scissor);
    vkCmdBindDescriptorSets(buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline_.pipeline_layout_, 0, 1, &descriptor_sets[frame_index], 0,
                            nullptr);
    vkCmdDrawIndexed(buffer, static_cast<uint32_t>(indices.size()), 1, 0, 0, 0);
    vkCmdEndRenderPass(buffer);
    end_command_buffer(buffer);
}


void VulkanRHI::test_draw_frame()
{
    FrameContext& current_frame_context = frame_resources_[frame_];
    vkWaitForFences(logical_device_, 1, &current_frame_context.in_flight_fence_, VK_TRUE, UINT64_MAX);
    vkResetFences(logical_device_, 1, &current_frame_context.in_flight_fence_);
    uint32 image_index = acquire_next_image_from_swapchain(viewport_.swapchain_.vk_swapchain_);
    vkResetCommandBuffer(current_frame_context.command_buffer_, 0);
    test_record_command_buffers(current_frame_context.command_buffer_, frame_);
    update_uniform_buffer(frame_);
    submit_to_queue(graphics_queue,
                    {current_frame_context.image_acquired_semaphore_},
                    {current_frame_context.image_rendered_semaphore_},
                    {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT},
                    {current_frame_context.command_buffer_},
                    current_frame_context.in_flight_fence_);

    present_image(viewport_.swapchain_.vk_swapchain_, image_index, &current_frame_context.image_rendered_semaphore_, 1);
    frame_ = (frame_ + 1) % frame_resources_.size();
}

void VulkanRHI::test_create_vertex_buffer()
{

    uint32 size = vertices.size() * sizeof(Vertex);
    VulkanBuffer staging_buffer{};
    staging_buffer = create_buffer(size, VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
                                           VK_MEMORY_PROPERTY_HOST_COHERENT_BIT | VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT);

    void* data;
    vkMapMemory(logical_device_, staging_buffer.memory, 0, size, 0, &data);
    memcpy(data, vertices.data(), size);
    vkUnmapMemory(logical_device_, staging_buffer.memory);

    vertex_buffer_ = create_buffer(size, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
                                           VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

    VkCommandBuffer copy_command_buffer =
            create_command_buffer(frame_resources_[frame_].command_pool);

    begin_command_buffer(copy_command_buffer, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);
    command_copy_buffer(copy_command_buffer, staging_buffer, vertex_buffer_, size);
    end_command_buffer(copy_command_buffer);

    submit_to_queue(graphics_queue, {}, {}, {}, {copy_command_buffer});
    vkQueueWaitIdle(graphics_queue.queue_);

    free_command_buffer(frame_resources_[frame_].command_pool, copy_command_buffer);
    vkDestroyBuffer(logical_device_, staging_buffer.buffer, nullptr);
    vkFreeMemory(logical_device_, staging_buffer.memory, nullptr);
}

void VulkanRHI::test_create_index_buffer()
{
    VkDeviceSize size = indices.size() * sizeof(indices[0]);
    VulkanBuffer staging_buffer = create_buffer(size, VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
                                            VK_MEMORY_PROPERTY_HOST_COHERENT_BIT | VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT);

    void* data = buffer_map(staging_buffer, 0, size, 0);
    memcpy(data, indices.data(), size);
    vkUnmapMemory(logical_device_, staging_buffer.memory);

    index_buffer_ = create_buffer(size, VK_BUFFER_USAGE_INDEX_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                          VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    VkCommandBuffer copy_command_buffer =
            create_command_buffer(frame_resources_[frame_].command_pool);

    begin_command_buffer(copy_command_buffer, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);
    command_copy_buffer(copy_command_buffer, staging_buffer, index_buffer_, size);
    end_command_buffer(copy_command_buffer);

    submit_to_queue(graphics_queue, {}, {}, {}, {copy_command_buffer});
    vkQueueWaitIdle(graphics_queue.queue_);

    free_command_buffer(frame_resources_[frame_].command_pool, copy_command_buffer);
    vkDestroyBuffer(logical_device_, staging_buffer.buffer, nullptr);
    vkFreeMemory(logical_device_, staging_buffer.memory, nullptr);
}

void VulkanRHI::update_uniform_buffer(uint32 current_frame_index)
{
    static std::chrono::time_point start_time = std::chrono::high_resolution_clock::now();

    std::chrono::time_point current_time = std::chrono::high_resolution_clock::now();
    float elapsed_time = std::chrono::duration<float, std::chrono::seconds::period>(current_time-start_time).count();

    UniformBufferObject ubo{};
    float aspect_ratio = viewport_.width_ / (float) viewport_.height_;

    ubo.model = Matrix4F::identity();
    ubo.view = Matrix4F::look_at_rh({2.f+elapsed_time,2,2}, {.57,.57,.57},{0,0,1});
    ubo.projection = Matrix4F::perspective_rh(glm::radians(45.0f), aspect_ratio, 0.1f, 10000.0f);
    memcpy(frame_resources_[current_frame_index].uniformed_buffer_mapped_, &ubo, sizeof(ubo));
}

void VulkanRHI::create_descriptor_pool()
{
    VkDescriptorPoolSize descriptor_pool_size{};
    descriptor_pool_size.type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    descriptor_pool_size.descriptorCount = frame_resources_.size();
    VkDescriptorPoolCreateInfo descriptor_pool_create_info{};
    descriptor_pool_create_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
    descriptor_pool_create_info.poolSizeCount = 1;
    descriptor_pool_create_info.pPoolSizes = &descriptor_pool_size;
    descriptor_pool_create_info.maxSets = frame_resources_.size();
    VK_ASSERT_SUCCESS(vkCreateDescriptorPool(logical_device_, &descriptor_pool_create_info, nullptr, &descriptor_pool));

}

void VulkanRHI::create_descriptor_sets()
{
    std::vector<VkDescriptorSetLayout> layouts(frame_resources_.size(), descriptor_set_layout);
    VkDescriptorSetAllocateInfo descriptor_set_allocate_info{};
    descriptor_set_allocate_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
    descriptor_set_allocate_info.descriptorPool = descriptor_pool;
    descriptor_set_allocate_info.descriptorSetCount = frame_resources_.size();
    descriptor_set_allocate_info.pSetLayouts = layouts.data();
    descriptor_sets.resize(frame_resources_.size());
    VK_ASSERT_SUCCESS(vkAllocateDescriptorSets(logical_device_, &descriptor_set_allocate_info, descriptor_sets.data()))

    for(uint32 i = 0; i < frame_resources_.size(); i++)
    {
        VkDescriptorBufferInfo buffer_info{};
        buffer_info.buffer = frame_resources_[i].uniform_buffer_.buffer;
        buffer_info.offset = 0;
        buffer_info.range = sizeof(UniformBufferObject);

        VkWriteDescriptorSet descriptor_write{};
        descriptor_write.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        descriptor_write.dstSet = descriptor_sets[i];
        descriptor_write.dstBinding = 0;
        descriptor_write.dstArrayElement = 0;
        descriptor_write.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        descriptor_write.descriptorCount = 1;
        descriptor_write.pBufferInfo = &buffer_info;
        vkUpdateDescriptorSets(logical_device_, 1, &descriptor_write, 0, nullptr);
    }
}






