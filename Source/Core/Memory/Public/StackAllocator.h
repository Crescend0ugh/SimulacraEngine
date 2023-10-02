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
        uint32 *Address;
    };

public:
    StackAllocator();

    explicit StackAllocator(uint32 StackSizeBytes);

    ~StackAllocator();

    void *Alloc(uint32 SizeBytes);

    void *Alloc(uint32 SizeBytes, uint16 Alignment = 16);

    void FreeToMarker();

    void Clear();

private:

    uint8 Size;
    uint8* MemoryBlock;

private:

    void Initialize();

};

#endif //SIMULACRAENGINE_STACKALLOCATOR_H
