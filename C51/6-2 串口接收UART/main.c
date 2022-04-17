#include <STC89C5xRC.H>
#include <INTRINS.H>
#include "Delayms.h"
#include "UART.h"

int main()
{
    UART_Init();
    while(1)
    {
        /*add your codes*/
        UART_SendByte(0x41);
        Delayms(500);
    }
    return 0;
}

void UART_Recv() interrupt 4
{
    if(RI == 1)			//判断是否是接收
    {
        P2 = ~SBUF;
        RI = 0;			//软件复位
    }
}