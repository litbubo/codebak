#include <stdio.h>
#include <string.h>

void fun(char  *s, char  t[])
{
    int i=0,j=0;
    while (s[i] != '\0')
    {
        if (i % 2 == 1&&s[i] % 2 == 1)
            t[j++] = s[i];
        i++;
    }
    t[j] = 0;
}

void main()
{
    char a[30],b[30];
    scanf("%s",a);
    fun(a,b);
    printf("жпнд");
}
