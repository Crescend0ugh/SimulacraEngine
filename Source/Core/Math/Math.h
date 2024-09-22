//
// Created by avsom on 8/15/2024.
//

#pragma once
#include "Platform/Platform.h"

#define PI 3.1415926535897932f
#define DOUBLE_PI  3.1415926535897932

namespace Math
{
    static forceinline float sqrt(float f)
    {
        return ::sqrtf(f);
    }

    static forceinline double sqrt(double d)
    {
        return ::sqrt(d);
    }

    static forceinline float inv_sqrt(float f)
    {
        return 1.0f/sqrtf(f);
    }

    static forceinline double inv_sqrt(double d)
    {
        return 1.0/sqrt(d);
    }

    static forceinline float radians(float degrees)
    {
        return degrees * PI/180.f;
    }
}