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
    printf ("���������Ҫ����ַ�����\n");
    gets(str);
    fun(str,str1);
    printf ("ȥ����β�Ǻź�Ľ��Ϊ��\n");
    puts(str1);
}
