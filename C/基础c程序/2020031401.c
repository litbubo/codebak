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
    printf("ÇëÊäÈë×Ö·û´®£¬ÒÔ#½áÊø£º\n");
    print();
    return 0;
}
