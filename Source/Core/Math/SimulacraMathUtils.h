//
// Created by avsom on 1/3/2024.
//

#pragma once

#include "../Sys/Precompiled.h"

namespace SMath
{

    /**
     *
     * @tparam T
     * @param  X
     * @return The absolute value
     */
    template<typename T>
    static constexpr SIM_FORCE_INLINE T Abs(const T X)
    {
        return X > 0 ? X : -X;
    }

    //@TODO write comment for this function
    /**
     *
     * @tparam T
     * @return
     */
    template<typename T>
    static SIM_FORCE_INLINE T Floor()
    {

    }

    /**
     *
     * @tparam\c A real number type
     * @param  A The first value
     * @param  B The second value
     * @return   The greater of the two values
     */
    template<typename T>
    static SIM_FORCE_INLINE T Max(T A, T B)
    {
        return A>B ? A : B;
    }


    /**
     *
     * @tparam T
     * @param  A First value
     * @param  B Second value
     * @return   The lesser of the two values
     */
    template<typename T>
    static SIM_FORCE_INLINE T Min(T A, T B)
    {
        return A<B ? A : B;
    }



    /**
     *
     * @tparam T
     * @param  X   The value to clamp
     * @param  Min The min value possible
     * @param  Max The max value possible
     * @return
     */
    template<typename T>
    static SIM_FORCE_INLINE T Clamp(T X, T Min, T Max)
    {
        return Max(Min(X, Max), Min);
    }

    /**
     *
     * @tparam T
     * @param X
     * @return
     */
    template<typename T>
    static constexpr SIM_FORCE_INLINE T Square(const T X)
    {
        return X*X;

    }

    /**
     *
     * @tparam T
     * @param X
     * @return
     */
    template< class T >
    static constexpr SIM_FORCE_INLINE T Cube(const T X )
    {
        return X*X*X;
    }





};