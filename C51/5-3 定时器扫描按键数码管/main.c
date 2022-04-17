#include <STC89C5xRC.H>
#include <INTRINS.H>
#include "Timer.h"
#include "Key.h"
#include "Nixie.h"

unsigned char seclo = 0, sec = 0, min = 0;
bit Runflag = 0;

int main()
{
    unsigned char key = 0;
    Timer0_Init();

    while (1)
    {
        key = Key();

        if(key == 1)
        {
            P20 = ~P20;
        }

        if(key == 2)
        {
            P21 = ~P21;
        }
        SetNixie(1, 7);
        SetNixie(2, 8);
        SetNixie(3, 9);
    }
    return 0;
}

void Timer0() interrupt 1
{
    static int count0 = 0, count1 = 0;
    TH0 = (65536 - 1000) / 256;
    TL0 = (65536 - 1000) % 256;
    count0++;
    count1++;
    if (count0 >= 10)
    {
        count0 = 0;
        KeyLoop();
    }
    if (count1 >= 1)
    {
        count1 = 0;
        NixieLoop();
    }
}