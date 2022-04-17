#include <STC89C5xRC.H>

void Timer0_Init()
{
    TMOD |= 0x01;
    TH0 = (65536 - 1000) / 256;
    TL0 = (65536 - 1000) % 256;
    TF0 = 0;
    EA = 1;
    ET0 = 1;
    PT0 = 0;
    TR0 = 1;
}

void Timer1_Init()
{
    TMOD |= 0x10;
    TH1 = (65536 - 500) / 256;
    TL1 = (65536 - 500) % 256;
    TF1 = 0;
    EA = 1;
    ET1 = 1;
    PT1 = 0;
    TR1 = 1;
}

/*
void Timer0() interrupt 1
{
    static int count = 0;
    TH0 = (65536 - 1000) / 256;
    TL0 = (65536 - 1000) % 256;
    count++;
    if (count >= 1000)
    {
        P20 = ~P20;
        count = 0;
    }
}
*/

/*
void Timer1() interrupt 3
{
    static int count = 0;
    TH1 = (65536 - 500) / 256;
    TL1 = (65536 - 500) % 256;
    count++;
    if (count >= 1000)
    {
        P22 = ~P22;
        count = 0;
    }
}
*/