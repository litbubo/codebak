#include <STC89C5xRC.H>
#include <INTRINS.H>
#include "Delayms.h"

int main()
{
	unsigned char num = 0;
	P2 = 0xFF;
    while(1)
    {
        /*add your codes*/
		if (P33 == 0)
		{
			Delayms(20);
			while( P33 == 0);
			Delayms(20);
			num++;
			P2 = ~num;
		}
    }
    return 0;
}