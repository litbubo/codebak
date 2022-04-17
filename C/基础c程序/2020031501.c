#include <stdio.h>
#include <string.h>          //数组比较大小
#include <stdlib.h>          //清除屏幕
#define N 100
typedef struct    worker    //定义结构体外号  wor
{
    char numb[N];            //员工编号
    char str[N];           //工龄
    char name[N];            //姓名
    char sex[N];             //性别
    char age[N];           //年龄
    char post[N];            //职务
    char dep[N];            //部门
    char add[N];           //住址
} wor;

int count=0;
int i;
char a;
int x=0;

void input(wor abc[]);       //1、录入职工信息
void deleted(wor abc[]);     //2、对职工信息的删除
void modify(wor abc[]);      //3、修改信息
void print(wor abc[]);       //4、显示职工信息
void query(wor abc[]);       //5、查询
void exits(wor abc[]);      //6、退出

void query1(wor abc[]);        //按姓名查找员工信息
void query2(wor abc[]);        //输入部门、性别，输出所有符合条件员工记录
void query3(wor abc[]);        //输入年龄范围，性别，输入所有符合条件员工记录
void query4(wor abc[]);        //输入部门，按工龄对所有符合条件员工记录排序输
void swit(wor abc[]);        //选择功能
void back(wor abc[]);        //返回主菜单
void menu();                 //菜单
int judge();                 //判断输入内容是否符合要求

void main()
{
    wor abc[N];              //定义数组最大容量
    swit(abc);               //调用菜单
}
int judge()
{
    menu();
    int b;
    printf ("请输入对应序号实现对应功能：");
    fflush(stdin);     //清除键盘输入缓冲区
    scanf("%d",&b);
    if(b<1||b>7)
    {
        system("cls");       //清空屏幕
        printf("\n****************输入错误，请重新输入****************\n");
        judge();             //若输入有误则重新调用函数
    }
    else
        return b;
}
void menu(wor abc[])      //主菜单
{
    printf(" \n");
    printf("   欢迎使用员工信息管理程序\n");
    printf("      (1)录入职工信息\n");
    printf("      (2)删除职工信息\n");
    printf("      (3)修改职工信息\n");
    printf("      (4)显示职工信息\n");
    printf("      (5)查询职工信息\n");
    printf("      (6)退出程序\n");
}
void back(wor abc[])       //返回主菜单
{
    printf("\n输入任意字符返回主菜单：\n");
    char a=getchar();
    if (1)
        swit(abc);
}
void exits(wor abc[])                 //退出
{
    printf("\n\n----------------------退出成功----------------------\n");
}
void swit(wor abc[])      //选择功能
{
    system("cls");           //清空屏幕
    printf("请输入数字以实现对应功能：\n");
    switch(judge())
    {
    case 1:
        input(abc);
        break;
    case 2:
        deleted(abc);
        break;
    case 3:
        modify(abc);
        break;
    case 4:
        print(abc);
        break;
    case 5:
        query(abc);
        break;
    case 6:
        exits(abc);
        break;
    }

}
void input(wor abc[])      //录入职工信息
{
    system("cls");         //清空屏幕
    printf("你已进入录入界面：\n");
    printf("请输入员工编号：\n");
    fflush(stdin);
    scanf("%s",&abc[count].numb);
    printf("请输入员工工龄：\n");
    scanf("%s",&abc[count].str);
    printf("请输入员工姓名：\n");
    scanf("%s",&abc[count].name);
    printf("请输入员工性别：\n");
    scanf("%s",&abc[count].sex);
    printf("请输入员工年龄：\n");
    scanf("%s",&abc[count].age);
    printf("请输入员工职务：\n");
    scanf("%s",&abc[count].post);
    printf("请输入员工部门：\n");
    scanf("%s",&abc[count].dep);
    printf("请输入员工住址：\n");
    scanf("%s",&abc[count].add);
    count++;
    printf("录入成功，输入0继续录入，输入任意字符返回主菜单\n");
    fflush(stdin);
    char a=getchar();
    if(a=='0')
        input(abc);
    else
        back(abc);
}
void deleted(wor abc[])       //删除职工信息
{
    system("cls");
    if(count==0)
    {
        printf("无职工信息，无法删除\n");
        back(abc);
    }
    else
    {
        char c[N];
        int m=0,n=count;
        printf("请输入要删除的职工编号：\n");
        fflush(stdin);
        gets(c);
        for (i=0; i<count; i++)                      //对每个员工信息进行循环
        {
            if (strcmp(abc[i].numb,c)==0)           //判断员工编号是否相同
            {
                for (i=0; i<count; i++)              //将其他的员工信息前移
                    abc[i]=abc[i+1];
                count--;
                if (count<n)                         //删除后少于删除前则删除成功
                    printf("删除成功\n");
            }
            m++;
            if(n==count)
                printf("未找到对应员工信息。");
            printf("输入0继续删除，输入其他字符返回主菜单。\n");
            char a=getchar();
            if(a=='0')
                deleted(abc);
            else
                back(abc);
        }

    }
}
void print(wor abc[])
{
    system("cls");
    if(count==0)
        printf("已录入信息为空。");
    else
        for(i=0; i<count; i++)
            printf("\n编号： %s\n工龄： %s\n姓名： %s\n性别： %s\n年龄： %s\n职务： %s\n部门： %s\n住址：%s\n\n",&abc[i].numb,&abc[i].str,&abc[i].name,&abc[i].sex,&abc[i].age,abc[i].post,&abc[i].dep,abc[i].add);
    printf("输入0返回主菜单。\n");
    fflush(stdin);
    char a=getchar();
    if(a=='0')
        back(abc);
}
void modify(wor abc[])
{
    system("cls");
    if(count==0)
    {
        printf("无职工信息，无法修改\n");
        back(abc);
    }
    else
    {
        char c[N];
        int m;
        printf("请输入要修改的职工编号：\n");
        fflush(stdin);
        gets(c);
        for (i=0; i<count; i++)                      //对每个员工信息进行循环
        {
            if (strcmp(abc[i].numb,c)==0)
            {
                printf("该员工信息如下：\n 编号： %s\n工龄： %s\n姓名： %s\n性别： %s\n年龄： %s\n职务： %s\n部门： %s\n住址：%s\n\n",&abc[i].numb,&abc[i].str,&abc[i].name,&abc[i].sex,&abc[i].age,abc[i].post,&abc[i].dep,abc[i].add);
                printf("请输入1-8以选择修改信息：\n");
                printf("(1)编号\n (2)工龄\n (3)姓名\n (4)性别\n (5)年龄\n (6)职务\n (7)部门\n (8)住址\n");
                fflush(stdin);
                scanf("%d",&m);
                fflush(stdin);
                switch(m)
                {
                case 1:
                    printf("请输入新的员工编号：\n");
                    scanf("%s",&abc[i].numb);
                    break;
                case 2:
                    printf("请输入新的员工工龄：\n");
                    scanf("%s",&abc[i].str);
                    break;
                case 3:
                    printf("请输入新的员工姓名：\n");
                    scanf("%s",&abc[i].name);
                    break;
                case 4:
                    printf("请输入新的员工性别：\n");
                    scanf("%s",&abc[i].sex);
                    break;
                case 5:
                    printf("请输入新的员工年龄：\n");
                    scanf("%s",&abc[i].age);
                    break;
                case 6:
                    printf("请输入新的员工职务：\n");
                    scanf("%s",&abc[i].post);
                    break;
                case 7:
                    printf("请输入新的员工部门：\n");
                    scanf("%s",&abc[i].dep);
                    break;
                case 8:
                    printf("请输入新的员工住址：\n");
                    scanf("%s",&abc[i].add);
                    break;
                }
                printf("修改成功，输入0继续修改，输入任意字符返回主菜单\n");
            }
            char a=getchar();
            if(a=='0')
                modify(abc);
            else
                back(abc);
        }
    }
}
void query(wor abc[])       //查询
{
    system("cls");
    printf ("\n您已选择查询功能。\n");
    if (count==0)
    {
        printf("\n无职工信息。\n");
        back(abc);
    }
    else
    {
        printf("请选择查询方式：\n");
        printf("\n（a）按姓名查找员工信息\n\n（b）输入部门、性别，输出所有符合条件员工记录\n\n(c)输入年龄范围，性别，输入所有符合条件员工记录\n\n(d)输入部门，按工龄对所有符合条件员工记录排序输出\n");
        char c;
        fflush(stdin);
        scanf("%c",&c);
        switch(c)
        {
        case 'a':
            query1(abc);
            break;
        case 'b':
            query2(abc);
            break;
        case 'c':
            query3(abc);
            break;
        case 'd':
            query4(abc);
            break;
        default :
            query(abc);
            break;
        }
    }
}
void query1(wor abc[])       //按姓名查找员工信息
{
    char c[N];
    printf("\n请输入需要查询的员工姓名：\n");
    fflush(stdin);
    gets(c);
    for (i=0; i<count; i++)
        if (strcmp(abc[i].name,c)==0)
        {
            printf("已显示姓名为“%s”的信息：\n\n",c);
            printf("该员工信息如下：\n 编号： %s\n工龄： %s\n姓名： %s\n性别： %s\n年龄： %s\n职务： %s\n部门： %s\n住址：%s\n\n",&abc[i].numb,&abc[i].str,&abc[i].name,&abc[i].sex,&abc[i].age,abc[i].post,&abc[i].dep,abc[i].add);
            x++;
        }
    if (x==0)
            printf("未找到相应的员工信息。\n");
    printf("\n输入0则继续查询，输入其他字符则返回主菜单：\n");
    fflush(stdin);
    char a=getchar();
    if(a=='0')
        query1(abc);
    else
        back(abc);
}
void query2(wor abc[])        //输入部门、性别，输出所有符合条件员工记录
{
    system("cls");
    char c[N];                //部门
    char d[N];                //性别
    printf("\n请输入部门、性别：\n");
    fflush(stdin);
    scanf("%s%s",&c,&d);
    for (i=0; i<count; i++)
        if (strcmp(abc[i].dep,c)==0&&strcmp(abc[i].sex,d)==0)
        {
            printf("已显示部门、性别为“%s%s”的员工信息：\n\n",c,d);
            printf("该员工信息如下：\n 编号： %s\n工龄： %s\n姓名： %s\n性别： %s\n年龄： %s\n职务： %s\n部门： %s\n住址：%s\n\n",&abc[i].numb,&abc[i].str,&abc[i].name,&abc[i].sex,&abc[i].age,abc[i].post,&abc[i].dep,abc[i].add);
            x++;
        }
    if (x==0)
            printf("未找到相应的员工信息。\n");
    printf("\n输入0则继续查询，输入其他字符则返回主菜单：\n");
    fflush(stdin);
    char a=getchar();
    if(a=='0')
        query2(abc);
    else
        back(abc);
}
void query3(wor abc[])        //输入年龄范围，性别，输入所有符合条件员工记录
{
    system("cls");
    int j;
    char c[N];                //年龄上限
    char d[N];                //年龄下限
    char e[N];                //性别
    printf("\n请输入年龄上限、年龄下限、性别：\n");
    fflush(stdin);
    scanf("%s%s%s",&c,&d,&e);
    for (i=0; i<count; i++)
        for(j=0; j<N; j++)
            if (strcmp(abc[i].age,c)<=0&&strcmp(abc[i].age,d)>=0&&strcmp(abc[i].sex,e)==0)
            {
                printf("已显示年龄上限、年龄下限、性别为“%s%s%s”的员工信息：\n\n",c,d,e);
                printf("该员工信息如下：\n 编号： %s\n工龄： %s\n姓名： %s\n性别： %s\n年龄： %s\n职务： %s\n部门： %s\n住址：%s\n\n",&abc[i].numb,&abc[i].str,&abc[i].name,&abc[i].sex,&abc[i].age,abc[i].post,&abc[i].dep,abc[i].add);
                x++;
            }
    if (x==0)
            printf("未找到相应的员工信息。\n");
    printf("\n输入0则继续查询，输入其他字符则返回主菜单：\n");
    fflush(stdin);
    char a=getchar();
    if(a=='0')
        query3(abc);
    else
        back(abc);
}
void query4(wor abc[])       //输入部门，按工龄对所有符合条件员工记录排序输
{
    system("cls");
    char c[N];
    int j,m,t;
    printf("\n请输入部门：\n");
    fflush(stdin);
    scanf("%s",&c);
    for (i=0; i<count; i++)
        if(strcmp(abc[i].dep,c)==0)
        {
            for(j=0; j<N-1; j++)
                for(m=0; m<N-j; m++)
                {
                    if(abc[count].str[m]<abc[count].str[m+1])                       //比较大小并交换
                    {
                        t=abc[count].str[m];
                        abc[count].str[m]=abc[count].str[m+1];
                        abc[count].str[m+1]=t;
                    }
                }
        printf("已显示部门为“%s”的员工信息：\n\n",c);
        printf("该员工信息如下：\n 编号： %s\n工龄： %s\n姓名： %s\n性别： %s\n年龄： %s\n职务： %s\n部门： %s\n住址：%s\n\n",&abc[i].numb,&abc[i].str,&abc[i].name,&abc[i].sex,&abc[i].age,abc[i].post,&abc[i].dep,abc[i].add);
        x++;
        }
    if (x==0)
            printf("未找到相应的员工信息。\n");
    printf("\n输入0则继续查询，输入其他字符则返回主菜单：\n");
    fflush(stdin);
    char a=getchar();
    if(a=='0')
        query4(abc);
    else
        back(abc);
}
