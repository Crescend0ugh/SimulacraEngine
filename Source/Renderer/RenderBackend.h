//
// Created by avsom on 9/13/2023.
//
#include <stdint.h>

#ifndef SIMULACRAENGINE_RENDERBACKEND_H
#define SIMULACRAENGINE_RENDERBACKEND_H


class RenderBackend {

private:
    void Init();

    void CreateInstance();

    CreateSurface();

    EnumeratePhysicalDevices();

    SelectPhysicalDevices();

    CreateLogicalDeviceAndQueues();

    CreateSemaphores();

    CreatrCommandPool();

    CreateCommandBuffer();

    CreateSwapChain();

    CreateRenderPass();

    CreatePipelineCache();

    CreateFrameBuffers();

};


#endif //SIMULACRAENGINE_RENDERBACKEND_H
