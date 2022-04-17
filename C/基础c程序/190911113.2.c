//第12题
#include <stdio.h>
main()
{
    int i=0,j;
    char str[100]={"****abcd**ef***gh*****"};
    printf("%s\n",str);
    while(str[i]!='\0')
        i++;
    for(j=i-1;str[j]=='*'; j--)
        str[j]='\0';
    printf("删除*号后的字符串为\n");
    printf("%s\n", str);
}
