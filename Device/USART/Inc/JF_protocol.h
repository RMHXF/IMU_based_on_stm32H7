#ifndef JF_PROTOCOL_H
#define JF_PROTOCOL_H

#include "usart.h"
#include "stdint.h"

typedef struct{
    uint8_t  tail[4];
}   FRAME_TAIL_t;

//四通道协议
typedef struct{
    uint8_t  channel[4][4];
    FRAME_TAIL_t  tail;
}   justfloat_t;

void Tail_Init(justfloat_t *jf);
void jf_transmit_buffer(float channel,uint8_t *byte_packet);
void Jf_transmit(justfloat_t *jf,float channel_1,float channel_2,float channel_3,float channel_4);
#endif