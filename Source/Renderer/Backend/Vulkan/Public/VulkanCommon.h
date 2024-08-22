//
// Created by avsom on 8/20/2024.
//

#pragma once
#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>

#define VK_ASSERT_SUCCESS(statement) \
{                                    \
VkResult result = statement;  \
if(result == VK_SUCCESS)     \
{                            \
}                            \
                             \
else                         \
{                            \
    std::cout << #statement << " failed\n";   \
}                                    \
}\
