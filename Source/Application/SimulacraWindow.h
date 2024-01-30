//
// Created by avsom on 12/24/2023.
//

#pragma once

#include "../Core/Sys/Precompiled.h"

struct SWindowDetails
{
    int32 SizeX;
    int32 SizeY;
    int32 PositionX;
    int32 PositionY;

};

class SWindowBase
{

public:

    SWindowBase() = default;

    virtual ~SWindowBase() = default;

    virtual void* GetHandle() = 0;

    virtual void GetSize(uint32& Width, uint32& Height) = 0;

    virtual bool ShouldClose() = 0;

    virtual void Resize(int32 InX, int32 InY, int32 InWidth, int32 InHeight) = 0;

    virtual void Move(int32 InX, int32 InY) = 0;

    virtual void Show() = 0;

    virtual void Hide() = 0;

    virtual void Minimize() = 0;

    virtual void Maximize() = 0;

    virtual void Restore() = 0;

    



    int32 Width;
    int32 Height;

    bool bShouldClose;

private:


};



