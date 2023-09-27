//
// Created by avsom on 9/15/2023.
//

#ifndef SIMULACRAENGINE_SIMENGINETYPES_H
#define SIMULACRAENGINE_SIMENGINETYPES_H




typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int dword;
typedef unsigned int uint;


typedef signed char int8;
typedef unsigned char uint8;
typedef signed short int16;
typedef unsigned short uint16;
typedef signed int int32;
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;


assert_sizeof(int8, 1);
assert_sizeof(uint8,1)
assert_sizeof(int16, 2);
assert_sizeof(uint16,2)
assert_sizeof(int32, 4);
assert_sizeof(uint32,4);
assert_sizeof(int64, 8);
assert_sizeof(uint64,8);



#endif //SIMULACRAENGINE_SIMENGINETYPES_H
