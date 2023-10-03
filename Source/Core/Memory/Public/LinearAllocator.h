//
// Created by avsom on 9/29/2023.
//

#ifndef SIMULACRAENGINE_LINEARALLOCATOR_H
#define SIMULACRAENGINE_LINEARALLOCATOR_H




/***
 *@brief Allocates memory by holding a pointer to the first free address in the managed memory block
 * @note Individual deallocations are not possible, instead the entire memory block is cleared
 */
class LinearAllocator : public Allocator
{

public:

    /***
     * @param AllocatorSize The size of memory to be managed by the allocator
     * @param AllocatorMemoryBlock The backing block of memory from the heap
     */
    LinearAllocator(size_t AllocatorSize, void* AllocatorMemoryBlock);
    ~LinearAllocator();


     /***
      *
      * @param AllocationSize The number of bytes to be allocated
      * @param Alignment The alignment of the allocated block
      * @return void* The address of the allocated block
      */
    void *Allocate(size_t AllocationSize, uint8 Alignment) override;

    /***
     * This function is overridden for completion
     * @warning Using this function will terminate the program
     */
    void Deallocate(void *p) override;

    /***
     * @brief Clears all the memory in the block managed by the allocator
     */
    void Clear();




private:

    /***
     * The pointer to the first free address in the managed memory
     */
    void* CurrentPosition;
};


#endif //SIMULACRAENGINE_LINEARALLOCATOR_H
