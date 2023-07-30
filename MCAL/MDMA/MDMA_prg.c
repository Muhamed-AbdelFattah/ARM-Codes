#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MDMA_cfg.h"
#include "MDMA_int.h"
#include "MDMA_prv.h"

static void (*DMA2_S0_PTR)(void)=NULL;

void DMA2_voidInit(void){

DMA2->S[0].CR &=~(1<<0);
DMA2->S[0].CR =(1<<9)|(1<<10)|(1<<7)|(1<<4) ;
DMA2->S[0].FCR=(1<<2)|(1<<1)|(1<<0);
}
void DMA2_voidSetStreamConfig(u8 Copy_u8StreamID,
                              u8 Copy_u8ChannelID,
                              u32 *Copy_pu32SourceAddress,
                              u32 *Copy_pu32Destination,
                              u8  Copy_pu8ElementSize,
                              u16 Copy_u16BlockSize)
  {
    DMA2->S[Copy_u8StreamID].CR &=~(1<<0);
    DMA2->S[Copy_u8StreamID].CR |=(Copy_u8ChannelID<<25);
    DMA2->S[Copy_u8StreamID].CR|=((Copy_pu8ElementSize<<13)|(Copy_pu8ElementSize<<11));
    DMA2->S[Copy_u8StreamID].NDTR =Copy_u16BlockSize;
    DMA2->S[Copy_u8StreamID].M0AR=Copy_pu32SourceAddress;
    DMA2->S[Copy_u8StreamID].M1AR=Copy_pu32Destination;



  }

void DMA2_SetCallBack(void (*ptr)(void)){
    if(ptr !=NULL)
    {
        DMA2_S0_PTR=ptr;
    }
}
void DMA2_voidStreamEnable(u8 Copy_StreamID){
	DMA2->DMA_LIFCR=(1<<0)|(1<<2)|(1<<3)|(1<<4)|(1<<5);
	SET_BIT(DMA2->S[Copy_StreamID].CR ,0);
}


void DMA2_Stream0_IRQHandler(void)
{
    if(DMA2_S0_PTR !=NULL)
    {
        DMA2_S0_PTR();
    }
}
