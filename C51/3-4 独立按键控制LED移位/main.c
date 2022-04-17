#include <STC89C5xRC.H>
#include <INTRINS.H>
#include "Delayms.h"

unsigned char num = 0;

int main()
{
    P2 = ~0x01;
    while(1)
    {
        /*add your codes*/
        if(P33 == 0)
        {
            Delayms(20);
            while(P33 == 0) ;
            Delayms(20);
            num++;
            if (num >= 8)
                num = 0;
            P2 = ~(0x01 << num);
        }
		
		if(P32 == 0)
        {
            Delayms(20);
            while(P32 == 0) ;
            Delayms(20);
            
            if (num  == 0)
                num = 7;
			else
				num--;
            P2 = ~(0x01 << num);
        }

    }
    return 0;
}