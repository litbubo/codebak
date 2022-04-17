#include "bsp_key.h"
#include "bsp_delay.h"
#include "cc.h"
#include "bsp_gpio.h"
/* 初始化按键 */
void key_init()
{
    gpio_pin_config_t key_config;
    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0); /* 复用为GPIO */
    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0xf080);

    /* GPIO初始化 */
    key_config.direction = kGPIO_DigitalInput;

    gpio_init(GPIO1, 18, &key_config);
}

/* 0按下，1松手 */
int get_key()
{
    int ret = 0;
    static int release = 1;
    if ((release == 1) && (gpio_pinread(GPIO1, 18) == 0)) 
    {
        delay(10);
        release = 0;
        if (gpio_pinread(GPIO1, 18) == 0)
        {
            ret = KEY0_VALUE;
        }
    }
    else if (gpio_pinread(GPIO1, 18) == 1)
    {
        release = 1;
        ret = KEY_NONE;
    }
   return ret;
}
