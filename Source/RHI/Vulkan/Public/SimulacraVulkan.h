//
// Created by avsom on 10/15/2023.
//

#pragma once






// Include Vulkan and Core includes
#include "../../../Core/Sys/Precompiled.h"
#include <vulkan/vulkan.h>

// Forward declarations
class SVulkanDeviceExtension;
class SVulkanInstanceExtension;
class SVulkanDeviceLayer;
class SVulkanInstanceLayer;
typedef std::vector<SVulkanDeviceExtension>   SVulkanDeviceExtensions;
typedef std::vector<SVulkanInstanceExtension> SVulkanInstanceExtensions;
typedef std::vector<SVulkanDeviceLayer>       SVulkanDeviceLayers;
typedef std::vector<SVulkanInstanceLayer>     SVulkanInstanceLayers;
class SVulkanRHI;
class SVulkanDevice;
class SVulkanQueue;
class SVulkanSwapchain;
class SVulkanViewport;
class SVulkanPipeline;

// Vulkan utilities
#include "SimulacraVulkanDebugUtils.h"
#include "SimulacraVulkanUtils.h"

// Platform specific implementations
#include "SimulacraVulkanPlatform.h"
#include "../Platforms/Windows/SimulacraVulkanWindowsPlatform.h"
#include "../Platforms/Linux/SimulacraVulkanLinuxPlatform.h"


// Vulkan classes
#include "SimulacraVulkanExtensions.h"
#include "SimulacraVulkanLayers.h"
#include "SimulacraVulkanRHI.h"
#include "SimulacraVulkanDevice.h"
#include "SimulacraVulkanQueue.h"
#include "SimulacraVulkanSwapchain.h"
#include "SimulacraVulkanViewport.h"
#include "SimulacraVulkanPipeline.h"

