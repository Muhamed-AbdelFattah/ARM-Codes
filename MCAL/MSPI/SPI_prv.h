#ifndef _SPI_PRV_H_
#define _SPI_PRV_H_


#define SPI_1_BASE_ADDRESS   (0x40013000)
#define SPI_2_BASE_ADDRESS   (0x40013400)


typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;


}SPI_REG_t;

#define  SPI_1      ((volatile SPI_REG_t*)SPI_1_BASE_ADDRESS)


#endif
