//
// Created by avsom on 9/20/2023.
//

#ifndef SIMULACRAENGINE_SIMENGINEDEFINES_H
#define SIMULACRAENGINE_SIMENGINEDEFINES_H




//-------------------------------


/***
 * =======================================================================================================
 * =======================================================================================================
 */
#define SIM_INLINE         inline
#define SIM_FORCE_INLINE __forceinline


//========================================================================================================

#define Align( Address, Alignment ) (void*) ( (UINT_PTR)Address & ~(Alignment-1) );

#endif //SIMULACRAENGINE_SIMENGINEDEFINES_H
