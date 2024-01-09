//
// Created by avsom on 1/4/2024.
//

#pragma once

#include "SimulacraVulkan.h"



class SVulkanDevice;
class SVulkanRHI;





enum EExtensionActivationPolicy : uint8
{
    AUTO_ACTIVATE,
    MANUALLY_ACTIVATE
};

/**
 * @brief The base class for vulkan extensions
 *
 */
class SVulkanExtension
{


public:

    explicit SVulkanExtension(const char* InExtensionName);
    SVulkanExtension(const char* InExtensionName, bool InSupport, EExtensionActivationPolicy InActivationPolicy);

    const char * GetExtensionName() const
    { return ExtensionName; }


    template<class ExtensionType>
    static const ExtensionType* FindExtensionByName(const std::vector<ExtensionType>& Extensions, const char* ExtensionName)
    {
        for (const ExtensionType& Extension : Extensions)
        {
            if(strcmp(Extension.GetExtensionName(), ExtensionName) == 0)
            {
                return &Extension;
            }

        }

        return nullptr;
    }



    bool IsSupported() const { return Supported; }
    bool IsLoaded()    const { return Loaded; }
    bool IsActivated() const { return Activated; }
    bool IsUsed()      const { return (Loaded & Supported & Activated); }

    void SetSupported(bool Value = true);
    void SetLoaded   (bool Value = true);
    void SetActivated(bool Value = true);


protected:


    const char* ExtensionName;

    bool Supported;

    bool Activated;

    bool Loaded;

    EExtensionActivationPolicy ActivationPolicy;



};

class SVulkanDeviceExtension : public SVulkanExtension
{

public:

    explicit SVulkanDeviceExtension(const char* ExtensionName);
    SVulkanDeviceExtension(const char* ExtensionName, bool Support, EExtensionActivationPolicy ActivationPolicy);
    ~SVulkanDeviceExtension() = default;

    static SVulkanExtension* FindExtensionByName(const std::vector<SVulkanExtension*>& Extensions, const char* ExtensionName)
    {
        for (SVulkanExtension* Extension : Extensions)
        {
            if(strcmp(Extension->GetExtensionName(), ExtensionName) == 0)
            {
                return Extension;
            }

        }

        return nullptr;
    }

public:

    static void GetRequiredExtensions(SVulkanDeviceExtensions &OutExtensions);



private:

    static SVulkanDevice* Device;

};



class SVulkanInstanceExtension : public SVulkanExtension
{

public:

    explicit SVulkanInstanceExtension(const char* ExtensionName);
    SVulkanInstanceExtension(const char* ExtensionName, bool Support, EExtensionActivationPolicy ActivationPolicy);
    ~SVulkanInstanceExtension() = default;

    typedef std::vector<SVulkanInstanceExtension> SVulkanInstanceExtensions;

public:

    static void GetRequiredExtensions(SVulkanInstanceExtensions& OutExtensions);


private:

    static SVulkanRHI* Instance;

};

