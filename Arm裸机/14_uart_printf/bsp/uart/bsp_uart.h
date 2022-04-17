#ifndef __BSP_URAT_H__
#define __BSP_URAT_H__

#include "imx6u.h"
void uart_init();
void uart_disenable(UART_Type *uart);
void uart_enable(UART_Type *uart);
void uart_reset(UART_Type *uart);
void uart_io_init();
void putc(uint8_t data);
uint8_t getc();
void puts(uint8_t *data);
void uart_setbaudrate(UART_Type *base, unsigned int baudrate, unsigned int srcclock_hz);

#endif // !__BSP_URAT_H__