#include <stdio.h>
main()
{
    printf("原始序列为：\n");
    int a[5]= {3,6,2,5,8};
    int i,x,y;
    for(y=0;y<5;y++)
        printf("%d ",a[y]);
    printf("\n");
    for(i=0; i<2; i++)
    {
        x=a[i];
        a[i]=a[4-i];
        a[4-i]=x;
    }
    printf("倒序为：\n");
    for(i=0; i<5; i++)
        printf("%d ",a[i]);
}
//数组2
