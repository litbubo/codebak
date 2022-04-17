#include <STC89C5xRC.H>
#include <INTRINS.H>

void Timer0_Init()
{
    TMOD |= 0x01;
    TMOD &= 0xF1;
    TL0 = 64536 % 256;
    TH0 = 64536 / 256;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}

void Timer1_Init()
{
    TMOD |= 0x10;
    TMOD &= 0x1F;
    TL1 = 64536 % 256;
    TH1 = 64536 / 256;
    EA = 1;
    ET1 = 1;
    TR1 = 1;
}

void Timer0_Inter() interrupt 1
{
    TL0 = 64536 % 256;
    TH0 = 64536 / 256;
    P20 = ~P20;
}

void Timer1_Inter() interrupt 3
{
    TL1 = 64536 % 256;
    TH1 = 64536 / 256;
    P21 = ~P21;
}

int main()
{
    Timer0_Init();
    Timer1_Init();

    while (1)
    {
    }

    return 0;
}