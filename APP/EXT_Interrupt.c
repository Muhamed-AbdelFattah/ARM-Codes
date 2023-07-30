#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MSTK_int.h"
#include "MNVIC_int.h"
#include "MEXTI_int.h"
void Func_1(void);

void main(void)
{
	MSTK_voidInit();
	MRCC_init();
	MRCC_Enable_peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_Enable_peripheral(RCC_AHB1,RCC_AHB1_GPIOB);
	MRCC_Enable_peripheral(RCC_APB2,RCC_APB2_SYSCFG);

	MNVIC_voidSetInterruptGroupMode(MNVIC_GROUP_MODE_G16S0);

	MNVIC_voidSetInterruptPriority(6,0,0);
	MNVIC_voidSetInterruptPriority(7,1,0);


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
	MGPIO_voidSetPinMode(PORT_B,PIN_1,INPUT_MODE);

	MGPIO_voidSetInputConfig(PORT_B,PIN_0,INPUT_PULLUP);
	MGPIO_voidSetInputConfig(PORT_B,PIN_1,INPUT_PULLUP);

	MNVIC_voidEnableInterrupt(6);
	MNVIC_voidEnableInterrupt(7);


	EXTI_voidSetExtiConfig(PORT_B,EXTI_0);
	EXTI_voidSetExtiConfig(PORT_B,EXTI_1);

	EXTI_voidEnableInterrupt(EXTI_0);
	EXTI_voidEnableInterrupt(EXTI_1);

	EXTI_voidSetTrigger(EXTI_0,EXTI_ONCHANGE);
	EXTI_voidSetTrigger(EXTI_1,EXTI_ONCHANGE);

	EXTI0_voidCallBack(Func_1);


	while (1)
	{

	}
}
void Func_1(void)
{
	while(1)
	{
	MGPIO_voidSetPinValue(PORT_A,PIN_0,PIN_HIGH);
	MGPIO_voidSetPinValue(PORT_A,PIN_1,PIN_HIGH);
	MGPIO_voidSetPinValue(PORT_A,PIN_2,PIN_HIGH);
	MGPIO_voidSetPinValue(PORT_A,PIN_3,PIN_HIGH);
	MGPIO_voidSetPinValue(PORT_A,PIN_4,PIN_HIGH);

	}
}
/*void Func_2()
{

}
*/
