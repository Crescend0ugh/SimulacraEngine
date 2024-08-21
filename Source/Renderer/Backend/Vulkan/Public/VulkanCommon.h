//
// Created by avsom on 8/20/2024.
//

#pragma once

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
