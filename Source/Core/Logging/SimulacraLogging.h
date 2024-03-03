#pragma once

#include "SimulacraLoggingSeverity.h"

//TODO this is terrible fix it
#define SLOG(Severity, Format, ...) \
::Simulacra::Logging::SLog(Severity, Format, ##__VA_ARGS__)        \

namespace Simulacra::Logging
{

    void SLog(ELogSeverity Severity, const char *Format, ...);




}
