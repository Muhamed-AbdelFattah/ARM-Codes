#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MSTK_int.h"
#include "MNVIC_int.h"
#include "MEXTI_int.h"
#include "S2P_int.h"
#include "HLEDMATRIX_int.h"
#include "SPI_int.h"
//#include "TFT_int.h"
#include "Photo.h"

u8 data;
u8 pin_value=0;

void main(void)
{


	MRCC_init();
	MSTK_voidInit();
	MRCC_Enable_peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_Enable_peripheral(RCC_APB2,RCC_APB2_SPI1);
	SPI_voidInit();
	//SPI_voidMasterEnable();
	SPI_voidSlaveEnable();

	/*Data and Cmd and Reset pins */
	MGPIO_voidSetPinMode(PORT_A,PIN_0,OUTPUT_MODE);
	MGPIO_voidSetPinMode(PORT_A,PIN_1,INPUT_MODE);
	MGPIO_voidSetPinOutConfig(PORT_A,PIN_0,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
	MGPIO_voidSetInputConfig(PORT_A,PIN_1,INPUT_PULLDOWN);

	/*AltFunc Pins */

	MGPIO_voidSetPinMode(PORT_A,PIN_5,ALT_FUNC_MODE);
	MGPIO_voidSetPinMode(PORT_A,PIN_7,ALT_FUNC_MODE);
	MGPIO_voidSetPinMode(PORT_A,PIN_6,ALT_FUNC_MODE);

	MGPIO_voidSetAltConfig(PORT_A,PIN_6,AF5);
	MGPIO_voidSetAltConfig(PORT_A,PIN_5,AF5);
	MGPIO_voidSetAltConfig(PORT_A,PIN_7,AF5);

	data=SPI_u8Transceive('A');
	if(data == 'A')
	{
		MGPIO_voidSetPinValue(PORT_A,PIN_0,PIN_HIGH);
		MSTK_voidDelayUs(1000);
	}
	while (1)
	{
		/*

		MGPIO_voidGetPinValue(PORT_A,PIN_1,&pin_value);
		if(pin_value!=0)
		{
			(void)SPI_u8Transceive('A');
		}
	*/
	}
}

