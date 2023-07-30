/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		29 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM_ARM (32-bit Architecture)
 * Layer:				MCAL
 ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MGPIO_int.h"
#include "MGPIO_prv.h"
#include "MGPIO_cfg.h"


void MGPIO_voidSetPinMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode){



	switch(Copy_u8Port)
	{
	case PORT_A:
		GPIOA->GPIOx_MODER &= ~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
		GPIOA->GPIOx_MODER |= ( Copy_u8Mode << Copy_u8Pin*2 )  ;
		break;
	case PORT_B:
		GPIOB->GPIOx_MODER &= ~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
		GPIOB->GPIOx_MODER |= ( Copy_u8Mode << Copy_u8Pin*2 );
		break;
	case PORT_C:
		GPIOC->GPIOx_MODER &= ~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
		GPIOC->GPIOx_MODER |= ( Copy_u8Mode << Copy_u8Pin*2 );
		break;
	default:
		break;
	}


}
void MGPIO_voidSetPinOutConfig(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8OutType,u8 Copy_u8Speed){
	switch(Copy_u8Port)
	{
	case PORT_A:
		GPIOA->GPIOx_OTYPER &= ~(GPIO_OTYPER_MASK<<(Copy_u8Pin));
		GPIOA->GPIOx_OTYPER |= ( Copy_u8OutType << Copy_u8Pin );
		GPIOA->GPIOx_OSPEEDR &= ~( GPIO_OSPEEDR_MASK << (Copy_u8Pin*2));
		GPIOA->GPIOx_OSPEEDR |= ( Copy_u8Speed << Copy_u8Pin*2 );
		break;
	case PORT_B:
		GPIOB->GPIOx_OTYPER  &= ~(GPIO_OTYPER_MASK<<(Copy_u8Pin));
		GPIOB->GPIOx_OTYPER  |= ( Copy_u8OutType << Copy_u8Pin );
		GPIOB->GPIOx_OSPEEDR &= ~( GPIO_OSPEEDR_MASK << (Copy_u8Pin*2));
		GPIOB->GPIOx_OSPEEDR |= ( Copy_u8Speed << Copy_u8Pin*2 );
		break;
	case PORT_C:
		GPIOC->GPIOx_OTYPER &= ~(GPIO_OTYPER_MASK<<(Copy_u8Pin));
		GPIOC->GPIOx_OTYPER |= ( Copy_u8OutType << Copy_u8Pin);

		GPIOC->GPIOx_OSPEEDR &= ~( GPIO_OSPEEDR_MASK << (Copy_u8Pin*2));
		GPIOC->GPIOx_OSPEEDR |= ( Copy_u8Speed << Copy_u8Pin*2 );
		break;
	default:    break;
	}

}
void MGPIO_voidSetInputConfig(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PinConfig){
	switch(Copy_u8Port)
	{
	case PORT_A:
		GPIOA->GPIOx_PUPDR &= ~( GPIO_PUPDR_MASK << (Copy_u8Pin*2) );
		GPIOA->GPIOx_PUPDR |= ( Copy_u8PinConfig << Copy_u8Pin*2 );
		break;
	case PORT_B:
		GPIOB->GPIOx_PUPDR &= ~( GPIO_PUPDR_MASK << (Copy_u8Pin*2) );
		GPIOB->GPIOx_PUPDR |= ( Copy_u8PinConfig << Copy_u8Pin*2 );
		break;
	case PORT_C:
		GPIOC->GPIOx_PUPDR &= ~( GPIO_PUPDR_MASK << (Copy_u8Pin*2) );
		GPIOC->GPIOx_PUPDR |= ( Copy_u8PinConfig << Copy_u8Pin*2 );
		break;
	default:
		break;
	}

}
void MGPIO_voidGetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *Copy_u8Data){
	switch(Copy_u8Port)
	{
	case PORT_A:
		*Copy_u8Data =( (GPIOA->GPIOx_IDR>>Copy_u8Pin) & 1 );
		break;
	case PORT_B:
		*Copy_u8Data =( (GPIOB->GPIOx_IDR>>Copy_u8Pin) & 1 );
		break;
	case PORT_C:
		*Copy_u8Data =( (GPIOC->GPIOx_IDR>>Copy_u8Pin) & 1 );
		break;
	default:
		break;
	}

}
void MGPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Data){

	switch(Copy_u8Port)
	{
	case PORT_A:
		GPIOA->GPIOx_ODR &= ~( 1 << Copy_u8Pin )  ;
		GPIOA->GPIOx_ODR |=  ( Copy_u8Data << Copy_u8Pin )  ;
		break;
	case PORT_B:
		GPIOB->GPIOx_ODR &= ~( 1 << Copy_u8Pin )  ;
		GPIOB->GPIOx_ODR |= ( Copy_u8Data << Copy_u8Pin);
		break;
	case PORT_C:
		GPIOC->GPIOx_ODR &= ~( 1 << Copy_u8Pin )  ;
		GPIOC->GPIOx_ODR |= ( Copy_u8Data << Copy_u8Pin);
		break;
	default:
		break;
	}
}
void MGPIO_voidSetPinValueAdvanced(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
	case PORT_A:
		GPIOA->GPIOx_BSRR |=  ( 1 << Copy_u8Pin )  ;
		break;
	case PORT_B:
		GPIOB->GPIOx_BSRR |=  ( 1 << Copy_u8Pin )  ;
		break;
	case PORT_C:
		GPIOC->GPIOx_BSRR |=  ( 1 << Copy_u8Pin )  ;
		break;
	default:
		break;
	}
}
void MGPIO_voidResetPinValueAdvanced(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8PinNum=Copy_u8Pin+16;
	switch(Copy_u8Port)
	{
	case PORT_A:
		GPIOA->GPIOx_BSRR|=(1<<Local_u8PinNum);
		break;
	case PORT_B:
		GPIOB->GPIOx_BSRR|=(1<<Local_u8PinNum);
		break;
	case PORT_C:
		GPIOC->GPIOx_BSRR|=(1<<Local_u8PinNum);
		break;
	default:
		break;
	}
}
void MGPIO_voidSetAltConfig(u8 Copy_u8Port,u8 Copy_u8Pin,AltFun_t Copy_uddAltFunNum){
	if(Copy_u8Pin<=PIN_7)
	{
		switch(Copy_u8Port)
		{
		case PORT_A:
			GPIOA->GPIOx_AFRL &=~(0b1111<<Copy_u8Pin*4);
			GPIOA->GPIOx_AFRL |=(Copy_uddAltFunNum<<Copy_u8Pin*4);
			break;
		case PORT_B:
			GPIOB->GPIOx_AFRL &=~(0b1111<<Copy_u8Pin*4);
			GPIOB->GPIOx_AFRL |=(Copy_uddAltFunNum<<Copy_u8Pin*4);
			break;
		default:
			break;
		}
	}
	else
	{
		switch(Copy_u8Port)
		{
		case PORT_A:
			GPIOA->GPIOx_AFRH &=~(0b1111<<(Copy_u8Pin-8)*4);
			GPIOA->GPIOx_AFRH |=(Copy_uddAltFunNum<<(Copy_u8Pin-8)*4);
			break;
		case PORT_B:
			GPIOB->GPIOx_AFRH &=~(0b1111<<(Copy_u8Pin-8)*4);
			GPIOB->GPIOx_AFRH |=(Copy_uddAltFunNum<<(Copy_u8Pin-8)*4);
			break;
		default:
			break;
		}
	}
}
