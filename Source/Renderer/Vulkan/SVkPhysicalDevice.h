//
// Created by avsom on 10/18/2023.
//

#ifndef SIMULACRAENGINE_SVKPHYSICALDEVICE_H
#define SIMULACRAENGINE_SVKPHYSICALDEVICE_H
#include <vulkan/vulkan.h>

struct SVkPhysicalDevice
{
    SVkPhysicalDevice() {};
    SVkPhysicalDevice(VkPhysicalDevice PhysicalDevice) { SPhysicalDevice = PhysicalDevice; }



    VkPhysicalDevice SPhysicalDevice;


};


#endif //SIMULACRAENGINE_SVKPHYSICALDEVICE_H
