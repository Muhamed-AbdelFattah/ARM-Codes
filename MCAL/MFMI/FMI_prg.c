#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FMI_int.h"
#include "FMI_cfg.h"
#include "FMI_prv.h"




void FMI_voidSectorErase(u8 Copy_u8Sector){
	/*1-Pooling on BSY Flag*/
	while (GET_BIT(FMI->SR,16)==1);

	/*2- Unlock Flash Register */
	if(GET_BIT(FMI->CR,31)==1)
	{
		FMI->KEYR=FMI_KEY1;
		FMI->KEYR=FMI_KEY2;
	}

	/*3- Select Sector*/
	FMI->CR &=~(0b1111<<3);
	FMI->CR |=(Copy_u8Sector<<3);

	/*4- Select Erase Mode*/
	SET_BIT(FMI->CR,1);

	/*5- Start Operation*/
	SET_BIT(FMI->CR,16);

	/*6- wait until it Finish*/
	while (GET_BIT(FMI->SR,16) == 1);

	/*CLear EOP Flag*/
	SET_BIT(FMI->SR,0);

	/*4- DeSelect Erase Mode*/
	CLR_BIT(FMI->CR,1);
}
void FMI_voidFlashWrite(u32 Copy_u32Address,u16 *Copy_pu16Data,u16 Copy_u16Length){
		/*1-Pooling on BSY Flag*/
		while (GET_BIT(FMI->SR,16)==1);

		/*2- Unlock Flash Register */
		if(GET_BIT(FMI->CR,31)==1)
		{
			FMI->KEYR=FMI_KEY1;
			FMI->KEYR=FMI_KEY2;
		}

		/*3- Select Psize (Element Size )  you wanna to write in flash*/
		FMI->CR &=~(0b11<<8);
		FMI->CR |=(1<<8);


		/*4- Activating Programming Mode*/
		SET_BIT(FMI->CR,0);

		/* 5- Write Data Array on Flash address */
			for(u16 Local_u8Counter=0; Local_u8Counter<Copy_u32Address; Local_u8Counter++)
			{
				*((volatile u16*)Copy_u32Address) = Copy_pu16Data[Local_u8Counter];
				Copy_u32Address += 2 ;

				/* 6- wait for Busy Flag    */
				while(GET_BIT(FMI->SR, 16) == 1){}
				/* 7- Clear EOP flag   */
				SET_BIT(FMI->SR, 0);
			}
			/* 8- deactivate programming mode */
			CLR_BIT(FMI->CR, 0);
}
