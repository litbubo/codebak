#include <STC89C5xRC.H>
#include <INTRINS.H>
#include "Delayms.h"
int main()
{
	char i = 0xFE;
    while(1)
    {
        /*add your codes*/
		P2 = i;
		i = _cror_(i, 1);
		Delayms(1000);
    }
    return 0;
}