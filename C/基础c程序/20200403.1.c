#include <stdio.h>
#define N 50
void main()
{
    int num[N];
    int i,j,count,temp;
    printf("请输入要输入的数字个数：\n");
    scanf("%d",&count);
    for(i=0; i<count; i++)
        scanf("%d",&num[i]);
    for(i=0; i<count-1; i++)
    {
        for(j=0; j<count-1-i; j++)
        {
            if(num[j]>num[j+1])
            {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
    for(i=0; i<count; i++)
        printf("%d ",num[i]);
}
