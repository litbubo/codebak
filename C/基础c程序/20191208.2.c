#include <stdio.h>
float fun(int n,float x);
main()
{
    int n;
    float x;
    scanf("%d",&n);
    scanf("%f",&x);
    fun(n,x);
    printf("s=%f",fun(n,x));
}
float fun(int n,float x)
{
    float sum=1,z=1,y=1;
    int i;
    for(i=1; i<=n; i++)
    {
        y*=x;
        z*=i;
        sum+=y/z;
    }
    return sum;
}
