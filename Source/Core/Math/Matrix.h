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

        static forceinline Matrix4<T> identity()
        {
            return
            {
                    {1, 0, 0, 0},
                    {0, 1, 0, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 1}
            };
        }

        bool is_invertable()
        {

        }

        forceinline Matrix4<T> get_inverse()
        {
            return {};
        }

        forceinline void invert();

        static forceinline Matrix4<T> look_at_rh(Vector3<T> eye, Vector3<T> target, Vector3<T> up_axis)
        {
            const Vector3<T> forward = (target).get_normal();
            const Vector3<T> right = up_axis.cross(forward).get_normal();
            const Vector3<T> up = forward.cross(right);


            return
                    {
                            {right.x, up.x, forward.x, 0},
                            {right.y, up.y, forward.y, 0},
                            {right.z, up.z, forward.z, 0},
                            {-right.dot(eye), -up.dot(eye), -forward.dot(eye), 1}
                    };
        }



        static forceinline Matrix4<T> perspective_rh(T fovy, T aspect_ratio, T near, T far)
        {
            const T cotan_half_fovy = 1/(tan(fovy/2));

//            Result[0][0] = static_cast<T>(1) / (aspect * tanHalfFovy);
//            Result[1][1] = static_cast<T>(1) / (tanHalfFovy);
//            Result[2][2] = - (zFar + zNear) / (zFar - zNear);
//            Result[2][3] = - static_cast<T>(1);
//            Result[3][2] = - (static_cast<T>(2) * zFar * zNear) / (zFar - zNear);

            return
            {
                    {cotan_half_fovy/aspect_ratio, 0, 0, 0},
                    {0, cotan_half_fovy, 0, 0},
                    {0, 0, far/(near-far), -1},
                    {0, 0, (near*far)/(near-far), 0},

            };

        }

        static forceinline Matrix4<T> orthographic_rh()
        {

        }

        static forceinline Matrix4<T> rotate(Matrix4<T> matrix, float radians, Vector3<T> axis)
        {

        }

        static forceinline Matrix4<T> translate(T x, T y, T z)
        {
            return
                    {
                            {1.0, 0.0, 0.0, 0},
                            {0.0, 1.0, 0.0, 0},
                            {0.0, 0.0, 1.0, 0},
                            {x,   y,   z,   1},

                    };
        }

        std::basic_string<char> to_string()
        {
            std::basic_string<char> result;
            result.append("Matrix4x4: [\n");
            for(int i = 0; i < 4; ++i)
            {
                result.append("{ ");
                for(int j = 0; j < 4; j++)
                {
                    result.append(std::to_string(matrix[i][j]));
                    result.append(" ");
                }
                result.append("}\n");
            }
            result.append("]");
            return result;
        }



        forceinline float determinant()
        {

        };

        alignas(16) T matrix[4][4];
    };





}
using Matrix4F = Math::Matrix4<float>;
using Matrix4D = Math::Matrix4<double>;
