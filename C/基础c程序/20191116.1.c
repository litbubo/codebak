//第8题
#include <stdio.h>
main()
{
    char str[100];
    int i,j;
    printf("输入需要拷贝的字符串：\n");
    gets(str);
    for (i=0;i<100;i++)
        str[j++]=str[i];
    printf("拷贝为%s",str);
}
