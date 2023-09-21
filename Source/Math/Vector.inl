//
// Created by avsom on 9/20/2023.
//

#ifndef SIMULACRAENGINE_VECTOR_INL
#define SIMULACRAENGINE_VECTOR_INL


#include "Vector.h"

SVector::SVector(int length)
{
    pData = nullptr;
    Size = length;
}


SVector::SVector(int length, float *data)
{
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
    Size = 0;
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

SVector SVector::operator+(const SVector v) const
{
    SVector t;
    t.SetSize(this->Size);
    for (int i = 0; i < Size; i++)
    {
        t[i] = this->pData[i] + v.pData[i];
    }

    return t;
}

SVector& SVector::operator+=(const SVector v)
{
    for (int i = 0; i < Size; ++i)
    {
        pData[i] += v.pData[i];
    }

    return *this;
}

SVector SVector::operator-(const SVector v) const
{
    SVector t;
    t.SetSize(this->Size);



    for (int i = 0; i < Size; i++)
    {
        t[i] = this->pData[i] - v.pData[i];
    }

    return t;
}

SVector& SVector::operator-=(const SVector v)
{
    for (int i = 0; i < Size; ++i)
    {
        pData[i] -= v.pData[i];
    }

    return *this;
}

SVector SVector::operator*(const float scale) const
{

    SVector t;
    t.SetSize(this->Size);
    for (int i = 0; i < Size; i++)
    {
        t.pData[i] = scale * this->pData[i];
    }

    return t;
}

SVector& SVector::operator*=(const float scale)
{
    for (int i = 0; i < Size; i++)
    {
        pData[i] *= scale;
    }

    return *this;
}

float SVector::operator*(const SVector v) const
{
    float sum = 0.0f;
    for (int i = 0; i < Size; i++)
    {
        sum = v.pData[i] * this->pData[i];
    }

    return sum;
}


SVector SVector::operator/(const float scale) const
{
    SVector t;
    t.SetSize(this->Size);
    for (int i = 0; i < Size; i++)
    {
        t[i] = this->pData[i] / scale;
    }

    return t;
}

SVector& SVector::operator/=(const float scale)
{
    for (int i = 0; i < Size; i++)
    {
        this->pData[i] /= scale;
    }

    return *this;
}

float SVector::Get(const int index) const
{
    return pData[index];
}

float &SVector::Get(const int index)
{
    return pData[index];
}

bool SVector::operator==(const SVector o) const
{
    return false;
}

bool SVector::operator!=(const SVector o) const
{
    return false;
}

bool SVector::Equals(const SVector o) const
{
    return false;
}

SVector SVector::operator%(SVector v) const
{
    SVector t;
    t.SetSize(this->Size);
    for (int i = 0; i < Size; i++)
    {
        t[i] = 0;
    }

    return t;
}

SVector &SVector::operator%=(const SVector v)
{
    return *this;
}

#endif //SIMULACRAENGINE_VECTOR_INL
