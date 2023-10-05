
#include "../../Sys/Precompiled.h"


LinearAllocator::LinearAllocator(size_t AllocatorSize, void *AllocatorMemoryBlock) :  CurrentPosition(reinterpret_cast<uintptr_t>(AllocatorMemoryBlock)),
                                                                                      ManagedMemory(AllocatorSize, AllocatorMemoryBlock)
{
    assert(AllocatorSize > 0);
}

LinearAllocator::~LinearAllocator()
{

    assert( ManagedMemory.NumAllocations == 0 && ManagedMemory.MemoryUsed == 0);
    ManagedMemory.MemoryBlockPointer = nullptr;
}


void *LinearAllocator::Allocate(size_t AllocationSize, uint8 Alignment)
{
    assert(AllocationSize != 0);
    uint8 Adjustment = AlignForwardAdjustment(CurrentPosition, Alignment);


    if(Adjustment + ManagedMemory.MemoryUsed + AllocationSize > ManagedMemory.MemoryBlockSize)
    {
        assert(false && "Allocation exceeded remaining memory");
        return nullptr;
    }

    uintptr_t aligned_address = (uintptr_t)CurrentPosition + Adjustment;
    CurrentPosition = (aligned_address + AllocationSize);
    ManagedMemory.MemoryUsed += AllocationSize + Adjustment;
    ManagedMemory.NumAllocations++;

    return (void*)aligned_address;

}



void LinearAllocator::Clear()
{
    ManagedMemory.NumAllocations = 0;
    ManagedMemory.MemoryUsed = 0;
    CurrentPosition = reinterpret_cast<uintptr_t>(ManagedMemory.MemoryBlockPointer);
}

const SMemoryBlock &LinearAllocator::GetManagedMemory() const
{
    return ManagedMemory;
}

