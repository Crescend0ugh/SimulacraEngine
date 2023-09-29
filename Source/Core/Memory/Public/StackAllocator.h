//
// Created by avsom on 9/29/2023.
//

#ifndef SIMULACRAENGINE_STACKALLOCATOR_H
#define SIMULACRAENGINE_STACKALLOCATOR_H

#include "../../Sys/SimEngineTypes.h"

/***
 * @brief The stack allocator
 */
class StackAllocator
{
public:

    StackAllocator();
    /***
     * @brief Constructs a new stack allocator with given size
     * @param Size Size in bytes
     */
    explicit StackAllocator(uint32 Size);

};


#endif //SIMULACRAENGINE_STACKALLOCATOR_H
