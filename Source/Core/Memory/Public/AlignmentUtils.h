


//
// Created by avsom on 9/30/2023.
//

#ifndef SIMULACRAENGINE_ALIGNMENTUTILS_H
#define SIMULACRAENGINE_ALIGNMENTUTILS_H


#include <vector>

SIM_INLINE uint8 AlignForwardAdjustment(uintptr_t Address, uint8 Alignment)
{

    uint8 Adjustment;

    const size_t Mask = Alignment-1;

    assert((Alignment & Mask) == 0);

    Adjustment = (Address - ((Address + Mask) & ~Mask));

    return Adjustment;
}

SIM_INLINE uint8 AlignForwardAdjustmentWithHeader(uintptr_t Address, uint8 Alignment, uint8 HeaderSize)
{
    uint8 Adjustment = AlignForwardAdjustment(Address, Alignment);

    if(Adjustment < HeaderSize)
    {
        HeaderSize -= Adjustment;

        Adjustment += Alignment * (HeaderSize/Alignment);

        if(HeaderSize % Alignment > 0) Adjustment += Alignment;
    }



    return Adjustment;
}






#endif //SIMULACRAENGINE_ALIGNMENTUTILS_H

