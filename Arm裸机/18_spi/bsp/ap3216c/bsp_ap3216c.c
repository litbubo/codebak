#include "bsp_ap3216c.h"
#include "bsp_i2c.h"
#include "bsp_gpio.h"
#include "bsp_uart.h"
#include "bsp_delay.h"
#include "stdio.h"

void ap3216_init()
{
    IOMUXC_SetPinMux(IOMUXC_UART4_TX_DATA_I2C1_SCL, 1);/* 复用为GPIO5_IO1 */
    IOMUXC_SetPinMux(IOMUXC_UART4_RX_DATA_I2C1_SDA, 1);/* 复用为GPIO5_IO1 */
	/* 
	 *bit 16:0 HYS关闭
	 *bit [15:14]: 1 默认47K上拉
	 *bit [13]: 1 pull功能
	 *bit [12]: 1 pull/keeper使能 
	 *bit [11]: 0 关闭开路输出
	 *bit [7:6]: 10 速度100Mhz
	 *bit [5:3]: 110 驱动能力为R0/6
	 *bit [0]: 1 高转换率
	 */
    IOMUXC_SetPinConfig(IOMUXC_UART4_TX_DATA_I2C1_SCL, 0x70b0);
    IOMUXC_SetPinConfig(IOMUXC_UART4_RX_DATA_I2C1_SDA, 0x70b0);

	i2c_init(I2C1);

	ap3216c_writebyte(AP3216C_ADDR, AP3216C_SYSTEMCONG, 0x4);
	delay_ms(100);
	ap3216c_writebyte(AP3216C_ADDR, AP3216C_SYSTEMCONG, 0x3);
	printf("AP3216C_SYSTEMCONG 的值为：%d", 
			ap3216c_readbyte(AP3216C_ADDR, AP3216C_SYSTEMCONG));
}

uint8_t ap3216c_readbyte(uint8_t addr, uint8_t reg)
{
	uint8_t val = 0;
	struct i2c_transfer masterXfer;
	masterXfer.slaveAddress = addr;
	masterXfer.direction = kI2C_Read;
	masterXfer.subaddress = reg;
	masterXfer.subaddressSize = 1;
	masterXfer.data = &val;
	masterXfer.dataSize = 1;
	i2c_master_transfer(I2C1, &masterXfer);
	return val;
}

uint8_t ap3216c_writebyte(uint8_t addr, uint8_t reg, uint8_t data)
{
	struct i2c_transfer masterXfer;
	masterXfer.slaveAddress = addr;
	masterXfer.direction = kI2C_Write;
	masterXfer.subaddress = reg;
	masterXfer.subaddressSize = 1;
	masterXfer.data = &data;
	masterXfer.dataSize = 1;
	return i2c_master_transfer(I2C1, &masterXfer);
}

void ap3216c_readdata(uint16_t *ir, uint16_t *ps, uint16_t *als)
{
	uint8_t buf[6];
	uint8_t i = 0;

	for (i = 0; i < 6; i++)
	{
		buf[i] = ap3216c_readbyte(AP3216C_ADDR, AP3216C_IRDATALOW + i);
	}
	if( (buf[0] & 0x80) == 1)
	{
		*ir = 0;
		*ps = 0;
	}
	else
	{
		*ir = ((uint16_t)buf[1] << 2) | (buf[0] & 0x03);
		*ps = (((uint16_t)buf[5] & 0x3f) << 4) | (buf[4] & 0x0f);
	}
	
	*als = ((uint16_t)buf[3] << 8) | buf[2];
}