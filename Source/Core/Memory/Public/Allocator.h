//
// Created by avsom on 9/29/2023.
//

#ifndef SIMULACRAENGINE_ALLOCATOR_H
#define SIMULACRAENGINE_ALLOCATOR_H

class Allocator
{
public:

    Allocator(size_t AllocatorBlockLength, void* AllocatorMemoryBlock)
    {
        MemoryBlock = AllocatorMemoryBlock;
        MemoryBlockLength = AllocatorBlockLength;
        MemoryUsed = 0;
        NumAllocations = 0;
    };

    virtual ~Allocator()
    {

        MemoryBlock = nullptr;
        MemoryBlockLength = 0;
    }

    virtual void *Allocate(size_t AllocationSize, uint8 Alignment) = 0;
    virtual void  Deallocate(void* p) = 0;


    void*  GetStart()           const { return MemoryBlock; };
    size_t GetSize()            const { return MemoryBlockLength; };
    size_t GetMemoryUsed()      const { return MemoryUsed; } ;
    size_t GetRemainingMemory() const { return MemoryBlockLength-MemoryUsed; };
    size_t GetNumAllocations()  const { return NumAllocations; };


protected:

    void*  MemoryBlock;
    size_t MemoryBlockLength;
    size_t MemoryUsed;
    size_t NumAllocations;

};



#endif //SIMULACRAENGINE_ALLOCATOR_H
