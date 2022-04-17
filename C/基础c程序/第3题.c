#include <stdio.h>
#include <string.h>          //数组比较大小
#include <stdlib.h>          //清除屏幕
#define N 50
typedef struct violation     //定义结构体外号VIO
{
    char numb[N];            //编号
    char brand[N];           //车牌号
    char name[N];            //车主姓名
    char sex[N];             //性别
    char viol[N];            //违章情况
    char time[N];            //违章时间
    char place[N];           //地点
} VIO;

int count=0;                 //已存储的结构体数组数量
int i;                       //全局 用于循环
char ch;                     //全局

void input(VIO tra[]);       //1、录入
void deleted(VIO tra[]);     //2、删除
void modify(VIO tra[]);      //3、修改
void print(VIO tra[]);       //4、显示
void query(VIO tra[]);       //5、查询
void statistics(VIO tra[]);  //6、统计
void exits();                //7、退出

void fun0(VIO tra[]);        //按车牌号查询违章
void fun1(VIO tra[]);        //按车主姓名查询违章
void swit(VIO tra[]);        //选择功能
void back(VIO tra[]);        //返回主菜单
void menu();                 //菜单
int judge();                 //判断输入是否超限

void main()
{
    VIO tra[N];              //定义数组最大容量
    swit(tra);               //调用选择菜单
}

void swit(VIO tra[])         //选择菜单，根据数字进入相应功能
{
    system("cls");           //清空屏幕
    switch (judge())
    {
    case 1 :
        input(tra);
        break;
    case 2 :
        deleted(tra);
        break;
    case 3 :
        modify(tra);
        break;
    case 4 :
        print(tra);
        break;
    case 5 :
        query(tra);
        break;
    case 6 :
        statistics(tra);
        break;
    case 7 :
        exits();
        break;
    }
}

int judge()                  //判断输入是否符合规则
{
    int x;
    menu();
    printf ("请输入对应序号实现相关功能：");
    setbuf(stdin, NULL);     //清除键盘输入缓冲区
    scanf ("%d",&x);
    if (x<1||x>7)
    {
        system("cls");       //清空屏幕
        printf("\n****************输入错误，请重新输入****************\n");
        judge();             //若输入有误则重新调用函数
    }
    else
        return x;
}

void menu()                  //打印菜单
{
    printf ("\n");
    printf ("----------------车辆交通违章管理程序----------------\n\n");
    printf ("\t（1）录入违章信息。\n");
    printf ("\t（2）删除违章信息。\n");
    printf ("\t（3）修改已经录入的数据。\n");
    printf ("\t（4）显示所有违章的信息。\n");
    printf ("\t（5）查询。\n");
    printf ("\t（6）统计。\n");
    printf ("\t（7）退出程序。\n\n");
    printf ("----------------------------------------------------\n");
}

void back(VIO tra[])       //返回主菜单
{
    printf("\n输入任意字符返回主菜单：\n");
    setbuf(stdin, NULL);
    scanf("%c",&ch);
    if (1)
        swit(tra);
}

void input(VIO tra[])       //录入
{
    system("cls");
    printf ("\n您已选择录入功能。\n");
    printf("\n请输入由数字组成的6位编号：\n");
    setbuf(stdin, NULL);
    scanf("%s",&tra[count].numb);
    printf("请输入车牌号：\n");
    setbuf(stdin, NULL);
    scanf("%s",&tra[count].brand);
    printf("请输入车主姓名：\n");
    setbuf(stdin, NULL);
    scanf("%s",&tra[count].name);
    printf("请输入性别：\n");
    setbuf(stdin, NULL);
    scanf("%s",&tra[count].sex);
    printf("请输入违章情况：\n");
    setbuf(stdin, NULL);
    scanf("%s",&tra[count].viol);
    printf("请输入违章时间：\n");
    setbuf(stdin, NULL);
    scanf("%s",&tra[count].time);
    printf("请输入地点：\n");
    setbuf(stdin, NULL);
    scanf("%s",&tra[count].place);
    count++;
    printf("录入结束，输入B则返回主菜单，输入其他字符则继续录入：\n");
    setbuf(stdin, NULL);
    scanf("%c",&ch);
    switch(ch)
    {
    case 'B':
        swit(tra);
        break;
    default :
        input(tra);
        break;
    }
}

void deleted(VIO tra[])     //删除
{
    system("cls");
    printf ("\n您已选择删除功能。\n");
    if (count==0)            //判断是否有已存储的记录
    {
        printf("\n已存储的违章记录为空，无法删除。\n");
        back(tra);
    }
    else
    {
        int m=0,n=count;
        char bi[N];
        printf("\n请输入需要删除的违章编号：\n");
        setbuf(stdin, NULL);
        scanf("%s",bi);
        for (i=0; i<count; i++)                      //对每个违章记录进行循环
        {
            if (strcmp(tra[i].numb,bi)==0)           //判断违章编号是否相同
            {
                for (i=m; i<count; i++)              //将已删除违章记录后的记录向前移动
                    tra[i]=tra[i+1];
                count--;
                if (count<n)                         //删除后的违章记录少于删除前则删除成功
                    printf("删除成功。\n");
            }
            m++;
        }
        if (n==count)                                //删除后的违章记录等于删除前则未删除
            printf("未找到相应编号的违章记录。\n");
        printf("\n输入B则返回主菜单，输入其他字符则继续删除：\n");
        setbuf(stdin, NULL);
        scanf("%c",&ch);
        switch(ch)
        {
        case 'B':
            swit(tra);
            break;
        default :
            deleted(tra);
            break;
        }
    }

}

void modify(VIO tra[])      //修改
{
    system("cls");
    printf ("\n您已选择修改功能。\n");
    if (count==0)
    {
        printf("\n已存储的违章记录为空，无法修改。\n");
        back(tra);
    }
    else
    {
        char bi[N];
        int x,y=1;
        printf("\n请输入需要修改的违章编号：\n");
        setbuf(stdin, NULL);
        scanf("%s",bi);
        for (i=0; i<count; i++)
            if (strcmp(tra[i].numb,bi)==0)
            {
                printf("已显示编号“%s”的违章信息：\n\n",bi);
                printf("编号：      %s\n",&tra[i].numb);
                printf("车牌号：    %s\n",&tra[i].brand);
                printf("车主姓名：  %s\n",&tra[i].name);
                printf("性别：      %s\n",&tra[i].sex);
                printf("违章情况：  %s\n",&tra[i].viol);
                printf("违章时间：  %s\n",tra[i].time);
                printf("地点：      %s\n",&tra[i].place);
                printf("\n选择需要修改的信息:\n\n");
                printf("（1）编号 （2）车牌号 （3）车主姓名 （4）性别 （5）违章情况 （6）违章时间 （7）地点。");
                printf("（若输入超限，则需重新查找。）\n");
                setbuf(stdin, NULL);
                scanf("%d",&x);
                printf("请输入修改后的内容：\n");
                setbuf(stdin, NULL);
                switch(x)                                  //按输入数字修改相应内容
                {
                case 1:
                    scanf("%s",&tra[i].numb);
                    break;
                case 2:
                    scanf("%s",&tra[i].brand);
                    break;
                case 3:
                    scanf("%s",&tra[i].name);
                    break;
                case 4:
                    scanf("%s",&tra[i].sex);
                    break;
                case 5:
                    scanf("%s",&tra[i].viol);
                    break;
                case 6:
                    scanf("%s",&tra[i].time);
                    break;
                case 7:
                    scanf("%s",&tra[i].place);
                    break;
                default:
                    modify(tra);
                    break;
                }
                printf("修改成功！！\n");
                y=0;
            }
        if (y)
            printf("未找到相应编号的违章记录。\n");
        printf("\n输入B则返回主菜单，输入其他字符则继续修改：\n");
        setbuf(stdin, NULL);
        scanf("%c",&ch);
        switch(ch)
        {
        case 'B':
            swit(tra);
            break;
        default :
            modify(tra);
            break;
        }
    }

}

void print(VIO tra[])       //显示
{
    system("cls");
    printf ("\n您已选择显示所有违章功能。\n");
    if (count==0)
        printf("\n已存储的违章记录为空。\n");
    else
        for (i=0; i<count; i++)                        //对每个数组循环并逐个打印
               {
                printf("编号：      %s\n",&tra[i].numb);
                printf("车牌号：    %s\n",&tra[i].brand);
                printf("车主姓名：  %s\n",&tra[i].name);
                printf("性别：      %s\n",&tra[i].sex);
                printf("违章情况：  %s\n",&tra[i].viol);
                printf("违章时间：  %s\n",tra[i].time);
                printf("地点：      %s\n\n",&tra[i].place);
               }
    back(tra);
}

void query(VIO tra[])       //查询
{
    system("cls");
    printf ("\n您已选择查询功能。\n");
    if (count==0)
    {
        printf("\n已存储的违章记录为空。\n");
        back(tra);
    }
    else
    {
        printf("请输入您选择的查询方式：\n");
        printf("\n（a）按车牌号查找违章记录\n\n（b）按车主姓名查找违章记录");
        printf("（若输入超限，则需重新查找。）\n");
        char c;
        setbuf(stdin, NULL);
        scanf("%c",&c);
        switch(c)
        {
        case 'a':
            fun0(tra);
            break;
        case 'b':
            fun1(tra);
            break;
        default :
            query(tra);
            break;
        }
    }
}

void statistics(VIO tra[])  //统计
{
    system("cls");
    printf ("\n您已选择统计功能。\n");
    if (count==0)
    {
        printf("\n已存储的违章记录为空。\n");
        back(tra);
    }
    else
    {
        char date[N];
        int y=1;
        printf("\n请输入需要统计的日期（例：20201231）：\n");
        setbuf(stdin, NULL);
        scanf("%s",date);
        for (i=0; i<count; i++)
            if (strcmp(tra[i].time,date)==0)
            {
                printf("已显示日期为“%s”的违章信息：\n\n",date);
                printf("编号：      %s\n",&tra[i].numb);
                printf("车牌号：    %s\n",&tra[i].brand);
                printf("车主姓名：  %s\n",&tra[i].name);
                printf("性别：      %s\n",&tra[i].sex);
                printf("违章情况：  %s\n",&tra[i].viol);
                printf("违章时间：  %s\n",tra[i].time);
                printf("地点：      %s\n",&tra[i].place);
                y=0;
            }
        if (y)
            printf("未找到相应日期的违章记录。\n");
        printf("\n输入B则返回主菜单，输入其他字符则继续统计：\n");
        setbuf(stdin, NULL);
        scanf("%c",&ch);
        switch(ch)
        {
        case 'B':
            swit(tra);
            break;
        default :
            statistics(tra);
            break;
        }
    }
}

void exits()                 //退出
{
    printf("\n\n----------------------退出成功----------------------\n");
    printf("\n\n------------感谢使用车辆交通违章管理程序------------\n\n");
}

void fun0(VIO tra[])        //按车牌号查询违章
{
    char pai[N];
    int j=0,y=1;
    printf("\n请输入需要查询的违章车牌号：\n");
    setbuf(stdin, NULL);
    scanf("%s",pai);
    for (i=0; i<count; i++)
        if (strcmp(tra[i].brand,pai)==0)
        {
            printf("已显示车牌号为“%s”的违章信息：\n\n",pai);
            printf("编号：      %s\n",&tra[i].numb);
                printf("车牌号：    %s\n",&tra[i].brand);
                printf("车主姓名：  %s\n",&tra[i].name);
                printf("性别：      %s\n",&tra[i].sex);
                printf("违章情况：  %s\n",&tra[i].viol);
                printf("违章时间：  %s\n",tra[i].time);
                printf("地点：      %s\n",&tra[i].place);
            j++;                              //统计同一车牌号的违章次数
            y=0;
            if (j>5)
                printf("\n警告：已超过五次违章！！\n");
        }
    if (y)
        printf("未找到相应车牌号的违章记录。\n");
    printf("\n输入B则返回主菜单，输入其他字符则继续查询：\n");
    setbuf(stdin, NULL);
    scanf("%c",&ch);
    switch(ch)
    {
    case 'B':
        swit(tra);
        break;
    default :
        query(tra);
        break;
    }
}

void fun1(VIO tra[])        //按车主姓名查询违章
{
    char na[N];
    int y=1;
    printf("\n请输入需要查询的车主姓名：\n");
    setbuf(stdin, NULL);
    scanf("%s",na);
    for (i=0; i<count; i++)
        if (strcmp(tra[i].name,na)==0)
        {
            printf("已显示姓名为“%s”的违章信息：\n\n",na);
            printf("编号：      %s\n",&tra[i].numb);
                printf("车牌号：    %s\n",&tra[i].brand);
                printf("车主姓名：  %s\n",&tra[i].name);
                printf("性别：      %s\n",&tra[i].sex);
                printf("违章情况：  %s\n",&tra[i].viol);
                printf("违章时间：  %s\n",tra[i].time);
                printf("地点：      %s\n",&tra[i].place);
            y=0;
        }
    if (y)
        printf("未找到车主的违章记录。\n");
    printf("\n输入B则返回主菜单，输入其他字符则继续查询：\n");
    setbuf(stdin, NULL);
    scanf("%c",&ch);
    switch(ch)
    {
    case 'B':
        swit(tra);
        break;
    default :
        query(tra);
        break;
    }
}
