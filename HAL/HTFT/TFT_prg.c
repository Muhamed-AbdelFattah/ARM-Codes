#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MGPIO_int.h"
#include "MSTK_int.h"
#include "SPI_int.h"


#include "TFT_int.h"
#include "TFT_cfg.h"
#include "TFT_prv.h"





void TFT_voidInit(void){
	MSTK_voidInit();
	SPI_voidInit();
	SPI_voidMasterEnable();

	TFT_voidReset();
	TFT_voidSendCmd(0x11);
	MSTK_voidDelayMs(10);
	TFT_voidSendData(0x05);
	TFT_voidSendCmd(0x29);

}
void TFT_voidDisplay(u16 *Copy_u16Data){
	u16 Local_u16Counter=0;
	//u8 Local_u8Data=0;
	/*Set x */
	TFT_voidSendCmd(0x2A);
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	TFT_voidSendData(127);
	/*Set y*/
	TFT_voidSendCmd(0x2B);
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	TFT_voidSendData(159);

	/*Write RAM CMD*/
	TFT_voidSendCmd(0x2C);
	for(Local_u16Counter=0;Local_u16Counter<20480;Local_u16Counter++)
	{
		//Local_u8Data=(u8)(Copy_u16Data[Local_u16Counter]>>8);

		//Local_u8Data=(u8)Copy_u16Data[Local_u16Counter];
		TFT_voidSendData((u8)Copy_u16Data[Local_u16Counter]>>8);
		TFT_voidSendData((u8)Copy_u16Data[Local_u16Counter]);

	}
}


static void TFT_voidReset(void)
{
	MGPIO_voidSetPinValue(PORT_A,RESET_PIN,PIN_HIGH);
	MSTK_voidDelayUs(100);
	MGPIO_voidSetPinValue(PORT_A,RESET_PIN,PIN_LOW);
	MSTK_voidDelayUs(1);
	MGPIO_voidSetPinValue(PORT_A,RESET_PIN,PIN_HIGH);
	MSTK_voidDelayUs(100);
	MGPIO_voidSetPinValue(PORT_A,RESET_PIN,PIN_LOW);
	MSTK_voidDelayUs(100);
	MGPIO_voidSetPinValue(PORT_A,RESET_PIN,PIN_HIGH);
	MSTK_voidDelayMs(120);
}
static void TFT_voidSendCmd(u8 Copy_u8Cmd)
{
	MGPIO_voidSetPinValue(PORT_A,CONTROL_PIN,PIN_LOW);
	SPI_u8Transceive(Copy_u8Cmd);
}
static void TFT_voidSendData(u8 Copy_u8Data)
{
	MGPIO_voidSetPinValue(PORT_A,CONTROL_PIN,PIN_HIGH);
	SPI_u8Transceive(Copy_u8Data);
}

