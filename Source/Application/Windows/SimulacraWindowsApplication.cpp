//
// Created by avsom on 12/22/2023.
//



#include "SimulacraWindowsWindow.h"
#include "SimulacraWindowsApplication.h"
#include "../../Core/SimulacraGameViewport.h"


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    switch (uMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
            return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

SWindowsApplication::SWindowsApplication()
{

    std::cout << "====== Created Windows Application ======\n\n";
    HInstance = GetModuleHandle(NULL);
    RegisterWindowClass();
    CreateWindowsWindow();

    SGameViewport::SetWindow(Windows[0]);


    ShowWindow((HWND)Windows[0]->GetHandle(), SW_SHOW);

}


bool SWindowsApplication::RegisterWindowClass()
{


    WNDCLASS WC;
    memset(&WC, 0, sizeof(WNDCLASS));
    WC.hInstance = HInstance;
    WC.lpfnWndProc = WindowProc;
    WC.lpszClassName = SWindowsWindow::WindowClassName.data();

    bool Result = ::RegisterClass(&WC);

    std::string Message = Result ? "====== Successfully registered WNDCLASS ======\n\n" : "====== Failed to register WNDCLASS ======\n\n";
    std::cout << Message;
    return Result;
}


SWindowsWindow *SWindowsApplication::CreateWindowsWindow()
{
    SWindowsWindow* Window = new SWindowsWindow();
    Window->Init(HInstance);
    Windows.push_back(Window);
    return Window;
}


SApplicationBase *SWindowsApplication::CreateApplication()
{

    return new SWindowsApplication();
}

void SWindowsApplication::PumpMessages()
{
    MSG msg;

    while(PeekMessage(&msg, (HWND)Windows[0]->GetHandle(), 0, 0, PM_REMOVE))
    {
        // Translate the message and dispatch it to WindowProc()
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

SWindowsApplication::~SWindowsApplication()
{

}


