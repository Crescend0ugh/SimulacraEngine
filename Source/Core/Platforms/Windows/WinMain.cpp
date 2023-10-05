//
// Created by avsom on 9/25/2023.
//






#include "../../Sys/Precompiled.h"
#include <windows.h>
#include <iostream>
#include <chrono>
#include "WindowsApplication.h"


Win32Vars	win32;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
    std::cout << "------ Windows Initialized ------\n";
    win32.hInstance = hInstance;
    win32.nCmdShow = nCmdShow;



    std::cout<< "Build Mode: ";
#if defined(_DEBUG)
    std::cout<< "DEBUG MODE\n";

#elif defined(_NDEBUG)
    std::cout<< "RELEASE MODE\n";

#endif


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

    for(int i = 0; i < 50; i++)
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

    for(int i = 0; i < 50; i++)
    {
        allocator.Allocate(1048576,1);
        allocator.Clear();
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::cout << "The Linear Test took " << (uint64)duration.count() << " milliseconds to execute.\n";







    return 0;


}

