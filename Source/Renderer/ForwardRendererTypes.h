//
// Created by Adithya Somashekhar on 10/21/24.
//

#pragma once
#include <Core.h>
#include "Metal/MetalInclude.h"

enum class StaticMeshVertexAttribute : uint8
{
    Position,
    Normal,
    Tangent,
    TextureCoordinates
};

enum class BufferIndices : uint8
{
    DynamicMeshAttributes,
    StaticMeshAttributes
};
