
#include "stdio.h"
int main()
{
    int a,b,c,MAX;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)
        MAX=a;
    else
        MAX=b;
    if(MAX<c)
        MAX=c;
    printf ("MAX=%d",MAX);



}
