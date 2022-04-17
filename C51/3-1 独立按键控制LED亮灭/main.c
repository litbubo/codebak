#include <STC89C5xRC.H>
#include <INTRINS.H>

int main()
{
    while(1)
    {
        /*add your codes*/
        if(P33 == 0 || P32 == 0)
        {
            P20 = 0;
        }
        else
        {
            P20 = 1;
        }
    }
    return 0;
}