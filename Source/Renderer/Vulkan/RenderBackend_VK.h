//
// Created by avsom on 9/13/2023.

#define VK_USE_PLATFORM_WIN32_KHR
#include <windows.h>
#include <vulkan/vulkan.h>

#ifndef SIMULACRAENGINE_RENDERBACKEND_H
#define SIMULACRAENGINE_RENDERBACKEND_H


class RenderBackend_VK {

};


static void CreateInstance();

static void CreateSurface();

static void EnumeratePhysicalDevices();

#endif //SIMULACRAENGINE_RENDERBACKEND_H
