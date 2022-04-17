#include <stdio.h>
main()
{
    float a[10],b[10],sum,average;
    int i,j=0;
    printf("请输入10位同学的成绩：\n");
    for(i=0; i<10; i++)
    {
        scanf("%f",&a[i]);
        sum+=a[i];
    }
    average=sum/10;
    for(i=0; i<10; i++)
    {
        if(a[i]>average)
            b[j++]=a[i];
    }
    printf("已输入的成绩为:\n");
    for(i=0; i<10; i++)
        printf("%.2f  ",a[i]);
    printf("\n");
    printf("平均分为%.2f\n",average);
    printf("大于平均分的成绩为:\n");
    for(i=0; i<j; i++)
        printf("%.2f  ",b[i]);
}
//数组3
