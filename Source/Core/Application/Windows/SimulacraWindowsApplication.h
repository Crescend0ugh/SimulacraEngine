//
// Created by avsom on 12/22/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAWINDOWSAPPLICATION_H
#define SIMULACRAENGINE_SIMULACRAWINDOWSAPPLICATION_H

#include "../../Sys/Precompiled.h"
#include "../SimulacraApplication.h"
#include <windows.h>

class SWindowsApplication
{


public:


    SWindowsApplication(HINSTANCE InHInstance);
    ~SWindowsApplication();

    bool RegisterWindowClass(HINSTANCE InHInstance);






private:

    HINSTANCE HInstance;




};


#endif //SIMULACRAENGINE_SIMULACRAWINDOWSAPPLICATION_H
