//
// Created by ovsom on 9/15/2023.
//

#ifndef SIMULACRAENGINE_VECTOR_H
#define SIMULACRAENGINE_VECTOR_H

#include "../Sys/SimEngineDefines.h"
#include "../Sys/SimEngineTypes.h"
#include "x86intrin.h"


struct SVector2
{
    struct
    {
        float X;
        float Y;
    };

    explicit SVector2(float f);
    SVector2(float inX, float inY);



    SIM_FORCE_INLINE bool operator==(const SVector2 v) const;
    SIM_FORCE_INLINE bool operator!=(const SVector2 v) const;
    SIM_FORCE_INLINE bool Equals(const SVector2 v, const float epsilon = SIM_SMALL_NUMBER ) const;

    SIM_FORCE_INLINE SVector2 operator+(SVector2 v) const;
    SIM_FORCE_INLINE SVector2 operator+=(SVector2 v);

    SIM_FORCE_INLINE SVector2 operator-(SVector2 v) const;
    SIM_FORCE_INLINE SVector2 operator-=(SVector2 v);

    SIM_FORCE_INLINE SVector2 operator*(const float f) const;
    SIM_FORCE_INLINE float operator*(SVector2 v) const;
    SIM_FORCE_INLINE SVector2 operator*=(const float f);

    SIM_FORCE_INLINE SVector2 operator/(const float scale) const;
    SIM_FORCE_INLINE SVector2 operator/=(const float scale);


};


struct SVector
{

};

struct SVectorX{

public:

    SIM_FORCE_INLINE SVectorX();

    SIM_FORCE_INLINE explicit SVectorX(int length);

    SIM_FORCE_INLINE SVectorX(int length, float *data);

    SIM_FORCE_INLINE void SetSize(int length);

//    SIM_FORCE_INLINE void SetData();

    SIM_FORCE_INLINE bool     operator==(const SVectorX o) const;
    SIM_FORCE_INLINE bool     operator!=(const SVectorX o) const;
    SIM_FORCE_INLINE bool     Equals(const SVectorX o) const;


    SIM_FORCE_INLINE float    operator[](const int index) const;
    SIM_FORCE_INLINE float    &operator[](const int index);
    SIM_FORCE_INLINE float    Get(const int index) const;
    SIM_FORCE_INLINE float    &Get(const int index);


    SIM_FORCE_INLINE SVectorX  operator+(const SVectorX v) const; /*** @param ***/
    SIM_FORCE_INLINE SVectorX& operator+=(const SVectorX v);

    SIM_FORCE_INLINE SVectorX  operator-(const SVectorX v) const;
    SIM_FORCE_INLINE SVectorX& operator-=(const SVectorX v);

    SIM_FORCE_INLINE SVectorX  operator*(const float scale) const;
    SIM_FORCE_INLINE float    operator*(const SVectorX &v) const;
    SIM_FORCE_INLINE SVectorX& operator*=(const float scale);

    SIM_FORCE_INLINE SVectorX  operator/(const float scale) const;
    SIM_FORCE_INLINE SVectorX& operator/=(const float scale);

    /// \TODO Implement cross product operator
    SIM_FORCE_INLINE SVectorX  operator%(SVectorX v) const;
    /// \TODO Implement cross product operator
    SIM_FORCE_INLINE SVectorX& operator%=(const SVectorX v);


private:
    float *pData;
    int Size;


};

#include "Vector.inl"

#endif //SIMULACRAENGINE_VECTOR_H
