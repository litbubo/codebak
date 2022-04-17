#include <STC89C5xRC.H>
#include <INTRINS.H>

sbit LED = P1^1;

void LED_Int() interrupt 2
{
    LED = ~LED;
}

void Inter_Init()
{
    TCON |= 0x04;
    EA = 1;
    EX1 = 1;
}

int main()
{
    Inter_Init();
    LED = 1;
    while (1)
    {
        /* code */
    }
    return 0;
}
