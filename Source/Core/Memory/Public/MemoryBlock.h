//
// Created by avsom on 9/29/2023.
//

#ifndef SIMULACRAENGINE_MEMORYBLOCK_H
#define SIMULACRAENGINE_MEMORYBLOCK_H


//Represents a block of managed memory
struct SMemoryBlock
{
public:


    SMemoryBlock(size_t BlockSize, void* BlockPointer)
    {
        MemoryBlockPointer = BlockPointer;
        MemoryBlockSize = BlockSize;
        MemoryUsed = 0;
        NumAllocations = 0;
    }


    virtual ~SMemoryBlock()
    {

        MemoryBlockPointer = nullptr;
        MemoryBlockSize = 0;
    }




    void*  GetStart()           const { return MemoryBlockPointer; };
    size_t GetSize()            const { return MemoryBlockSize; };
    size_t GetMemoryUsed()      const { return MemoryUsed; } ;
    size_t GetMemoryRemaining() const { return MemoryBlockSize - MemoryUsed; };
    size_t GetNumAllocations()  const { return NumAllocations; };


private:

    void*  MemoryBlockPointer;
    size_t MemoryBlockSize;
    size_t MemoryUsed;
    size_t NumAllocations;


    friend class LinearAllocator;
    friend class StackAllocator;
    friend class PoolAllocator;
    friend class DEStackAllocator;


};



#endif //SIMULACRAENGINE_MEMORYBLOCK_H
