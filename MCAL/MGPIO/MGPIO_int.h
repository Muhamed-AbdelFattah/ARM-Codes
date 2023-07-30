/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		29 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM_ARM (32-bit Architecture)
 * Layer:				MCAL
 ********************************************/
#ifndef _MGPIO_INT_H_
#define _MGPIO_INT_H_


/***************************** PORT MACROS  ***********************/
#define   PORT_A   0
#define   PORT_B   1
#define   PORT_C   2

/***************************** PIN MACROS ***************************/
#define PIN_0      	0
#define PIN_1		1
#define PIN_2		2
#define PIN_3		3
#define PIN_4       4
#define PIN_5       5
#define PIN_6       6
#define PIN_7       7
#define PIN_8       8
#define PIN_9       9
#define PIN_10      10
#define PIN_11      11
#define PIN_12      12
#define PIN_13      13
#define PIN_14      14
#define PIN_15      15

/*************************** Mode Direction Macros  ****************************/
#define   INPUT_MODE     00
#define   OUTPUT_MODE    01
#define   ALT_FUNC_MODE  10
#define   ALALOG_MODE    11

/************************** OUTPUT Macros ***************************/
#define OUTPUT_PUSH_PULL    	0
#define OUTPUT_OPEN_DRAIN    	1

/************************** OUTPUT Speed Macros *********************/
#define OUTPUT_LOW_SPEED   		    	0
#define OUTPUT_MEDIUM_SPEED     		1
#define OUTPUT_HIGH_SPEED    			2
#define OUTPUT_VHIGH_SPEED       		3

/************************* INPUT Mode Macros **********************/
#define INPUT_FLOAT     	    0
#define INPUT_PULLUP  	        1
#define INPUT_PULLDOWN       	2

/************************  PINS               *********************/
#define PIN_HIGH      1
#define PIN_LOW       0
/***********************   Alternative PINS   ***********************/
typedef enum
{
	AF0  ,
	AF1  ,
	AF2  ,
	AF3  ,
	AF4  ,
	AF5  ,
	AF6  ,
	AF7  ,
	AF8  ,
	AF9  ,
	AF10 ,
	AF11 ,
	AF12 ,
	AF13 ,
	AF14 ,
	AF15
}AltFun_t;

void MGPIO_voidSetPinMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode);

void MGPIO_voidSetPinOutConfig(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8OutType,u8 Copy_u8Speed);

void MGPIO_voidSetInputConfig(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PinConfig);

void MGPIO_voidGetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *Copy_u8Data);

void MGPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Data);

void MGPIO_voidResetPinValueAdvanced(u8 Copy_u8Port,u8 Copy_u8Pin);

void MGPIO_voidSetAltConfig(u8 Copy_u8Port,u8 Copy_u8Pin,AltFun_t Copy_uddAltFunNum);





#endif
