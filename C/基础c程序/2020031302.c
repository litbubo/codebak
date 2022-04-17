#include <stdio.h>
#include <stdlib.h>
#include<string.h>
static int i=0;
struct Person
{
    char name[20];
    char sex[20];
    char tel[20];
    char email[20];
    char relate[20];
} p[100];
void menu()
{
    system("cls");
    printf("\t\t**********小型通讯录菜单**********\n");
    printf("\t\t                                  \n");
    printf("\t\t           1.信息录入             \n");
    printf("\t\t                                  \n");
    printf("\t\t           2.信息修改             \n");
    printf("\t\t                                  \n");
    printf("\t\t           3.信息删除             \n");
    printf("\t\t                                  \n");
    printf("\t\t           4.信息查询             \n");
    printf("\t\t                                  \n");
    printf("\t\t           5.信息显示             \n");
    printf("\t\t                                  \n");
    printf("\t\t           6.退出程序             \n");
    printf("\t\t                                  \n");
    printf("\t\t**********************************\n");

}
void input()
{
    char c[2];
    printf("输入联系人信息\n");
    do
    {
        printf("姓名：");
        scanf("%s",&p[i].name);
        printf("性别: ");
        scanf("%s",&p[i].name);
        printf("电话：");
        scanf("%s",&p[i].tel);
        printf("email:");
        scanf("%s",&p[i].email);
        printf("关系:");
        scanf("%s",&p[i].relate);
        i++;
        printf("继续添加");
        scanf("%s",c);
    }
    while (!(strcmp(c,"a")));
}
void modify()
{
    int a,b;
    char name[50],sex[50],tel[50],email[50],relate[50];
    do
    {
        printf("输入你要修改的位次");
        scanf("%d",&a);
        scanf("%s,%s,%s,%s,%s",name,sex,tel,email,relate);
        strcpy(p[a-1].name,name);
        strcpy(p[a-1].sex,sex);
        strcpy(p[a-1].tel,tel);
        strcpy(p[a-1].email,email);
        strcpy(p[a-1].relate,relate);
        printf("请输入0结束，输入1继续!\n");
        scanf("%d",&b);
    }
    while(b!=0);
}
void del()
{
    int add;
    int w,k;
    int t=0;
    char name[20];
    printf("输入姓名");
    scanf("%s",&name);
    add=-1;
    for(w=0; w<i; w++)
    {
        if(strcmp(name,p[w].name)==0)
        {
            printf("以下是要删除的联系人：\n");
            printf("姓名：%s\n",p[w].name);
            printf("性别: %s\n",p[w].sex);
            printf("电话：%s\n",p[w].tel);
            printf("电子邮件：%s\n",p[w].email);
            printf("关系：%s\n",p[w].relate);
            add=w;
            t++;
            break;
        }
    }
    if (add==-1)
    {
        printf("无此人\n");
    }
    else
    {
        for(w=add; w<i; w++)
            p[w]=p[w+1];
    }
}

void find()

{
    int k;
    int num;
    char name[20];
    char sex[20];
    char relate[20];
    if(i=0)
    {
        printf("\n\t\t当前还没有联系人信息   ");
        printf("\n\n\t\t");
        system("cls");
        getchar();
        return;
    }
    printf("\n1.按姓名查找\n");
    printf("\n2.按性别查找\n");
    printf("\n3.按与本人的关系查找\n");
    printf("\n  请选择：\n");
    scanf("%d",&num);
    system("cls");
    switch (num)
    {
    case 1:
        printf("1.按姓名查找\n");
        printf("请输入姓名:");
        scanf("%s",&name);
        for(k=0; k<i; k++)
        {
            if(strcmp(p[k].name,name)==0)
            {
                printf("姓名： %s\n",p[k].name);
                printf("性别:  %s\n",p[k].sex);
                printf("电话： %s\n",p[k].tel);
                printf("E-mail： %s\n",p[k].email);
                printf("与本人关系： %s\n",p[k].relate);
            }
            else
                printf("\n\t您所输入的关系有误或不存在! ");
        }
    case 2:
        printf("2.按性别查找\n");
        printf("请输入性别");
        scanf("%s",&sex);
        for(k=0; k<i; k++)
        {
            if(strcmp(p[k].sex,sex)==0)
            {
                printf("姓名： %s\n",p[k].name);
                printf("性别:  %s\n",p[k].sex);
                printf("电话： %s\n",p[k].tel);
                printf("E-mail： %s\n",p[k].email);
                printf("与本人关系： %s\n",p[k].relate);
            }
            else
                printf("\n\t您所输入的关系有误或不存在! ");
        }
    case 3:
        printf("3.按与本人的关系查找\n");
        printf("请输入与本人的关系");
        scanf("%s",&relate);
        for(k=0; k<i; k++)
        {
            if(strcmp(p[k].relate,relate)==0)
            {
                printf("姓名： %s\n",p[k].name);
                printf("性别:  %s\n",p[k].sex);
                printf("电话： %s\n",p[k].tel);
                printf("E-mail： %s\n",p[k].email);
                printf("与本人关系： %s\n",p[k].relate);
            }
            else
                printf("\n\t您所输入的关系有误或不存在! ");
        }
    }
}
void show()
{
    int w;
    if(i=0)
    {
        printf("\n\t\t当前还没有联系人记录      ");
        printf("\n\n\t\t");
        system("cls");
        getchar();
        return;
    }
    printf("\n所有联系人记录如下: \n");
    for(w=0; w<i-1; w++)
    {
        printf("姓名： %s\n",p[w].name);
        printf("性别:  %s\n",p[w].sex);
        printf("电话： %s\n",p[w].tel);
        printf("E-mail： %s\n",p[w].email);
        printf("relate： %s\n",p[w].relate);
    }
}
void esc()
{
    printf("\n\n\t\t  退出系统!  \n");
    printf("\n\n\t\t感谢您使用本系统!\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
void main()
{
    while(1)
    {
        int num;
        menu();
        printf("请选择：\n");
        scanf("%d",&num);
        system("cls");
        switch (num)
        {
        case 1:
            input();
            break;
        case 2:
            modify();
            break;
        case 3:
            del();
            break;
        case 4:
            find();
            break;
        case 5:
            show();
            break;
        case 6:
            break;
        default:
            printf("\n\n\t\t 输入错误！请按任意键返回重新选择\n\n\t\t");
            system("pause");
            system("cls");
            getchar();
        }
    }
}
