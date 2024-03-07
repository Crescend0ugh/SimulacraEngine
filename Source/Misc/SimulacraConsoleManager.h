//
// Created by avsom on 12/26/2023.
//

#pragma once


#include "SimulacraIConsoleSystem.h"
#include <unordered_map>


class SConsoleManager : public IConsoleManager
{

public:

//    SConsoleManager();
//    ~SConsoleManager();
//
//    void Init();
//    void Shutdown();

private:

    IConsoleVariable* RegisterConsoleVariable(const char *Name, char *Value, char* Help, uint16 Flags) override;
    IConsoleVariable* RegisterConsoleVariable(const char *Name, int32 Value, char* Help, uint16 Flags) override;
    IConsoleVariable* RegisterConsoleVariable(const char *Name, float Value, char* Help, uint16 Flags) override;
    IConsoleVariable* RegisterConsoleVariable(const char *Name, bool  Value, char* Help, uint16 Flags) override;


private:
    //TODO fix the map values

    std::unordered_map<char*, IConsoleEntry*>  ConsoleCommandMap;


};





