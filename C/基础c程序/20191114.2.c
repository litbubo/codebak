#include <stdio.h>
int fun(int y)
{
    int x;
    if (y%100==0)
        if (y%400==0)
            x=1;
        else
            x=0;
    else if(y%4==0)
        x=1;
    else
        x=0;
    return x;
}
main()
{
    int x;
    for(x=2000; x<=2050; x++)
        if(fun(x))
        {
            printf("%d   ",x);
        }

}
