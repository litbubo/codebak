#include<stdio.h>
#include<math.h>
void main()
{
    double s,i,t;
    double n=2;
    s=1;
    i=1;
    do
    {
        t=(n-1)/(2*n-1);
        i=i*t;
        s=s+i;
        n++;
     }while(i>=0.0005);
 printf("%lf",s);
}
