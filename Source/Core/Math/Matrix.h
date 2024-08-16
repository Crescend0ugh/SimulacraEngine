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

        Matrix<T>()= default;
        Matrix<T>(Vector<T> x, Vector<T> y, Vector<T> z, Vector<T> w)
        {
            matrix[0][0] = x.x;  matrix[0][1] = x.y;  matrix[0][2] = x.z;  matrix[0][3] = 0.0f;
            matrix[1][0] = y.x;  matrix[1][1] = y.y;  matrix[1][2] = y.z;  matrix[1][3] = 0.0f;
            matrix[2][0] = z.x;  matrix[2][1] = z.y;  matrix[2][2] = z.z;  matrix[2][3] = 0.0f;
            matrix[3][0] = w.x;  matrix[3][1] = w.y;  matrix[3][2] = w.z;  matrix[3][3] = 1.0f;
        }

        static __forceinline Matrix<T> identity()
        {
            return Matrix<T>
                    (
                            Vector<T>(1, 0, 0),
                            Vector<T>(0, 1, 0),
                            Vector<T>(0, 0, 1),
                            Vector<T>(0, 0, 0)
                    );
        }

        __forceinline Matrix<T>        inverse()
        {
            return {};
        }

        static __forceinline Matrix<T>
        make_look_at(Vector<T> eye_position, Vector<T> center_position, Vector<T> up_vector)
        {
            Vector<T> z_axis = (eye_position - center_position).get_normal();
            Vector<T> x_axis = (up_vector.cross(z_axis)).get_normal();
            Vector<T> y_axis = z_axis.cross(x_axis);

            Matrix<T> view_matrix =
                              {
                                      Vector<T>(x_axis.x, y_axis.x, z_axis.x),
                                      Vector<T>(x_axis.y, y_axis.y, z_axis.y),
                                      Vector<T>(x_axis.z, y_axis.z, z_axis.z),
                                      Vector<T>(-x_axis.dot(eye_position),
                                                -y_axis.dot(eye_position),
                                                z_axis.dot(eye_position)),
                              };

            return view_matrix;
        }

        static __forceinline Matrix<T> make_perspective(T radians, T aspect_ratio, T near, T far)
        {
            T e = 1/(tan(radians/2));
            Matrix<T> matrix;
            matrix.matrix[0][0] = e/aspect_ratio;
            matrix.matrix[1][1] = e;
            matrix.matrix[2][2] = (far+near)/(near-far);
            matrix.matrix[2][3] = (2*far*near)/(near-far);
            matrix.matrix[3][2] = -1;
            return matrix;
        }

        static __forceinline Matrix<T> rotate(Matrix<T> matrix, float radians, Vector<T> axis)
        {
            return {};
        }

        __forceinline float determinant()
        {

        };


        alignas(16) T matrix[4][4];
    };





}
using Matrix4F = Math::Matrix<float>;
using Matrix4D = Math::Matrix<double>;
