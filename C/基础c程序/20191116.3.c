//��10��
#include <stdio.h>
main()
{
    char str[100]="abcd",str2[100]="efghijk";
    int i,j=4;
    printf ("����һΪ%s\n�����Ϊ%s\n",str,str2);
    for (i=0; i<10; i++)
        str[j++]=str2[i];
    printf ("���Ϊ%s",str);
}
