//
// Created by avsom on 12/22/2023.
//

#pragma once

#include "../SimulacraApplication.h"
#include "SimulacraWindowsWindow.h"
#include <windows.h>
#include <vector>


class SWindowsApplication : public SApplicationBase
{

public:

    static SApplicationBase* CreateApplication();

public:

    SWindowsWindow *CreateWindowsWindow();

    SWindowsApplication();

    ~SWindowsApplication();

    bool RegisterWindowClass();



protected:

    void ProcessMessage();
    void PumpMessages() override;


private:

    //The handle to the module
    HINSTANCE HInstance;

    //Windows owned by the application
    std::vector<SWindowsWindow *> Windows;


};

typedef SWindowsApplication SApplication;




