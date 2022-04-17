#include <stdio.h>

void main()
{
    float d1,f1,h,d2,f2;
    scanf("%f%f%f%f%f",&d1,&f1,&h,&d2,&f2);
    float x,y;
    x=(d1*f1)+h;
    y=d2*f2;
    if(x<y)
        printf("highway");
    else
        printf("no");
}
