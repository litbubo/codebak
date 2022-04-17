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

int main(void)
{
    //u8 i = 0;
    u8 led_state = OFF;
    //u8 keyvalue = 0;
    //u8 beep_state = OFF;
    //uint8_t data = 0;
    rtc_datetime rtc_Date;

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

    lcd_drawpoint(0, 0, LCD_RED);
    lcd_drawpoint(0, tftlcd_dev.height - 1, LCD_RED);
    lcd_drawpoint(tftlcd_dev.width - 1, 0, LCD_RED);
    lcd_drawpoint(tftlcd_dev.width - 1, tftlcd_dev.height - 1, LCD_RED);

    lcd_fill(100, 100, 200, 200, LCD_RED);
    lcd_show_string(10, 400, 800, 32, 32, (char *)"LI QIU I LOVE YOU!");

#if 0
    key_init();
    exti_init();
    epit_init(0, 33000000);
#endif
    /*初始化LED*/
    while (1)
    {
        led_state = !led_state;
        led_switch(LED0, led_state);
        delay_ms(1000);
        rtc_readtime(&rtc_Date);
        printf("当前时间：%d年%d月%d日%d时%d分%d秒\r\n", rtc_Date.year,
                                                    rtc_Date.month,
                                                    rtc_Date.day,
                                                    rtc_Date.hour,
                                                    rtc_Date.minute,
                                                    rtc_Date.second);

#if 0
        printf("请输入您的字符：");
        scanf("%c", &data);
        //data = getc();
        printf("\r\n您输入的数据为：%c\r\n", data);
        //delay_ms(1000);

        puts((uint8_t *)"请输入您的字符：");
        puts((uint8_t *)"\r\n");
        data = getc();
        puts((uint8_t *)"您输入的字符是：");
        puts(&data);
        puts((uint8_t *)"\r\n");

        keyvalue = get_key();
        if (keyvalue)
        {
            switch (keyvalue)
            {
            case KEY0_VALUE:
                beep_state = !beep_state;
                beep_switch(beep_state);
                break;
            default:
                break;
            }
        } 
        
        i++;
        if (i == 50)
        {
            i = 0;
            led_state = !led_state;
            led_switch(LED0, led_state);
        }
        delay(10);
#endif
    }
    return 0;
}