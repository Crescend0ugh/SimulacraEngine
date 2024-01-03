//
// Created by avsom on 1/3/2024.
//

#pragma once

#include <xmmintrin.h>

typedef __m64 v2i;   // vector 2 ints
typedef __m128i v4i;   // vector 4 ints
typedef __m128i v2i64; // vector 2 64 bit ints
typedef __m128 v4f;  // vector 4 floats
typedef __m128d v2d;   // vector 2 doubles

#define SIGN_MASK (0x80000000)f




namespace SMath::SSE
{
    v4f sin_ps(v4f X)
    {
        v4f x, y, z;

        //Finds the absolute value of this register by doing a bitwise and operation with the inverse of the sign mask
    }
}
