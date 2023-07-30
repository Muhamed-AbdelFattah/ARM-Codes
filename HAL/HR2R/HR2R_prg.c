/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		4 June, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM_ARM (32-bit Architecture)
 * Layer:				MCAL
 ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MSTK_int.h"
#include "MGPIO_int.h"

#include "HR2R_cfg.h"
#include "HR2R_int.h"
#include "HR2R_prv.h"


void HR2R_voidInit(void)
{

	MGPIO_voidSetPinMode(DACPORT,DAC_0,OUTPUT_MODE);
	MGPIO_voidSetPinMode(DACPORT,DAC_1,OUTPUT_MODE);
	MGPIO_voidSetPinMode(DACPORT,DAC_2,OUTPUT_MODE);
	MGPIO_voidSetPinMode(DACPORT,DAC_3,OUTPUT_MODE);
	MGPIO_voidSetPinMode(DACPORT,DAC_4,OUTPUT_MODE);
	MGPIO_voidSetPinMode(DACPORT,DAC_5,OUTPUT_MODE);
	MGPIO_voidSetPinMode(DACPORT,DAC_6,OUTPUT_MODE);
	MGPIO_voidSetPinMode(DACPORT,DAC_7,OUTPUT_MODE);

	MGPIO_voidSetPinOutConfig(DACPORT,DAC_0,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinOutConfig(DACPORT,DAC_1,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinOutConfig(DACPORT,DAC_2,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinOutConfig(DACPORT,DAC_3,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinOutConfig(DACPORT,DAC_4,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinOutConfig(DACPORT,DAC_5,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinOutConfig(DACPORT,DAC_6,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinOutConfig(DACPORT,DAC_7,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);

}

void HR2R_voidSendData(const u8 *Copy_u16Arr,u32 Copy_ArrIndex)
{
	u8 Local_u8Counter_1=0;
	for(Local_u8Counter_1=0;Local_u8Counter_1<Copy_ArrIndex;Local_u8Counter_1++)
	{

			MGPIO_voidSetPinValue(DACPORT,DAC_0,GET_BIT(Copy_u16Arr[Local_u8Counter_1],0));
			MGPIO_voidSetPinValue(DACPORT,DAC_1,GET_BIT(Copy_u16Arr[Local_u8Counter_1],1));
			MGPIO_voidSetPinValue(DACPORT,DAC_2,GET_BIT(Copy_u16Arr[Local_u8Counter_1],2));
			MGPIO_voidSetPinValue(DACPORT,DAC_3,GET_BIT(Copy_u16Arr[Local_u8Counter_1],3));
			MGPIO_voidSetPinValue(DACPORT,DAC_4,GET_BIT(Copy_u16Arr[Local_u8Counter_1],4));
			MGPIO_voidSetPinValue(DACPORT,DAC_5,GET_BIT(Copy_u16Arr[Local_u8Counter_1],5));
			MGPIO_voidSetPinValue(DACPORT,DAC_6,GET_BIT(Copy_u16Arr[Local_u8Counter_1],6));
			MGPIO_voidSetPinValue(DACPORT,DAC_7,GET_BIT(Copy_u16Arr[Local_u8Counter_1],7));
			MSTK_voidDelayUs(125);

	}
}
