#include <STC89C5xRC.H>
#include <INTRINS.H>
#include "Delayms.h"
int main()
{
    while(1)
    {
        /*add your codes*/
        if(P33 == 0)
        {
            Delayms(20);
            while(P33 == 0) ;
            Delayms(20);
            P20 = ~P20;
        }
        
    }
    return 0;
}