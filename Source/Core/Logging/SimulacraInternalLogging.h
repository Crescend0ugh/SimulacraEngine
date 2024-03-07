#pragma once

#include "SimulacraLogSeverity.h"
#include <iterator>
#include <streambuf>
#include "../Sys/Precompiled.h"

namespace SLog
{


    /**
     * @brief Internal log that doesn't allocate any memory
     *  @param Msg  String to log
     * @param  Severity  Severity of log
    **/
    void InternalLog(const char *Msg, ESLogSeverity Severity);


    /**
     *  @brief Internal Log with severity of INFO
     **/
    void InternalLogInfo(const char *Msg)
    { InternalLog(Msg, INFO); }

    /**
     * @brief InternalLog with severity of WARNING
     **/
    void InternalLogWarning(const char *Msg)
    { InternalLog(Msg, WARNING); }

    /**
     * @brief InternalLog with severity of ERROR
     **/
    void InternalLogError(const char *Msg)
    { InternalLog(Msg, ERROR); }

    /**
     * @brief InternalLog with severity of FATAL
     **/
    void InternalLogFatal(const char *Msg)
    { InternalLog(Msg, FATAL); }

}

template<std::size_t Size> 
struct StaticStreamBuffer 
{

public:


private:
	char Data[Size];
};
