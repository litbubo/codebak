#include <stdio.h>
float fun(float x,int n)
{
    int p,q,i;
    float t,sum,m=0.0;
    sum=1.0;
    q=p=1;
    t=0.0;
    for(i=0; i<n; i++)
    {
        sum*=x;
        q*=p;
        m=sum/q;
        p++;
        t+=m;
    }
    return t;
}
main()
{
    int n;
    float s,x;
    printf("ÊäÈëx,nÖµ\n");
    scanf("%f%d",&x,&n);
    s=1+fun(x,n);
    printf("%.6f",s);
}
