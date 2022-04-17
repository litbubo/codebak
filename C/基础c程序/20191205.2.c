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
    printf ("请输入学生姓名和成绩：\n");
    for ( k=0;k<N;k++ )
    {
        printf ("第%d个学生姓名：",k+1);
        scanf ("%s",stu[k].name);
        printf ("高数，英语，C语言成绩：");
        scanf ("%f,%f,%f",&stu[k].ma,&stu[k].en,&stu[k].cp);
        fun(k);
    }
    printf ("请输入学生成绩：\n");
    printf ("姓名    高数     英语     C语言    平均成绩\n");
    for ( k=0;k<N;k++)
    {
        printf ("%s    %.2f     %.2f     %.2f     %.2f\n",stu[k].name,stu[k].ma,stu[k].en,stu[k].cp,stu[k].ave);
    }
}
