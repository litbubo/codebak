//#include    <stdio.h>
#define N 20
void main()
{
    int m;
    int a[N];
    int i,t,j,n;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for(i=0; i<n; i++)
        printf("%d",a[i]);
}


