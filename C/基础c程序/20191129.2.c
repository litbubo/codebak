#include <stdio.h>
#include <stdlib.h>
/*
* 120Ã‚
*/
int main(int argc, char *argv[])
{
    int m,n,i,j,max,t,have=0;
    printf("Please input m and n:");
    scanf("%d%d",&m,&n);
    printf("Please input a juZheng(%d hang, %d lie):\n",m,n);
    int **arr=(int **)malloc(m*sizeof(int *));
    for(i=0; i<m; i++)
        arr[i]=(int *)malloc(n*sizeof(int));
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",*(arr+i)+j);
        }
    }
    for(i=0; i<m; i++)
    {
        max=arr[i][0];
        t=0;
        for(j=0; j<n; j++)
        {
            if(arr[i][j]>max)
            {
                max=arr[i][j];
                t=j;
            }
        }
        for(j=0; j<m; j++)
        {
            if(max>arr[j][t])
                break;
        }
        if(j==m)
        {
            have=1;
            break;
        }
    }
    printf("\nOutput:\n");
    if(have)
    {
        printf("you an dian, wei: juZhen[%d][%d]=%d\n",i,t,arr[i][t]);
    }
    else
        printf("mei you an dian.\n");
    return 0;
}
/*
31 42 1136 792 2358 88
32 57 4137 4333 47 1447
97 51 157 777 445 459
33 65 744 779 425 43
68 3425 2182 789 123 2134
*/
