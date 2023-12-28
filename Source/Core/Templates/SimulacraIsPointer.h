//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAISPOINTER_H
#define SIMULACRAENGINE_SIMULACRAISPOINTER_H


template <typename T>
struct TIsPointer { static constexpr bool Value = false; };

template <typename T>
struct TIsPointer<T*> { static constexpr bool Value = true; };



#endif //SIMULACRAENGINE_SIMULACRAISPOINTER_H
