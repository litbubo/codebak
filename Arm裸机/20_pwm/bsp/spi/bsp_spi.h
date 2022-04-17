#ifndef __BSP_SPI__H__
#define __BSP_SPI__H__

#include "imx6u.h"
void spi_init(ECSPI_Type *base);
uint8_t spich0_readwrite_byte(ECSPI_Type *base, uint8_t txdata);

#endif // !__BSP_SPI__H__
