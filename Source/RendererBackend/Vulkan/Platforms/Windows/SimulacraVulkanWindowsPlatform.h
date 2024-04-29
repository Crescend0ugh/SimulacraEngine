//
// Created by avsom on 12/9/2023.
//

#pragma once




#define VK_USE_PLATFORM_WIN32_KHR

#include "../../Public/SimulacraVulkan.h"

void create_surface()
{
    //TODO fill out structure and return created surface
    VkWin32SurfaceCreateInfoKHR surface_create_info {};
    surface_create_info.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
};