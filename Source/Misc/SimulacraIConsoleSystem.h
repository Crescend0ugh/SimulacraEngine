//
// Created by avsom on 12/26/2023.
//

#pragma once


#include "../Core/Sys/Precompiled.h"


class IConsoleManager;
class IConsoleEntry;
class IConsoleVariable;
class IConsoleCommand;


enum class EConsoleVariableFlags : uint16
{
    ECVF_ARCHIVE   = 1 << 0,
    ECVF_READ_ONLY = 1 << 1

};

class IConsoleManager
{

public:

//    /**
//     *
//     * @param Name Name of the console variable to retrieve
//     * @return A pointer to the console variable that was retrieved if one is found and nullptr if one is not
//     */
//
//    virtual IConsoleVariable* GetConsoleVariable(const char* Name) = 0;
//
//    /**
//     * @brief Prints a string into the console
//     *
//     * @param InString The string to be printed
//     */
//
//    virtual void Print(const char* InString);
//
//    /**
//     * @brief Prints a string into the console and goes to the next line
//     *
//     * @param InString The string to be printed
//     */
//
//    virtual void PrintLn(const char* InString);
//
//    /**
//     * @brief Clears the text on the console
//     *
//     * @param InString The string to be printed
//     */
//
//    virtual void Clear();

protected:
    /**
     * @brief Register a string console variable
     *
     * @param Name  The name of the console variable
     * @param Value The value of the console variable
     * @param Flags Optional bit flags
     * @param Help  Help text for console variable
     *
     * @return      A pointer to the created console variable
     */

    virtual IConsoleVariable* RegisterConsoleVariable(const char *Name, char* Value, char* Help, uint16 Flags) = 0;

    /**
     * @brief Register a integer console variable
     *
     * @param Name  The name of the console variable
     * @param Value The value of the console variable
     * @param Flags Optional bit flags
     * @param Help  Help text for console variable
     *
     * @return      A pointer to the created console variable
     */

    virtual IConsoleVariable* RegisterConsoleVariable(const char* Name, int32 Value, char* Help, uint16 Flags) = 0;

    /**
     * @brief Register a float console variable
     *
     * @param Name  The name of the console variable
     * @param Value The value of the console variable
     * @param Flags Optional bit flags
     * @param Help  Help text for console variable
     *
     * @return      A pointer to the created console variable
     */

    virtual IConsoleVariable* RegisterConsoleVariable(const char* Name, float Value, char* Help, uint16 Flags) = 0;

    /**
     * @brief Register a boolean console variable
     *
     * @param Name  The name of the console variable
     * @param Value The value of the console variable
     * @param Flags Optional bit flags
     * @param Help  Help text for console variable
     *
     * @return      A pointer to the created console variable
     */

    virtual IConsoleVariable* RegisterConsoleVariable(const char* Name, bool Value, char* Help, uint16 Flags) = 0;

    /**
     *
     * @param Command         The name of the console command
     * @param CommandFunction A pointer to the function to call with the console command
     * @param Help            Optional bitflags
     * @param Flags           Help text for console command
     *
     * @return                A pointer to the created console variable
     */

    virtual IConsoleCommand*  RegisterConsoleCommand(const char* Command, void* CommandFunction, char* Help, uint16 Flags) = 0;







};

class IConsoleEntry
{
public:

    /**
     *
     * @return
     */

    virtual const char* GetHelpText() const;

    /**
     *
     */

    virtual void SetHelpText() const;

    /**
     *
     * @return
     */

    virtual EConsoleVariableFlags GetFlags();

    /**
     *
     * @param Flags
     */
    virtual void SetFlags(EConsoleVariableFlags Flags);


};

class IConsoleVariable: public IConsoleEntry
{



protected:
    const char* Help;

    EConsoleVariableFlags Flags;


};

class IConsoleCommand: public IConsoleEntry
{

};






