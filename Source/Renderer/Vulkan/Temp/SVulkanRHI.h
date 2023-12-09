//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SVULKANRHI_H
#define SIMULACRAENGINE_SVULKANRHI_H


#include "SimulacraVulkanDevice.h"

class SVulkanDevice;

class SVulkanRHI {

    void Shutdown();

public:
    SVulkanRHI();

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
    SVulkanDevice* Device;
};


#endif //SIMULACRAENGINE_SVULKANRHI_H
