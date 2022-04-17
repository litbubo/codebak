#include <STC89C5xRC.H>
#include <INTRINS.H>
#include "Delay.h"
/*串口初始化寄存器配置*/
void Serialport_Init()
{
    SCON &= 0x0f;     // 高四位清零
    SCON |= 0x50;     // 设置8位异步工作方式，REN使能允许接收
    PCON |= 0x80;     // 设置波特率加倍，SMOD = 1
    TMOD |= 0x20;     // 设置定时器1工作方式10（8bit自动重装）
    TH1 = TL1 = 0XF3; // 赋初值，波特率4800
    RI = 0;
    TI = 0;  // TI/RI软重置
    EA = 1;  // 中断允许总控制位使能
    ES = 1;  // 串口中断允许
    ET1 = 0; // 禁止定时器1中断
    TR1 = 1; // 开启定时器1
}
/*串行发送*/
void SendData(char buf)
{
    if (TI == 0)
        SBUF = buf;
    while (TI == 0) // 等待发送完成
        ;
    TI = 0; // 软重置TI寄存器
}
/*串行接收*/
void ReadData() interrupt 4 // 串口中断服务程序
{
    char temp;
    if (RI == 1) // 判断是否为接收触发中断
    {
        temp = SBUF;
        SendData(temp);
        RI = 0;
    }
}

int main()
{
    Serialport_Init();
    while (1)
    {
    }

    return 0;
}