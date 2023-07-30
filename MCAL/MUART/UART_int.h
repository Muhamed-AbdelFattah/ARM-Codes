/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		6  June, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM_ARM (32-bit Architecture)
 * Layer:				MCAL
 ********************************************/
#ifndef _UART_INT_H_
#define _UART_INT_H_

void UART_voidInit(void);
void UART_voidSendData(u8 Copy_u8Data);
u8 UART_u8RecieveData(void);
void UART_voidEnable(void);
void UART_voidDisable(void);
void UART_voidCallBackFun(void(*PTR)(void));




#endif
