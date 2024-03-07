//
// Created by avsom on 9/14/2023.
//


#pragma once

#include "../Sys/SimulacraEngineTypes.h"
#include "../Sys/SimulacraEngineDefines.h"

struct SMatrix2
{

};

struct SMatrix3
{

};

/***
 * @brief A MxN matrix of arbitrary size
 */
struct SMatrixX
{

public:
    SIM_FORCE_INLINE      SMatrixX();
    SIM_FORCE_INLINE      SMatrixX(int NRows, int NColumns);

    SIM_FORCE_INLINE void SetSize(int NumberOfRows, int NColumns);
    SIM_FORCE_INLINE void SetData(float *Data);

    SIM_FORCE_INLINE bool Equals(SMatrixX m, float epsilon = 1e-7) const;

    // SIM_FORCE_INLINE void SetZero();

    static void Test();

private:


    //Number of rows in the matrix




    int NumRows;
    int NumColumns;
    float *pData;


};

#include "SimulacraMatrix.inl"




