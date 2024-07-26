//
// Created by avsom on 9/15/2023.
//

#pragma once


#include "SimEngineAsserts.h"

using byte = unsigned char;
using word = unsigned short;
using dword = unsigned int;
using uint = unsigned int;
using int8 = signed char ;
using uint8 = unsigned char ;
using int16 = signed short ;
using uint16 = unsigned short ;
using int32 = signed int ;
using uint32 = unsigned int ;
using int64 = long long ;
using uint64 = unsigned long long;

assert_sizeof(int8, 1);
assert_sizeof(uint8,1);
assert_sizeof(int16, 2);
assert_sizeof(uint16,2);
assert_sizeof(int32, 4);
assert_sizeof(uint32,4);
assert_sizeof(int64, 8);
assert_sizeof(uint64,8);



