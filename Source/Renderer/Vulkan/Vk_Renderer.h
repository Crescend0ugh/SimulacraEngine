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
    
private:

    VkInstance Instance;
    VkPhysicalDevice PhysicalDevice;
    VkDevice Device;



};

#endif //SIMULACRAENGINE_VK_RENDERER_H
