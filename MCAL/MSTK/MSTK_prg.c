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
#include "MSTK_cfg.h"
#include "MSTK_int.h"
#include "MSTK_prv.h"

static void (*STK_CallBackFunc)(void)=NULL;

void MSTK_voidInit(void){
#if  ( CLKSOURCE == AHB_DIV_8_CLK)
	CLR_BIT((MSTK->CTRL),2);
#elif (CLKSOURCE == AHB_CLK)
	SET_BIT((MSTK->CTRL),2);
#else
#endif

}

void MSTK_voidEnableInterrupt(void){
	SET_BIT((MSTK->CTRL),1);
}

void MSTK_voidDisableInterrupt(void){
	CLR_BIT((MSTK->CTRL),1);
}
void MSTK_voidStart(u32 Copy_u32Value){
	/*Copy Value to STK LOAD*/
	MSTK->LOAD=Copy_u32Value;

	/*Make MSTK Rest write any Number on Register*/
	MSTK->VAL=0;

	/*Enable Counter*/
	SET_BIT((MSTK->CTRL),0);

}
void MSTK_voidStartPeriod(u32 Copy_u32Value,void (*CallBackFunc)(void)){

	STK_CallBackFunc=CallBackFunc;
	/*Copy Value to STK LOAD*/
	MSTK->LOAD=Copy_u32Value;

	/*Make MSTK Rest write any Number on Register*/
	MSTK->VAL=0;

	/*Enable Counter*/
	SET_BIT((MSTK->CTRL),0);

}
void MSTK_voidDelayMs(u32 Copy_u32DelayMs){
	MSTK_voidDisableInterrupt();
	MSTK_voidStart(Copy_u32DelayMs*(2000));
	while(GET_BIT(MSTK->CTRL,16) == 0);
}
void MSTK_voidDelayUs(u32 Copy_u32DelayUs){
	MSTK_voidDisableInterrupt();
	MSTK_voidStart(Copy_u32DelayUs*2);
	while(GET_BIT(MSTK->CTRL,16) == 0);
}
u8 MSTK_voidGetFlag(void){
	return(GET_BIT(MSTK->CTRL,16));
}
void MSTK_voidSetCallBackFunc(void (*ptr)(void)){
	STK_CallBackFunc=ptr;
}
void Systick_Handler(void)
{
	if(STK_CallBackFunc != NULL)
	{
		STK_CallBackFunc();
	}
	else
	{

	}
}
u32 MSTK_u32GetElapsedTime(void)
{
	return(MSTK->LOAD-MSTK->VAL);
}
