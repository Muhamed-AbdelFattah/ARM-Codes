/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		30 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM_ARM (32-bit Architecture)
 * Layer:				MCAL
 ********************************************/
#ifndef _MEXTI_INT_H_
#define _MEXTI_INT_H_

typedef enum
{
	EXTI_RISSING =0,
	EXTI_FALLING   ,
	EXTI_ONCHANGE
}EXTI_TRIGGER_t;


typedef enum
{
	EXTI_0    ,
	EXTI_1    ,
	EXTI_2    ,
	EXTI_3    ,
	EXTI_4    ,
	EXTI_5    ,
	EXTI_6    ,
	EXTI_7    ,
	EXTI_8    ,
	EXTI_9    ,
	EXTI_10   ,
	EXTI_11   ,
	EXTI_12   ,
	EXTI_13   ,
	EXTI_14   ,
	EXTI_15

}EXTI_NUM_t;

typedef enum
{
	EXTI0_INDEX = 0 ,
	EXTI1_INDEX,
	EXTI2_INDEX,
	EXTI3_INDEX,
	EXTI4_INDEX,
	EXTI5_INDEX,
	EXTI6_INDEX,
	EXTI7_INDEX,
	EXTI8_INDEX,
	EXTI9_INDEX,
	EXTI10_INDEX,
	EXTI11_INDEX,
	EXTI12_INDEX,
	EXTI13_INDEX,
	EXTI14_INDEX,
	EXTI15_INDEX,

}EXTI_INDEX_t;

void EXTI_voidSetExtiConfig(u8 Copy_u8Port,EXTI_NUM_t Copy_uddInterruptNum);
void EXTI_voidEnableInterrupt(EXTI_NUM_t Copy_uddInterruptNum);
void EXTI_voidDisbleInterrupt(EXTI_NUM_t Copy_uddInterruptNum);
void EXTI_voidSetTrigger(EXTI_NUM_t Copy_uddInterruptNum,EXTI_TRIGGER_t Copy_uddTrigger);
void EXTI_voidGetTrigger(EXTI_NUM_t Copy_uddInterruptNum,u8 *Copy_u8Data);
void EXTI_voidSWEvent(EXTI_NUM_t Copy_uddInterruptNum);
void EXTI_voidClearSwEvent(EXTI_NUM_t Copy_uddInterruptNum);

void EXTI0_voidCallBack(void (*NotificationFunction)(void));
void EXTI1_voidCallBack(void (*NotificationFunction)(void));
void EXTI2_voidCallBack(void (*NotificationFunction)(void));
void EXTI3_voidCallBack(void (*NotificationFunction)(void));
void EXTI4_voidCallBack(void (*NotificationFunction)(void));

void EXTI_voidCallBack(void(*Notification)(void),EXTI_INDEX_t Copy_uddEXTI_INDEX);





#endif

