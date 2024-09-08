//
// Created by avsom on 9/5/2024.
//

#pragma once

#include "Core.h"
#include "VulkanCommon.h"

enum VertexFormat
{

};


struct StaticMeshVertex
{
    Vector3f position;
    Vector3f normal;
    Vector2f texture_coordinates;
    Color    color;
};

struct VertexAttribute
{
    uint32   binding;
    uint32   index;
    uint32   offset;
    VkFormat format;
};

using VertexAttributeList = std::vector<VertexAttribute>;