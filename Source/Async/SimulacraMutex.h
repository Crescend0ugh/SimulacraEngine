//
// Created by avsom on 3/7/2024.
//

#pragma once

#include <atomic>
#include "../Core/Sys/SimulacraEngineTypes.h"

struct SMutex
{

    std::atomic<uint8> State;
};