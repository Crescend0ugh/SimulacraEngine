//
// Created by avsom on 12/31/2023.
//

#pragma once


#include "SimulacraVulkan.h"

class SVulkanResource
{
public:
    SVulkanResource();


private:

    SVulkanDevice* OwningDevice;
};

class SVulkanBuffer : public SVulkanResource
{
public:

    SVulkanBuffer();


private:
    VkBuffer Buffer;
};

class SVulkanTexture
{

public:

private:


    VkImage Image;

};

