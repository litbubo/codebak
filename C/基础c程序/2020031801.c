#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fun(char *s,char t[ ] )
{
    int i,j=0,length;
    length=strlen(s);
    for(i=0; i<length; i++)
        if(i%2==1&&(int)(s[i])%2==1)
            t[j++]=s[i];
    t[j]=0;
}
main()
{
    char a[30],b[30];
    scanf("%s",a);
    fun(a,b);
    printf(b);
}
