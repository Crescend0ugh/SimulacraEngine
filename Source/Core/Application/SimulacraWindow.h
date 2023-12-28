//
// Created by avsom on 12/24/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAWINDOW_H
#define SIMULACRAENGINE_SIMULACRAWINDOW_H


#include "../Sys/Precompiled.h"

class SWindow
{

public:

    SWindow();

    ~SWindow();


    virtual void MoveWindow(uint32 InX, uint32 InY);

    virtual void Show();

    virtual void Hide();

    virtual void Minimize();

    virtual void Maximize();


private:


};


#endif //SIMULACRAENGINE_SIMULACRAWINDOW_H
