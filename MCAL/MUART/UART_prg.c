/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		6  June, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM_ARM (32-bit Architecture)
 * Layer:				MCAL
 ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_int.h"
#include "UART_cfg.h"
#include "UART_prv.h"



void UART_voidInit(void){
	/*OverSampling by 16 */
	CLR_BIT(UART1->CR1,13);
	/*8 Data bits*/
	CLR_BIT(UART1->CR1,12);
	/*Disable Parity Pin*/
	CLR_BIT(UART1->CR1,10);
	/*Receiver enable*/
	SET_BIT(UART1->CR1,2);
	/*Transmitter Enable*/
	SET_BIT(UART1->CR1,3);
	/*Stop Bits 1 */
	CLR_BIT(UART1->CR2,12);
	CLR_BIT(UART1->CR2,13);
	/*Set Baud Rate */
	UART1->BRR = (104<<4)|(3);

}
void UART_voidSendData(u8 Copy_u8Data){
	UART1->DR=Copy_u8Data;
	while(GET_BIT(UART1->SR,7)== 0);
}
u8   UART_u8RecieveData(void){
	u8 Local_u8Data=UART1->DR;
	while(GET_BIT(UART1->SR,5)== 0);
	return(Local_u8Data);
}
void UART_voidEnable(void){
	/*UART Enable*/
SET_BIT(UART1->CR1,13);
}
void UART_voidDisable(void){
	/*UART Enable*/
	CLR_BIT(UART1->CR1,13);
}

/*
void UART_voidCallBackFun(void(*PTR)(void)){

}
*/
