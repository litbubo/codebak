//��8��
#include <stdio.h>
main()
{
    char str[100];
    int i,j;
    printf("������Ҫ�������ַ�����\n");
    gets(str);
    for (i=0;i<100;i++)
        str[j++]=str[i];
    printf("����Ϊ%s",str);
}
