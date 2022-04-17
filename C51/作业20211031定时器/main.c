#include <REGX52.H>

void timer0_Init()
{
	TMOD |= 0x01;
	TL0 = 0x18;
	TH0 = 0xFC;
	TR0 = 1;
	TF0 = 0;
}

void main()
{
	timer0_Init();
	while(1)
	{
		TL0 = 0x18;
		TH0 = 0xFC;
		while(TF0 == 0)
			;
		TF0 = 0;
		P1_0 = ~P1_0;
	}
}