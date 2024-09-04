//
// Created by avsom on 9/4/2024.
//

#pragma once

#include "Core.h"

enum ProjectionMode : uint8
{
    Orthographic,
    Perspective
};

class Camera
{
public:
    float          field_of_view;
    float          aspect_ratio;
    ProjectionMode projection_mode;
    float near_clip_plane_distance;
    float far_clip_plane_distance;
    
};
