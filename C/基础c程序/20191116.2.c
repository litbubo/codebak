//µÚ9Ìâ
#include <stdio.h>
main()
{
    char str[30];
    int i=0;
    gets(str);
    while (str[i]!='\0')
        i++;
    printf("%d",i);
}
