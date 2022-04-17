#include <stdio.h>
#include <math.h>
double fun(int n);
main()
{
    int n;
    scanf("%d",&n);
    fun(n);
    printf("s=%f",fun(n));

}
double fun(int n)
{
    double sum=0,x;
    int i;
    for(i=1; i<=n; i++)
    {
        x=i*(i+1);
        sum+=(1.0/x);
    }
    return sum;
}
