
#include <algorithm>
#include <chrono>
#include <iostream>

#include "Source/Math/Vector.h"


int main()
{



    // Generate Random values

    // Fill up the vector
    const int size = 1e5;


    float testData[size]= {  };
    std::fill(std::begin(testData), std::begin(testData)+size, 10);
    SVector Test = SVector(std::size(testData), testData);
    SVector Test2 = SVector(std::size(testData), testData);
    std::cout << Test[1] << std::endl;



    auto start = std::chrono::high_resolution_clock::now();
    float lol = Test* Test2;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << lol << std::endl;
    std::cout << duration.count() << std::endl;


    return 0;
}
