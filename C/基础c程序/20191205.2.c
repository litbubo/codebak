#include <stdio.h>
#define N 5
struct score
{   char name[12];
    float ma;
    float en;
    float cp;
    float ave;
};
float fun (int k)
{

    float x;
    struct score stu[k];
    stu[k].ave=(stu[k].ma+stu[k].en+stu[k].cp)/3;
    x=stu[k].ave;
    return x;
}
main()
{
    int k;
    struct score stu[N];
    printf ("������ѧ�������ͳɼ���\n");
    for ( k=0;k<N;k++ )
    {
        printf ("��%d��ѧ��������",k+1);
        scanf ("%s",stu[k].name);
        printf ("������Ӣ�C���Գɼ���");
        scanf ("%f,%f,%f",&stu[k].ma,&stu[k].en,&stu[k].cp);
        fun(k);
    }
    printf ("������ѧ���ɼ���\n");
    printf ("����    ����     Ӣ��     C����    ƽ���ɼ�\n");
    for ( k=0;k<N;k++)
    {
        printf ("%s    %.2f     %.2f     %.2f     %.2f\n",stu[k].name,stu[k].ma,stu[k].en,stu[k].cp,stu[k].ave);
    }
}
