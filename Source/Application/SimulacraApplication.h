//
// Created by avsom on 12/24/2023.
//

#pragma once



#include <memory>
#include "SimulacraWindow.h"


class SApplicationBase
{


public:

    virtual void PumpMessages() = 0;

protected:

    virtual void ProcessMessage() = 0;


private:



};


