//
// Created by avsom on 9/25/2023.
//






#include "../Sys/Precompiled.h"
#include <windows.h>
#include <iostream>
#include <chrono>


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
    std::cout << "------ Windows Initialized ------\n";



    std::cout<< "Build Mode: ";
#if defined(_DEBUG)
    std::cout<< "DEBUG MODE\n";

#elif defined(_NDEBUG)
    std::cout<< "RELEASE MODE\n";

#endif


    LinearAllocator allocator = LinearAllocator(100, malloc(100));

//    allocator.Allocate(101,1);

    StackAllocator stackAllocator = StackAllocator(100, malloc(100));
    stackAllocator.Allocate(1,1);
    std::cout << "Number of Allocations: " << stackAllocator.GetManagedMemory().NumAllocations << "\n";
    std::cout << "Memory Size: " << stackAllocator.GetManagedMemory().MemoryBlockSize << "\n";
    std::cout << "Memory Used: " << stackAllocator.GetManagedMemory().MemoryUsed << "\n";
    std::cout << "Memory Remaining: " << stackAllocator.GetManagedMemory().GetMemoryRemaining() << "\n";

    return 0;


}

