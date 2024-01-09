//
// Created by avsom on 1/8/2024.
//

#pragma once

#include "SimulacraVulkan.h"


class SVulkanInstance
{

public:

    SVulkanInstance();

    ~SVulkanInstance();

    // Query for supported extensions
    void PreCreateInstance();

    void CreateInstance();

    void PostCreateInstance();


    VkInstance GetHandle() { return Instance; }


private:

    SVulkanInstanceExtensions QueryExtensionSupport();

    VkInstance                Instance;
    SVulkanInstanceExtensions InstanceExtensions;
    SVulkanInstanceLayers     InstanceLayers;

};
