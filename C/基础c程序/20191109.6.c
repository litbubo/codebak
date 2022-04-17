#include <stdio.h>
main()
{
    int a[10]= {46,30,32,40,6,17,45,15,48,26};
    int b[10];
    int i,j=0,sum=0,average,x=9;
    printf("原序列为：\n");
    for(i=0; i<10; i++)
    {
        printf("%d ",a[i]);
        sum+=a[i];
    }
    printf("\n");
    printf("调整为：\n");
    average=sum/10;
    for(i=0; i<10; i++)
        if(a[i]<=average)
            b[j++]=a[i];
        else
            b[x--]=a[i];
    for(i=0; i<10; i++)
        printf("%d ",b[i]);
}
//数组4
