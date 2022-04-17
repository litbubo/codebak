#include <stdio.h>
main()
{
    int i,j,x;
    for(i=0; i<4; i++)
    {
        for(j=0; j<3-i; j++)
            printf(" ");
        for(x=0; x<i+1; x++)
            printf("*");
        printf("\n");
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<i+1; j++)
            printf(" ");
        for(x=0; x<3-i; x++)
            printf("*");
        printf("\n");
    }
}
//ÐÇºÅÍ¼3
