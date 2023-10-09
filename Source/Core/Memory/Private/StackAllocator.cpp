//
// Created by avsom on 9/29/2023.
//

#include "../../Sys/Precompiled.h"



StackAllocator::StackAllocator(size_t AllocatorSize, void *AllocatorMemoryBlock) : ManagedMemory(AllocatorSize, AllocatorMemoryBlock)
{
    CurrentPosition = reinterpret_cast<uintptr_t>(AllocatorMemoryBlock);
    assert(AllocatorSize > 0);
}

StackAllocator::~StackAllocator()
{
    assert(ManagedMemory.GetNumAllocations() == 0 && ManagedMemory.GetMemoryUsed() == 0);

}

void *StackAllocator::Allocate(size_t AllocationSize, uint8 Alignment)
{
    assert(AllocationSize != 0);
    uint8 Adjustment = AlignForwardAdjustmentWithHeader(reinterpret_cast<uintptr_t>(CurrentPosition), Alignment, sizeof(AllocationHeader));

    if(Adjustment + ManagedMemory.MemoryUsed + AllocationSize > ManagedMemory.MemoryBlockSize)
    {
        assert(false && "Allocation exceeded remaining memory");
        return nullptr;
    }

    uintptr_t AlignedAddress = reinterpret_cast<uintptr_t>(CurrentPosition) + Adjustment;
    AllocationHeader* Header = reinterpret_cast<AllocationHeader*>(AlignedAddress-sizeof(AllocationHeader));
    Header->Adjustment = Adjustment;

    CurrentPosition = AlignedAddress+AllocationSize;
    ManagedMemory.MemoryUsed += AllocationSize+Adjustment;
    ManagedMemory.NumAllocations ++;

    return reinterpret_cast<void*>(AlignedAddress);


}

void StackAllocator::Deallocate(void *Ptr)
{
    uintptr_t ArithmeticPtr = reinterpret_cast<uintptr_t>(Ptr);

    AllocationHeader* Header = reinterpret_cast<AllocationHeader*>(ArithmeticPtr-sizeof(AllocationHeader));
    ManagedMemory.MemoryUsed -= reinterpret_cast<uintptr_t>(CurrentPosition) - ArithmeticPtr + Header->Adjustment;
    CurrentPosition = ArithmeticPtr - Header->Adjustment;
    ManagedMemory.NumAllocations--;
}
