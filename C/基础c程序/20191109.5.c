#include <stdio.h>
main()
{
    float a[10],b[10],sum,average;
    int i,j=0;
    printf("������10λͬѧ�ĳɼ���\n");
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
    printf("������ĳɼ�Ϊ:\n");
    for(i=0; i<10; i++)
        printf("%.2f  ",a[i]);
    printf("\n");
    printf("ƽ����Ϊ%.2f\n",average);
    printf("����ƽ���ֵĳɼ�Ϊ:\n");
    for(i=0; i<j; i++)
        printf("%.2f  ",b[i]);
}
//����3
