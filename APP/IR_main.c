#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MSTK_int.h"
#include "MNVIC_int.h"
#include "MEXTI_int.h"

void Func_1(void);
void Func_2(void);
void Func_3(void);

volatile u8 flag=0;
volatile u32 Arr_Data[50];
volatile u8 counter=0;
volatile u8 Data=0;
void main(void)
{
	MSTK_voidInit();
	MRCC_init();
	MRCC_Enable_peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_Enable_peripheral(RCC_AHB1,RCC_AHB1_GPIOB);
	MRCC_Enable_peripheral(RCC_APB2,RCC_APB2_SYSCFG);
	MSTK_voidEnableInterrupt();
	MNVIC_voidEnableInterrupt(6);


	MGPIO_voidSetPinMode(PORT_A,PIN_0,OUTPUT_MODE);
	MGPIO_voidSetPinMode(PORT_A,PIN_1,OUTPUT_MODE);
	MGPIO_voidSetPinMode(PORT_A,PIN_2,OUTPUT_MODE);
	MGPIO_voidSetPinMode(PORT_A,PIN_3,OUTPUT_MODE);
	MGPIO_voidSetPinMode(PORT_A,PIN_4,OUTPUT_MODE);
	MGPIO_voidSetPinMode(PORT_A,PIN_5,OUTPUT_MODE);
	MGPIO_voidSetPinMode(PORT_A,PIN_6,OUTPUT_MODE);
	MGPIO_voidSetPinMode(PORT_A,PIN_7,OUTPUT_MODE);

	MGPIO_voidSetPinOutConfig(PORT_A,PIN_0,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinOutConfig(PORT_A,PIN_1,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinOutConfig(PORT_A,PIN_2,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinOutConfig(PORT_A,PIN_3,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinOutConfig(PORT_A,PIN_4,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinOutConfig(PORT_A,PIN_5,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinOutConfig(PORT_A,PIN_6,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinOutConfig(PORT_A,PIN_7,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(PORT_B,PIN_0,INPUT_MODE);
	//MGPIO_voidSetPinMode(PORT_B,PIN_1,INPUT_MODE);

	MGPIO_voidSetInputConfig(PORT_B,PIN_0,INPUT_PULLUP);
	//MGPIO_voidSetInputConfig(PORT_B,PIN_1,INPUT_PULLUP);

	EXTI_voidSetExtiConfig(PORT_B,EXTI_0);
	//EXTI_voidSetExtiConfig(PORT_B,EXTI_1);

	EXTI_voidEnableInterrupt(EXTI_0);
	//EXTI_voidEnableInterrupt(EXTI_1);

	EXTI_voidSetTrigger(EXTI_0,EXTI_FALLING);
	//	EXTI_voidSetTrigger(EXTI_1,EXTI_ONCHANGE);

	//EXTI0_voidCallBack(Func_1);

	EXTI_voidCallBack(Func_1,EXTI0_INDEX);
	MSTK_voidSetCallBackFunc(Func_2);

	while (1)
	{

	}
}
void Func_1(void)
{
	if(flag==0)
	{
		flag=0;
		MSTK_voidStart(30000);
	}
	else
	{
		Arr_Data[counter]=MSTK_u32GetElapsedTime();
		MSTK_voidStart(30000);
		counter++;
	}
	Func_3();
}
void Func_2(void)
{
	counter=0;
	flag=0;
	for(int i=0;i<8;i++)
	{
		if(Arr_Data[25-i]>=2000 && Arr_Data[i]<=3000)
		{
			CLR_BIT(Data,i);
		}
		else
		{
			SET_BIT(Data,i);
		}
	}

}
void Func_3(void){
	MGPIO_voidSetPinValue(PORT_A,PIN_0,GET_BIT(Data,0));
	MGPIO_voidSetPinValue(PORT_A,PIN_1,GET_BIT(Data,1));
	MGPIO_voidSetPinValue(PORT_A,PIN_2,GET_BIT(Data,2));
	MGPIO_voidSetPinValue(PORT_A,PIN_3,GET_BIT(Data,3));
	MGPIO_voidSetPinValue(PORT_A,PIN_4,GET_BIT(Data,4));
	MGPIO_voidSetPinValue(PORT_A,PIN_5,GET_BIT(Data,5));
	MGPIO_voidSetPinValue(PORT_A,PIN_6,GET_BIT(Data,6));
	MGPIO_voidSetPinValue(PORT_A,PIN_7,GET_BIT(Data,7));
}

