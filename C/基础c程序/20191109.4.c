#include <stdio.h>
main()
{
    printf("ԭʼ����Ϊ��\n");
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
    printf("����Ϊ��\n");
    for(i=0; i<5; i++)
        printf("%d ",a[i]);
}
//����2
