#include "bsp_ft5426.h"
#include "bsp_gpio.h"
#include "bsp_int.h"
#include "bsp_delay.h"
#include "bsp_i2c.h"
#include "stdio.h"
struct ft5426_dev_struc ft5426_dev;
void ft5426_init()
{
    uint8_t val[2] = {0x1, 0x1};
    // IO 初始化
    IOMUXC_SetPinMux(IOMUXC_UART5_TX_DATA_I2C2_SCL, 1);
    IOMUXC_SetPinMux(IOMUXC_UART5_RX_DATA_I2C2_SDA, 1);
    IOMUXC_SetPinConfig(IOMUXC_UART5_TX_DATA_I2C2_SCL, 0x70b0);
    IOMUXC_SetPinConfig(IOMUXC_UART5_RX_DATA_I2C2_SDA, 0x70b0);
    // 初始化 INT 引脚， 使能中断
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO09_GPIO1_IO09, 0); /* 复用为GPIO */
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO09_GPIO1_IO09, 0xf080);

    gpio_pin_config_t ctint_config;
    ctint_config.direction = kGPIO_DigitalInput;
    ctint_config.interrupt_Mode = kGPIO_IntRisingOrFallingEdge;
    gpio_init(GPIO1, 9, &ctint_config);

    GIC_EnableIRQ(GPIO1_Combined_0_15_IRQn);
    system_register_irqhandler(GPIO1_Combined_0_15_IRQn, (system_irq_handler_t)gpio1_io09_irqhandler, NULL);
    gpio_enableInt(GPIO1, 9);

    // 复位 IO 初始化
    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER9_GPIO5_IO09, 0);
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER9_GPIO5_IO09, 0x10b0);
    gpio_pin_config_t ctrst_config;
    ctrst_config.direction = kGPIO_DigitalOutput;
    ctrst_config.output_Logic = 1;
    gpio_init(GPIO5, 9, &ctrst_config);

    gpio_pinwrite(GPIO5, 9, 0);
    delay_ms(50);
    gpio_pinwrite(GPIO5, 9, 1);
    delay_ms(50);

    i2c_init(I2C2);

    // ft5426初始化
    ft5426_read_len(FT5426_ADDR, FT5426_IDGLIB_VERSION, 2, val);

    printf(" Touch Frimware Version:%#X\r\n", (((uint16_t)val[0] << 8) | val[1]));
    /*
    ft5426_writebyte(FT5426_ADDR, 0x80, 0x55);
    char ret = ft5426_readbyte(FT5426_ADDR, 0x80);
    printf(" test:%#X\r\n", ret);
    */
    ft5426_writebyte(FT5426_ADDR, FT5426_DEVICE_MODE, 0);  // 正常运行
    ft5426_writebyte(FT5426_ADDR, FT5426_IDG_MODE, 1);     // 中断模式

    ft5426_dev.initfalg = FT5426_INIT_FINISHED;
}

/* 中断处理函数 */
void gpio1_io09_irqhandler(uint32_t gicciar, void *param)
{
    if (ft5426_dev.initfalg == FT5426_INIT_FINISHED)
    {
        ft5426_read_tpcoord();
    }
    /* 清除中断标志 */
    gpio_clearintflags(GPIO1, 18);
}

uint8_t ft5426_writebyte(uint8_t addr, uint8_t reg, uint8_t data)
{
	struct i2c_transfer masterXfer;
	masterXfer.slaveAddress = addr;
	masterXfer.direction = kI2C_Write;
	masterXfer.subaddress = reg;
	masterXfer.subaddressSize = 1;
	masterXfer.data = &data;
	masterXfer.dataSize = 1;
	return i2c_master_transfer(I2C2, &masterXfer);
}

uint8_t ft5426_readbyte(uint8_t addr, uint8_t reg)
{
	uint8_t val = 0;
	struct i2c_transfer masterXfer;
	masterXfer.slaveAddress = addr;
	masterXfer.direction = kI2C_Read;
	masterXfer.subaddress = reg;
	masterXfer.subaddressSize = 1;
	masterXfer.data = &val;
	masterXfer.dataSize = 1;
	i2c_master_transfer(I2C2, &masterXfer);
	return val;
}
 
void ft5426_read_len(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *buf)
{
	struct i2c_transfer masterXfer;
	masterXfer.slaveAddress = addr;
	masterXfer.direction = kI2C_Read;
	masterXfer.subaddress = reg;
	masterXfer.subaddressSize = 1;
	masterXfer.data = buf;
	masterXfer.dataSize = len;
	i2c_master_transfer(I2C2, &masterXfer);
}

void ft5426_read_tpcoord()
{
    uint8_t i;
    uint8_t point_buf[FT5426_XYCOORDREG_NUM];
    ft5426_dev.point_num = ft5426_readbyte(FT5426_ADDR, FT5426_TD_STATUS);
    //printf("touch num = %d\r\n", ft5426_dev.point_num);
    ft5426_read_len(FT5426_ADDR, FT5426_TOUCH1_XH, FT5426_XYCOORDREG_NUM, point_buf);
    for (i = 0; i < ft5426_dev.point_num; i++)
    {
        uint8_t *buf = &point_buf[i * 6];
        ft5426_dev.y[i] = ((buf[0] << 8) | buf[1]) & 0xfff;
        ft5426_dev.x[i] = ((buf[2] << 8) | buf[3]) & 0xfff;
        //uint8_t type = buf[0] >> 6;
    }
}