#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_int.h"
#include "MSTK_int.h"
#include "S2P_int.h"
#include "S2P_cfg.h"
#include "S2P_prv.h"


void S2P_voidInit(void){

MGPIO_voidSetPinMode(S2P_PORT,S2P_DATA ,OUTPUT_MODE);
MGPIO_voidSetPinMode(S2P_PORT,S2P_LATCH,OUTPUT_MODE);
MGPIO_voidSetPinMode(S2P_PORT,S2P_SHIFT,OUTPUT_MODE);

MGPIO_voidSetPinOutConfig(S2P_PORT,S2P_DATA ,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
MGPIO_voidSetPinOutConfig(S2P_PORT,S2P_LATCH,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
MGPIO_voidSetPinOutConfig(S2P_PORT,S2P_SHIFT,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);

}
void S2P_voidShiftData(u8 Copy_u8Data){
	s8 Local_s8Counter=0;
	for(Local_s8Counter=7;Local_s8Counter>=0;Local_s8Counter--)
	{

	MGPIO_voidSetPinValue(PORT_A,S2P_DATA,GET_BIT(Copy_u8Data,Local_s8Counter));

	/*Signal for Shift pin to shift value */
	MGPIO_voidSetPinValue(S2P_PORT,S2P_SHIFT,PIN_HIGH);
	MSTK_voidDelayUs(10);
	MGPIO_voidSetPinValue(S2P_PORT,S2P_SHIFT,PIN_LOW);
	MSTK_voidDelayUs(10);
	}
}

void S2P_voidSendData(void){

	MGPIO_voidSetPinValue(S2P_PORT,S2P_LATCH,PIN_HIGH);
	MSTK_voidDelayUs(5);
	MGPIO_voidSetPinValue(S2P_PORT,S2P_LATCH,PIN_LOW);
	MSTK_voidDelayUs(5);
}

/*int arra[8]={0, 102, 0, 36, 24, 66, 36, 24}*/

/*
 * for(i=0;i<8;i++)
 * {
 * 	local=(1<<i)|arr[i];
 * 	local=0b0000 0001   0000 0000
 * 	S2P_voidShiftData(local)
 * }
 * */


