//
// Created by avsom on 9/20/2023.
//

#ifndef SIMULACRAENGINE_VECTOR_INL
#define SIMULACRAENGINE_VECTOR_INL



#endif //SIMULACRAENGINE_VECTOR_INL




SVector2::SVector2(float f)
{

}

SVector2::SVector2(float inX, float inY)
{
    X = inX;
    Y = inY;
}

bool SVector2::operator==(const SVector2 v) const
{
    return false;
}

bool SVector2::operator!=(const SVector2 v) const
{
    return false;
}

bool SVector2::Equals(const SVector2 v, const float epsilon) const
{

    return std::abs(this->X-v.X)>epsilon && std::abs(this->Y-v.Y)>epsilon;

}



SVector2 SVector2::operator+(SVector2 v) const
{
    return SVector2(0);
}

SVector2 SVector2::operator+=(SVector2 v)
{
    return SVector2(0);
}

SVector2 SVector2::operator-(SVector2 v) const
{
    return SVector2(0);
}

SVector2 SVector2::operator-=(SVector2 v)
{
    return SVector2(0);
}

SVector2 SVector2::operator*(const float f) const
{
    return SVector2(0);
}

float SVector2::operator*(SVector2 v) const
{
    return 0;
}

SVector2 SVector2::operator*=(const float f)
{
    return SVector2(0);
}

SVector2 SVector2::operator/(const float scale) const
{
    return SVector2(0);
}

SVector2 SVector2::operator/=(const float scale)
{
    return SVector2(0);
}

SVectorX::SVectorX(int length)
{
    pData = nullptr;
    Size = length;
}


SVectorX::SVectorX(int length, float *data)
{
    this->Size = length;
    this->pData = data;
    //SetSize(Size);
}

void SVectorX::SetSize(int length)
{
    Size = length;
}


SVectorX::SVectorX()
{
    Size = 0;
    pData = nullptr;
}


float SVectorX::operator[](const int index) const
{
    return pData[index];
}


float &SVectorX::operator[](const int index)
{
    return pData[index];
}

SVectorX SVectorX::operator+(const SVectorX v) const
{
    SVectorX t;
    t.SetSize(this->Size);
    for (int i = 0; i < Size; i++)
    {
        t[i] = this->pData[i] + v.pData[i];
    }

    return t;
}

SVectorX& SVectorX::operator+=(const SVectorX v)
{
    for (int i = 0; i < Size; ++i)
    {
        pData[i] += v.pData[i];
    }

    return *this;
}

SVectorX SVectorX::operator-(const SVectorX v) const
{
    SVectorX t;
    t.SetSize(this->Size);



    for (int i = 0; i < Size; i++)
    {
        t[i] = this->pData[i] - v.pData[i];
    }

    return t;
}

SVectorX& SVectorX::operator-=(const SVectorX v)
{
    for (int i = 0; i < Size; ++i)
    {
        pData[i] -= v.pData[i];
    }

    return *this;
}

SVectorX SVectorX::operator*(const float scale) const
{

    SVectorX t;
    t.SetSize(this->Size);
    for (int i = 0; i < Size; i++)
    {
        t.pData[i] = scale * this->pData[i];
    }

    return t;
}

SVectorX& SVectorX::operator*=(const float scale)
{
    for (int i = 0; i < Size; i++)
    {
        pData[i] *= scale;
    }

    return *this;
}

float SVectorX::operator*(const SVectorX &v) const
{
    float sum = 0.0f;
    for (int i = 0; i < Size; i++)
    {
        sum += v.pData[i] * this->pData[i];
    }

    return sum;
}


SVectorX SVectorX::operator/(const float scale) const
{
    SVectorX t;
    t.SetSize(this->Size);
    for (int i = 0; i < Size; i++)
    {
        t[i] = this->pData[i] / scale;
    }

    return t;
}

SVectorX& SVectorX::operator/=(const float scale)
{
    for (int i = 0; i < Size; i++)
    {
        this->pData[i] /= scale;
    }

    return *this;
}

float SVectorX::Get(const int index) const
{
    return pData[index];
}

float &SVectorX::Get(const int index)
{
    return pData[index];
}

bool SVectorX::operator==(const SVectorX o) const
{
    return false;
}

bool SVectorX::operator!=(const SVectorX o) const
{
    return false;
}

bool SVectorX::Equals(const SVectorX o) const
{
    return false;
}

SVectorX SVectorX::operator%(SVectorX v) const
{
    SVectorX t;
    t.SetSize(this->Size);
    for (int i = 0; i < Size; i++)
    {
        t[i] = 0;
    }

    return t;
}

SVectorX &SVectorX::operator%=(const SVectorX v)
{
    return *this;
}