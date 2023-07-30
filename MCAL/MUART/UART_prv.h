/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		6  June, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM_ARM (32-bit Architecture)
 * Layer:				MCAL
 ********************************************/
#ifndef _UART_PRV_H_
#define _UART_PRV_H_

#define UART1_BASE_ADDRESS   (0x40011000)

typedef struct
{
	u32     SR   ;
	u32     DR   ;
	u32     BRR  ;
	u32     CR1  ;
	u32     CR2  ;
	u32     CR3  ;
	u32     GTPR ;
}UART_t;

#define  UART1    ((volatile UART_t*)UART1_BASE_ADDRESS)


#endif
