


//
// Created by avsom on 9/30/2023.
//

#ifndef SIMULACRAENGINE_ALIGNMENTUTILS_H
#define SIMULACRAENGINE_ALIGNMENTUTILS_H


SIM_INLINE uintptr_t AlignAddress(uintptr_t Address, size_t Alignment)
{
    const size_t Mask = Alignment - 1;
    assert(((Alignment & Mask) == 0));
    return (Address+Mask) & ~Mask;
}


SIM_INLINE uintptr_t AlignPointer(uintptr_t Ptr, size_t Alignment)
{
    uintptr_t p, a, modulo;

   // assert(is_power_of_two(align));

    p = Ptr;
    a = (uintptr_t)Alignment;
    // Same as (p % a) but faster as 'a' is a power of two
    modulo = p & (a-1);

    if (modulo != 0) {
        // If 'p' address is not aligned, push the address to the
        // next value which is aligned
        p += a - modulo;
    }
    return p;
}


inline uint8 AlignForward(void* Address, uint8 Alignment)
{
    uint8 adjustment = Alignment - (reinterpret_cast<uintptr_t>(Address)& static_cast<uintptr_t>(Alignment - 1));

    if(adjustment == Alignment)
        return 0; //already aligned

    return adjustment;
}


#endif //SIMULACRAENGINE_ALIGNMENTUTILS_H

