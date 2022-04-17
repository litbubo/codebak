#include <STC89C5xRC.H>
#include <INTRINS.H>
#include "Delayms.h"
#include "Nixie.h"

void Timer0_Init(void)
{
    TMOD &= 0xF0;		//设置定时器模式
    TMOD |= 0x01;		//设置定时器模式
    TL0 = 0x9C;		//设置定时初值
    TH0 = 0xFF;		//设置定时初值
    TF0 = 0;		//清除TF0标志
    TR0 = 1;		//定时器0开始计时
    ET0=1;
    EA=1;
    PT0=0;
}
unsigned char compare, i = 0;
int main()
{
    Timer0_Init();
    while(1)
    {
        /*add your codes*/
        if (P33 == 0)
        {
            Delayms(20);
            while(P33 == 0);
            Delayms(20);
            i++;
        }
        switch (i)
        {
        case 0:
            compare = 5;
            Nixie(1, 0);
            break;
        case 1:
            compare = 50;
            Nixie(1, 1);
            break;
        case 2:
            compare = 75;
            Nixie(1, 2);
            break;
        case 3:
            compare = 99;
            Nixie(1, 3);
            break;
        default:
            i = 0;
            break;
        }
    }
    return 0;
}

void Timer0_Routine() interrupt 1
{
    static unsigned int T0Count;
    TL0 = 0x9C;		//设置定时初值
    TH0 = 0xFF;		//设置定时初值
    T0Count++;
	T0Count %= 100;
	if(T0Count < compare)
		P20 = 0xff;
	else
		P20 = 0x00;
}
