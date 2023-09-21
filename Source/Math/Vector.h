//
// Created by ovsom on 9/15/2023.
//

#ifndef SIMULACRAENGINE_VECTOR_H
#define SIMULACRAENGINE_VECTOR_H

#include "../EngineDefines.h"
#include "../EngineTypes.h"
#include "x86intrin.h"

struct SVector
{

public:

    SIM_FORCE_INLINE SVector();

    SIM_FORCE_INLINE SVector(int length);

    SIM_FORCE_INLINE SVector(int length, float *data);

    SIM_FORCE_INLINE void SetSize(int length);


    SIM_FORCE_INLINE bool     operator==(const SVector o) const;
    SIM_FORCE_INLINE bool     operator!=(const SVector o) const;
    SIM_FORCE_INLINE bool     Equals(const SVector o) const;


    SIM_FORCE_INLINE float    operator[](const int index) const;
    SIM_FORCE_INLINE float    &operator[](const int index);
    SIM_FORCE_INLINE float    Get(const int index) const;
    SIM_FORCE_INLINE float    &Get(const int index);


    SIM_FORCE_INLINE SVector  operator+(const SVector v) const; /*** @param ***/
    SIM_FORCE_INLINE SVector& operator+=(const SVector v);

    SIM_FORCE_INLINE SVector  operator-(const SVector v) const;
    SIM_FORCE_INLINE SVector& operator-=(const SVector v);

    SIM_FORCE_INLINE SVector  operator*(const float scale) const;
    SIM_FORCE_INLINE float    operator*(const SVector v) const;
    SIM_FORCE_INLINE SVector& operator*=(const float scale);

    SIM_FORCE_INLINE SVector  operator/(const float scale) const;
    SIM_FORCE_INLINE SVector& operator/=(const float scale);

    /// \TODO Implement cross product operator
    SIM_FORCE_INLINE SVector  operator%(SVector v) const;
    /// \TODO Implement cross product operator
    SIM_FORCE_INLINE SVector& operator%=(const SVector v);


private:
    int Size;
    float *pData;


};


#endif //SIMULACRAENGINE_VECTOR_H
