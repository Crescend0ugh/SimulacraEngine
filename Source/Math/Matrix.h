//
// Created by avsom on 9/14/2023.
//


#ifndef SIMULACRAENGINE_MATRIX_H
#define SIMULACRAENGINE_MATRIX_H

#include <xmmintrin.h>

/***
 * @brief A MxN matrix of arbitrary size
 */
class MatrixX {

public:
    inline MatrixX();
    inline MatrixX(int NRows, int NColumns);

    inline void SetSize(int NRows, int NColumns);
   // inline void SetZero();

   static void Test();
private:


    //Number of rows in the matrix




    int   NumRows;
    int   NumColumns;
    float *pData;


};


#endif //SIMULACRAENGINE_MATRIX_H


