/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		30 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM_ARM (32-bit Architecture)
 * Layer:				MCAL
 ********************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "MNVIC_int.h"
#include "MNVIC._cfg.h"
#include "MNVIC_prv.h"

 static u8 Local_u8GroupMode=0;
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntPos){
	u8 Local_u8InterriptNum=Copy_u8IntPos/32;
	u8 Local_u8InterruptPos=Copy_u8IntPos%32;

	NVIC->ISER[Local_u8InterriptNum]  = 1 << Local_u8InterruptPos;

}
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntPos){
	u8 Local_u8InterriptNum=Copy_u8IntPos/32;
	u8 Local_u8InterruptPos=Copy_u8IntPos%32;

	NVIC->ICER[Local_u8InterriptNum]  = 1 << Local_u8InterruptPos;

}
void MNVIC_voidEnableInterruptPending (u8 Copy_u8IntPos){
	u8 Local_u8InterriptNum=Copy_u8IntPos/32;
	u8 Local_u8InterruptPos=Copy_u8IntPos%32;

	NVIC->ISPR[Local_u8InterriptNum]  = 1 << Local_u8InterruptPos;

}
void MNVIC_voidDisableInterruptPending (u8 Copy_u8IntPos){
	u8 Local_u8InterriptNum=Copy_u8IntPos/32;
	u8 Local_u8InterruptPos=Copy_u8IntPos%32;

	NVIC->ICPR[Local_u8InterriptNum]  = 1 << Local_u8InterruptPos;
}
u8 MNVIC_u8IsInterruptActive (u8 Copy_u8IntPos){
	u8 Local_u8InterriptNum=Copy_u8IntPos/32;
	u8 Local_u8InterruptPos=Copy_u8IntPos%32;
	u8 Local_u8PinAction;
	 Local_u8PinAction=( NVIC->IABR[Local_u8InterriptNum]>>Local_u8InterruptPos ) & 1 ;
	 return Local_u8PinAction;
}
void MNVIC_voidSetInterruptPriority (u8 Copy_u8IntPos , u8 Copy_u8GroupNum,u8 Copy_u8SubGroup){

	switch (Local_u8GroupMode)
	{
	case MNVIC_GROUP_MODE_G16S0 : NVIC->IPR[Copy_u8IntPos] = Copy_u8GroupNum << 4;
		break;
	case MNVIC_GROUP_MODE_G8S2  :NVIC->IPR[Copy_u8IntPos] = ( Copy_u8GroupNum << 5 ) | (Copy_u8SubGroup << 4 );
		break;
	case MNVIC_GROUP_MODE_G4S4  :NVIC->IPR[Copy_u8IntPos] = ( Copy_u8GroupNum << 6 ) | (Copy_u8SubGroup << 4 );
		break;
	case  MNVIC_GROUP_MODE_G2S8  : NVIC->IPR[Copy_u8IntPos] = ( Copy_u8GroupNum << 7 ) | (Copy_u8SubGroup << 4 );
		break;
	case MNVIC_GROUP_MODE_G0S16 :NVIC->IPR[Copy_u8IntPos] = ( Copy_u8GroupNum << 8 ) | (Copy_u8SubGroup << 4 );
		break;
	default :
		break;

	}

}
void MNVIC_voidSetInterruptGroupMode(u8 Copy_u8GroupMode){
	Local_u8GroupMode=Copy_u8GroupMode;
	MSCB_AIRCR= MNVIC_VECTKEY;
	MSCB_AIRCR= MNVIC_VECTKEY | (Copy_u8GroupMode<<8) ;
}







