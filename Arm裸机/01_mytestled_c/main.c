#include "main.h"
/*使能外设时钟*/
void clk_init()
{
    CCM_CCGR0 = 0xffffffff;
    CCM_CCGR1 = 0xffffffff;
    CCM_CCGR2 = 0xffffffff;
    CCM_CCGR3 = 0xffffffff;
    CCM_CCGR4 = 0xffffffff;
    CCM_CCGR5 = 0xffffffff;
    CCM_CCGR6 = 0xffffffff;
}

void led_init()
{
    SW_MUX_GPIO1_IO03 = 0x5; /*复用 */
    SW_PAD_GPIO1_IO03 = 0x10b0; /*设置电气属性*/

    GPIO1_GDIR = 0x8;
    GPIO1_DR = 0x0;

}

void delay_shorts(volatile unsigned int n)
{
    while (n--);
}

/*延时， 一次循环1ms，主频396Mhz */
void delay(volatile unsigned int n)
{
    while (n--)
    {
        delay_shorts(0x7ff);
    }
}

void led_on()
{
    GPIO1_DR &= ~(1<<3);
}

void led_close()
{
    GPIO1_DR |= (1<<3);
}

int main(void)
{
    clk_init();
    led_init();
    /*初始化LED*/
    while (1)
    {
        /* code */
        led_on();
        delay(1000);
        led_close();
        delay(1000);
    }
    
    return 0;
}