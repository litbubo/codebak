#include <stdio.h>
main()
{
    int x;
    int a[]={1,2,3,4,5,6,7,8};
    for(x=0;x<8;x++)
        printf("%d ",a[x]);
    int i,j=0;
    for(i=0;i<7;i++)
        if(a[i]%2!=0)
        {
            a[j++]=a[i];
        }
    printf("\n");
    printf("����������Ϊ:\n");
    for(i=0;i<j;i++)
    printf("%d ",a[i]);
    printf("\n");
    printf("����%d��������",j);
}
//����1
