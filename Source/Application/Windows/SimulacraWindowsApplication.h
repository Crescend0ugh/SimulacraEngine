//
// Created by avsom on 12/22/2023.
//

#pragma once

#include "../SimulacraApplication.h"
#include "SimulacraWindowsWindow.h"
#include <windows.h>
#include <vector>

/**
 * A Windows application
 */
class SWindowsApplication : public SApplicationBase
{

public:

    static SApplicationBase* CreateApplication();

public:


    SWindowsApplication();

    ~SWindowsApplication() override;

    bool RegisterWindowClass();

    SWindowsWindow *CreateWindowsWindow();

    SWindowBase* GetWindow(int Index) override { return Windows[Index];}


protected:

    void PumpMessages() override;


private:

    //The handle to the module
    HINSTANCE HInstance;

    //Windows owned by the application
    std::vector<SWindowsWindow *> Windows;


};

typedef SWindowsApplication SApplication;




