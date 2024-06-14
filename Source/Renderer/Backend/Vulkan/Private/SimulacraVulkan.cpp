//
// Created by avsom on 6/5/2024.
//

#include "SimulacraVulkan.h"

void vulkan_renderer::init()
{
    create_instance();
    select_physical_device();
    create_device();

}

void vulkan_renderer::shutdown()
{
    release_device();
    release_instance();

}

void vulkan_renderer::create_instance()
{
    VkApplicationInfo application_info{};
    application_info.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    application_info.pApplicationName   = "Vulkan Application";
    application_info.applicationVersion = VK_MAKE_VERSION(0, 1, 0);
    application_info.pEngineName        = "Simulacra Engine";
    application_info.engineVersion      = VK_MAKE_VERSION(0, 1, 0);
    application_info.apiVersion         = VK_API_VERSION_1_3;

    uint32   instance_extension_count = 0;
    VkResult result                   = vkEnumerateInstanceExtensionProperties(nullptr, &instance_extension_count,
                                                                               nullptr);

    if (instance_extension_count == 0 || result != VK_SUCCESS) {
        printf("failed to retrieve instance extensions!");
        terminate();
    }

    std::vector<VkExtensionProperties> supported_extensions(instance_extension_count);
    std::unordered_set<const char*>    supported_extension_names;

    result = vkEnumerateInstanceExtensionProperties(nullptr, &instance_extension_count,
                                                    supported_extensions.data());

    if (instance_extension_count == 0 || result != VK_SUCCESS) {
        printf("failed to retrieve instance extensions!");
        terminate();
    }

    for (const VkExtensionProperties &properties: supported_extensions) {
        supported_extension_names.emplace(properties.extensionName);
    }

    for (const char* name: requested_instance_extensions_) {
        if (supported_extension_names.find(name) == supported_extension_names.end()) {
            printf("requested extension unavailable\n ");
            terminate();
        }
    }

    VkInstanceCreateInfo instance_create_info{};
    instance_create_info.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instance_create_info.enabledExtensionCount   = requested_instance_extensions_.size();
    instance_create_info.enabledLayerCount       = 0;
    instance_create_info.ppEnabledExtensionNames = requested_instance_extensions_.data();
    instance_create_info.ppEnabledLayerNames     = nullptr;

    result = vkCreateInstance(&instance_create_info, nullptr, &instance_);

    if (result != VK_SUCCESS) {
        printf("failed to create instance!\n");
        terminate();
    }


}

void vulkan_renderer::release_instance()
{
    vkDestroyInstance(instance_, nullptr);
}

void vulkan_renderer::select_physical_device()
{
    uint32 physical_device_count;

    if (const VkResult result = vkEnumeratePhysicalDevices(instance_, &physical_device_count, nullptr);
            result != VK_SUCCESS) {
        std::cerr << "Couldn't find compatible vulkan logical_handle or driver\n";
        terminate();
    } else {
        std::cout << "======= Found " << physical_device_count << " physical devices. =======\n\n";
    }

    std::vector<VkPhysicalDevice> physical_devices(physical_device_count);
    vkEnumeratePhysicalDevices(instance_, &physical_device_count, physical_devices.data());

    VkPhysicalDevice selected_device = VK_NULL_HANDLE;

    for (const VkPhysicalDevice &i: physical_devices) {
        VkPhysicalDeviceProperties PhysicalDeviceProperties;
        vkGetPhysicalDeviceProperties(i, &PhysicalDeviceProperties);
        if (PhysicalDeviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
            selected_device = i;
        }
    }

    if (selected_device == VK_NULL_HANDLE) {
        selected_device = physical_devices[0];
    }

    device_.physical_device_ = selected_device;
}

void vulkan_renderer::create_device()
{
    std::optional<uint32> graphics_queue_family;
    std::optional<uint32> compute_queue_family;
    std::optional<uint32> transfer_queue_family;

    uint32 queue_family_count = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device_.physical_device_, &queue_family_count, nullptr);
    std::vector<VkQueueFamilyProperties> queue_families(queue_family_count);
    vkGetPhysicalDeviceQueueFamilyProperties(device_.physical_device_, &queue_family_count, queue_families.data());


}


void vulkan_renderer::release_device()
{
    VkDevice test = VK_NULL_HANDLE;
    vkDestroyDevice(device_.logical_device_, nullptr);
}

void vulkan_renderer::create_surface()
{

}

void vulkan_renderer::release_surface()
{

}

void vulkan_renderer::create_swapchain()
{
    VkSwapchainCreateInfoKHR swapchain_create_info_khr {};
    swapchain_create_info_khr.sType = VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR;
}

void vulkan_renderer::recreate_swapchain()
{
    VkSwapchainCreateInfoKHR swapchain_create_info_khr {};
    swapchain_create_info_khr.sType = VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR;
    //TODO pass in old vulkan_swapchain
    swapchain_create_info_khr.oldSwapchain = VK_NULL_HANDLE;

}

void vulkan_renderer::release_swapchain(vulkan_swapchain& swapchain)
{
    vkDestroySwapchainKHR(device_.logical_device_, swapchain.vk_swapchain_, nullptr);
}

void vulkan_renderer::create_pipeline_manager()
{

}

void vulkan_renderer::release_pipeline_manager()
{

}

void vulkan_renderer::create_pipeline(const vulkan_graphics_pipeline_description &pipeline_description)
{
}

void vulkan_renderer::release_pipeline()
{

}

void vulkan_renderer::create_render_pass()
{
}

void vulkan_renderer::create_framebuffer(VkRenderPass render_pass, const std::vector<VkImageView> &attachment_views,
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


void vulkan_renderer::release_framebuffer(VkFramebuffer &framebuffer)
{
    vkDestroyFramebuffer(device_.logical_device_, framebuffer, nullptr);
}

void vulkan_renderer::create_command_pool(uint32 queue_family_index)
{
    VkCommandPoolCreateInfo command_pool_create_info {};
    command_pool_create_info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    command_pool_create_info.queueFamilyIndex = queue_family_index;

    //TODO fill this out properly
    vkCreateCommandPool(device_.logical_device_, &command_pool_create_info, nullptr, nullptr);
}


void vulkan_renderer::create_command_buffer(VkCommandPool command_pool)
{

    VkCommandBufferAllocateInfo command_buffer_allocate_info {};
    command_buffer_allocate_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    command_buffer_allocate_info.commandPool = command_pool;
    command_buffer_allocate_info.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    command_buffer_allocate_info.commandBufferCount = 1;

    //TODO fill this out properly
    vkAllocateCommandBuffers(device_.logical_device_, &command_buffer_allocate_info, nullptr);

}

void vulkan_renderer::begin_command_buffer(const VkCommandBuffer command_buffer)
{
    VkCommandBufferBeginInfo command_buffer_begin_info {};
    command_buffer_begin_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

    vkBeginCommandBuffer(command_buffer, &command_buffer_begin_info);

}

void vulkan_renderer::end_command_buffer(const VkCommandBuffer command_buffer)
{
    vkEndCommandBuffer(command_buffer);
}

void vulkan_renderer::reset_command_buffer(VkCommandBuffer command_buffer)
{
    //TODO come back to this to check flags
    vkResetCommandBuffer(command_buffer, 0);
}

void vulkan_renderer::create_queue(uint32 queue_family_index, uint32 queue_index)
{
    vkGetDeviceQueue(device_.logical_device_, queue_family_index, queue_index, nullptr);
}

void vulkan_renderer::submit_to_queue()
{
    VkSubmitInfo submit_info {};
    submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

}

void vulkan_renderer::release_render_pass()
{

}

void vulkan_renderer::begin_render_pass()
{
    VkRenderPassBeginInfo render_pass_begin_info {};
    render_pass_begin_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
}

void vulkan_renderer::end_render_pass()
{
//    vkCmdEndRenderPass();
}

void vulkan_renderer::reset_command_pool()
{

}

void vulkan_renderer::free_command_pool()
{

}

void vulkan_renderer::command_draw()
{
//    vkCmdDraw()
}

void vulkan_renderer::command_draw_indexed()
{
//    vkCmdDrawIndexed()
}

void vulkan_renderer::command_draw_indirect()
{
//    vkCmdDrawIndirect()
}

void vulkan_renderer::command_draw_indexed_indirect()
{
//    vkCmdDrawIndexedIndirect()
}

void vulkan_renderer::create_buffer()
{

}

void vulkan_renderer::release_buffer()
{
}

void* vulkan_renderer::buffer_map()
{
//    vkMapMemory()
    return nullptr;
}

void vulkan_renderer::buffer_unmap()
{
//    vkUnmapMemory()
}

void vulkan_renderer::command_copy_buffer()
{
//    vkCmdCopyBuffer()
}

void vulkan_renderer::command_copy_image()
{
//    vkCmdCopyImage()
}

void vulkan_renderer::command_copy_buffer_to_image()
{
//    vkCmdCopyBufferToImage()
}

void vulkan_renderer::command_copy_image_to_buffer()
{
//    vkCmdCopyImageToBuffer()
}

void vulkan_renderer::create_semaphore()
{
//    vkCreateSemaphore()
}

void vulkan_renderer::release_semaphore()
{
//    vkDestroySemaphore()
}

void vulkan_renderer::create_fence()
{
//    vkCreateFence()
}

void vulkan_renderer::release_fence()
{
//    vkDestroyFence()
}

void vulkan_renderer::wait_for_fences()
{
//    vkWaitForFences()
}

void vulkan_renderer::reset_fence()
{
//    vkResetFences()
}




