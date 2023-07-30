#ifndef _DMA_PRV_H_
#define _DMA_PRV_H_


#define DMA_1_BASE_ADDRESS   (0x40026000)
#define DMA_2_BASE_ADDRESS   (0x40026400)

typedef struct 
{
    u32 CR;
    u32 NDTR;
    u32 PAR;
    u32 M0AR;
    u32 M1AR;
    u32 FCR;
}DMA_Stream_t;



typedef struct 
{
    u32 DMA_LISR;
    u32 DMA_HISER;
    u32 DMA_LIFCR;
    u32 DMA_HIFCR;
    DMA_Stream_t S[8];
        

}DMA_REG_t;


#define DMA1    ((volatile DMA_REG_t*)DMA_1_BASE_ADDRESS)
#define DMA2    ((volatile DMA_REG_t*)DMA_2_BASE_ADDRESS)







#endif
