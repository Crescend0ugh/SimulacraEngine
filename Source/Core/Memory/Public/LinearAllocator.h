//
// Created by avsom on 9/29/2023.
//

#ifndef SIMULACRAENGINE_LINEARALLOCATOR_H
#define SIMULACRAENGINE_LINEARALLOCATOR_H



class LinearAllocator : public Allocator
{

public:


    LinearAllocator(size_t AllocatorSize, void* AllocatorMemoryBlock);
    ~LinearAllocator();

    void *Allocate(size_t AllocationSize, uint8 Alignment) override;
    void Deallocate(void *p) override;
    void Clear();




private:

    void* CurrentPosition;
};


#endif //SIMULACRAENGINE_LINEARALLOCATOR_H
