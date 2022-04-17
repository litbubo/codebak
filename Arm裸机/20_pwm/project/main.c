#include "imx6u.h"

#include "bsp_clk.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_delay.h"
#include "bsp_key.h"
#include "bsp_int.h"
#include "bsp_exti.h"
#include "bsp_epit.h"
#include "bsp_keyfilter.h"
#include "bsp_uart.h"
#include "stdio.h"
#include "bsp_lcd.h"
#include "bsp_lcdapi.h"
#include "bsp_rtc.h"
#include "bsp_i2c.h"
#include "bsp_ap3216c.h"
#include "bsp_icm20608.h"
#include "bsp_ft5426.h"
#include "bsp_pwm.h"
/*
 * @description	: 指定的位置显示整数数据
 * @param - x	: X轴位置
 * @param - y 	: Y轴位置
 * @param - size: 字体大小
 * @param - num : 要显示的数据
 * @return 		: 无
 */
void integer_display(unsigned short x, unsigned short y, unsigned char size, signed int num)
{
	char buf[200];
	
	lcd_fill(x, y, x + 50, y + size, tftlcd_dev.backcolor);
	
	memset(buf, 0, sizeof(buf));
	if(num < 0)
		sprintf(buf, "-%d", -num);
	else 
		sprintf(buf, "%d", num);
	lcd_show_string(x, y, 50, size, size, buf); 
}


/*
 * @description	: 指定的位置显示小数数据,比如5123，显示为51.23
 * @param - x	: X轴位置
 * @param - y 	: Y轴位置
 * @param - size: 字体大小
 * @param - num : 要显示的数据，实际小数扩大100倍，
 * @return 		: 无
 */
void decimals_display(unsigned short x, unsigned short y, unsigned char size, signed int num)
{
	signed int integ; 	/* 整数部分 */
	signed int fract;	/* 小数部分 */
	signed int uncomptemp = num; 
	char buf[200];

	if(num < 0)
		uncomptemp = -uncomptemp;
	integ = uncomptemp / 100;
	fract = uncomptemp % 100;

	memset(buf, 0, sizeof(buf));
	if(num < 0)
		sprintf(buf, "-%d.%d", integ, fract);
	else 
		sprintf(buf, "%d.%d", integ, fract);
	lcd_fill(x, y, x + 60, y + size, tftlcd_dev.backcolor);
	lcd_show_string(x, y, 60, size, size, buf); 
}

/*
 * @description	: 使能I.MX6U的硬件NEON和FPU
 * @param 		: 无
 * @return 		: 无
 */
 void imx6ul_hardfpu_enable(void)
{
	uint32_t cpacr;
	uint32_t fpexc;

	/* 使能NEON和FPU */
	cpacr = __get_CPACR();
	cpacr = (cpacr & ~(CPACR_ASEDIS_Msk | CPACR_D32DIS_Msk))
		   |  (3UL << CPACR_cp10_Pos) | (3UL << CPACR_cp11_Pos);
	__set_CPACR(cpacr);
	fpexc = __get_FPEXC();
	fpexc |= 0x40000000UL;	
	__set_FPEXC(fpexc);
}

int main(void)
{
    //u8 i = 0;
    u8 led_state = OFF;
    //u8 keyvalue = 0;
    //u8 beep_state = OFF;
    //uint8_t data = 0;
    //rtc_datetime rtc_Date;
    //uint16_t ir, ps, als;
    imx6ul_hardfpu_enable();
    int_init();
    system_irqTable_init();
    imx6u_clkinit();
    clk_init();
    led_init();
    delay_init();
    beep_init();
    keyfilter_init();
    uart_init();
    lcd_init();
    rtc_init();
	ft5426_init();
	pwm_init();
    //i2c_init(I2C1);
    //ap3216_init();
    //icm20608_init();

    lcd_drawpoint(0, 0, LCD_RED);
    lcd_drawpoint(0, tftlcd_dev.height - 1, LCD_RED);
    lcd_drawpoint(tftlcd_dev.width - 1, 0, LCD_RED);
    lcd_drawpoint(tftlcd_dev.width - 1, tftlcd_dev.height - 1, LCD_RED);

    //lcd_fill(100, 100, 200, 200, LCD_RED);
    //lcd_show_string(10, 400, 800, 32, 32, (char *)"LI QIU I LOVE YOU!");

    while(icm20608_init())		/* 初始化ICM20608	 			*/
	{
		lcd_show_string(50, 100, 200, 16, 16, (char*)"ICM20608 Check Failed!");
		delay_ms(500);
		lcd_show_string(50, 100, 200, 16, 16, (char*)"Please Check!        ");
		delay_ms(500);
	}	

	lcd_show_string(50, 100, 200, 16, 16, (char*)"ICM20608 Ready");
	
	lcd_show_string(50, 130, 200, 16, 16, (char*)"accel x:");  
	lcd_show_string(50, 150, 200, 16, 16, (char*)"accel y:");  
	lcd_show_string(50, 170, 200, 16, 16, (char*)"accel z:");  
	lcd_show_string(50, 190, 200, 16, 16, (char*)"gyro  x:"); 
	lcd_show_string(50, 210, 200, 16, 16, (char*)"gyro  y:"); 
	lcd_show_string(50, 230, 200, 16, 16, (char*)"gyro  z:"); 
	lcd_show_string(50, 250, 200, 16, 16, (char*)"temp   :"); 

	lcd_show_string(50 + 181, 130, 200, 16, 16, (char*)"g");  
	lcd_show_string(50 + 181, 150, 200, 16, 16, (char*)"g");  
	lcd_show_string(50 + 181, 170, 200, 16, 16, (char*)"g");  
	lcd_show_string(50 + 181, 190, 200, 16, 16, (char*)"o/s"); 
	lcd_show_string(50 + 181, 210, 200, 16, 16, (char*)"o/s"); 
	lcd_show_string(50 + 181, 230, 200, 16, 16, (char*)"o/s"); 
	lcd_show_string(50 + 181, 250, 200, 16, 16, (char*)"C");

	lcd_show_string(600, 110, 400, 16, 16,	(char*)"TP Num	:");  
	lcd_show_string(600, 130, 200, 16, 16,	(char*)"Point0 X:");  
	lcd_show_string(600, 150, 200, 16, 16,	(char*)"Point0 Y:");  
	lcd_show_string(600, 170, 200, 16, 16,	(char*)"Point1 X:");  
	lcd_show_string(600, 190, 200, 16, 16,	(char*)"Point1 Y:");  
	lcd_show_string(600, 210, 200, 16, 16,	(char*)"Point2 X:");  
	lcd_show_string(600, 230, 200, 16, 16,	(char*)"Point2 Y:");  
	lcd_show_string(600, 250, 200, 16, 16,	(char*)"Point3 X:");  
	lcd_show_string(600, 270, 200, 16, 16,	(char*)"Point3 Y:");  
	lcd_show_string(600, 290, 200, 16, 16,	(char*)"Point4 X:");  
	lcd_show_string(600, 310, 200, 16, 16,	(char*)"Point4 Y:");  
	
	tftlcd_dev.forecolor = LCD_BLUE;

	pwm_dev.pwm_duty = 10;
    pwm1_setduty(pwm_dev.pwm_duty);
	//int lights = 10;

	while(1)					
	{	
		int ret = get_key();
		if (ret == KEY0_VALUE)
		{
			pwm_dev.pwm_duty += 10;
			if (pwm_dev.pwm_duty > 100)
			{
				pwm_dev.pwm_duty = 0;
			}
			pwm1_setduty(pwm_dev.pwm_duty);
		}
		//printf("point : x == %d, y == %d\r\n", ft5426_dev.x[0], ft5426_dev.y[0]);
		icm20608_getdata();
		integer_display(50 + 70, 130, 16, icm20608_dev.accel_x_adc);
		integer_display(50 + 70, 150, 16, icm20608_dev.accel_y_adc);
		integer_display(50 + 70, 170, 16, icm20608_dev.accel_z_adc);
		integer_display(50 + 70, 190, 16, icm20608_dev.gyro_x_adc);
		integer_display(50 + 70, 210, 16, icm20608_dev.gyro_y_adc);
		integer_display(50 + 70, 230, 16, icm20608_dev.gyro_z_adc);
		integer_display(50 + 70, 250, 16, icm20608_dev.temp_adc);

		decimals_display(50 + 70 + 50, 130, 16, icm20608_dev.accel_x_act);
		decimals_display(50 + 70 + 50, 150, 16, icm20608_dev.accel_y_act);
		decimals_display(50 + 70 + 50, 170, 16, icm20608_dev.accel_z_act);
		decimals_display(50 + 70 + 50, 190, 16, icm20608_dev.gyro_x_act);
		decimals_display(50 + 70 + 50, 210, 16, icm20608_dev.gyro_y_act);
		decimals_display(50 + 70 + 50, 230, 16, icm20608_dev.gyro_z_act);
		decimals_display(50 + 70 + 50, 250, 16, icm20608_dev.temp_act);

		lcd_shownum(600 + 72, 110, ft5426_dev.point_num , 1, 16);
		lcd_shownum(600 + 72, 130, ft5426_dev.x[0], 5, 16);
		lcd_shownum(600 + 72, 150, ft5426_dev.y[0], 5, 16);
		lcd_shownum(600 + 72, 170, ft5426_dev.x[1], 5, 16);
		lcd_shownum(600 + 72, 190, ft5426_dev.y[1], 5, 16);
		lcd_shownum(600 + 72, 210, ft5426_dev.x[2], 5, 16);
		lcd_shownum(600 + 72, 230, ft5426_dev.y[2], 5, 16);
		lcd_shownum(600 + 72, 250, ft5426_dev.x[3], 5, 16);
		lcd_shownum(600 + 72, 270, ft5426_dev.y[3], 5, 16);
		lcd_shownum(600 + 72, 290, ft5426_dev.x[4], 5, 16);
		lcd_shownum(600 + 72, 310, ft5426_dev.y[4], 5, 16);

		lcd_drawpoint(ft5426_dev.x[0], ft5426_dev.y[0], LCD_RED);

        led_state = !led_state;
        led_switch(LED0, led_state);
        //delay_ms(100);
    }
    return 0;
}