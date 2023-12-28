//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANRHI_H
#define SIMULACRAENGINE_SIMULACRAVULKANRHI_H


#include "SimulacraVulkanDevice.h"

class VulkanDevice;

class VulkanRHI {

    void Shutdown();

public:
    VulkanRHI();

    void Init();

protected:

    VkInstance         Instance;
    std::vector<char*> InstanceExtensions;
    std::vector<char*> InstanceLayers;




    void CreateInstance();
    void InitInstance();
    void CreateDevice();
    void InitDevice();

    VkPhysicalDevice SelectPhysicalDevice(VkInstance InInstance);

private:
    VulkanDevice* Device;
};


#endif //SIMULACRAENGINE_SIMULACRAVULKANRHI_H
