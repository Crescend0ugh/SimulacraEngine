//
// Created by avsom on 10/23/2023.
//

#include "SimulacraVulkanRHI.h"
#include "SimulacraVulkanCommon.h"

void SimulacraVulkanRHI::CreateInstance() {

}

void SimulacraVulkanRHI::SelectDevice(VkInstance InInstance)
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



}

void SimulacraVulkanRHI::CreateDevice(SVulkanDevice *Device)
{
    VkDeviceCreateInfo DeviceInfo;
    SetZeroVulkanStruct(DeviceInfo, VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO);
    DeviceInfo.p


}
