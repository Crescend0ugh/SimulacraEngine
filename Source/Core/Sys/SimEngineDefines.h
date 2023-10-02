//
// Created by avsom on 9/20/2023.
//

#ifndef SIMULACRAENGINE_SIMENGINEDEFINES_H
#define SIMULACRAENGINE_SIMENGINEDEFINES_H




//-------------------------------
#define SIM_SMALL_NUMBER 1e-5
#define SIM_VERY_SMALL_NUMBER 1e-7


#define PI          3.14159265358979323846
#define HALF_PI 	1.57079632679489661923
#define QUARTER_PI  0.785398163397448309616

/***
 * =======================================================================================================
 * =======================================================================================================
 */
#define SIM_INLINE         inline
#define SIM_FORCE_INLINE __forceinline


//========================================================================================================

#define Align( Address, Alignment ) (void*) ( (UINT_PTR)Address & ~(Alignment-1) );

#endif //SIMULACRAENGINE_SIMENGINEDEFINES_H