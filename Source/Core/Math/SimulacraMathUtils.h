//
// Created by avsom on 1/3/2024.
//

#pragma once

#include "../Sys/Precompiled.h"

namespace SMath
{

    template<typename T>
    static SIM_FORCE_INLINE T Abs(T x)
    {

    }

    template<typename T>
    static SIM_FORCE_INLINE T Floor()
    {

    }

    template<typename T>
    static SIM_FORCE_INLINE T Clamp(T X, T Min, T Max)
    {
        //return Max(Min(X, Max), Min)
    }

    template<typename T>
    static constexpr SIM_FORCE_INLINE T Square(const T X)
    {
        return X*X;

    }

    template< class T >
    static constexpr SIM_FORCE_INLINE T Cube(const T X )
    {
        return X*X*X;
    }





};