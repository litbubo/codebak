#include <STC89C5xRC.H>

//#include <REGX52.H>
#include <INTRINS.H>

unsigned char LED = 0;

void Delay(unsigned int xms)
{
    unsigned char i, j;
    while (xms--)
    {
        i = 2;
        j = 239;
        do
        {
            while (--j);
        }
        while (--i);
    }
}

void main()
{
    int temp = 0x01;
    P2 = 0xfe;
    while(1)
    {
        if(P33 == 0)
        {
            Delay(20);
            while(P33 == 0);
            Delay(20);
            ++LED;
            if (LED >= 8)
            {
                LED = 0;
            }
            P2 = ~(temp<<LED);
        }
        if(P31 == 0)
        {
            Delay(20);
            while(P31 == 0);
            Delay(20);
            if (LED <= 0)
            {
                LED = 8;
            }
            --LED;
            P2 = ~(temp<<LED);
        }

    }
}

