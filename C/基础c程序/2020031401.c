#include <stdio.h>
#include <stdlib.h>

void print()
{
    char c;
    scanf("%c",&c);
    if(c != '#')
        print();
    if(c != '#')
        printf("%c",c);
    printf("66666");
}
int main()
{
    printf("�������ַ�������#������\n");
    print();
    return 0;
}
