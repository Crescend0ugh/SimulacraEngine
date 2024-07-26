//
// Created by avsom on 7/26/2024.
//

#pragma once

namespace Math
{
    template<typename T>
    struct Vector4
    {
        T x;
        T y;
        T z;
    };

}
using Vector4D = Math::Vector4<double>;
using Vector4F = Math::Vector4<float>;
