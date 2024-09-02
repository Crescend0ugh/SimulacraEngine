//
// Created by avsom on 9/20/2023.
//

#pragma once



#if defined(_DEBUG)

#undef assert

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
#define assert_sizeof( type , size ) static_assert(sizeof(type) == size)

