#include "bsp_key.h"
#include "bsp_delay.h"
#include "cc.h"
/* 初始化按键 */
void key_init()
{
    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0); /* 复用为GPIO */
    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0xf080);

    /* GPIO初始化 */
    GPIO5->GDIR &= ~(1 << 18);
}

/* 0按下，1松手 */
int read_key()
{
    int ret = ((GPIO1->DR) >> 18) & 0x01;
    return ret;
}

int get_key()
{
    int ret = 0;
    static int release = 1;
    if ((release == 1) && (read_key() == 0)) 
    {
        delay(10);
        release = 0;
        if (read_key() == 0)
        {
            ret = KEY0_VALUE;
        }
    }
    else if (read_key() == 1)
    {
        release = 1;
        ret = KEY_NONE;
    }
   return ret;
}
