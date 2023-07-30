#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
//#include "MSTK_int.h"
#include "MNVIC_int.h"
#include "MEXTI_int.h"
//#include "S2P_int.h"
#include "HLEDMATRIX_int.h"
//#include "SPI_int.h"
#include "TFT_int.h"
#include "Photo.h"



void main(void)
{

	MRCC_init();
	MRCC_Enable_peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_Enable_peripheral(RCC_APB2,RCC_APB2_SPI1);

	/*Data and Cmd and Reset pins */
	MGPIO_voidSetPinMode(PORT_A,PIN_0,OUTPUT_MODE);
	MGPIO_voidSetPinMode(PORT_A,PIN_1,OUTPUT_MODE);
	MGPIO_voidSetPinOutConfig(PORT_A,PIN_0,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetPinOutConfig(PORT_A,PIN_1,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);

	/*AltFunc Pins */

	MGPIO_voidSetPinMode(PORT_A,PIN_5,ALT_FUNC_MODE);
	MGPIO_voidSetPinMode(PORT_A,PIN_7,ALT_FUNC_MODE);

	MGPIO_voidSetAltConfig(PORT_A,PIN_5,AF5);
	MGPIO_voidSetAltConfig(PORT_A,PIN_7,AF5);
	TFT_voidInit();

	TFT_voidDisplay(test_img);


	while (1)
	{

	}
}

