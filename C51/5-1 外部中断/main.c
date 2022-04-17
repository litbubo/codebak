#include <STC89C5xRC.H>
#include <INTRINS.H>

void INTR0_Init();
void INTR1_Init();
void Delay20ms();

int main()
{
    INTR0_Init();
    INTR1_Init();
    while(1)
    {
        /*add your codes*/
    }
    return 0;
}

void Delay20ms()		//@12.000MHz
{
    unsigned char i, j;

    i = 39;
    j = 230;
    do
    {
        while (--j);
    } while (--i);
}


void INTR0_Init()
{
    IT0 = 1;        //下降沿触发
    IE0 = 0;        //软清零
    EA = 1;         //中断总允许开关
    EX0 = 1;        //打开INTR0中断允许
    PX0 = 0;
}

void Intr0() interrupt 0
{
    Delay20ms();
    P20 = ~P20;
}

void INTR1_Init()
{
    IT1 = 1;        //下降沿触发
    IE1 = 0;        //软清零
    EA = 1;         //中断总允许开关
    EX1 = 1;        //打开INTR1中断允许
    PX1 = 0;
}

void Intr1() interrupt 2
{
    Delay20ms();
    P21 = ~P21;
}