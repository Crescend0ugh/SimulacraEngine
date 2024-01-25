//
// Created by avsom on 10/23/2023.
//


#include "../Public/SimulacraVulkan.h"
#include "../../../../Source/Core/SimulacraGameViewport.h"
#include "../Public/SimulacraVulkanRHI.h"


void SVulkanRHI::CreateInstance()
{

    Instance = new SVulkanInstance();
}

VkPhysicalDevice SVulkanRHI::SelectPhysicalDevice(VkInstance InInstance)
{
    VkResult Result;
    uint32   PhysicalDeviceCount = 0;
    Result = vkEnumeratePhysicalDevices(InInstance, &PhysicalDeviceCount, nullptr);
    if (Result != VK_SUCCESS)
    {
        std::cout << "Could not find a compatible Vulkan device or driver\n";
    } else
    {
        std::cout << "======= Found " << PhysicalDeviceCount << " Vulkan Devices. =======\n\n";
    }
    std::vector<VkPhysicalDevice> PhysicalDevices(PhysicalDeviceCount);
    vkEnumeratePhysicalDevices(InInstance, &PhysicalDeviceCount, PhysicalDevices.data());
    return PhysicalDevices[0];

}

//TODO move physical device creation to the SVulkanDevice class
void SVulkanRHI::CreateDevice()
{

    VkPhysicalDevice PhysicalDevice = SelectPhysicalDevice(Instance->GetHandle());

    Device = new SVulkanDevice(this, PhysicalDevice);

    Device->CreatePhysicalDevice();
    Device->CreateLogicalDevice();


}

void SVulkanRHI::CreateSwapchain()
{
    Swapchain = new SVulkanSwapchain(Instance->GetHandle(), Device, SGameViewport::GetWindow()->GetHandle());

}


SVulkanRHI::SVulkanRHI() : Instance(VK_NULL_HANDLE),
                           Device(nullptr)
{

}

void SVulkanRHI::Init()
{

    CreateInstance();
    CreateDevice();
    CreateSwapchain();
    CreatePipeline();
    CreateCommandPool();


}

void SVulkanRHI::Shutdown()
{

}

void SVulkanRHI::CreatePipeline()
{
    Pipeline = new SVulkanPipeline(Device, Swapchain);
}

void SVulkanRHI::CreateCommandPool()
{
    CommandPool         = new SVulkanCommandPool(Device, Device->GetGraphicsQueue()->GetFamilyIndex());
    ActiveCommandBuffer = new SVulkanCommandBuffer(Device, CommandPool);

}

void SVulkanRHI::DrawFrame()
{
    vkWaitForFences(Device->GetHandle(), 1, &Swapchain->GetInFlightFence()->GetHandle(), VK_TRUE, UINT64_MAX);
    vkResetFences(Device->GetHandle(), 1, &Swapchain->GetInFlightFence()->GetHandle());

    uint32 ImageIndex;

    vkAcquireNextImageKHR(Device->GetHandle(), Swapchain->GetHandle(), UINT64_MAX,
                          Swapchain->GetImageAvailableSemaphores()->GetHandle(), VK_NULL_HANDLE, &ImageIndex);
    vkResetCommandBuffer(ActiveCommandBuffer->GetHandle(), 0);
    SVulkanCommandBuffer::RecordCommandBuffer(ActiveCommandBuffer, Swapchain, Pipeline,  ImageIndex);
    VkSubmitInfo SubmitInfo{};
    SubmitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

    VkSemaphore          WaitSemaphores[] = {Swapchain->GetImageAvailableSemaphores()->GetHandle()};
    VkPipelineStageFlags WaitStages[]     = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
    SubmitInfo.waitSemaphoreCount = 1;
    SubmitInfo.pWaitSemaphores    = WaitSemaphores;
    SubmitInfo.pWaitDstStageMask  = WaitStages;

    SubmitInfo.commandBufferCount = 1;
    SubmitInfo.pCommandBuffers    = &ActiveCommandBuffer->GetHandle();

    SubmitInfo.signalSemaphoreCount = 1;
    SubmitInfo.pSignalSemaphores    = &Swapchain->GetRenderFinishedSemaphores()->GetHandle();

    if (vkQueueSubmit(Device->GetGraphicsQueue()->GetHandle(), 1, &SubmitInfo,
                      Swapchain->GetInFlightFence()->GetHandle()) != VK_SUCCESS)
    {
        throw std::runtime_error("failed to submit draw command buffer!");
    }

    VkPresentInfoKHR presentInfo{};
    presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;

    presentInfo.waitSemaphoreCount = 1;
    presentInfo.pWaitSemaphores = &Swapchain->GetRenderFinishedSemaphores()->GetHandle();

    presentInfo.swapchainCount = 1;
    presentInfo.pSwapchains = &Swapchain->GetHandle();

    presentInfo.pImageIndices = &ImageIndex;

    vkQueuePresentKHR(Device->GetPresentQueue()->GetHandle(), &presentInfo);

}


SVulkanSemaphore::SVulkanSemaphore(SVulkanDevice *InDevice) : Device(InDevice), Semaphore(VK_NULL_HANDLE)
{
    VkSemaphoreCreateInfo SemaphoreCreateInfo;
    SetZeroVulkanStruct(SemaphoreCreateInfo, VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO);
    vkCreateSemaphore(Device->GetHandle(), &SemaphoreCreateInfo, nullptr, &Semaphore);

}

SVulkanSemaphore::~SVulkanSemaphore()
{
    vkDestroySemaphore(Device->GetHandle(), Semaphore, nullptr);
}

SVulkanFence::SVulkanFence(SVulkanDevice *InDevice) : Device(InDevice), Fence(VK_NULL_HANDLE)
{
    VkFenceCreateInfo FenceCreateInfo;
    SetZeroVulkanStruct(FenceCreateInfo, VK_STRUCTURE_TYPE_FENCE_CREATE_INFO);
    FenceCreateInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

    vkCreateFence(Device->GetHandle(), &FenceCreateInfo, nullptr, &Fence);
}

SVulkanFence::~SVulkanFence()
{
    vkDestroyFence(Device->GetHandle(), Fence, nullptr);
}
