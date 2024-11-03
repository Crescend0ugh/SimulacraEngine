//
// Created by Adithya Somashekhar on 9/29/24.
//

#include <simd/simd.h>

/**  METAL VERTEX
 *   (position)            float: x, y, z
 *   (normal )             char:  x, y, z
 *   (tangent)             char:  x, y, z
 *   (color)               char:  r, g, b, a
 *   (texture_coordinates) short: u, v
 */
typedef struct
{
    vector_float3 position;
    vector_char3  normal;
//    vector_char3  tangent;
//    vector_char4  color;
    vector_short2 texture_coordinates;
} MetalVertex;