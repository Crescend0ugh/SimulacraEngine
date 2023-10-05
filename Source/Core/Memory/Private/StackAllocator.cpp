//
// Created by avsom on 9/29/2023.
//

#include "../../Sys/Precompiled.h"


StackAllocator::StackAllocator(size_t AllocatorSize, void *AllocatorMemoryBlock) : ManagedMemory(AllocatorSize, AllocatorMemoryBlock)
{

}

StackAllocator::~StackAllocator()
{
    assert(ManagedMemory.NumAllocations == 0 && ManagedMemory.MemoryUsed == 0);


}

void *StackAllocator::Allocate(size_t AllocationSize, uint8 Alignment)
{
    return nullptr;
}

void StackAllocator::Deallocate(void *Ptr)
{

}
