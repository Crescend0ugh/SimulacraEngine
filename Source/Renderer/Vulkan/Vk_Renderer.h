//
// Created by avsom on 10/11/2023.
//

#ifndef SIMULACRAENGINE_VK_RENDERER_H
#define SIMULACRAENGINE_VK_RENDERER_H

#include <vulkan/vulkan.h>



class Vk_Renderer
{

public:


    bool Initialize();
    bool Deintialize();



protected:

    void CreateInstance();
    void CreateSurface();
    void CreatePhysicalDevice();
    void CreateLogicalDevice();
    void CreateSwapChain();
private:

    VkInstance Instance;
    VkSurfaceKHR Surface;
    VkPhysicalDevice PhysicalDevice;
    VkDevice Device;
    VkQueue GraphicsQueue;
    VkQueue PresentQueue;

};

#endif //SIMULACRAENGINE_VK_RENDERER_H
