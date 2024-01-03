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



    virtual void Move(int32 InX, int32 InY) = 0;

    virtual void Show() = 0;

    virtual void Hide() = 0;

    virtual void Minimize() = 0;

    virtual void Maximize() = 0;

    virtual void* GetHandle() = 0;


private:


};



