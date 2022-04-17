#include <REGX52.H>

unsigned char temp;

void UART_A_Init()
{
    PCON &= 0x7F; //波特率不倍速
    SCON = 0x50;  //8位数据,可变波特率
    TMOD &= 0x0F; //设置定时器模式
    TMOD |= 0x20; //设置定时器模式
    TL1 = 0xFA;   //设置定时初始值
    TH1 = 0xFA;   //设置定时重载值
    ET1 = 0;      //禁止定时器%d中断
    TR1 = 1;      //定时器1开始计时
    EA = 1;
    ES = 1;
	TI = 0;
	RI = 0;
}

void UART_Inter() interrupt 4
{
    if (TI == 1)
    {
        TI = 0;
    }
    if (RI == 1)
    {
        temp = SBUF;
        if (temp == 0x01)
            SBUF = 0xF1;
        if (temp == 0x02)
            SBUF = 0xF2;
        RI = 0;
    }
}

void main()
{
    UART_A_Init();
    while (1)
        ;
}
