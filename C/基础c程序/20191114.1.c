#include <stdio.h>
#include <math.h>
fun(int n);
main()
{
    int n;
    scanf("%d",&n);
    fun(n);
}
fun(int n)
{
    double sum=1,x=1;
    int i;
    for(i=2;i<=n;i++)
    {
        sum+=sqrt(i);
        x+=sum;
    }
    printf("%f",x);
}
