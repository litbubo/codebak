#include<stdio.h>
fun(char *p,char *q)
{
    while(*p=='*')
        p++;
    while(*p)
        *q++=*p++;
    q--;
    while(*q=='*')
        q--;
    *(++q)=0;
}
main()
{
    char str[50],str1[50];
    printf ("���������Ҫ����ַ�����\n");
    gets(str);
    fun(str,str1);
    printf ("ȥ����β�Ǻź�Ľ��Ϊ��\n");
    puts(str1);
}
