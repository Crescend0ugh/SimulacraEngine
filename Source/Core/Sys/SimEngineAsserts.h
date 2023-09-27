//
// Created by avsom on 9/26/2023.
//

#ifndef SIMULACRAENGINE_SIMENGINEASSERTS_H
#define SIMULACRAENGINE_SIMENGINEASSERTS_H

#endif //SIMULACRAENGINE_SIMENGINEASSERTS_H

#if defined(_DEBUG)

#else //DEBUG



#endif //DEBUG





#define assert_sizeof( type,size ) static_assert(sizeof(type) == size);
#define is_aligned_16(type)