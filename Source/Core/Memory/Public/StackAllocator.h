//
// Created by avsom on 9/29/2023.
//

#ifndef SIMULACRAENGINE_STACKALLOCATOR_H
#define SIMULACRAENGINE_STACKALLOCATOR_H


/***
 * @brief The stack allocator
 */

class StackAllocator
{
public:

    /***
     * @param AllocatorSize
     * @param AllocatorMemoryBlock
     */
    StackAllocator(size_t AllocatorSize, void* AllocatorMemoryBlock);
    ~StackAllocator();

    /***
     * @param AllocationSize
     * @param Alignment
     * @return void *
     */
    void *Allocate(size_t AllocationSize, uint8 Alignment);

    void Deallocate(void* Ptr);

    const SMemoryBlock &GetManagedMemory() const {return ManagedMemory; };


public:

    struct AllocationHeader
    {
        #if defined(_DEBUG)

        void* PrevAddress;

        #endif

        uint8 Adjustment;
    };

private:

    uintptr_t CurrentPosition;
    SMemoryBlock ManagedMemory;


};

#endif //SIMULACRAENGINE_STACKALLOCATOR_H
