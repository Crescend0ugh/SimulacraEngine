//
// Created by avsom on 7/26/2024.
//

#pragma once

#include "Math.h"

namespace Math
{
    template<typename T>
    struct Vector3
    {

        Vector3(T x, T y, T z) : x(x), y(y), z(z)
        {};

        Vector3<T> get_normal()
        {
            const T scale_factor = inv_sqrt((x * x + y * y + z * z));
            return Vector3<T>(x * scale_factor, y * scale_factor, z * scale_factor);
        }

        __forceinline T magnitude() const
        {
            sqrt(x * x + y * y + z * z);
        }

        T dot(const Vector3<T>& other) const
        {
            return x*other.x+y*other.y+z*other.z;
        }

        Vector3<T> cross(const Vector3<T> &other) const
        {
            return Vector3<T>(y * other.z - z * other.y,
                             z * other.x - x * other.z,
                             x * other.y - y * other.x);
        }


        Vector3<T> operator+(const Vector3<T>& other)
        {
            return Vector3<T>(x + other.x, y + other.y, z + other.z);
        }

        Vector3<T> operator-(const Vector3<T>& other)
        {
            return Vector3<T>(x - other.x, y - other.y, z - other.z);
        }


        T x;
        T y;
        T z;
    };
}
using Vector3D = Math::Vector3<double>;
using Vector3F = Math::Vector3<float>;
