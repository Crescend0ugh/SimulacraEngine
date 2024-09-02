//
// Created by avsom on 7/26/2024.
//

#pragma once

namespace Math
{
    template<typename T>
    struct Vector2
    {
        T x;
        T y;
    };

}
using Vector2D = Math::Vector2<double>;
using Vector2f = Math::Vector2<float>;
