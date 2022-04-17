//10.8：本题平均分说的不清楚，可以是一个同学三门课的平均分，也可以是一门课的所有同学平均分，也可以是所有同学所有成绩的平均分，本题是第一种理解
#include <stdio.h>
#define N 10   //定义数组长度，注意，学生个数未必就是数组长度N
struct student
{
    int num;
    float math;
    float english;
    float c_language;
};

void fun(struct student *p,int n);//函数声明
main()
{
    struct student str[N];
    int n;
    printf("请输入学生个数：");
    scanf("%d",&n);  //在这里输入学生个数n，应该保证n<=N
    fun(str,n);     //注意：不是数组做实参，是数组名做实参，学生个数也做实参
}
void fun(struct student *p,int n)//p指向了主函数数组中的str[0]元素
{
    struct student *s;
    float ave=0;
    int i=0;//用来表示学生的编号
    s=p;
    while(s<p+n)//循环次数一定是学生的个数n
    {
        s->num=i++;//编号0给第0个元素的num成员
        printf("请输入第%d个学生成绩：\n",s->num+1);//+1是为了方便表述
        scanf("%f%f%f",&s->math,&s->english,&s->c_language);//成绩用空格分隔，回车结束当前输入
        ave=(s->math+s->english+s->c_language)/3.0;
        printf("该生的平均成绩为：%.2f\n",ave);
        ave=0;//为下一个同学的平均值清零
        s++;//s指向下一个元素
    }
}
