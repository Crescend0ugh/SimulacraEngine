
#include <iostream>
#include "Source/Math/Vector.h"


int main()
{
    std::cout << sizeof(SVectorX) << std::endl;

    float data[] ={9.0f, 2.0f, 5.0f};
    float* t = data;
    SVectorX sVectorX = SVectorX(3, t);
    float ans = sVectorX*sVectorX;
    std::cout << ans << std::endl;
}
