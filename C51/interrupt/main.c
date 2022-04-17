#include <STC89C5xRC.H>
#include <INTRINS.H>

char num = 0;

void Delay20ms()		//@11.0592MHz
{
    unsigned char i, j, k;

    _nop_();
    _nop_();
    i = 1;
    j = 216;
    k = 35;
    do
    {
        do
        {
            while (--k);
        } while (--j);
    } while (--i);
}

void numledup() interrupt 0
{
	num++;
}

void numledup2() interrupt 2
{
	num++;
}

void count() interrupt 1
{
	TH0 = (65536 - 50000) / 256;
	TL0 = (65536 - 50000) % 256;
	//TR1 = 1;
	P27 = ~P27;
	num++;
	Delay20ms();
}

void count2() interrupt 3
{
	TH0 = (65536 - 50000) / 256;
	TL0 = (65536 - 50000) % 256;
	//TR1 = 1;
	P21 = ~P21;
	num++;
}

void main()
{
	P27 = 0;
	TCON = 0x05;
	IE = 0x85;
	IP = 0X05;
	
	TMOD = 0x01;
	TH0 = (65536 - 50000) / 256;
	TL0 = (65536 - 50000) % 256;
	TCON |= 0x10;
	IE |= 0X02;
	IP |= 0X00;
	
	TMOD |= 0x10;
	TCON |= 0x40;
	TH0 = (65536 - 50000) / 256;
	TL0 = (65536 - 50000) % 256;
	IE |= 0x08;
	IP |= 0x00;
	
	
	
	
	
	
	while (1)
	{
		//P2 = ~num;
	
	}
	/*
    while (1)
    {
        if ( P33 == 0)
        {
            Delay20ms();
            while ( P33 == 0 ) ;
			Delay20ms();
            //P20 = 0;
			num++;
        }
		if ( P32 == 0)
        {
            Delay20ms();
            while ( P32 == 0 ) ;
			Delay20ms();
            //P21 = 0;
			num--;
        }
		
		P2 = ~num;
		
    }*/
    return ;
}