#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SPI_cfg.h"
#include "SPI_int.h"
#include "SPI_prv.h"


void SPI_voidInit(void){

	/* 1- SPI Mode: CPHA and CPOL */
	SET_BIT(SPI_1->CR1, 0);
	SET_BIT(SPI_1->CR1, 1);
	/* 2- Select Master/Slave Mode  */
	SET_BIT(SPI_1->CR1, 2);

	/* 3- Select Baud Rate Prescaler */
	CLR_BIT(SPI_1->CR1, 3);
	CLR_BIT(SPI_1->CR1, 4);
	SET_BIT(SPI_1->CR1, 5);


	/* 4- MSB/LSB first */
	CLR_BIT(SPI_1->CR1, 7);


	/* 6- sELECT Software slave managment */
	SET_BIT(SPI_1->CR1, 9); //SSM
	SET_BIT(SPI_1->CR1, 8); //SSI

	/* 7- Data Format */
	CLR_BIT(SPI_1->CR1, 11); //DFF

	/*Disable interrrupt  Tx*/
	CLR_BIT(SPI_1->CR2,7);
	/*Disable interrupt Rx*/
	CLR_BIT(SPI_1->CR2,6);
	/*Frame Format Error*/
	CLR_BIT(SPI_1->SR,8);


}
void SPI_voidMasterEnable(void)
{
	/* 1- Select Master */
	SET_BIT(SPI_1->CR1, 2);
	/* 2- ENABLE SPI PERIPHERAL */
	SET_BIT(SPI_1->CR1, 6);
}
void SPI_voidSlaveEnable(void){
	/* 1-Slave Mode  */
	CLR_BIT(SPI_1->CR1,2);

	/* 2- ENABLE SPI PERIPHERAL */

	SET_BIT(SPI_1->CR1,6);
}
u8   SPI_u8Transceive(u8 Copy_u8Data){
	SPI_1->DR=Copy_u8Data;
	while(GET_BIT(SPI_1->SR,7)== 1	);
	return(SPI_1->DR);
}
