//
// Created by avsom on 12/24/2023.
//

#pragma once



#include "../Core/Sys/Precompiled.h"

class IWindow
{

public:



    virtual void Move(int32 InX, int32 InY) = 0;

    virtual void Show() = 0;

    virtual void Hide() = 0;

    virtual void Minimize() = 0;

    virtual void Maximize() = 0;


private:


};



