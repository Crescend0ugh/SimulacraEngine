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
    std::vector<char*> ExtensionNames;
    std::vector<char*> ExtensionLayers;




    void CreateInstance();

    VkPhysicalDevice SelectPhysicalDevice(VkInstance InInstance);
    void CreateDevice();

private:
    SVulkanDevice* Device;
};


#endif //SIMULACRAENGINE_SVULKANRHI_H
