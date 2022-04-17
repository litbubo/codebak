#include "bsp_lcd.h"
#include "bsp_gpio.h"
#include "bsp_uart.h"
#include "bsp_delay.h"
#include "stdio.h"

tftlcd_type tftlcd_dev;

void lcd_init()
{
    uint16_t id = lcd_readid();
    printf("屏幕的ID为：%#X\r\n", id);
    lcd_gpioinit();
    lcd_reset();
    delay_ms(10);
    lcd_noreset();

    switch (id)
    {
    case ATK4342:
        tftlcd_dev.height = 272;
        tftlcd_dev.width = 480;
        tftlcd_dev.vspw = 1;
        tftlcd_dev.vbpd = 8;
        tftlcd_dev.vfpd = 8;
        tftlcd_dev.hspw = 1;
        tftlcd_dev.hbpd = 40;
        tftlcd_dev.hfpd = 5;
        lcdclk_init(27, 8, 8); /* 初始化LCD时钟 10.1MHz */
        break;
    case ATK4384:
        tftlcd_dev.height = 480;
        tftlcd_dev.width = 800;
        tftlcd_dev.vspw = 3;
        tftlcd_dev.vbpd = 32;
        tftlcd_dev.vfpd = 13;
        tftlcd_dev.hspw = 48;
        tftlcd_dev.hbpd = 88;
        tftlcd_dev.hfpd = 40;
        lcdclk_init(42, 4, 8); /* 初始化LCD时钟 31.5MHz */
        break;
    case ATK7084:
        tftlcd_dev.height = 480;
        tftlcd_dev.width = 800;
        tftlcd_dev.vspw = 1;
        tftlcd_dev.vbpd = 23;
        tftlcd_dev.vfpd = 22;
        tftlcd_dev.hspw = 1;
        tftlcd_dev.hbpd = 46;
        tftlcd_dev.hfpd = 210;
        lcdclk_init(30, 3, 7); /* 初始化LCD时钟 34.2MHz */
        break;
    case ATK7016:
        tftlcd_dev.height = 600;
        tftlcd_dev.width = 1024;
        tftlcd_dev.vspw = 3;
        tftlcd_dev.vbpd = 20;
        tftlcd_dev.vfpd = 12;
        tftlcd_dev.hspw = 20;
        tftlcd_dev.hbpd = 140;
        tftlcd_dev.hfpd = 160;
        lcdclk_init(32, 3, 5); /* 初始化LCD时钟 51.2MHz */
        break;
    default:
        break;
    }
    tftlcd_dev.pixsize = 4; /* ARGB8888模式，每个像素4字节 */
    tftlcd_dev.framebuffer = LCD_FRAMEBUF_ADDR;
    tftlcd_dev.backcolor = LCD_YELLOW; /* 背景色为白色 */
    tftlcd_dev.forecolor = LCD_BLUE;  /* 前景色为黑色 */

    /* 初始化ELCDIF的CTRL寄存器
     * bit [31] 0 : 停止复位
     * bit [19] 1 : 旁路计数器模式
     * bit [17] 1 : LCD工作在dotclk模式
     * bit [15:14] 00 : 输入数据不交换
     * bit [13:12] 00 : CSC不交换
     * bit [11:10] 11 : 24位总线宽度
     * bit [9:8]   11 : 24位数据宽度,也就是RGB888
     * bit [5]     1  : elcdif工作在主模式
     * bit [1]     0  : 所有的24位均有效
	 */
    LCDIF->CTRL = 0;
    LCDIF->CTRL |= (1 << 5) | (3 << 8) | (3 << 10) | (1 << 17) | (1 << 19);
    /*
     * 初始化ELCDIF的寄存器CTRL1
     * bit [19:16]  : 0X7 ARGB模式下，传输24位数据，A通道不用传输
	 */
    LCDIF->CTRL1 = 0;
    LCDIF->CTRL1 = (0x7 << 16);

    LCDIF->TRANSFER_COUNT = 0;
    LCDIF->TRANSFER_COUNT = (tftlcd_dev.height << 16) | (tftlcd_dev.width << 0);

    /*
     * 初始化ELCDIF的VDCTRL0寄存器
     * bit [29] 0 : VSYNC输出
     * bit [28] 1 : 使能ENABLE输出
     * bit [27] 0 : VSYNC低电平有效
     * bit [26] 0 : HSYNC低电平有效
     * bit [25] 0 : DOTCLK上升沿有效
     * bit [24] 1 : ENABLE信号高电平有效
     * bit [21] 1 : DOTCLK模式下设置为1
     * bit [20] 1 : DOTCLK模式下设置为1
     * bit [17:0] : vsw参数
	 */
    LCDIF->VDCTRL0 = 0;
    LCDIF->VDCTRL0 = (tftlcd_dev.vspw << 0) | (1 << 20) | (1 << 21) | (1 << 24) | (1 << 28);

    LCDIF->VDCTRL1 = tftlcd_dev.vspw + tftlcd_dev.vbpd + tftlcd_dev.height + tftlcd_dev.vfpd;

    LCDIF->VDCTRL2 = (tftlcd_dev.hspw + tftlcd_dev.hbpd + tftlcd_dev.width + tftlcd_dev.hfpd) | 
                     (tftlcd_dev.hspw << 18);

    LCDIF->VDCTRL3 = (tftlcd_dev.vspw + tftlcd_dev.vbpd) | 
                     ((tftlcd_dev.hspw + tftlcd_dev.hbpd) << 16);
    LCDIF->VDCTRL4 = (tftlcd_dev.width) | (1 << 18);

    LCDIF->CUR_BUF = (uint32_t)tftlcd_dev.framebuffer;
    LCDIF->NEXT_BUF = (uint32_t)tftlcd_dev.framebuffer;

    lcd_enable();
    delay_ms(10);
    lcd_clear(LCD_YELLOW);
}

/* 像素时钟初始化， LCD 时钟 = 24 * loopdiv / prediv / div */
void lcdclk_init(uint8_t loopdiv, uint8_t prediv, uint8_t div)
{
    /* 不使用小数分频器 */
    CCM_ANALOG->PLL_AUDIO_NUM = 0;
    CCM_ANALOG->PLL_VIDEO_DENOM = 0;

    CCM_ANALOG->PLL_VIDEO = (1 << 13) | (2 << 19) | (loopdiv << 0);
    CCM_ANALOG->MISC2 &= ~(3 << 30);

    CCM->CSCDR2 &= ~(7 << 15);
    CCM->CSCDR2 |= (2 << 15);

    CCM->CSCDR2 &= ~(7 << 12);
    CCM->CSCDR2 |= ((prediv - 1) << 12);

    CCM->CBCMR &= ~(7 << 23);
    CCM->CBCMR |= ((div - 1) << 23);

    CCM->CSCDR2 &= ~(7 << 9);
    CCM->CSCDR2 |= (0 << 9);
}

/* 复位 LCD 控制器 */
void lcd_reset()
{
    LCDIF->CTRL |= 1 << 31;
}

/* 停止复位 LCD 控制器 */
void lcd_noreset()
{
    LCDIF->CTRL &= ~(1 << 31);
}

/* LCD 使能 */
void lcd_enable()
{
    LCDIF->CTRL |= 1 << 0;
}

/*
 * 读取屏幕ID，
 * 描述：LCD_DATA23=R7(M0);LCD_DATA15=G7(M1);LCD_DATA07=B7(M2);
 * 		M2:M1:M0
 *		0 :0 :0	//4.3寸480*272 RGB屏,ID=0X4342
 *		0 :0 :1	//7寸800*480 RGB屏,ID=0X7084
 *	 	0 :1 :0	//7寸1024*600 RGB屏,ID=0X7016
 *  	1 :0 :1	//10.1寸1280*800,RGB屏,ID=0X1018
 *		1 :0 :0	//4.3寸800*480 RGB屏,ID=0X4384
 * @param 		: 无
 * @return 		: 屏幕ID
 */

uint16_t lcd_readid()
{
    uint8_t idx;
    /* 打开模拟开关 */
    gpio_pin_config_t lcd_vsync;
    IOMUXC_SetPinMux(IOMUXC_LCD_VSYNC_GPIO3_IO03, 0); /* 复用为GPIO */
    IOMUXC_SetPinConfig(IOMUXC_LCD_VSYNC_GPIO3_IO03, 0x10b0);
    /* GPIO初始化 */
    lcd_vsync.direction = kGPIO_DigitalOutput;
    lcd_vsync.output_Logic = 1;
    gpio_init(GPIO3, 3, &lcd_vsync);

    /* 读取屏幕ID */
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA07_GPIO3_IO12, 0); /* 复用为GPIO */
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA15_GPIO3_IO20, 0); /* 复用为GPIO */
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA23_GPIO3_IO28, 0); /* 复用为GPIO */
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA07_GPIO3_IO12, 0xf080);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA15_GPIO3_IO20, 0xf080);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA23_GPIO3_IO28, 0xf080);
    lcd_vsync.direction = kGPIO_DigitalInput;
    gpio_init(GPIO3, 12, &lcd_vsync);
    gpio_init(GPIO3, 20, &lcd_vsync);
    gpio_init(GPIO3, 28, &lcd_vsync);

    idx = (uint8_t)gpio_pinread(GPIO3, 12) << 0;  // M0
    idx |= (uint8_t)gpio_pinread(GPIO3, 20) << 1; // M1
    idx |= (uint8_t)gpio_pinread(GPIO3, 28) << 2; // M2

    if (idx == 0)
        return ATK4342; //4.3寸屏,480*272分辨率
    else if (idx == 1)
        return ATK7084; //7寸屏,800*480分辨率
    else if (idx == 2)
        return ATK7016; //7寸屏,1024*600分辨率
    else if (idx == 4)
        return ATK4384; //4寸屏,800*480分辨率
    else if (idx == 5)
        return ATK1018; //10.1寸屏,1280*800分辨率
    else
        return 0;
}

void lcd_gpioinit()
{
    gpio_pin_config_t bl_gpio;
    /* 1、IO初始化复用功能 */
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA00_LCDIF_DATA00, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA01_LCDIF_DATA01, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA02_LCDIF_DATA02, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA03_LCDIF_DATA03, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA04_LCDIF_DATA04, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA05_LCDIF_DATA05, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA06_LCDIF_DATA06, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA07_LCDIF_DATA07, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA08_LCDIF_DATA08, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA09_LCDIF_DATA09, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA10_LCDIF_DATA10, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA11_LCDIF_DATA11, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA12_LCDIF_DATA12, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA13_LCDIF_DATA13, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA14_LCDIF_DATA14, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA15_LCDIF_DATA15, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA16_LCDIF_DATA16, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA17_LCDIF_DATA17, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA18_LCDIF_DATA18, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA19_LCDIF_DATA19, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA20_LCDIF_DATA20, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA21_LCDIF_DATA21, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA22_LCDIF_DATA22, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA23_LCDIF_DATA23, 0);

    IOMUXC_SetPinMux(IOMUXC_LCD_CLK_LCDIF_CLK, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_ENABLE_LCDIF_ENABLE, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_HSYNC_LCDIF_HSYNC, 0);
    IOMUXC_SetPinMux(IOMUXC_LCD_VSYNC_LCDIF_VSYNC, 0);

    /* 2、配置LCD IO属性	
	 *bit 16:0 HYS关闭
	 *bit [15:14]: 0 默认22K上拉
	 *bit [13]: 0 pull功能
	 *bit [12]: 0 pull/keeper使能 
	 *bit [11]: 0 关闭开路输出
	 *bit [7:6]: 10 速度100Mhz
	 *bit [5:3]: 111 驱动能力为R0/7
	 *bit [0]: 1 高转换率
	 */
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA00_LCDIF_DATA00, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA01_LCDIF_DATA01, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA02_LCDIF_DATA02, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA03_LCDIF_DATA03, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA04_LCDIF_DATA04, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA05_LCDIF_DATA05, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA06_LCDIF_DATA06, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA07_LCDIF_DATA07, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA08_LCDIF_DATA08, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA09_LCDIF_DATA09, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA10_LCDIF_DATA10, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA11_LCDIF_DATA11, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA12_LCDIF_DATA12, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA13_LCDIF_DATA13, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA14_LCDIF_DATA14, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA15_LCDIF_DATA15, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA16_LCDIF_DATA16, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA17_LCDIF_DATA17, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA18_LCDIF_DATA18, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA19_LCDIF_DATA19, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA20_LCDIF_DATA20, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA21_LCDIF_DATA21, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA22_LCDIF_DATA22, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA23_LCDIF_DATA23, 0xB9);

    IOMUXC_SetPinConfig(IOMUXC_LCD_CLK_LCDIF_CLK, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_ENABLE_LCDIF_ENABLE, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_HSYNC_LCDIF_HSYNC, 0xB9);
    IOMUXC_SetPinConfig(IOMUXC_LCD_VSYNC_LCDIF_VSYNC, 0xB9);

    /* lcd 背光 */
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO08_GPIO1_IO08, 0); /* 背光BL引脚      */
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO08_GPIO1_IO08, 0x10b0);

    /* GPIO初始化 */
    bl_gpio.direction = kGPIO_DigitalOutput;
    bl_gpio.output_Logic = 1;
    gpio_init(GPIO1, 8, &bl_gpio);
}

/* 画点函数 */
inline void lcd_drawpoint(uint16_t x, uint16_t y, uint32_t color)
{
    *(uint32_t *)((uint32_t)tftlcd_dev.framebuffer + tftlcd_dev.pixsize * (tftlcd_dev.width * y + x))
        = color; 
}

inline uint32_t lcd_readpoint(uint16_t x, uint16_t y)
{
    return *(uint32_t *)((uint32_t)tftlcd_dev.framebuffer + tftlcd_dev.pixsize * (tftlcd_dev.width * y + x)); 
}

/* 清屏 */
void lcd_clear(uint32_t color)
{
    uint32_t num;
    uint32_t i = 0;

    uint32_t* start = (uint32_t *)tftlcd_dev.framebuffer;
    num = (uint32_t)(tftlcd_dev.height * tftlcd_dev.width);

    for(i = 0; i < num; i++)
    {
        start[i] = color;
    }
}

void lcd_fill(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint32_t color)
{ 
    uint16_t x, y;

	if(x0 < 0) x0 = 0;
	if(y0 < 0) y0 = 0;
	if(x1 >= tftlcd_dev.width) x1 = tftlcd_dev.width - 1;
	if(y1 >= tftlcd_dev.height) y1 = tftlcd_dev.height - 1;
	
    for(y = y0; y <= y1; y++)
    {
        for(x = x0; x <= x1; x++)
			lcd_drawpoint(x, y, color);
    }
}