//
// Created by avsom on 9/14/2023.
//


#ifndef SIMULACRAENGINE_MATRIX_H
#define SIMULACRAENGINE_MATRIX_H

#include <x86intrin.h>
#include "../EngineTypes.h"
#include "../EngineDefines.h"


/***
 * @brief A MxN matrix of arbitrary size
 */
struct SMatrix {

public:
    SIM_FORCE_INLINE      SMatrix();
    SIM_FORCE_INLINE      SMatrix(int NRows, int NColumns);


    SIM_FORCE_INLINE void SetSize(int NumberOfRows, int NColumns);
    SIM_FORCE_INLINE void SetData(float* Data);

    SIM_FORCE_INLINE bool Equals(SMatrix m, float epsilon = 1e-7) const;

   // SIM_FORCE_INLINE void SetZero();

   static void Test();
private:


    //Number of rows in the matrix




    int   NumRows;
    int   NumColumns;
    float *pData;


};

#include "Matrix.inl"


#endif //SIMULACRAENGINE_MATRIX_H


