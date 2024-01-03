//
// Created by avsom on 9/20/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVECTOR_INL
#define SIMULACRAENGINE_SIMULACRAVECTOR_INL


SIM_FORCE_INLINE SVector2::SVector2(float f)
{
    X = f;
    Y = f;
}

SIM_FORCE_INLINE SVector2::SVector2(float inX, float inY)
{
    X = inX;
    Y = inY;
}

SIM_FORCE_INLINE bool SVector2::operator==(const SVector2 v) const
{
    return false;
}

SIM_FORCE_INLINE bool SVector2::operator!=(const SVector2 v) const
{
    return false;
}

SIM_FORCE_INLINE bool SVector2::Equals(const SVector2 v, const float epsilon) const
{
    return std::abs(this->X - v.X) > epsilon && std::abs(this->Y - v.Y) > epsilon;

}



SIM_FORCE_INLINE SVector2 SVector2::operator+(SVector2 v) const
{
    return SVector2(0);
}

SIM_FORCE_INLINE SVector2 SVector2::operator+=(SVector2 v)
{
    return SVector2(0);
}

SIM_FORCE_INLINE SVector2 SVector2::operator-(SVector2 v) const
{
    return SVector2(0);
}

SIM_FORCE_INLINE SVector2 SVector2::operator-=(SVector2 v)
{
    return SVector2(0);
}

SIM_FORCE_INLINE SVector2 SVector2::operator*(const float f) const
{
    return SVector2(0);
}

SIM_FORCE_INLINE float SVector2::operator*(SVector2 v) const
{
    return 0;
}

SIM_FORCE_INLINE SVector2 SVector2::operator*=(const float f)
{
    return SVector2(0);
}

SIM_FORCE_INLINE SVector2 SVector2::operator/(const float scale) const
{
    return SVector2(0);
}

SIM_FORCE_INLINE SVector2 SVector2::operator/=(const float scale)
{
    return SVector2(0);
}

SIM_FORCE_INLINE SVectorX::SVectorX(int length)
{
    pData = nullptr;
    Size = length;
}


SIM_FORCE_INLINE SVectorX::SVectorX(int length, float* data)
{
    this->Size = length;
    this->pData = data;
    //SetSize(Size);
}

SIM_FORCE_INLINE void SVectorX::SetSize(int length)
{
    Size = length;
}


SIM_FORCE_INLINE SVectorX::SVectorX()
{
    Size = 0;
    pData = nullptr;
}


SIM_FORCE_INLINE float SVectorX::operator[](const int index) const
{
    return pData[index];
}


SIM_FORCE_INLINE float& SVectorX::operator[](const int index)
{
    return pData[index];
}

SIM_FORCE_INLINE SVectorX SVectorX::operator+(const SVectorX v) const
{
    SVectorX t;
    t.SetSize(this->Size);
    for (int i = 0; i < Size; i++)
    {
        t[i] = this->pData[i] + v.pData[i];
    }

    return t;
}

SIM_FORCE_INLINE SVectorX& SVectorX::operator+=(const SVectorX v)
{
    for (int i = 0; i < Size; ++i)
    {
        pData[i] += v.pData[i];
    }

    return *this;
}

SIM_FORCE_INLINE SVectorX SVectorX::operator-(const SVectorX v) const
{
    SVectorX t;
    t.SetSize(this->Size);



    for (int i = 0; i < Size; i++)
    {
        t[i] = this->pData[i] - v.pData[i];
    }

    return t;
}

SIM_FORCE_INLINE SVectorX& SVectorX::operator-=(const SVectorX v)
{
    for (int i = 0; i < Size; ++i)
    {
        pData[i] -= v.pData[i];
    }

    return *this;
}

SIM_FORCE_INLINE SVectorX SVectorX::operator*(const float scale) const
{

    SVectorX t;
    t.SetSize(this->Size);
    for (int i = 0; i < Size; i++)
    {
        t.pData[i] = scale * this->pData[i];
    }

    return t;
}

SIM_FORCE_INLINE SVectorX& SVectorX::operator*=(const float scale)
{
    for (int i = 0; i < Size; i++)
    {
        pData[i] *= scale;
    }

    return *this;
}

SIM_FORCE_INLINE float SVectorX::operator*(const SVectorX& v) const
{
    float sum = 0.0f;
    for (int i = 0; i < Size; i++)
    {
        sum += v.pData[i] * this->pData[i];
    }

    return sum;
}


SIM_FORCE_INLINE SVectorX SVectorX::operator/(const float scale) const
{
    SVectorX t;
    t.SetSize(this->Size);
    for (int i = 0; i < Size; i++)
    {
        t[i] = this->pData[i] / scale;
    }

    return t;
}

SIM_FORCE_INLINE SVectorX& SVectorX::operator/=(const float scale)
{
    for (int i = 0; i < Size; i++)
    {
        this->pData[i] /= scale;
    }

    return *this;
}

SIM_FORCE_INLINE float SVectorX::Get(const int index) const
{
    return pData[index];
}

SIM_FORCE_INLINE float& SVectorX::Get(const int index)
{
    return pData[index];
}

SIM_FORCE_INLINE bool SVectorX::operator==(const SVectorX o) const
{
    return false;
}

SIM_FORCE_INLINE bool SVectorX::operator!=(const SVectorX o) const
{
    return false;
}

SIM_FORCE_INLINE bool SVectorX::Equals(const SVectorX o) const
{
    return false;
}

SIM_FORCE_INLINE SVectorX SVectorX::operator%(SVectorX v) const
{
    SVectorX t;
    t.SetSize(this->Size);
    for (int i = 0; i < Size; i++)
    {
        t[i] = 0;
    }

    return t;
}

SIM_FORCE_INLINE SVectorX& SVectorX::operator%=(const SVectorX v)
{
    return *this;
}
#endif //SIMULACRAENGINE_SIMULACRAVECTOR_INL



