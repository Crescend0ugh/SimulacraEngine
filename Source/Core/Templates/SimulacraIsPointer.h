//
// Created by avsom on 10/23/2023.
//

#pragma once


/**
 *@brief 
 *
 **/
template <typename T>
struct TIsPointer { static constexpr bool Value = false; };

template <typename T>
struct TIsPointer<T*> { static constexpr bool Value = true; };



