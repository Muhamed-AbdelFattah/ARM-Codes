/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		30 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM_ARM (32-bit Architecture)
 * Layer:				MCAL
 ********************************************/
#ifndef _MNVIC_INT_H_
#define _MNVIC_INT_H_


#define MNVIC_GROUP_MODE_G16S0        3
#define MNVIC_GROUP_MODE_G8S2         4
#define MNVIC_GROUP_MODE_G4S4         5
#define MNVIC_GROUP_MODE_G2S8         6
#define MNVIC_GROUP_MODE_G0S16		  7

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntPos);
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntPos);
void MNVIC_voidEnableInterruptPending (u8 Copy_u8IntPos);
void MNVIC_voidDisableInterruptPending (u8 Copy_u8IntPos);
u8 MNVIC_u8IsInterruptActive (u8 Copy_u8IntPos);
void MNVIC_voidSetInterruptPriority (u8 Copy_u8IntPos , u8 Copy_u8GroupNum,u8 Copy_u8SubGroup);
void MNVIC_voidSetInterruptGroupMode(u8 Copy_u8GroupMode);







#endif
