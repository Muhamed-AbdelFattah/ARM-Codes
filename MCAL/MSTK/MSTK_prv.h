/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		31 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM_ARM (32-bit Architecture)
 * Layer:				MCAL
 ********************************************/
#ifndef _MSTK_PRV_H_
#define _MSTK_PRV_H_


#define   SYSTICK_BASE_ADDRESS  (0xE000E010)

typedef struct
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;

}MSTK_t;

#define AHB_DIV_8_CLK 0
#define AHB_CLK       1
#define  MSTK    ((volatile MSTK_t*)SYSTICK_BASE_ADDRESS)


#endif
