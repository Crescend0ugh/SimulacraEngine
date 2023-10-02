
#include "../../Sys/Precompiled.h"
#include "../Public/LinearAllocator.h"

LinearAllocator::LinearAllocator(size_t AllocatorSize, void *AllocatorMemoryBlock) : Allocator(AllocatorSize, AllocatorMemoryBlock), CurrentPosition(AllocatorMemoryBlock)
{
    assert(AllocatorSize > 0);
}

LinearAllocator::~LinearAllocator()
{

    assert( NumAllocations == 0 && MemoryUsed == 0);
}


void *LinearAllocator::Allocate(size_t AllocationSize, uint8 Alignment)
{
    assert(AllocationSize != 0);
    uint8 Adjustment = AlignForward(CurrentPosition, Alignment);

    if(MemoryUsed + Adjustment + AllocationSize > MemoryBlockLength)
    {
        return nullptr;
    }

    uintptr_t aligned_address = (uintptr_t)CurrentPosition + Adjustment;
    CurrentPosition = (void*)(aligned_address + AllocationSize);
    MemoryUsed += AllocationSize + Adjustment;
    NumAllocations++;

    return (void*)aligned_address;
}

void LinearAllocator::Deallocate(void *p)
{
    assert(false && "Use Clear() for Linear Allocator");
}

void LinearAllocator::Clear()
{
    NumAllocations = 0;
    MemoryUsed = 0;
    CurrentPosition = MemoryBlock;
}

