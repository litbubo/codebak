#include <stdio.h>
#include <string.h>
struct kh
{
    char name[16];
    char tele[12];
};
void fun (struct kh *p ,int n);
main()
{
    struct kh per[50];
    int m,i;
    char c[2]="y";
    printf("请输入：\n");
    for ( m=0;strcmp(c,"y")==0;m++)
    {
        printf ("第%d个姓名和电话号码：",m+1);
        scanf ("%s%s",per[m].name,per[m].tele);
        printf ("\n继续输入请按y：");
        scanf ("%s",c);
    }
    fun(per,m);
    printf("输出客户姓名    电话号码：\n");
    for ( i=0; i<m; i++)
    {
        printf ("%s         %s\n",per[i].name,per[i].tele);
    }
}
void fun (struct kh *p ,int n)
{
    int i,j,k;
    struct kh temp;
    for (i=0; i<n ;i++)
    {
        k=i;
        for ( j=i+1; j<n; j++)
            if(strcmp(p[k].name,p[j].name)>0)
                k=j;
        temp=p[k];
        p[k]=p[i];
        p[i]=temp;
    }
}
