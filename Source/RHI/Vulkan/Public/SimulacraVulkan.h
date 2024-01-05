//
// Created by avsom on 10/15/2023.
//

#pragma once



#include "../../../Core/Sys/Precompiled.h"
#include <vulkan/vulkan.h>

// Vulkan utilities
#include "SimulacraVulkanDebugUtils.h"
#include "SimulacraVulkanUtils.h"

// Platform specific implementations
#include "SimulacraVulkanPlatform.h"
#include "../Platforms/Windows/SimulacraVulkanWindowsPlatform.h"
#include "../Platforms/Linux/SimulacraVulkanLinuxPlatform.h"

// Vulkan classes
#include "SimulacraVulkanRHI.h"
#include "SimulacraVulkanDevice.h"
#include "SimulacraVulkanQueue.h"
#include "SimulacraVulkanSwapchain.h"
#include "SimulacraVulkanViewport.h"
#include "SimulacraVulkanPipeline.h"

