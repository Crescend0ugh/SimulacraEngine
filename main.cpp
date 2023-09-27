#define GlFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <iostream>
#include "Source/Renderer/RenderBackend.h"


class TutorialVulkanApplication
{
public:
    void Run()
    {
        InitVulkan();
        MainLoop();
        Cleanup();
    }

private:

    void InitVulkan()
    {

    }

    void MainLoop()
    {

    }

    void Cleanup()
    {

    }

};


