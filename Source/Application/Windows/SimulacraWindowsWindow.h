//
// Created by avsom on 12/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAWINDOWSWINDOW_H
#define SIMULACRAENGINE_SIMULACRAWINDOWSWINDOW_H

#include <memory>
#include <windows.h>
#include "../SimulacraWindow.h"

class SWindowsWindow : IWindow
{

public:

    static std::string WindowClassName;




public:



    SWindowsWindow();

    ~SWindowsWindow();

    void Init(HINSTANCE InHInstance);

    void Move(int32 InX, int32 InY) override;

    void Show() override;

    void Hide() override;

    void Minimize() override;

    void Maximize() override;

    HWND GetHWnd() const { return HWnd; }


private:



private:

    HWND HWnd;




};

typedef SWindowsWindow SWindow;

#endif //SIMULACRAENGINE_SIMULACRAWINDOWSWINDOW_H
