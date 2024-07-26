//
// Created by avsom on 7/26/2024.
//

#pragma once

namespace Math
{
    template<typename T>
    struct Vector
    {
        T x;
        T y;
        T z;
    };
}
using Vector3D = Math::Vector<double>;
using Vector3F = Math::Vector<float>;
