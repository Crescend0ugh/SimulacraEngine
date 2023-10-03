//
// Created by avsom on 9/29/2023.
//

#ifndef SIMULACRAENGINE_STACKALLOCATOR_H
#define SIMULACRAENGINE_STACKALLOCATOR_H


/***
 * @brief The stack allocator
 */

class StackAllocator : public Allocator
{
public:

    struct Marker
    {
        
    };

    StackAllocator(void* AllocatorMemory, size_t AllocatorSize);
    ~StackAllocator() override;


    void *Allocate(size_t AllocationSize, uint8 Alignment) override;
    void Deallocate(void *p) override;




};

#endif //SIMULACRAENGINE_STACKALLOCATOR_H
