//
// Created by avsom on 1/6/2024.
//

#include "../Public/SimulacraVulkanExtensions.h"



SVulkanExtension::SVulkanExtension(const char *InExtensionName, bool InSupport, EExtensionActivationPolicy InActivationPolicy) :
ExtensionName(InExtensionName),
Supported(InSupport),
Loaded(false),
Activated(InActivationPolicy == EExtensionActivationPolicy::AUTO_ACTIVATE),
ActivationPolicy(InActivationPolicy)
{

}

void SVulkanExtension::SetSupported(bool Value)
{
    Supported = Value;
}

void SVulkanExtension::SetLoaded(bool Value)
{
    Loaded = Value;
}

void SVulkanExtension::SetActivated(bool Value)
{
    if(ActivationPolicy == EExtensionActivationPolicy::AUTO_ACTIVATE)
    {
        assert(Value == true);
    }

    else
    {
        Activated = true;
    }
}




SVulkanDeviceExtension::SVulkanDeviceExtension(const char *ExtensionName, bool Support, EExtensionActivationPolicy ActivationPolicy) : SVulkanExtension(ExtensionName, Support, ActivationPolicy)
{

}

void SVulkanDeviceExtension::GetRequiredExtensions(SVulkanDeviceExtensions &OutExtensions)
{

    //Required extensions
    OutExtensions.emplace_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);


    //Get platform extensions
    SVulkanPlatform::GetDeviceExtensions(OutExtensions);

}



SVulkanInstanceExtension::SVulkanInstanceExtension(const char *ExtensionName, bool Support, EExtensionActivationPolicy ActivationPolicy) : SVulkanExtension(ExtensionName, Support, ActivationPolicy)
{

}

void SVulkanInstanceExtension::GetRequiredExtensions(SVulkanInstanceExtensions& OutExtensions)
{

    //Required extensions



    //Get platform extensions
    SVulkanPlatform::GetInstanceExtensions(OutExtensions);

}