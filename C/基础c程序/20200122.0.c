#include<stdio.h>
fun(char str1[],char str2[])
{
    int x,i=0;
    while(str1[i]!=0&&str2[i]!=0)
    {
        if(str1[i]==str2[i])
            x=0;
        else
            x=1;
        i++;
    }
    return x;
}
main()
{
    char str1[50],str2[50];
    int x;
    printf ("请输入字符串，按回车结束输入。\n");
    gets(str1);
    gets(str2);
    x=fun(str1,str2);
    printf ("两字符串的内容");
    switch(x)
    {
    case 1:
        printf("不同。");
        break;
    case 0:
        printf("相同。");
        break;
    }
}
