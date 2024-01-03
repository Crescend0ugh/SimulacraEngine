//
// Created by avsom on 12/23/2023.
//

#pragma once

#include <memory>
#include <windows.h>
#include "../SimulacraWindow.h"

class SWindowsWindow : public SWindowBase
{

public:

    static std::string WindowClassName;




public:



    SWindowsWindow();

    ~SWindowsWindow();

    void Init(HINSTANCE InHInstance);

    void  Move(int32 InX, int32 InY) override;

    void  Show() override;

    void  Hide() override;

    void  Minimize() override;

    void  Maximize() override;

    void* GetHandle() override { return HWnd; };


private:



private:

    HWND HWnd;




};

typedef SWindowsWindow SWindow;

