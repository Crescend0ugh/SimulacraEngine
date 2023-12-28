//
// Created by avsom on 12/26/2023.
//

#ifndef SIMULACRAENGINE_SIMUALCRAISSAME_H
#define SIMULACRAENGINE_SIMUALCRAISSAME_H

template<typename T, typename U>
struct TIsSame {static constexpr bool Value = false;};

template<typename T>
struct TIsSame<T,T> {static constexpr bool Value = true;};

#endif //SIMULACRAENGINE_SIMUALCRAISSAME_H
