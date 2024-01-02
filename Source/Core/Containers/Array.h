//
// Created by avsom on 10/21/2023.
//

#include "../../Core/Sys/SimEngineAsserts.h"

#pragma once

template<class T_, int NumElements > class SimArray {
public:
    int				Num() const { return NumElements; }
    int				ByteSize() const { return sizeof( ptr ); }
    void			Zero() { memset( ptr, 0, sizeof( ptr ) ); }
    void			Memset( const char fill ) { memset( ptr, fill, NumElements * sizeof( *ptr ) ); }

    const T_ &		operator[]( int index ) const { assert( (unsigned)index < (unsigned)NumElements ); return ptr[index]; }
    T_ &			operator[]( int index ) { assert( (unsigned)index < (unsigned)NumElements ); return ptr[index]; }

    const T_ *		Ptr() const { return ptr; }
    T_ *			Ptr() { return ptr; }

private:
    T_				ptr[NumElements];
};
