//
// Created by avsom on 12/26/2023.
//

#ifndef SIMULACRAENGINE_SIMUALCRAISSIMPLE_H
#define SIMULACRAENGINE_SIMUALCRAISSIMPLE_H


#include <string>
#include "../Sys/SimEngineTypes.h"

/**
 * @brief Checks if the type is a simple data type (integer, float, string, bool)
 * @tparam T
 */
template<typename T>
struct TIsSimple  { static constexpr bool Value = false; };

template<>
struct TIsSimple<int8> { static constexpr bool Value = true; };

template<>
struct TIsSimple<uint8> { static constexpr bool Value = true; };

template<>
struct TIsSimple<int16> { static constexpr bool Value = true; };

template<>
struct TIsSimple<uint16> { static constexpr bool Value = true; };

template<>
struct TIsSimple<int32> { static constexpr bool Value = true; };

template<>
struct TIsSimple<uint32> { static constexpr bool Value = true; };

template<>
struct TIsSimple<int64> { static constexpr bool Value = true; };

template<>
struct TIsSimple<uint64> { static constexpr bool Value = true; };

template<>
struct TIsSimple<float> { static constexpr bool Value = true; };

template<>
struct TIsSimple<double> { static constexpr bool Value = true; };

template<>
struct TIsSimple<bool> { static constexpr bool Value = true; };

template<>
struct TIsSimple<std::string> { static constexpr bool Value = true; };

#endif //SIMULACRAENGINE_SIMUALCRAISSIMPLE_H
