#ifndef __UART_H__
#define __UART_H__

#include "stm32f10x.h"                  // Device header

extern uint8_t rev[17];
extern char *ack_open;
extern char *ack_close;
extern char *ack_wifi;

void UART2_IO_Init(void);
void UART2_Init(uint32_t bound);



#endif

