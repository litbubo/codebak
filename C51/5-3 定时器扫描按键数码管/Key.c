#include <STC89C5xRC.H>

unsigned char KeyNumber = 0;

unsigned char Key()
{
    unsigned char temp = 0;
    temp = KeyNumber;
    KeyNumber = 0;
    return temp;
}

unsigned char KeyGet()
{
    unsigned char KeyNum = 0;

    if(P31 == 0)
    {
        KeyNum = 1;
    }

    if(P30 == 0)
    {
        KeyNum = 2;
    }

    if(P32 == 0)
    {
        KeyNum = 3;
    }

    if(P33 == 0)
    {
        KeyNum = 4;
    }
    return KeyNum;
}

void KeyLoop()
{
    static unsigned char LastNum = 0, NowNum = 0;
    LastNum = NowNum;
    NowNum = KeyGet();

    if (LastNum == 0 && NowNum == 1)
    {
        KeyNumber = 1;
    }
    if (LastNum == 0 && NowNum == 2)
    {
        KeyNumber = 2;
    }
    if (LastNum == 0 && NowNum == 3)
    {
        KeyNumber = 3;
    }
    if (LastNum == 0 && NowNum == 4)
    {
        KeyNumber = 4;
    }
}