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

SWindowsWindow::~SWindowsWindow()
= default;



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

    HWND hwnd = CreateWindowEx(
            0,                              // Optional window styles.
            SWindowsWindow::WindowClassName.data(),                     // Window class
            L"Learn to Program Windows",    // Window text
            WS_OVERLAPPEDWINDOW,            // Window style

            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            NULL,       // Parent window
            NULL,       // Menu
            HInstance,  // Instance handle
            NULL        // Additional application data
    );


}

