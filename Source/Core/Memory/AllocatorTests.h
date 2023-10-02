//
// Created by avsom on 10/2/2023.
//

#ifndef SIMULACRAENGINE_ALLOCATORTESTS_H
#define SIMULACRAENGINE_ALLOCATORTESTS_H

#include <chrono>
#include <iostream>
#include "../Sys/Precompiled.h"


void TestLinear()
{
    void * DynamicTest;
    auto start = std::chrono::high_resolution_clock::now();
// do something

    for(int i = 0; i < 10'000; i++)
    {
        DynamicTest = malloc(16);
        free(DynamicTest);
    }

    for(int i = 0; i < 1'000; i++)
    {
        DynamicTest = malloc(256);
        free(DynamicTest);
    }

    for(int i = 0; i < 10000; i++)
    {
        DynamicTest = malloc(1048576);
        free(DynamicTest);
    }



    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::cout << "The Malloc test took " << (uint64)duration.count()<< " milliseconds to execute.\n";



    LinearAllocator allocator = LinearAllocator(1048576, malloc(1048576));

    start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < 10'000; i++)
    {
        allocator.Allocate(16,1);
        allocator.Clear();
    }

    for(int i = 0; i < 1'000; i++)
    {
        allocator.Allocate(256,1);
        allocator.Clear();
    }

    for(int i = 0; i < 10000; i++)
    {
        allocator.Allocate(1048576,1);
        allocator.Clear();
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::cout << "The Linear Test took " << (uint64)duration.count() << " milliseconds to execute.\n";

}

#endif //SIMULACRAENGINE_ALLOCATORTESTS_H
