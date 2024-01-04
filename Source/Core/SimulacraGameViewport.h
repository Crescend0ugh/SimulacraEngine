//
// Created by avsom on 1/4/2024.
//

#pragma once


#include "../Application/Windows/SimulacraWindowsWindow.h"

class SGameViewport
{
public:

    SGameViewport(SGameViewport &Other) = delete;

    void operator=(const SGameViewport &) = delete;

    static SGameViewport *GetInstance()
    {

        if(!GameViewport)
        {
            GameViewport = new SGameViewport();
        }


        return GameViewport;
    }

    static SWindowBase *GetWindow()
    {
        return SGameViewport::GetInstance()->Window;
    }

    static void SetWindow(SWindowBase* InWindow)
    {
        SGameViewport::GetInstance()->Window = InWindow;
    }

public:



private:


    SGameViewport() = default;

    static SGameViewport *GameViewport;
    static SWindowBase *Window;



};
