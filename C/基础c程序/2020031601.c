#include<stdio.h>
void fun(char *p,char *q)
{
    int i=0;
    while(*p)
    {
        if(*p!='*')
            *q++=*p;
        p++;
    }
    p--;
    while(*p=='*')
    {
        p--;
        i++;
    }
    while(i)
    {
        *q++='*';
        i--;
    }
    *q=0;
}
void main()
{
    char str[50],str1[50];
    printf ("请输入符合要求的字符串：\n");
    gets(str);
    fun(str,str1);
    printf ("去掉首尾星号后的结果为：\n");
    puts(str1);
}
