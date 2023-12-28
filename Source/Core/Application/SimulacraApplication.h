//
// Created by avsom on 12/24/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAAPPLICATION_H
#define SIMULACRAENGINE_SIMULACRAAPPLICATION_H


#include <memory>
#include "SimulacraWindow.h"

class SApplication
{

public:

    SApplication();
    ~SApplication();

    virtual void Init();
    virtual void Shutdown();

    void PumpMessages();


private:



};


#endif //SIMULACRAENGINE_SIMULACRAAPPLICATION_H
