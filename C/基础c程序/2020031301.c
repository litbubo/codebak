#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<stdlib.h>

#include<string.h>



typedef struct People
{

    char name[20];

    char sex[4];

    int age;

    int tel[11];

    char add[20];

};

typedef struct List
{
    struct People Peo[1000];
    int count;
};



void menu()

{

    printf("            欢迎使用通讯录            \n");

    printf("**********1.添加联系人信息************\n");

    printf("********2.删除指定联系人信息**********\n");

    printf("********3.查找指定联系人信息**********\n");

    printf("********4.修改指定联系人信息**********\n");

    printf("********5.显示所有联系人信息**********\n");

    printf("**********6.清空联系人信息************\n");

    printf("******7.以名字排序所有联系人信********\n");

    printf("****** 0.退出当前通讯录系统 ********\n");

}


void add_peo(struct List *L)//添加联系人信息

{

    if (L->count > 1000)

    {

        printf("通讯录已满\n");

        return;

    }

    else

    {

        printf("请输入要添加的联系人姓名\n");

        scanf("%s", &L->Peo[L->count].name);

        printf("请输入要添加的联系人的性别\n");

        scanf("%s", &L->Peo[L->count].sex);

        printf("请输入要添加的联系人的年龄\n");

        scanf("%d", &L->Peo[L->count].age);

        printf("请输入要添加的联系人的手机号\n");

        scanf("%s", &L->Peo[L->count].tel);

        printf("请输入要添加的联系人的地址\n");

        scanf("%s", &L->Peo[L->count].add);

        L->count++;

        printf("联系人数据添加成功\n");



    }

}
int rearch(struct List *L, char *name)

{

    int ret = 0;

    int i = 0;

    for (; i < (L->count); i++)

    {

        if (strcmp(L->Peo[i].name, name) == 0)

            return i;

    }

    return -1;//没找到相同的名字



}
void del_peo(struct List *L)//删除指定联系人信息

{

    char name[20];

    int ret = 0;

    int i = 0;

    printf("请输入你想要删除的联系人的姓名\n");

    scanf("%s", &name);

    ret = rearch(L, name);

    if (ret == -1)

    {

        printf("想要删除的联系人不存在\n");



    }

    else

    {

        for (i = ret; i <= L->count; i++)

        {

            L->Peo[i] = L->Peo[i + 1];

        }

        printf("删除成功\n");

    }



}
void ser_peo(struct List *L)//查找指定联系人信息

{

    char name[20];

    int ret = 0;

    int i = 0;

    printf("请输入你想要删除的联系人的姓名\n");

    scanf("%s", &name);

    ret = rearch(L, name);

    if (ret == -1)

    {

        printf("您查找的联系人不存在\n");

    }

    else

    {

        printf("联系人姓名%s\n", L->Peo[ret].name);

        printf("联系人性别%s\n", L->Peo[ret].sex);

        printf("联系人年龄%d\n", L->Peo[ret].age);

        printf("联系人手机号%s\n", L->Peo[ret].tel);

        printf("联系人地址%s\n", L->Peo[ret].add);



    }

}
void mod_peo(struct List *L)//修改指定联系人信息

{

    char name[20];

    int ret = 0;

    int i = 0;

    printf("请输入你想要删除的联系人的姓名\n");

    scanf("%s", &name);

    ret = rearch(L, name);

    if (ret == -1)

    {

        printf("您查找的联系人不存在\n");

    }

    else

    {

        printf("请输入要添加的联系人姓名\n");

        scanf("%s", &L->Peo[ret].name);

        printf("请输入要添加的联系人的性别\n");

        scanf("%s", &L->Peo[ret].sex);

        printf("请输入要添加的联系人的年龄\n");

        scanf("%d", &L->Peo[ret].age);

        printf("请输入要添加的联系人的手机号\n");

        scanf("%s", &L->Peo[ret].tel);

        printf("请输入要添加的联系人的地址\n");

        scanf("%s", &L->Peo[ret].add);

        printf("联系人数据修改成功成功\n");

    }

}
void pri_peo(struct List *L)//显示所有联系人信息

{

    int i = 0;

    for (; i < L->count; i++)

    {

        printf("第%d个联系人信息：\n", i + 1);

        printf("联系人姓名%s\n", L->Peo[i].name);

        printf("联系人性别%s\n", L->Peo[i].sex);

        printf("联系人年龄%d\n", L->Peo[i].age);

        printf("联系人手机号%s\n", L->Peo[i].tel);

        printf("联系人地址%s\n", L->Peo[i].add);

        printf("\n");

    }

}
void emp_peo(struct List *L)//.清空联系人信息

{

    L->count = 0;

    return ;

}


void sort_peo(struct List *L)//以名字排序所有联系人信

{

    int m = 0;

    int n = 0;

    for (; m < L->count-1; m++)

    {

        n = m;

        for (; n < L->count-1-m; n++)

        {

            if (strcmp(L->Peo[n].name, L->Peo[n + 1].name))

            {

                struct People tmp;

                tmp = L->Peo[n];

                L->Peo[n] = L->Peo[n + 1];

                L->Peo[n + 1] = tmp;



            }

        }

    }

}
int main()

{

    struct List L;

    menu();

    int n = 0;

    printf("请选择您所要进行的操作\n");

    scanf("%d", &n);

    while (n)

    {



        switch (n)

        {

        case 0:

            return 0;

        case 1:

            add_peo(&L);

            break;

        case 2:

            del_peo(&L);

            break;

        case 3:

            ser_peo(&L);

            break;

        case 4:

            mod_peo(&L);

            break;

        case 5:

            pri_peo(&L);

            break;

        case 6:

            emp_peo(&L);

            break;

        case 7:

            sort_peo(&L);

            break;

        default:

            printf("输入参数错误\n");

        }

        printf("\n");

        menu();

        printf("请选择您所要进行的操作\n");

        scanf("%d", &n);



    }





}
