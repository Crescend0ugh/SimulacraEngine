//
// Created by avsom on 12/22/2023.
//



#include "SimulacraWindowsWindow.h"
#include "SimulacraWindowsApplication.h"

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


            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
            return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

SWindowsApplication::SWindowsApplication(HINSTANCE InHInstance)
{
    HInstance = GetModuleHandle(0);

}


bool SWindowsApplication::RegisterWindowClass( HINSTANCE InHInstance)
{


    WNDCLASS WC;
    memset(&WC, 0, sizeof(WNDCLASS));
    WC.hInstance = HInstance;
    WC.lpfnWndProc = WindowProc;
    WC.lpszClassName = SWindowsWindow::WindowClassName.data();

    bool Result = ::RegisterClass(&WC);

    std::string Message = Result ? "Successfully registered window class\n\n" : "Failed to register window class\n\n";
    std::cout << Message;
    return Result;
}


