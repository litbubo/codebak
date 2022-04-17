#include <REGX52.H>

unsigned char send[2] = {0x01, 0x02};
unsigned char count = 0;
unsigned char temp;

void UART_A_Init()
{
    TMOD = 0x20;
    TL1 = 0xF3;
    TH1 = 0xF3;
    PCON = 0x00;
    SCON = 0x50;
    TR1 = 1;
    EA = 1;
    ES = 1;
	TI = 0;
	RI = 0;
}

/*

甲机程序
void UART_Inter() interrupt 4
{
    if (TI == 1)
    {
        TI = 0;
        if ( count == 0)
        {
            count++;
            SBUF = send[count];
        }
    }
    if (RI == 1)
    {
        temp = SBUF;
        P1 = temp;
        RI = 0;
    }
}



void main()
{
    UART_A_Init();
    SBUF = send[count];
    while(1);
}
*/


void UART_Inter() interrupt 4
{
    if (TI == 1)
    {
        TI = 0;
    }
    if (RI == 1)
    {
        temp = SBUF;
        if(temp == 0x01)
			SBUF = 0xF1;
		if(temp == 0x02)
			SBUF = 0xF2;
		P1 = ~temp;
        RI = 0;
    }
}


void main()
{
    UART_A_Init();
    while(1);
}
