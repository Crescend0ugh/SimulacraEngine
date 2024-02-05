//
// Created by avsom on 1/8/2024.
//

#include "../Public/SimulacraVulkanInstance.h"

SVulkanInstance::SVulkanInstance() : Instance(VK_NULL_HANDLE)
{
    PreCreateInstance();
    CreateInstance();
}

SVulkanInstance::~SVulkanInstance()
{
    vkDestroyInstance(Instance, nullptr);
}

void SVulkanInstance::PreCreateInstance()
{
    const SVulkanInstanceExtensions SupportedInstanceExtensions = QueryExtensionSupport();
    SVulkanInstanceExtensions  RequiredInstanceExtensions;
    SVulkanInstanceExtension::GetRequiredExtensions(RequiredInstanceExtensions);

    for (SVulkanInstanceExtension& RequiredInstanceExtension : RequiredInstanceExtensions)
    {
        assert(SVulkanInstanceExtension::FindExtensionByName(SupportedInstanceExtensions, RequiredInstanceExtension.GetExtensionName()));
        RequiredInstanceExtension.SetSupported();
    }

    SVulkanInstanceExtension::GetRequiredExtensions(InstanceExtensions);
}

void SVulkanInstance::CreateInstance()
{


    VkApplicationInfo ApplicationInfo;
    SetZeroVulkanStruct(ApplicationInfo, VK_STRUCTURE_TYPE_APPLICATION_INFO);
    ApplicationInfo.pApplicationName = "Vulkan Application";
    ApplicationInfo.applicationVersion = VK_MAKE_VERSION(0,1,0);
    ApplicationInfo.pEngineName = "Simulacra Engine";
    ApplicationInfo.engineVersion = VK_MAKE_VERSION(0,1,0);
    ApplicationInfo.apiVersion = VK_API_VERSION_1_3;

    SVulkanInstanceExtension::GetRequiredExtensions(InstanceExtensions);

    const char* EnabledExtensionNames[InstanceExtensions.size()];
    for(int i = 0; i < InstanceExtensions.size(); i++)
    {
        EnabledExtensionNames[i] = InstanceExtensions[i].GetExtensionName();

    }


    VkInstanceCreateInfo InstanceCreateInfo;
    SetZeroVulkanStruct(InstanceCreateInfo, VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO);
    InstanceCreateInfo.enabledExtensionCount = InstanceExtensions.size();
    InstanceCreateInfo.enabledLayerCount = 0;
    InstanceCreateInfo.ppEnabledExtensionNames = EnabledExtensionNames;
    InstanceCreateInfo.ppEnabledLayerNames = nullptr;

    VkResult Result = vkCreateInstance(&InstanceCreateInfo, nullptr, &Instance);

    if(Result != VK_SUCCESS)
    {
        std::cout << "Couldn't create Vulkan Instance.\n";
    }

    else
    {
        std::cout << "======= Created Vulkan Instance! =======\n\n";
    }


}

void SVulkanInstance::PostCreateInstance()
{

}

SVulkanInstanceExtensions SVulkanInstance::QueryExtensionSupport()
{
    uint32   ExtensionPropertiesCount;
    VkResult Result = vkEnumerateInstanceExtensionProperties(nullptr, &ExtensionPropertiesCount, nullptr);
    if(Result != VK_SUCCESS)
    {
        std::cout << "Unable to query instance extension properties\n";
    }

    std::vector<VkExtensionProperties> SupportedInstanceExtensionProperties(ExtensionPropertiesCount);

    Result = vkEnumerateInstanceExtensionProperties(nullptr, &ExtensionPropertiesCount, SupportedInstanceExtensionProperties.data());
    if(Result != VK_SUCCESS)
    {
        std::cout << "Unable to query instance extension properties\n";
    }


    SVulkanInstanceExtensions SupportedExtensions;
    for (VkExtensionProperties& ExtensionProperties : SupportedInstanceExtensionProperties)
    {
        SupportedExtensions.emplace_back(ExtensionProperties.extensionName);
    }

    return SupportedExtensions;
}
