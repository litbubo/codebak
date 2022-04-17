
//10.9：客户姓名按字典顺序排序
#include <stdio.h>
#define N 10   //定义数组长度，注意，客户个数未必就是数组长度N
struct customer
{
    char name[10];
    char tel[11];//电话号码一般不用整型，用字符串还是好处多
};
void fun(struct customer *s,int n);
main()
{
    struct customer cus[N];
    int n;
    printf("请输入客户个数：");
    scanf("%d",&n);  //在这里输入客户个数n，应该n<=N
    fun(cus,n);
}
void fun(struct customer *s,int n)//s指向了主函数数组中的cus[0]
{
    int i=0,j;
    char ch;
    struct customer *p=s,t;
    getchar();//主函数有个scanf，回车结束，这个getchar是把这个回车吸收掉
    while(i<n)//n是客户个数，这个while是通过键盘输入客户信息
    {
        gets(p->name);
        gets(p->tel);
        p++;//p指向下一个元素
        i++;
    }
    for(i=0;i<n-1;i++)//选择排序，牢记
        for(j=i+1;j<n;j++)
            if(strcmp(s[i].name,s[j].name)>0)//一定要清楚为什么用strcmp，s[i].name>s[j].name可以不？
            {
                t=s[i];
                s[i]=s[j];
                s[j]=t;
            }
    printf("排序后的客户信息：\n");
    for(p=s;p<s+n;p++)
        printf("%s\t%s\n",p->name,p->tel);
}
