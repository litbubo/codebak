#include <stdio.h>
void fun(int *p,int *q)
{
    int *r;
    r=p;
    p=q;
    q=r;
}
void main ()
{
    int a=3,b=4;
    fun(&a,&b);
    printf ("%d %d",a,b);
}
