#include "bsp_spi.h"

void spi_init(ECSPI_Type *base)
{
    base->CONREG = 0;
    base->CONREG |= (1 << 0) | (1 << 3) | (1 << 4) | (7 << 20);

    base->CONFIGREG = 0;

    base->PERIODREG = 0x2000;

    // SPI 时钟 6Mhz
    base->CONREG &= ~( (0xf << 12) | (0xf << 8) );
    base->CONREG |= (9 << 12);
}

// SPI 发送/接收
uint8_t spich0_readwrite_byte(ECSPI_Type *base, uint8_t txdata)
{
    uint32_t spirxdata = 0;
    uint32_t spitxdata = txdata;

    // 选择通道 0
    base->CONREG &= ~(3 << 18);
    base->CONREG |= (0 << 18);

    // 数据发送
    while ((base->STATREG & 1) == 0);
    base->TXDATA = spitxdata;

    while((base->STATREG & (1 << 3)) == 0);
    spirxdata = base->RXDATA;

    return spirxdata;
}
