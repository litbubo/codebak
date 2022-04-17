#include "Delay.h"

void Delayms(unsigned int time) //@12.000MHz
{
    unsigned char i, j;

    while (time--)
    {
        /* code */
        i = 2;
        j = 239;
        do
        {
            while (--j)
                ;
        } while (--i);
    }
}
