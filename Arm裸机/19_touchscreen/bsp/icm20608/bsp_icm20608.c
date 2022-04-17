#include "bsp_icm20608.h"
#include "bsp_spi.h"
#include "stdio.h"
#include "bsp_delay.h"

struct icm20608_dev_struc icm20608_dev;

uint8_t icm20608_init()
{
    uint8_t ret = 0;
    gpio_pin_config_t cs_config;
    // SPI 引脚初始化
    IOMUXC_SetPinMux(IOMUXC_UART2_CTS_B_ECSPI3_MOSI, 0);
    IOMUXC_SetPinMux(IOMUXC_UART2_RTS_B_ECSPI3_MISO, 0);
    IOMUXC_SetPinMux(IOMUXC_UART2_RX_DATA_ECSPI3_SCLK, 0);
	
    IOMUXC_SetPinConfig(IOMUXC_UART2_CTS_B_ECSPI3_MOSI, 0x10b0);
    IOMUXC_SetPinConfig(IOMUXC_UART2_RTS_B_ECSPI3_MISO, 0x10b0);
    IOMUXC_SetPinConfig(IOMUXC_UART2_RX_DATA_ECSPI3_SCLK, 0x10b0);
    // 片选引脚初始化
    IOMUXC_SetPinMux(IOMUXC_UART2_TX_DATA_GPIO1_IO20, 0);
    IOMUXC_SetPinConfig(IOMUXC_UART2_TX_DATA_GPIO1_IO20, 0x10b0);

    
    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0); /* 复用为GPIO */
    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0xf080);

    /* GPIO初始化 */
    cs_config.direction = kGPIO_DigitalOutput;
    cs_config.output_Logic = 0;
    gpio_init(GPIO1, 20, &cs_config);

    // SPI控制器的初始化
    spi_init(ECSPI3);

    icm20608_write_reg(ICM20_PWR_MGMT_1, 0x80);		/* 复位，复位后为0x40,睡眠模式 			*/
	delay_ms(50);
	icm20608_write_reg(ICM20_PWR_MGMT_1, 0x01);		/* 关闭睡眠，自动选择时钟 				*/
	delay_ms(50);

    // ICM20608 初始化 
    ret = icm20608_read_reg(ICM20_WHO_AM_I);
    if((ret != ICM20608D_ID) && (ret != ICM20608G_ID))
        return 1;
    icm20608_write_reg(ICM20_SMPLRT_DIV, 0x00); 	/* 输出速率是内部采样率				 */
	icm20608_write_reg(ICM20_GYRO_CONFIG, 0x18); 	/* 陀螺仪±2000dps量程 				*/
	icm20608_write_reg(ICM20_ACCEL_CONFIG, 0x18); 	/* 加速度计±16G量程 				*/
	icm20608_write_reg(ICM20_CONFIG, 0x04); 		/* 陀螺仪低通滤波BW=20Hz 			*/
	icm20608_write_reg(ICM20_ACCEL_CONFIG2, 0x04); 	/* 加速度计低通滤波BW=21.2Hz 		*/
	icm20608_write_reg(ICM20_PWR_MGMT_2, 0x00); 	/* 打开加速度计和陀螺仪所有轴 		 */
	icm20608_write_reg(ICM20_LP_MODE_CFG, 0x00); 	/* 关闭低功耗 						*/
	icm20608_write_reg(ICM20_FIFO_EN, 0x00);		/* 关闭FIFO			                */
    
    ret = icm20608_read_reg(ICM20_GYRO_CONFIG);
    printf("ICM20_GYRO_CONFIG = %#X\r\n", ret);			     
    return 0;
}

// 从 ICM20608 SPI 读数据
uint8_t icm20608_read_reg(uint8_t reg)
{
    uint8_t ret = 0;
    reg |= 0x80;
    ICM20608_CSN(0);
    spich0_readwrite_byte(ECSPI3, reg);
    ret = spich0_readwrite_byte(ECSPI3, 0xff);
    ICM20608_CSN(1);
    return ret;
}

// 从 ICM20608 SPI 写数据
void icm20608_write_reg(uint8_t reg, uint8_t val)
{
    reg &= ~0x80;
    ICM20608_CSN(0);
    spich0_readwrite_byte(ECSPI3, reg);
    spich0_readwrite_byte(ECSPI3, val);
    ICM20608_CSN(1);
}

/*
 * @description	: 读取ICM20608连续多个寄存器
 * @param - reg	: 要读取的寄存器地址
 * @return 		: 读取到的寄存器值
 */
void icm20608_read_len(uint8_t reg, uint8_t *buf, uint8_t len)
{  
	uint8_t i;
	
	/* ICM20608在使用SPI接口的时候寄存器地址，只有低7位有效,
	 * 寄存器地址最高位是读/写标志位读的时候要为1，写的时候要为0。
	 */
	reg |= 0x80; 
		
   	ICM20608_CSN(0);               				/* 使能SPI传输	 		*/
  	spich0_readwrite_byte(ECSPI3, reg);			/* 发送寄存器地址  		*/   	   
 	for(i = 0; i < len; i++)					/* 顺序读取寄存器的值 			*/
 	{
		buf[i] = spich0_readwrite_byte(ECSPI3, 0XFF);	
	}
 	ICM20608_CSN(1);                			/* 禁止SPI传输 			*/
}

/*
 * @description : 获取陀螺仪的分辨率
 * @param		: 无
 * @return		: 获取到的分辨率
 */
float icm20608_gyro_scaleget()
{
	uint8_t data;
	float gyroscale;
	
	data = (icm20608_read_reg(ICM20_GYRO_CONFIG) >> 3) & 0X3;
	switch(data) {
		case 0: 
			gyroscale = 131;
			break;
		case 1:
			gyroscale = 65.5;
			break;
		case 2:
			gyroscale = 32.8;
			break;
		case 3:
			gyroscale = 16.4;
			break;
	}
	return gyroscale;
}

/*
 * @description : 获取加速度计的分辨率
 * @param		: 无
 * @return		: 获取到的分辨率
 */
uint16_t icm20608_accel_scaleget()
{
	uint8_t data;
	uint16_t accelscale;
	
	data = (icm20608_read_reg(ICM20_ACCEL_CONFIG) >> 3) & 0X3;
	switch(data) {
		case 0: 
			accelscale = 16384;
			break;
		case 1:
			accelscale = 8192;
			break;
		case 2:
			accelscale = 4096;
			break;
		case 3:
			accelscale = 2048;
			break;
	}
	return accelscale;
}


/*
 * @description : 读取ICM20608的加速度、陀螺仪和温度原始值
 * @param 		: 无
 * @return		: 无
 */
void icm20608_getdata()
{
	float gyroscale;
	uint16_t accescale;
	uint8_t data[14];
	
	icm20608_read_len(ICM20_ACCEL_XOUT_H, data, 14);
	
	gyroscale = icm20608_gyro_scaleget();
	accescale = icm20608_accel_scaleget();

	icm20608_dev.accel_x_adc = (signed short)((data[0] << 8) | data[1]); 
	icm20608_dev.accel_y_adc = (signed short)((data[2] << 8) | data[3]); 
	icm20608_dev.accel_z_adc = (signed short)((data[4] << 8) | data[5]); 
	icm20608_dev.temp_adc    = (signed short)((data[6] << 8) | data[7]); 
	icm20608_dev.gyro_x_adc  = (signed short)((data[8] << 8) | data[9]); 
	icm20608_dev.gyro_y_adc  = (signed short)((data[10] << 8) | data[11]);
	icm20608_dev.gyro_z_adc  = (signed short)((data[12] << 8) | data[13]);

	/* 计算实际值 */
	icm20608_dev.gyro_x_act = ((float)(icm20608_dev.gyro_x_adc)  / gyroscale) * 100;
	icm20608_dev.gyro_y_act = ((float)(icm20608_dev.gyro_y_adc)  / gyroscale) * 100;
	icm20608_dev.gyro_z_act = ((float)(icm20608_dev.gyro_z_adc)  / gyroscale) * 100;

	icm20608_dev.accel_x_act = ((float)(icm20608_dev.accel_x_adc) / accescale) * 100;
	icm20608_dev.accel_y_act = ((float)(icm20608_dev.accel_y_adc) / accescale) * 100;
	icm20608_dev.accel_z_act = ((float)(icm20608_dev.accel_z_adc) / accescale) * 100;

	icm20608_dev.temp_act = (((float)(icm20608_dev.temp_adc) - 25 ) / 326.8 + 25) * 100;
}