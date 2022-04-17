#include <STC89C5xRC.H>
#include <INTRINS.H>

void Delay500ms()
{
    unsigned char i, j, k;

    _nop_();
    i = 4;
    j = 205;
    k = 187;
    do
    {
        do
        {
            while (--k)
                ;
        } while (--j);
    } while (--i);
}

int main()
{
    unsigned char i = 0x01;
    unsigned char x = 0x01;
    while (1)
    {
        /*add your codes*/
        P2 = ~(i << x);
        x++;
        if (x > 8)
            x = 0x00;
        Delay500ms();
    }
    return 0;
}