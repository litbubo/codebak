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
        UART_SendByte(0X41);
        Delayms(500);
    }
    return 0;
}