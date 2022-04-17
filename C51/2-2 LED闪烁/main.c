#include <STC89C5xRC.H>
#include <INTRINS.H>
//#include "Delayms.h"
#include "Delay.h"

int main()
{
    while(1)
    {
        /*add your codes*/
        P2 = ~P2;
        Delayms(1000);
       
    }
    return 0;
}