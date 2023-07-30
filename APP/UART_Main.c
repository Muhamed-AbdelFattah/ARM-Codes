#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MSTK_int.h"
#include "MNVIC_int.h"
#include "MEXTI_int.h"
//#include "S2P_int.h"
#include "HLEDMATRIX_int.h"
//#include "SPI_int.h"
#include "TFT_int.h"
#include "Photo.h"
#include "UART_int.h"

#define APP 2

#if APP == 1
void main(void)
{

	MRCC_init();
	MRCC_Enable_peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_Enable_peripheral(RCC_AHB1,RCC_AHB1_GPIOB);
	MRCC_Enable_peripheral(RCC_APB2,RCC_APB2_USART1);

	/*Data and Cmd and Reset pins */
	MGPIO_voidSetPinMode(PORT_A,PIN_0,OUTPUT_MODE);
	MGPIO_voidSetPinMode(PORT_A,PIN_1,OUTPUT_MODE);
	MGPIO_voidSetPinOutConfig(PORT_A,PIN_0,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinOutConfig(PORT_A,PIN_1,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);

	/*AltFunc Pins */

	MGPIO_voidSetPinMode(PORT_B,PIN_6,ALT_FUNC_MODE);
	MGPIO_voidSetPinMode(PORT_B,PIN_7,ALT_FUNC_MODE);

	MGPIO_voidSetAltConfig(PORT_B,PIN_6,AF7);
	MGPIO_voidSetAltConfig(PORT_B,PIN_7,AF7);
	UART_voidInit();
	UART_voidEnable();


	while (1)
	{
		UART_voidSendData('M');
	}
}
#elif APP == 2
void main(void)
{

	MRCC_init();
	MRCC_Enable_peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_Enable_peripheral(RCC_AHB1,RCC_AHB1_GPIOB);
	MRCC_Enable_peripheral(RCC_APB2,RCC_APB2_USART1);

	/*Data and Cmd and Reset pins */
	MGPIO_voidSetPinMode(PORT_A,PIN_0,OUTPUT_MODE);
	MGPIO_voidSetPinMode(PORT_A,PIN_1,OUTPUT_MODE);
	MGPIO_voidSetPinOutConfig(PORT_A,PIN_0,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinOutConfig(PORT_A,PIN_1,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);

	/*AltFunc Pins */

	MGPIO_voidSetPinMode(PORT_B,PIN_6,ALT_FUNC_MODE);
	MGPIO_voidSetPinMode(PORT_B,PIN_7,ALT_FUNC_MODE);
	MGPIO_voidSetAltConfig(PORT_B,PIN_6,AF7);
	MGPIO_voidSetAltConfig(PORT_B,PIN_7,AF7);
	MGPIO_voidSetPinValue(PORT_A,PIN_1,PIN_HIGH);
	UART_voidInit();
	UART_voidEnable();

	u8 Local_u8Data=0;

	while (1)
	{
		Local_u8Data=UART_u8RecieveData();
			if(Local_u8Data == 'M')
			{
				MGPIO_voidSetPinValue(PORT_A,PIN_0,PIN_HIGH);
			}
	}
}
#endif
