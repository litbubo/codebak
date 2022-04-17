#include<stdio.h>
#define N 10
main ()
{
    int i,k,j=0,sum=0;
    float a[N]= {90.5,85.3,89.5,94.0,62.5,77.5,69.0,88.0,96.0,86.5};
    float b[N];
    for(i=0; i<N; i++)
        sum+=a[i]/N;
    for(i=0; i<N; i++)
        if(a[i]>sum)
        {
            b[j]=a[i];
            j++;
        }
    printf("大于平均成绩的值为:\n");
    for(k=0; k<j; k++)
        printf("%f\n",b[k]);
}
