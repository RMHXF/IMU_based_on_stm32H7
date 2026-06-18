#include "JF_protocol.h"
#include "pid.h"
void Tail_Init(justfloat_t *jf)
{
    jf->tail.tail[0] = 0x00;
    jf->tail.tail[1] = 0x00;
    jf->tail.tail[2] = 0x80;
    jf->tail.tail[3] = 0x7F;
}

void jf_transmit_buffer(float channel,uint8_t *byte_packet)
{
    union{
        float f;
        uint32_t u;
    }converter;
    converter.f = channel;
    uint32_t temp = converter.u;
    byte_packet[0] = (uint8_t)temp;
    byte_packet[1] = (uint8_t)(temp >> 8);
    byte_packet[2] = (uint8_t)(temp >> 16);
    byte_packet[3] = (uint8_t)(temp >> 24);
}

void Jf_transmit(justfloat_t *jf,float channel_1,float channel_2,float channel_3,float channel_4)
{
    Tail_Init(jf);
    jf_transmit_buffer(channel_1,jf->channel[0]);
    jf_transmit_buffer(channel_2,jf->channel[1]);
    jf_transmit_buffer(channel_3,jf->channel[2]);
    jf_transmit_buffer(channel_4,jf->channel[3]);
    HAL_UART_Transmit_DMA(&huart1,(uint8_t*)jf,sizeof(justfloat_t));
}