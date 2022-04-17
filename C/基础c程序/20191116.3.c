//第10题
#include <stdio.h>
main()
{
    char str[100]="abcd",str2[100]="efghijk";
    int i,j=4;
    printf ("数组一为%s\n数组二为%s\n",str,str2);
    for (i=0; i<10; i++)
        str[j++]=str2[i];
    printf ("组合为%s",str);
}
