//
// Created by avsom on 9/26/2023.
//

#pragma once



bool AssertFailed( const char *file, int line, const char *expression );

#if defined(_DEBUG)

#undef assert


#define debugBreak() asm { int 3 }

#define assert(expression) \
if(!(expression)) \
{ \
std::cerr << "Assertion failed at " << __FILE__ << ":" << __LINE__ << ", " << "Condition Failed: " << #expression<< "\n"; \
abort(); \
}




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

