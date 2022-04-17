#include <STC89C5xRC.H>

void UART_Init()
{
    SCON = 0x50;		//设置8位异步收发，允许接收
    PCON = 0x80;		//SMOD = 1 波特率加倍
    TMOD &= 0x0F;		//清除定时器1设置
    TMOD |= 0x20;		//设置定时器1 8位自动重装
    TL1 = 0xF3;			//设置值
    TH1 = 0xF3;			//设置值
    EA = 1;				//总中断打开
    ES = 1;				//串口中断
    ET1 = 0;			//禁止定时器1中断
    TR1 = 1;			//定时器1开始计数
    RI = 0;				//软件复位
    TI = 0;				//软件复位
}


void UART_SendByte(unsigned char byte)
{
    SBUF = byte;
    while(TI == 0);
    TI = 0;
}
