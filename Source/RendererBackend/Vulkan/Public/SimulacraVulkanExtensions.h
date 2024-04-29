//
// Created by avsom on 1/4/2024.
//

#pragma once

#include <vector>

struct vulkan_device;
struct vulkan_instance;

struct vulkan_instance_extension
{

    explicit vulkan_instance_extension(const char* extension_name);
    ~vulkan_instance_extension();
    bool is_supported() const;
    const char* get_name() const { return extension_name_; }
    static std::vector<vulkan_instance_extension> required_extensions();

private:

    static  vulkan_instance* instance_;
    const char *extension_name_;
};

struct vulkan_device_extension
{

    explicit vulkan_device_extension(const char* extension_name);
    ~vulkan_device_extension();
    bool is_supported();
    const char* get_name() const { return extension_name_; }
    static std::vector<vulkan_device_extension> required_extensions();



private:

    static vulkan_device* device_;
    const char *extension_name_;
};
