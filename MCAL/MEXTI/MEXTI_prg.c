/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		31 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM_ARM (32-bit Architecture)
 * Layer:				MCAL
 ********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MEXTI_cfg.h"
#include "MEXTI_int.h"
#include "MEXTI_prv.h"
static void (*pvArrayEXTI_CallBack[MAX_INTERRUPT])(void)={NULL};

void EXTI_voidSetExtiConfig(u8 Copy_u8Port,EXTI_NUM_t Copy_uddInterruptNum){
	u8 Local_u8REG=Copy_uddInterruptNum/4;
	u8 Local_u8BIT=Copy_uddInterruptNum%4;

		EXTI_CR->EXTICR[Local_u8REG] &= ~(EXTI_CR_MASK<<4*Local_u8BIT);
		EXTI_CR->EXTICR[Local_u8REG] |=  (Copy_u8Port<<4*Local_u8BIT);

}
void EXTI_voidEnableInterrupt(EXTI_NUM_t Copy_uddInterruptNum){

	EXTI->IMR |= (1 << Copy_uddInterruptNum);
}
void EXTI_voidDisbleInterrupt(EXTI_NUM_t Copy_uddInterruptNum){

	EXTI->IMR &= ~ (1 << Copy_uddInterruptNum);
}
void EXTI_voidSetTrigger(EXTI_NUM_t Copy_uddInterruptNum,EXTI_TRIGGER_t Copy_uddTrigger){

	switch(Copy_uddTrigger)
	{
	case EXTI_RISSING :
		EXTI->RTSR |=  (1 << Copy_uddInterruptNum);
		EXTI->FTSR &= ~(1 << Copy_uddInterruptNum);
		break;
	case EXTI_FALLING :
		EXTI->FTSR |=  (1 << Copy_uddInterruptNum);
		EXTI->RTSR &= ~(1 << Copy_uddInterruptNum);
		break;
	case EXTI_ONCHANGE :
		EXTI->FTSR |=  (1 << Copy_uddInterruptNum);
		EXTI->RTSR |=  (1 << Copy_uddInterruptNum);
		break;
	default :
		break;
	}
}
void  EXTI_voidGetTrigger(EXTI_NUM_t Copy_uddInterruptNum,u8 *Copy_u8Data){

	*Copy_u8Data=((EXTI->PR>>Copy_uddInterruptNum) & 1) ;

}

void EXTI_voidSetSwEvent(EXTI_NUM_t Copy_uddInterruptNum){

	EXTI->SWIER |= (1<<Copy_uddInterruptNum);
}

void EXTI_voidClearSwEvent(EXTI_NUM_t Copy_uddInterruptNum){
	SET_BIT(EXTI->PR,Copy_uddInterruptNum);
}

void EXTI0_voidCallBack(void (*NotificationFunction)(void)){
	pvArrayEXTI_CallBack[EXTI0_INDEX]=NotificationFunction;
}
void EXTI1_voidCallBack(void (*NotificationFunction)(void)){
	pvArrayEXTI_CallBack[EXTI1_INDEX]=NotificationFunction;
}
void EXTI2_voidCallBack(void (*NotificationFunction)(void)){
	pvArrayEXTI_CallBack[EXTI2_INDEX]=NotificationFunction;
}
void EXTI3_voidCallBack(void (*NotificationFunction)(void)){
	pvArrayEXTI_CallBack[EXTI3_INDEX]=NotificationFunction;
}
void EXTI4_voidCallBack(void (*NotificationFunction)(void)){
	pvArrayEXTI_CallBack[EXTI4_INDEX]=NotificationFunction;
}

void EXTI_voidCallBack(void(*Notification)(void),EXTI_INDEX_t Copy_uddEXTI_INDEX)
{
	pvArrayEXTI_CallBack[Copy_uddEXTI_INDEX]=Notification;
}

void EXTI0_IRQHandler(void){
	pvArrayEXTI_CallBack[EXTI0_INDEX]();
	SET_BIT(EXTI->PR,EXTI0_INDEX);
}
void EXTI1_IRQHandler(void){
	pvArrayEXTI_CallBack[EXTI1_INDEX]();
	SET_BIT(EXTI->PR,EXTI1_INDEX);
}
void EXTI2_IRQHandler(void){
	pvArrayEXTI_CallBack[EXTI2_INDEX]();
	SET_BIT(EXTI->PR,EXTI2_INDEX);
}
void EXTI3_IRQHandler(void){
	pvArrayEXTI_CallBack[EXTI3_INDEX]();
	SET_BIT(EXTI->PR,EXTI3_INDEX);
}
void EXTI4_IRQHandler(void){
	pvArrayEXTI_CallBack[EXTI4_INDEX]();
	SET_BIT(EXTI->PR,EXTI4_INDEX);
}


 /* void MEXTIO_voidCallback(void(void (*ptr)(void));
  * void EXT0_IRQHandler(void); dont forget to remove pending flag by clear bit
  * static void (*EXTO_CallBack)(void)=NULL;
  * */
