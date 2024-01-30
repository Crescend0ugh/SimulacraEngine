//
// Created by avsom on 12/23/2023.
//


#include "../../Core/Sys/SimulacraEngineTypes.h"
#include "SimulacraWindowsWindow.h"

std::string SWindowsWindow::WindowClassName = "SimulacraEngineWindow";


SWindowsWindow::SWindowsWindow()
{
    HWnd = nullptr;
}

SWindowsWindow::~SWindowsWindow() = default;

void SWindowsWindow::Init(HINSTANCE InHInstance)
{
    uint32      WindowExStyle = 0;
    const char* ClassName = WindowClassName.data();
    const char* WindowName = "SimulacraWindow";
    uint32      WindowStyle = WS_OVERLAPPEDWINDOW;
    int         XPos = CW_USEDEFAULT;
    int         YPos = CW_USEDEFAULT;
    int         Width = CW_USEDEFAULT;
    int         Height = CW_USEDEFAULT;
    HWND        HWndParent = nullptr;
    HMENU       HMenu = nullptr;
    HINSTANCE   HInstance = InHInstance;

    HWND hwnd = CreateWindowEx(
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

    HWnd = hwnd;

}

void SWindowsWindow::GetSize(uint32 &Width, uint32 &Height)
{
    RECT Area;
    GetClientRect(HWnd, &Area);
    Width = Area.right;
    Height = Area.bottom;

}

void SWindowsWindow::Move(int32 InX, int32 InY)
{
    ::MoveWindow(HWnd, InX, InY, CW_USEDEFAULT, CW_USEDEFAULT, FALSE);
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

void *SWindowsWindow::GetHandle()
{
    return HWnd;
}

bool SWindowsWindow::ShouldClose()
{
    return bShouldClose;
}

void SWindowsWindow::Resize(int32 InX, int32 InY, int32 InWidth, int32 InHeight)
{

}

void SWindowsWindow::Restore()
{

}

