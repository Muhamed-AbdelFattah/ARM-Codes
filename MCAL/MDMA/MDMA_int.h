#ifndef _DMA_INT_H_
#define _DMA_INT_H_


void DMA2_voidInit(void);
void DMA2_voidSetStreamConfig(u8 Copy_u8StreamID,
                              u8 Copy_u8ChannelID,
                              u32 *Copy_pu32SourceAddress,
                              u32 *Copy_pu32Destination,
                              u8  Copy_pu8ElementSize,
                              u16 Copy_u16BlockSize);

void DMA2_SetCallBack(void (*ptr)(void));


void DMA2_voidStreamEnable(u8 Copy_StreamID);







#endif
