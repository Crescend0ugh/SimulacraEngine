//
// Created by avsom on 7/26/2024.
//

#pragma once

namespace Math
{


    template<typename T>
    struct Matrix
    {

        static_assert(std::is_floating_point<T>().value);


        Matrix(Vector<T> x, Vector<T> y, Vector<T> z, Vector<T> w)
        {
            matrix[0][0] = x.x;  matrix[0][1] = x.y;  matrix[0][2] = x.z;  matrix[0][3] = 0.0f;
            matrix[1][0] = y.x;  matrix[1][1] = y.y;  matrix[1][2] = y.z;  matrix[1][3] = 0.0f;
            matrix[2][0] = z.x;  matrix[2][1] = z.y;  matrix[2][2] = z.z;  matrix[2][3] = 0.0f;
            matrix[3][0] = w.x;  matrix[3][1] = w.y;  matrix[3][2] = w.z;  matrix[3][3] = 1.0f;
        }

        static __forceinline Matrix<T> identity()
        {
            return {};
        }

        __forceinline Matrix<T>        inverse()
        {
            return {};
        }

        static __forceinline Matrix<T>
        make_look_at(Vector<T> eye_position, Vector<T> center_position, Vector<T> up_vector)
        {
            Vector<T> z_axis = normal(eye_position - center_position);
            Vector<T> x_axis = normal(up_vector.cross(z_axis));
            Vector<T> y_axis = z_axis.cross(x_axis);

            Matrix<T> view_matrix =
                              {
                                      Vector<T>(x_axis.x, y_axis.x, z_axis.x),
                                      Vector<T>(x_axis.y, y_axis.y, z_axis.y),
                                      Vector<T>(x_axis.z, y_axis.z, z_axis.z),
                                      Vector<T>(x_axis.x, x_axis.y, x_axis.z),
                              };

            return view_matrix;
        }

        static __forceinline Matrix<T> make_perspective()
        {
            return {};
        }

        static __forceinline Matrix<T> rotate(Matrix<T> matrix, float radians, Vector<T> axis)
        {
            return {};
        }

        __forceinline float determinant()
        {

        };


        T matrix[4][4];
    };





}
using Matrix4F = Math::Matrix<float>;
using Matrix4D = Math::Matrix<double>;
