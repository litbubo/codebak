//µÚ13Ìâ
#include <stdio.h>
main()
{
    char str[100]="****abcd**ef***gh*****";
    int n=0,p=0,x,i,j,k;
    while (str[p]!='\0')
        p++;
    x=p-1;
    while (str[n]=='*')
        n++;
    while (str[x]=='*')
        x--;
    for (i=n; i<=x ; i++)
        if (str[i]!='*')
            str[n++]=str[i];
    for (j=p-1; j>=x; j--)
        str[j-1]=str[j];
    for (k=p-1; k>=x+1 ; k--)
        str[k]='\0';
    printf("%s",str);
}
