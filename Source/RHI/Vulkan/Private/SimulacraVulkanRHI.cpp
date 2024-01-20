//
// Created by avsom on 10/23/2023.
//


#include "../Public/SimulacraVulkan.h"
#include "../../../../Source/Core/SimulacraGameViewport.h"
#include "../Public/SimulacraVulkanRHI.h"


void SVulkanRHI::CreateInstance() {

  Instance = new SVulkanInstance();
  }

VkPhysicalDevice SVulkanRHI::SelectPhysicalDevice(VkInstance InInstance)
{
    VkResult Result;
    uint32 PhysicalDeviceCount = 0;
    Result = vkEnumeratePhysicalDevices(InInstance, &PhysicalDeviceCount, nullptr );
    if(Result != VK_SUCCESS)
    {
        std::cout << "Could not find a compatible Vulkan device or driver\n";
    }

    else
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




SVulkanRHI::SVulkanRHI(): Instance(VK_NULL_HANDLE),
                          Device(nullptr)
{

}

void SVulkanRHI::Init() {

    CreateInstance();
    CreateDevice();
    CreateSwapchain();
    CreatePipeline();
    CreateCommandPool();
    

}

void SVulkanRHI::Shutdown() {

}

void SVulkanRHI::CreatePipeline()
{
    Pipeline = new SVulkanPipeline(Device, Swapchain);
}

void SVulkanRHI::CreateCommandPool()
{
    CommandPool = new SVulkanCommandPool(Device, Device->GetGraphicsQueue()->GetFamilyIndex());
}

void SVulkanRHI::DrawFrame()
{
    uint32 ImageIndex;
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

SVulkanFence::SVulkanFence(SVulkanDevice* InDevice) : Device(InDevice), Fence(VK_NULL_HANDLE)
{
    VkFenceCreateInfo FenceCreateInfo;
}

SVulkanFence::~SVulkanFence()
{
    vkDestroyFence(Device->GetHandle(), Fence, nullptr);
}
