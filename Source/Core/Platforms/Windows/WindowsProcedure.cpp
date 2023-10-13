////
//// Created by avsom on 10/12/2023.
////
//
//#include <windows.h>
//
//
//void OnSize(HWND hwnd, UINT flag, int width, int height)
//{
//    // Handle resizing
//}
//
//
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//    switch (uMsg)
//    {
//        case WM_SIZE:
//        {
//            int width = LOWORD(lParam);  // Macro to get the low-order word.
//            int height = HIWORD(lParam); // Macro to get the high-order word.
//
//            // Respond to the message:
//            OnSize(hwnd, (UINT)wParam, width, height);
//        }
//            break;
//    }
//}
//
