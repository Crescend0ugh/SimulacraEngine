
#include "../../Sys/Precompiled.h"


LinearAllocator::LinearAllocator(size_t AllocatorSize, void *AllocatorMemoryBlock) : CurrentPosition(reinterpret_cast<uintptr_t>(AllocatorMemoryBlock)),
                                                                                     ManagedMemoryBlock(AllocatorSize, AllocatorMemoryBlock)
{
    assert(AllocatorSize > 0);
}

LinearAllocator::~LinearAllocator()
{

    assert(ManagedMemoryBlock.NumAllocations == 0 && ManagedMemoryBlock.MemoryUsed == 0);
    ManagedMemoryBlock.MemoryBlockPointer = nullptr;
}


void *LinearAllocator::Allocate(size_t AllocationSize, uint8 Alignment)
{
    assert(AllocationSize != 0);
    uint8 Adjustment = AlignForwardAdjustment(CurrentPosition, Alignment);


    if(Adjustment + ManagedMemoryBlock.MemoryUsed + AllocationSize > ManagedMemoryBlock.MemoryBlockSize)
    {
        assert(false && "Allocation exceeded remaining memory");
        return nullptr;
    }

    uintptr_t AlignedAddress = reinterpret_cast<uintptr_t>(CurrentPosition) + Adjustment;
    CurrentPosition = (AlignedAddress + AllocationSize);
    ManagedMemoryBlock.MemoryUsed += AllocationSize + Adjustment;
    ManagedMemoryBlock.NumAllocations++;

    return (void*)AlignedAddress;

}



void LinearAllocator::Clear()
{
    ManagedMemoryBlock.NumAllocations = 0;
    ManagedMemoryBlock.MemoryUsed = 0;
    CurrentPosition = reinterpret_cast<uintptr_t>(ManagedMemoryBlock.MemoryBlockPointer);
}

const SMemoryBlock &LinearAllocator::GetManagedMemory() const
{
    return ManagedMemoryBlock;
}

