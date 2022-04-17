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
    printf ("请输入符合要求的字符串：\n");
    gets(str);
    fun(str,str1);
    printf ("去掉首尾星号后的结果为：\n");
    puts(str1);
}
