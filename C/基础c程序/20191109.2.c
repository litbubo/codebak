#include<stdio.h>
main()
{
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4-1-i; j++)
            printf(" ");
        for(j=0; j<i+i+1; j++)
            printf("*");
        printf("\n");
    }
    for(i=2; i>=0; i--)
    {
        for(j=0; j<4-1-i; j++)
            printf(" ");
        for(j=0; j<i+i+1; j++)
            printf("*");
        printf("\n");
    }
}
//ÐÇºÅÍ¼2
