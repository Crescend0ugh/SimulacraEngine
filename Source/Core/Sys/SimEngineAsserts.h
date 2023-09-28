//
// Created by avsom on 9/26/2023.
//

#ifndef SIMULACRAENGINE_SIMENGINEASSERTS_H
#define SIMULACRAENGINE_SIMENGINEASSERTS_H

#endif //SIMULACRAENGINE_SIMENGINEASSERTS_H

#if defined(_DEBUG)

#else //DEBUG   



#endif //DEBUG





#define assert_is_aligned(type, value)

#define assert_sizeof( type,size ) static_assert(sizeof(type) == size)



#define is_aligned_4(type) assert_is_aligned(type, 4)
#define is_aligned_8(type) assert_is_aligned(type, 8)
#define is_aligned_16(type) assert_is_aligned(type, 16)
#define is_aligned_32(type) assert_is_aligned(type, 32)
#define is_aligned_64(type) assert_is_aligned(type, 64)