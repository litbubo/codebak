#include "bsp_led.h"

void led_init()
{
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03 , 0);
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0x10b0);
                                       
	GPIO1->GDIR = 0x0000008;
	GPIO1->DR &= ~(1 << 3);	
}

void led_on()
{
    GPIO1->DR &= ~(1<<3);
}

void led_close()
{
    GPIO1->DR |= (1<<3);
}

void led_switch(int led, int status)
{
    switch (led) 
    {
        case LED0:
            if (status == 1)
                GPIO1->DR &= ~(1 << 3);
            else if (status == 0)
                GPIO1->DR |= (1 << 3);
            break;
        default:
            break;
    }
}
