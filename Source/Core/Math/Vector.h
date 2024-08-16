//
// Created by avsom on 7/26/2024.
//

#pragma once

#include "Math.h"

namespace Math
{
    template<typename T>
    struct Vector
    {

        Vector(T x, T y, T z) : x(x), y(y), z(z)
        {};

        Vector<T> get_normal()
        {
            const T scale_factor = inv_sqrt((x * x + y * y + z * z));
            return Vector<T>(x * scale_factor, y * scale_factor, z * scale_factor);
        }

        __forceinline T magnitude()
        {
            sqrt(x * x + y * y + z * z);
        }

        Vector<T> cross(const Vector<T> &other)
        {
            return Vector<T>(y * other.z - z * other.y,
                             z * other.x - x * other.z,
                             x * other.y - y * other.x);
        }

        T x;
        T y;
        T z;
    };
}
using Vector3D = Math::Vector<double>;
using Vector3F = Math::Vector<float>;
