#include <STC89C5xRC.H>
#include <INTRINS.H>
#include "Timer.h"
#include "Key.h"
#include "Nixie.h"
#include "AT24C02.h"
#include "Delayms.h"

unsigned char seclo = 0, sec = 0, min = 0;
unsigned char i = 0, j = 0;
bit Runflag = 0;

void SecLoop()
{
    if(Runflag == 1)
    {
        seclo++;
        if(seclo >= 100)
        {
            seclo = 0;
            sec++;
            if(sec >= 60)
            {
                sec = 0;
                min++;
                if(min >= 60)
                {
                    min = 0;
                }
            }
        }
    }
}

int main()
{
    unsigned char key = 0;
    Timer0_Init();

    while (1)
    {
        key = Key();

        if(key == 1)
        {
            Runflag =! Runflag;
        }

        if(key == 2)
        {
            Runflag = 0;
            seclo = 0;
            sec = 0;
            min = 0;
			i = 0;
			j = 0;
			
        }
		if(key == 3)
        {
            AT24C02_WriteByte(i + 1, seclo);
			Delayms(5);
			AT24C02_WriteByte(i + 2, sec);
			Delayms(5);
			AT24C02_WriteByte(i + 3, min);
			Delayms(5);
			i += 3;
			if(i > 12)
				i = 0;
        }
		if(key == 4)
        {
            seclo = AT24C02_ReadByte(j + 1);
			sec = AT24C02_ReadByte( j + 2);
			min = AT24C02_ReadByte(j + 3);
			j += 3;
			if (j > 12)
				j = 0;
        }
        SetNixie(1, min/10);
        SetNixie(2, min%10);
        SetNixie(3, 11);
        SetNixie(4, sec/10);
        SetNixie(5, sec%10);
        SetNixie(6, 11);
        SetNixie(7, seclo/10);
        SetNixie(8, seclo%10);
    }
    return 0;
}

void Timer0() interrupt 1
{
    static int count0 = 0, count1 = 0, count2 = 0;
    TH0 = (65536 - 1000) / 256;
    TL0 = (65536 - 1000) % 256;
    count0++;
    count1++;
    count2++;
    if (count0 >= 20)
    {
        count0 = 0;
        KeyLoop();
    }
    if (count1 >= 2)
    {
        count1 = 0;
        NixieLoop();
    }
    if (count2 >= 10)
    {
        count2 = 0;
        SecLoop();
    }
}