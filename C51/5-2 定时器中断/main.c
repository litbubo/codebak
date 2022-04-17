#include <STC89C5xRC.H>
#include <INTRINS.H>

void Timer0_Init();
void Timer1_Init();

int main()
{
    Timer0_Init();
    Timer1_Init();
    while (1)
    {
        /*add your codes*/
    }
    return 0;
}

void Timer0_Init()
{
    TMOD |= 0x01; //定时器0设置为01方式（16位重装）
    TH0 = (65536 - 1000) / 256;
    TL0 = (65536 - 1000) % 256;
    TF0 = 0; //软清零
    EA = 1;  //中断总开关
    ET0 = 1; //允许定时器0中断
    PT0 = 0;
    TR0 = 1; //启动定时器0
}

void Timer1_Init()
{
    TMOD |= 0x10; //定时器0设置为01方式（16位重装）
    TH1 = (65536 - 500) / 256;
    TL1 = (65536 - 500) % 256;
    TF1 = 0; //软清零
    EA = 1;  //中断总开关
    ET1 = 1; //允许定时器0中断
    PT1 = 0;
    TR1 = 1; //启动定时器0
}

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