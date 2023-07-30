/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		31 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM_ARM (32-bit Architecture)
 * Layer:				MCAL
 ********************************************/
#ifndef _MSTK_INT_H_
#define _MSTK_INT_H_

void MSTK_voidInit(void);
void MSTK_voidStart(u32 Copy_u8Value);
void MSTK_voidEnableInterrupt(void);
void MSTK_voidDisableInterrupt(void);
void MSTK_voidDelayMs(u32 Copy_u32DelayMs);
void MSTK_voidDelayUs(u32 Copy_u32DelayUs);
void MSTK_voidStartPeriod(u32 Copy_u32Value,void (*CallBackFunc)(void));
u8 MSTK_u8GetFlag(void);
u32 MSTK_u32GetElapsedTime(void);


#endif
