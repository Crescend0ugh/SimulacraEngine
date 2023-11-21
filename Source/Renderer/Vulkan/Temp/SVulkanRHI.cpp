//
// Created by avsom on 10/23/2023.
//


#include "SimulacraVulkan.h"
#include "SVulkanRHI.h"


void SVulkanRHI::CreateInstance() {

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
    std::vector<VkPhysicalDevice> PhysicalDevices;
    PhysicalDevices.reserve(PhysicalDeviceCount);
    vkEnumeratePhysicalDevices(InInstance, &PhysicalDeviceCount, PhysicalDevices.data());
    return PhysicalDevices[0];

}

void SVulkanRHI::CreateDevice(SVulkanDevice *Device)
{

    VkPhysicalDevice PhysicalDevice = SelectPhysicalDevice(Instance);

    VkDeviceCreateInfo DeviceInfo;
    SetZeroVulkanStruct(DeviceInfo, VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO);


}

SVulkanRHI::SVulkanRHI():
        Device(nullptr)
{

}

void SVulkanRHI::Init() {

}

void SVulkanRHI::Shutdown() {

}
