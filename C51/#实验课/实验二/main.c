#include <STC89C5xRC.H>
#include <INTRINS.H>

void Key_Init()
{
    TCON = 0x01;
    EX0 = 1;
    EX1 = 1;
    EA = 1;
}

void Key1_Inter() interrupt 0
{
    P20 = ~P20;
}

void Key2_Inter() interrupt 2
{
    P21 = ~P21;
}

int main()
{
    Key_Init();

    while (1)
    {
    }

    return 0;
}
