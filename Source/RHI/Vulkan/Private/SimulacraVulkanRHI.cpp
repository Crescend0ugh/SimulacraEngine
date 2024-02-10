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
    CreateVertexBuffer();
    CreateSwapchain();
    CreatePipeline();



}

void SVulkanRHI::Shutdown()
{

}

void SVulkanRHI::CreatePipeline()
{
    Pipeline = new SVulkanPipeline(Device, Swapchain);
}


void SVulkanRHI::DrawFrame()
{
    vkWaitForFences(Device->GetHandle(), 1, &Swapchain->GetCurrInFlightFence()->GetHandle(), VK_TRUE, UINT64_MAX);

    Swapchain->AcquireNextImage();

    vkResetFences(Device->GetHandle(), 1, &Swapchain->GetCurrInFlightFence()->GetHandle());

    vkResetCommandBuffer(Swapchain->GetCurrCommandBuffer()->GetHandle(), /*VkCommandBufferResetFlagBits*/ 0);


    SVulkanCommandBuffer::RecordCommandBuffer(Swapchain->GetCurrCommandBuffer(),Swapchain, Pipeline, VertexBuffer);


    Device->GetGraphicsQueue()->Submit(Swapchain->GetCurrCommandBuffer(), 1, Swapchain->GetCurrImageAcquiredSemaphore(),
                                       1, Swapchain->GetCurrRenderFinishedSemaphore(), Swapchain->GetCurrInFlightFence());



    Swapchain->Present();

}

void SVulkanRHI::CreateVertexBuffer()
{
    VertexBuffer = new SVulkanBuffer(Device);
    VkMemoryRequirements MemoryRequirements;
    vkGetBufferMemoryRequirements(Device->GetHandle(), VertexBuffer->GetHandle(), &MemoryRequirements);

    VertexBuffer->AllocateMemory(MemoryRequirements.memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

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
