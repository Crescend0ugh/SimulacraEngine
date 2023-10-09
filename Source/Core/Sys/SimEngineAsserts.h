//
// Created by avsom on 9/26/2023.
//

#ifndef SIMULACRAENGINE_SIMENGINEASSERTS_H
#define SIMULACRAENGINE_SIMENGINEASSERTS_H

#endif //SIMULACRAENGINE_SIMENGINEASSERTS_H



bool AssertFailed( const char *file, int line, const char *expression );

#if defined(_DEBUG)

#undef assert


#define debugBreak() asm { int 3 }

#define assert(condition) \
if(!(condition)) \
{ \
std::cerr << "Assertion failed at " << __FILE__ << ":" << __LINE__ << ", " << "Condition Failed: " << #condition<< "\n"; \
abort(); \
} \




#else //DEBUG   

#undef assert

#define assert(x) ((void*)0)


#endif //DEBUG


#define assert_x_byte_aligned(ptr, x)  assert( ( ((UINT_PTR)(ptr)) &  x-1 ) == 0 )
#define assert_2_byte_aligned( ptr )   assert( ( ((UINT_PTR)(ptr)) &  1 ) == 0 )
#define assert_4_byte_aligned( ptr )   assert( ( ((UINT_PTR)(ptr)) &  3 ) == 0 )
#define assert_8_byte_aligned( ptr )   assert( ( ((UINT_PTR)(ptr)) &  7 ) == 0 )
#define assert_16_byte_aligned( ptr )  assert( ( ((UINT_PTR)(ptr)) &  15 ) == 0 )
#define assert_32_byte_aligned( ptr )  assert( ( ((UINT_PTR)(ptr)) &  31 ) == 0 )
#define assert_64_byte_aligned( ptr )  assert( ( ((UINT_PTR)(ptr)) &  63 ) == 0 )
#define assert_128_byte_aligned( ptr ) assert( ( ((UINT_PTR)(ptr)) &  127 ) == 0 )




#define assert_sizeof( type , size ) static_assert(sizeof(type) == size)

