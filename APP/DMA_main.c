#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MSTK_int.h"
#include "MNVIC_int.h"
#include "MEXTI_int.h"
#include "MDMA_int.h"

void Func_1(void);
u32 Array_1[500];
u32 Array_2[500];

u32 Array_3[500];
u32 Array_4[500];
void main(void)
{
	for(int i=0;i<500;i++)
	{
	Array_1[i]=10;
	Array_2[i]=150;
	}
	MRCC_init();
	MRCC_Enable_peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_Enable_peripheral(RCC_AHB1,RCC_AHB1_DMA2);
	MSTK_voidInit();
	MGPIO_voidSetPinMode(PORT_A,PIN_0,OUTPUT_MODE);
	MGPIO_voidSetPinOutConfig(PORT_A,PIN_0,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinMode(PORT_A,PIN_1,OUTPUT_MODE);
	MGPIO_voidSetPinOutConfig(PORT_A,PIN_1,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MNVIC_voidEnableInterrupt(56);
	DMA2_voidInit();
	DMA2_voidSetStreamConfig(0,0,Array_1,Array_2,2,500);
	DMA2_SetCallBack(Func_1);
	DMA2_voidStreamEnable(0);
	for(int i=0;i<500;i++)
	{
		Array_4[i]=Array_3[i];
	}
	MGPIO_voidSetPinValue(PORT_A,PIN_0,PIN_HIGH);
	while(1)
	{
	}
}
void Func_1(void)
{
	MGPIO_voidSetPinValue(PORT_A,PIN_1,PIN_HIGH);

}
