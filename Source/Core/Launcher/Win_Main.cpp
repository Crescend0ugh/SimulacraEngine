#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>


#include <thread>

#include "../../RendererBackend/Vulkan/Public/SimulacraVulkanInstance.h"
#include "../../RendererBackend/Vulkan/Public/SimulacraVulkanDevice.h"


#define NUM_PROCESSORS




int main()
{
    vulkan_instance instance;
    vulkan_device device;
    device.select_physical_device(instance);
    device.initialize_logical_device();


    return 0;
}