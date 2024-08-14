//
// Created by avsom on 7/26/2024.
//

#pragma once

namespace Math
{
    template<typename T>
    struct Matrix4
    {
        T matrix_[16];
    };

using Matrix4F = Matrix4<float>;
using Matrix4D = Matrix4<double>;

}

