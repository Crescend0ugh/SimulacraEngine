//
// Created by avsom on 12/22/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAWINDOWSAPPLICATION_H
#define SIMULACRAENGINE_SIMULACRAWINDOWSAPPLICATION_H

#include "../../Sys/Precompiled.h"
#include "../SimulacraApplication.h"
#include "SimulacraWindowsWindow.h"
#include <windows.h>
#include <vector>

class SWindowsApplication
{


public:

    static SWindowsWindow* CreateWindowsWindow();

    SWindowsApplication(HINSTANCE InHInstance);
    ~SWindowsApplication();

    bool RegisterWindowClass(HINSTANCE InHInstance);
    void PumpMessages();







private:

    //The handle to the module
    HINSTANCE HInstance;

    //Windows owned by the application
    std::vector<SWindowsWindow> Windows;





};


#endif //SIMULACRAENGINE_SIMULACRAWINDOWSAPPLICATION_H
