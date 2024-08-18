//
// Created by avsom on 7/26/2024.
//

#pragma once

namespace Math
{
    template<typename T>
    struct Vector4
    {

        Vector4<T>() = default;
        Vector4<T>(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {};

        T x;
        T y;
        T z;
        T w;
    };

}
using Vector4D = Math::Vector4<double>;
using Vector4F = Math::Vector4<float>;
