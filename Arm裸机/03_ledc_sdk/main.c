#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"

/*使能外设时钟*/
void clk_init()
{
    CCM->CCGR0 = 0xffffffff;
    CCM->CCGR1 = 0xffffffff;
    CCM->CCGR2 = 0xffffffff;
    CCM->CCGR3 = 0xffffffff;
    CCM->CCGR4 = 0xffffffff;
    CCM->CCGR5 = 0xffffffff;
    CCM->CCGR6 = 0xffffffff;
}

void led_init()
{
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03 , 0);
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0x10b0);
                                       
	GPIO1->GDIR = 0x0000008;
	GPIO1->DR &= ~(1 << 3);	
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
    GPIO1->DR &= ~(1<<3);
}

void led_close()
{
    GPIO1->DR |= (1<<3);
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