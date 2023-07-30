#ifndef MRCC_INT_H
#define MRCC_INT_H

/*
define 4 BUS
*/

#define RCC_APB1  	  0
#define RCC_APB2  	  1
#define RCC_AHB1  	  2
#define RCC_AHB2      3
#define RCC_AHB1LPENR 4

/*
another definition for BUS
typedef enum
{
 RCC_APB1 = 0,
 RCC_APB2  ,
 RCC_AHB1  ,
 RCC_AHB2  
}MRCC_BUS_T;
*/

/*
define peripherals bits
*/

/*****************************AHB1*******************************/
#define RCC_AHB1_GPIOA   0
#define RCC_AHB1_GPIOB   1
#define RCC_AHB1_GPIOC   2
#define RCC_AHB1_GPIOD   3
#define RCC_AHB1_GPIOE   4
#define RCC_AHB1_GPIOH   7
#define RCC_AHB1_CRC     12
#define RCC_AHB1_DMA1    21
#define RCC_AHB1_DMA2    22

/*****************************AHB2*******************************/
#define RCC_AHB2_OTGFS   7

/*****************************APB1*******************************/
#define RCC_APB1_TIM2     0
#define RCC_APB1_TIM3     1
#define RCC_APB1_TIM4     2
#define RCC_APB1_TIM5     3
#define RCC_APB1_WWDG     11
#define RCC_APB1_SPI2     14
#define RCC_APB1_SPI3     15
#define RCC_APB1_USART2   17
#define RCC_APB1_I2C1     21
#define RCC_APB1_I2C2     22
#define RCC_APB1_I2C3     23
#define RCC_APB1_PWR      28

/*****************************APB2*******************************/
#define RCC_APB2_TIM1     0
#define RCC_APB2_USART1   4
#define RCC_APB2_USART6   5
#define RCC_APB2_ADC1     8
#define RCC_APB2_SDIO     11
#define RCC_APB2_SPI1     12
#define RCC_APB2_SPI4     13
#define RCC_APB2_SYSCFG   14
#define RCC_APB2_TIM9     16
#define RCC_APB2_TIM10    17
#define RCC_APB2_TIM11    18
/***************************** AHB1LPENR ***************************/
#define RCC_AHB1LPENR_FMI       15

void MRCC_init(void);

void MRCC_Enable_peripheral(u32 Copy_u32Adress_Bus, u32 Copy_u32peripheral );

void MRCC_Disable_peripheral(u32 Copy_u32Adress_Bus, u32 Copy_u32peripheral );






#endif
