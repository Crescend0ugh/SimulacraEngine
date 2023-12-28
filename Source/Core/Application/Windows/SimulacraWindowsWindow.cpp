//
// Created by avsom on 12/23/2023.
//


#include "../../Sys/SimEngineTypes.h"
#include "../SimulacraWindow.h"
#include "SimulacraWindowsWindow.h"

std::string SWindowsWindow::WindowClassName = "SimulacraEngineWindow";

SWindowsWindow::SWindowsWindow()
{
    HWnd = nullptr;
}

SWindowsWindow::~SWindowsWindow()
{

}



void SWindowsWindow::MoveWindow(uint32 InX, uint32 InY)
{

}

void SWindowsWindow::Show()
{
    ::ShowWindow(HWnd, SW_SHOW);
}

void SWindowsWindow::Hide()
{
    ::ShowWindow(HWnd, SW_HIDE);
}

void SWindowsWindow::Minimize()
{
    ::ShowWindow(HWnd, SW_MINIMIZE);
}

void SWindowsWindow::Maximize()
{
    ::ShowWindow(HWnd, SW_MAXIMIZE);
}

void SWindowsWindow::Init(HINSTANCE InHInstance)
{
    uint32      WindowExStyle;
    const char* ClassName = WindowClassName.data();
    const char* WindowName;
    uint32      WindowStyle = WS_OVERLAPPEDWINDOW;
    int         XPos = CW_USEDEFAULT;
    int         YPos = CW_USEDEFAULT;
    int         Width = CW_USEDEFAULT;
    int         Height = CW_USEDEFAULT;
    HWND        HWndParent;
    HMENU       HMenu;
    HINSTANCE   HInstance = InHInstance;

    HWnd = CreateWindowEx(
            WindowExStyle,
            ClassName,
            WindowName,
            WindowStyle,
            XPos,
            YPos,
            Width,
            Height,
            HWndParent,
            HMenu,
            HInstance,
            nullptr
            );

}

