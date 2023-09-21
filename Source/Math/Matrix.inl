//
// Created by avsom on 9/20/2023.
//

#ifndef SIMULACRAENGINE_MATRIX_INL
#define SIMULACRAENGINE_MATRIX_INL


#include "Matrix.h"
#include <cmath>





/***
 * @param m The other matrix being compared with.
 * @param epsilon Error Tolerance.
 * @return true if two matrices are equal, within specified tolerance, otherwise false
 */
bool SMatrix::Equals(SMatrix m, float epsilon) const
{
    //Checks if dimensions are same
    /// \TODO Should probably add a helper function to do this
    if(this->NumRows != m.NumRows && this->NumColumns != m.NumColumns )
    {
        return false;
    }

    //iterate through columns
    for(int i = 0; i < NumRows; i++)
    {
        //iterate through rows
        for (int j = 0; j < NumColumns; ++j)
        {
            //difference between elements at the same position in matrix
            float difference = abs(this->pData[i*NumColumns+j] - m.pData[i*NumColumns+j]);

            //return false if the difference is greater than the tolerance
            if(difference>epsilon)
            {
                return false;
            }
        }
    }

    //return true otherwise
    return true;

}



#endif //SIMULACRAENGINE_MATRIX_INL
