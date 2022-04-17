#include "bsp_delay.h"

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