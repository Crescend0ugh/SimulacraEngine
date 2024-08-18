//
// Created by avsom on 7/26/2024.
//

#pragma once

namespace Math
{


    template<typename T>
    struct Matrix4
    {

        static_assert(std::is_floating_point<T>().value);

        Matrix4<T>() = default;

        Matrix4<T>(Vector3<T> x, Vector3<T> y, Vector3<T> z, Vector3<T> w)
        {
            matrix[0][0] = x.x;  matrix[0][1] = x.y;  matrix[0][2] = x.z;  matrix[0][3] = 0.0f;
            matrix[1][0] = y.x;  matrix[1][1] = y.y;  matrix[1][2] = y.z;  matrix[1][3] = 0.0f;
            matrix[2][0] = z.x;  matrix[2][1] = z.y;  matrix[2][2] = z.z;  matrix[2][3] = 0.0f;
            matrix[3][0] = w.x;  matrix[3][1] = w.y;  matrix[3][2] = w.z;  matrix[3][3] = 1.0f;
        }

        Matrix4<T>(Vector4<T> x, Vector4<T> y, Vector4<T> z, Vector4<T> w)
        {
            matrix[0][0] = x.x;  matrix[0][1] = x.y;  matrix[0][2] = x.z;  matrix[0][3] = x.w;
            matrix[1][0] = y.x;  matrix[1][1] = y.y;  matrix[1][2] = y.z;  matrix[1][3] = y.w;
            matrix[2][0] = z.x;  matrix[2][1] = z.y;  matrix[2][2] = z.z;  matrix[2][3] = z.w;
            matrix[3][0] = w.x;  matrix[3][1] = w.y;  matrix[3][2] = w.z;  matrix[3][3] = w.w;
        }

        static __forceinline Matrix4<T> identity()
        {
            return
            {
                    {1, 0, 0, 0},
                    {0, 1, 0, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 1}
            };
        }

        __forceinline Matrix4<T> inverse()
        {
            return {};
        }

        static __forceinline Matrix4<T>
        look_at_rh(Vector3<T> eye, Vector3<T> target, Vector3<T> up_axis)
        {
            const Vector3<T> forward = (target-eye).get_normal();
            const Vector3<T> right = forward.cross(up_axis).get_normal();
            const Vector3<T> up = right.cross(forward);
            Matrix4<T> result{};
            result.matrix[0][0] = right.x;
            result.matrix[1][0] = right.y;
            result.matrix[2][0] = right.z;
            result.matrix[3][0] =-right.dot( eye);

            result.matrix[0][1] = up.x;
            result.matrix[1][1] = up.y;
            result.matrix[2][1] = up.z;
            result.matrix[3][1] =-up.dot(eye);

            result.matrix[0][2] =-forward.x;
            result.matrix[1][2] =-forward.y;
            result.matrix[2][2] =-forward.z;
            result.matrix[3][2] = forward.dot( eye);

            result.matrix[0][3] = 0;
            result.matrix[1][3] = 0;
            result.matrix[2][3] = 0;
            result.matrix[3][3] = 1;

            return result;
        }


        static __forceinline Matrix4<T> perspective_rh(T fovy, T aspect_ratio, T near, T far)
        {
            const T tan_half_fovy = tan(fovy/2);
            Matrix4<T> result {};
            result.matrix[0][0] = static_cast<T>(1) / (aspect_ratio * tan_half_fovy);
            result.matrix[1][1] = static_cast<T>(1) / (tan_half_fovy);
            result.matrix[2][2] = - (far + near) / (far - near);
            result.matrix[2][3] = - static_cast<T>(1);
            result.matrix[3][2] = - (static_cast<T>(2) * far * near) / (far - near);
            return result;

        }

        static __forceinline Matrix4<T> rotate(Matrix4<T> matrix, float radians, Vector3<T> axis)
        {
            return {};
        }

        __forceinline float determinant()
        {

        };

        alignas(16) T matrix[4][4];
    };





}
using Matrix4F = Math::Matrix4<float>;
using Matrix4D = Math::Matrix4<double>;
