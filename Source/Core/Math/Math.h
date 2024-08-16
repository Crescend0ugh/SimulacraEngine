//
// Created by avsom on 8/15/2024.
//

#pragma once
#include <math.h>

namespace Math
{
    __forceinline float sqrt(float f)
    {
        return ::sqrtf(f);
    }

    __forceinline double sqrt(double d)
    {
        return ::sqrt(d);
    }

    __forceinline float inv_sqrt(float f)
    {
        return 1.0f/sqrtf(f);
    }

    __forceinline double inv_sqrt(double d)
    {
        return 1.0/ sqrt(d);
    }
}