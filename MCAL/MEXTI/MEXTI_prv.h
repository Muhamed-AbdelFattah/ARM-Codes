/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		30 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM_ARM (32-bit Architecture)
 * Layer:				MCAL
 ********************************************/
#ifndef _MEXTI_PRV_H_
#define _MEXTI_PRV_H_


#define EXTI_BASE_ADDRESS    (0x40013C00)
#define EXTICR_BASE_ADDRESS  (0x40013800)

typedef struct
{
	u32  IMR;
	u32  EMR;
	u32  RTSR;
	u32  FTSR;
	u32  SWIER;
	u32  PR;
}EXTI_t;
typedef struct
{

	u32  MEMRMP     ;
	u32  PMC        ;
	u32  EXTICR[4]  ;
	u32  Reserved0  ;
	u32  Reserved1  ;
	u32  CMPCR      ;
}EXTICR_t;

typedef enum
{
	EXTICR_1 =1 ,
	EXTICR_2    ,
	EXTICR_3    ,
	EXTICR_4
}EXTIREG_t;


#define EXTI    ((volatile EXTI_t*)EXTI_BASE_ADDRESS)

#define EXTI_CR    ((volatile EXTICR_t*)EXTICR_BASE_ADDRESS)

#define EXTI_CR_MASK    0b1111

#define MAX_INTERRUPT     16


#endif

