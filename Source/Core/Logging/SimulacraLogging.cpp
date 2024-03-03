#include <cstdarg>
#include <cstdio>
#include "SimulacraLogging.h"

void Simulacra::Logging::SLog(ELogSeverity Severity, const char *Format, ...)
{
    va_list args;
    va_start(args, Format);

    vprintf(Format, args);

    va_end(args);
}