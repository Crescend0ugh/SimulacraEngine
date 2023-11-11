//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SVULKANRHI_H
#define SIMULACRAENGINE_SVULKANRHI_H


#include "SimulacraVulkanDevice.h"


class SVulkanRHI {

    SVulkanRHI();

    void Init();
    void Shutdown();

protected:

    VkInstance         Instance;
    std::vector<char*> ExtensionNames;
    std::vector<char*> ExtensionLayers;


    SVulkanDevice Device;

    void CreateInstance();

    VkPhysicalDevice SelectPhysicalDevice(VkInstance InInstance);
    void CreateDevice(SVulkanDevice* Device);


};


#endif //SIMULACRAENGINE_SVULKANRHI_H
