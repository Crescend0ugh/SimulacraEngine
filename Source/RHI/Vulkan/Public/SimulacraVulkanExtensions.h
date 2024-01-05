//
// Created by avsom on 1/4/2024.
//

#pragma once

#include "SimulacraVulkan.h"

struct SVulkanExtensionBase
{
private:

    const char* ExtensionName;
    const uint8 ApiVersion;
    const bool  IsUsed;

};

class SVulkanInstanceExtension : public SVulkanExtensionBase
{

public:


private:

};

class SVulkanDeviceExtension : public SVulkanExtensionBase
{

};