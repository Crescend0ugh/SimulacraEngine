//
// Created by ovsom on 9/15/2023.
//

#ifndef SIMULACRAENGINE_VECTOR_H
#define SIMULACRAENGINE_VECTOR_H

#include <cassert>
#include "string"
#include "mmintrin.h"
#include "x86intrin.h"

class alignas(128) SVector
{

public:

    inline SVector();

    inline SVector(int length);

    inline SVector(int length, float *data);

    inline void SetSize(int length);


    inline bool     operator==(const SVector o) const;
    inline bool     operator!=(const SVector o) const;
    inline bool     Equals(const SVector o) const;


    inline float    operator[](const int index) const;
    inline float    &operator[](const int index);
    inline float    Get(const int index) const;
    inline float    &Get(const int index);


    inline SVector  operator+(const SVector V) const; /*** @param ***/
    inline SVector& operator+=(const SVector V);

    inline SVector  operator-(const SVector V) const;
    inline SVector& operator-=(const SVector V);

    inline SVector  operator*(const float Scale) const;
    inline float    operator*(const SVector V) const;
    inline SVector& operator*=(const float Scale);

    inline SVector  operator/(const float Scale) const;
    inline SVector& operator/=(const float Scale);


    //inline float Dot(const SVector V)
    inline float *GetData()
    {
        return pData;
    }

private:
    int Size;
    int Alloced;
    float *pData;


};

SVector::SVector(int length)
{
    pData = nullptr;
    Size = length;
}


SVector::SVector(int length, float *data)
{
    Alloced = 0;
    this->Size = length;
    this->pData = data;
    //SetSize(Size);
}

void SVector::SetSize(int length)
{
    Size = length;
}


SVector::SVector()
{
    Size = Alloced = 0;
    pData = nullptr;
}


float SVector::operator[](const int index) const
{
    return pData[index];
}


float &SVector::operator[](const int index)
{
    return pData[index];
}

SVector SVector::operator+(const SVector V) const
{
    SVector t;
    t.SetSize(this->Size);
    for (int i = 0; i < Size; i++)
    {
        t[i] = this->pData[i] + V.pData[i];
    }

    return t;
}

SVector& SVector::operator+=(const SVector V)
{
    for (int i = 0; i < Size; ++i)
    {
        pData[i] += V.pData[i];
    }

    return *this;
}

SVector SVector::operator-(const SVector V) const
{
    SVector t;
    t.SetSize(this->Size);



    for (int i = 0; i < Size; i++)
    {
        t[i] = this->pData[i] - V.pData[i];
    }

    return t;
}

SVector& SVector::operator-=(const SVector V)
{
    for (int i = 0; i < Size; ++i)
    {
        pData[i] -= V.pData[i];
    }

    return *this;
}

SVector SVector::operator*(const float Scale) const
{

    SVector t;
    t.SetSize(this->Size);
    for (int i = 0; i < Size; i++)
    {
        t.pData[i] = Scale * this->pData[i];
    }

    return t;
}

SVector& SVector::operator*=(const float Scale)
{
    for (int i = 0; i < Size; i++)
    {
        pData[i] *= Scale;
    }

    return *this;
}

float SVector::operator*(const SVector V) const
{
    float sum = 0.0f;
    for (int i = 0; i < Size; i++)
    {
        sum = V.pData[i] * this->pData[i];
    }

    return sum;
}


SVector SVector::operator/(const float Scale) const
{
    SVector t;
    t.SetSize(this->Size);
    for (int i = 0; i < Size; i++)
    {
        t[i] = this->pData[i] / Scale;
    }

    return t;
}

SVector& SVector::operator/=(const float Scale)
{
    for (int i = 0; i < Size; i++)
    {
        this->pData[i] /= Scale;
    }

    return *this;
}

float SVector::Get(const int index) const
{
    assert(index < Size);
    return pData[index];
}

float &SVector::Get(const int index)
{
    assert(index < Size);
    return pData[index];
}


#endif //SIMULACRAENGINE_VECTOR_H
