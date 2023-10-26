//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANRHI_H
#define SIMULACRAENGINE_SIMULACRAVULKANRHI_H


#include "SimEngineVulkan.h"

class SimulacraVulkanRHI {


    void InitRHI();

protected:

    VkInstance    Instance;
    std::vector<char*> ExtensionNames;
    std::vector<char*> ExtensionLayers;


    SVulkanDevice Device;

    void CreateInstance();
    void SelectDevice(VkInstance InInstance);
    void CreateDevice(SVulkanDevice* Device);


};


#endif //SIMULACRAENGINE_SIMULACRAVULKANRHI_H
