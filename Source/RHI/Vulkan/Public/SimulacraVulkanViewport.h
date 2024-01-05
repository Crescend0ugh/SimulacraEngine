//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANVIEWPORT_H
#define SIMULACRAENGINE_SIMULACRAVULKANVIEWPORT_H

#include "SimulacraVulkan.h"
#include "SimulacraVulkanSwapchain.h"

class SVulkanViewport
{

public:

    SVulkanViewport(SVulkanDevice* InDevice, SVulkanSwapchain* InSwapchain);
    ~SVulkanViewport();

protected:


    void GetImagesFromSwapchain();
    void CreateImageViews();




private:

    SVulkanDevice    *Device;
    SVulkanSwapchain *Swapchain;

    uint32                   BufferCount = 3;
    std::vector<VkImage>     Images;
    std::vector<VkImageView> ImageViews;
    VkFormat                 ImageFormat;


};


#endif //SIMULACRAENGINE_SIMULACRAVULKANVIEWPORT_H
