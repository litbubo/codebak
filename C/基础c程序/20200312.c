#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30
#define MIN 15
typedef struct
{
    char Name[MIN]={'\0'};    //姓名
    char Sex[MIN]={'\0'};       //性别
    char City[MIN]={'\0'};       //城市
    char PostCode[MIN]={'\0'};      //邮编
    char PhoneNumber[MIN]={'\0'};      //手机号
    char QQ[MIN]={'\0'};          //QQ号
    char Email[MAX]={'\0'};   //邮箱
} ConType;
typedef struct node
{
    ConType data;         //存放联系人信息
    struct node *next;        //指向下一个节点的指针
} ConList;       //联系人单链表节点类型

void ModifyCon(ConList *L);
void ReadFile(ConList *&L);
void SaveFile(ConList *L);
void InputCon(ConList *&L);
void DeleteCon(ConList *&L);
void DisplayCon(ConList *&L);
void LocateCon(ConList *L);
void DestroyCon(ConList *&L);
ConList *LocateAll(ConList *L, int select, char s[MAX]);
void DispCon(ConType con);
void ItemModifyCom(ConList *L, int item);
void DeleteOne(ConList *&L);
void DeleteAll(ConList *&L);

void ModifyCon(ConList *L)     //修改联系人信息
{
    system("cls");
    ConList *p;
    ConType con;
    char s[MIN] = {'\0'};      //接收选择
    char search[MIN] = {'\0'};     //输入要查找的联系人
    int item = 9;     //选择修改联系人项目
    int select;      //接收选择
    int i = 0;
    while (i < 100)
    {
        system("cls");
        printf("\t       修改\n");
        printf("\t******************** \n");
        printf("\t☆ 按姓名查找请按1\n");
        printf("\t☆ 按手机号查找请按2\n");
        printf("\t☆ 按QQ号查找请按3\n");
        printf("\t☆ 按Email查找请按4\n");
        printf("\t☆ 退出请按0\n");
        printf("\t********************\n");
        printf("\n>>请输入你的选择：");
        scanf("%s", &s);         //接收选择
        select = (int)s[0] - 48;       //接收选择
        p = (ConList *)malloc(sizeof(ConList));
        switch (select)
        {
        case 1:
            //按姓名查找
            printf("\n>>请输入待修改人的姓名：");
            scanf("%s", search);
            p = LocateAll(L, 1, search);      //返回所查找的姓名所在链表指针
            if (p == NULL)
            {
                printf("\n提示：无此联系人！请重新查找\n\n");
                system("pause");
            }
            else
            {
                DispCon(p->data);
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n可供修改的条目如下：\n");
                printf("\t1. 姓名");
                printf("\t\t2. 性别\n");
                printf("\t3. 城市");
                printf("\t\t4. 邮编\n");
                printf("\t5. 手机号");
                printf("\t6. QQ号\n");
                printf("\t7. Email");
                printf("\t0. 退出\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                while (1)
                {
                    printf("\n\n>>请选择需要修改的内容：");
                    scanf("%d", &item);
                    if (item == 0)
                        break;
                    ItemModifyCom(p, item);
                }
            }
            break;        case 2:
            //按手机号查找
            printf(">>请输入待修改人的手机号：");
            scanf("%s", search);
            p = LocateAll(L, 1, search);
            if (p == NULL)
            {
                printf("提示：无此联系人！请重新查找\n");
                system("pause");
            }
            else
            {
                DispCon(p->data);
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n可供修改的条目如下：\n");
                printf("\t1. 姓名");
                printf("\t\t2. 性别\n");
                printf("\t3. 城市");
                printf("\t\t4. 邮编\n");
                printf("\t5. 手机号");
                printf("\t6. QQ号\n");
                printf("\t7. Email");
                printf("\t0. 退出\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                while (1)
                {
                    printf("\n\n>>请选择需要修改的内容：");
                    scanf("%d", &item);
                    if (item == 0)
                        break;
                    ItemModifyCom(p, item);
                }
            }
            break;
        case 3:
            //按QQ号查找
            printf(">>请输入待修改人的QQ号：");
            scanf("%s", search);
            p = LocateAll(L, 1, search);
            if (p == NULL)
            {
                printf("提示：无此联系人！请重新查找\n");
                system("pause");
            }
            else
            {
                DispCon(p->data);
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n可供修改的条目如下：\n");
                printf("\t1. 姓名");
                printf("\t\t2. 性别\n");
                printf("\t3. 城市");
                printf("\t\t4. 邮编\n");
                printf("\t5. 手机号");
                printf("\t6. QQ号\n");
                printf("\t7. Email");
                printf("\t0. 退出\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                while (1)
                {
                    printf("\n\n>>请选择需要修改的内容：");
                    scanf("%d", &item);
                    if (item == 0)
                        break;
                    ItemModifyCom(p, item);
                }
            }
            break;
        case 4:
            //按Email查找
            printf("输入Email：");
            scanf("%s", search);
            p = LocateAll(L, 1, search);
            if (p == NULL)
            {
                printf("提示：无此联系人！请重新查找\n");
                system("pause");
            }
            else
            {
                DispCon(p->data);
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n可供修改的条目如下：\n");
                printf("\t1. 姓名");
                printf("\t\t2. 性别\n");
                printf("\t3. 城市");
                printf("\t\t4. 邮编\n");
                printf("\t5. 手机号");
                printf("\t6. QQ号\n");
                printf("\t7. Email");
                printf("\t0. 退出\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                while (1)
                {
                    printf("\n\n>>请选择需要修改的内容：");
                    scanf("%d", &item);
                    if (item == 0)
                        break;
                    ItemModifyCom(p, item);
                }
            }
            break;        case 0:
            //0
            return;
        default:
            printf("\n提示：输入错误，请重新输入！\n\n");
            system("pause");
            break;
        }
        ++i;
    }
}

void ReadFile(ConList *&L)       //读取文件，建立联系人单链表L
{
    FILE *fp;
    ConType con;
    ConList *p, *r;
    int n = 0;
    L = (ConList *)malloc(sizeof(ConList));       //建立头结点
    r = L;
    if ((fp = fopen("contacts.txt", "rb")) == NULL)       //不存在contacts.txt文件
    {
        if ((fp = fopen("contacts.txt", "wb")) == NULL)
            printf("  提示：不能创建contacts.txt文件\n");
        printf("失败");
    }
    else      //若存在contacts.txt文件
    {
        fseek(fp, 0, SEEK_SET);
        while (fread(&con, sizeof(ConType), 1, fp) == 1)
        { //采用尾插法建立单链表L
            p = (ConList *)malloc(sizeof(ConList));
            p->data = con;
            r->next = p;
            r = p;
            n++;
        }
    }
    r->next = NULL;
    printf("提示：通讯录中共有%d个联系人\n", n);
    fclose(fp);
}

void SaveFile(ConList *L)     //保存文件
{
    ConList *p = L->next;
    int n = 0;
    FILE *fp;
    if ((fp = fopen("contacts.txt", "wb")) == NULL)
    {
        printf("  提示：不能创建文件contacts.txt\n");
        return;
    }
    fseek(fp,0, SEEK_END);
    while (p != NULL)
    {
        fwrite(&p->data, sizeof(ConType), 1, fp);
        p = p->next;
        n++;
    }
    fclose(fp);
    DestroyCon(L);      //释放联系人单链表L
    if (n > 0)
        printf("提示：成功添加%d个联系人\n", n);
    else
        printf("提示：没有添加任何联系人\n");
}

void InputCon(ConList *&L)       //添加一个联系人
{
    system("cls");
    ConType p;
    ConList *s;
    printf("\t          添加\n");
    printf("\t************************\n");
    printf("\t      ☆ 返回请输入0\n");
    printf("\t************************\n\n");
    printf(">>输入姓名：");
    scanf("%s", &p.Name);
    if (strcmp(p.Name, "0") == 0)
        return;
    printf(">>输入性别：");
    scanf("%s", &p.Sex);
    printf(">>输入城市：");
    scanf("%s", &p.City);
    printf(">>输入邮编：");
    scanf("%s", &p.PostCode);
    printf(">>输入手机号：");
    scanf("%s", &p.PhoneNumber);
    printf(">>输入QQ：");
    scanf("%s", &p.QQ);
    printf(">>输入Email：");
    scanf("%s", &p.Email);
    s = (ConList *)malloc(sizeof(ConList));
    s->data = p;
    s->next = L->next;      //采用头插法插入节点s
    L->next = s;
    printf("\n提示：添加成功\n\n");
    system("pause");
}

void DeleteCon(ConList *&L)       //删除联系人
{
    system("cls");
    int selection;
    while (1)
    {
        printf("\t          删除\n");
        printf("\t************************\n");
        printf("\t☆ 删除某一个联系人请按1\n");
        printf("\t☆ 删除全部联系人请按2\n");
        printf("\t☆ 返回请按0\n");
        printf("\t************************\n\n");
        printf(">>请输入你的选择：");
        scanf("%d", &selection);
        switch (selection)
        {
        case 0:
            return;
        case 1:
            DeleteOne(L);
            break;
        case 2:
            DeleteAll(L);
            break;
        default:
            printf("  提示：输入有误，请重新输入");
        }
    }
}

void DisplayCon(ConList *&L)       //浏览通讯录中所有联系人的信息
{
    system("cls");
    printf("\t\t\t\t          浏览\n");
    printf("\t\t\t\t************************\n");
    printf("\t\t\t\t    ☆ 返回请按任意键\n");
    printf("\t\t\t\t************************\n\n");
    ConList *p = L->next;
    if (p == NULL)
        printf("  提示：通讯录中没有任何联系人\n");
    else
    {
        printf("\n\t姓名\t性别\t城市\t邮编\t手机号\t\tQQ号\t\tEmail\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        while (p != NULL)
        {
            printf("\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", p->data.Name, p->data.Sex, p->data.City, p->data.PostCode, p->data .PhoneNumber
    , p->data.QQ, p->data.Email);
            p = p->next;
        }
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    }
}

void LocateCon(ConList *L)      //通过姓名和手机号查找联系人
{
    system("cls");
    ConList *p;
    char s[MAX] = {'\0'};
    char select[MAX] = {'\0'};
    p = (ConList *)malloc(sizeof(ConList));
    printf("\t            查询\n");
    printf("\t**************************\n");
    printf("\t☆ 按姓名查询请按1\n\t☆ 按电话号码查询请按2\n\t☆ 退出请按0\n ");
    printf("\t**************************\n");
    while (1)
    {
        printf("\n>>请输入查找方式：");
        scanf("%s", select);
        int t = (int)select[0];
        if (t - 48 == 1) //姓名查找
        {
            printf("\n>>请输入要查找的姓名：");
            scanf("%s", s, MAX);
            p = LocateAll(L, 1, s);       //1对应LocateAll中的姓名查找
            if (p != NULL)
            {
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~");
                DispCon(p->data); //输出查找的联系人信息
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            }
            else
            {
                printf("\n提示：所查找姓名的联系人不存在！ 将返回重新选择查找方式\n");
            }
        }
        else if (t - 48 == 2) //手机号码查找
        {
            printf("\n>>请输入要查找的手机号：");
            scanf("%s", s);
            p = LocateAll(L, 5, s);       //5对应LocateAll中的手机号查找
            if (p != NULL)
            {
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~");
                DispCon(p->data); //输出查找的联系人信息
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            }            else
            {
                printf("所查找号码的联系人不存在！ 将返回重新选择查找方式\n");
            }
        }
        else if (t - 48 == 0)
        {
            printf("已0查找！");
            return;
        }
        else
        {
            printf("输入错误，请重新输入！\n");
        }
    }
}

void DestroyCon(ConList *&L)       //释放联系人单链表L
{
    ConList *pre = L, *p = pre->next;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

ConList *LocateAll(ConList *L, int select, char s[MAX])       //提供全部查找功能
{
    ConType con;
    ConList *p;
    p = L->next;
    if (p == NULL)
    {
        return NULL;
    }
    switch (select)
    {
    case 1:
        //按姓名查找
        while (p != NULL && (strcmp(p->data.Name, s)) != 0)
        {
            p = p->next;
        }
        if (p == NULL)
            return NULL;
        else
            return p;
    case 2:
        //按性别查找
        while (p != NULL && strcmp(p->data.Sex, s) != 0)
        {
            p = p->next;
        }
        if (p == NULL)
            return NULL;
        else
            return p;
    case 3:
        //按城市查找
        while (p != NULL && strcmp(p->data.City, s) != 0)
        {
            p = p->next;
        }
        if (p == NULL)
            return NULL;
        else
            return p;
    case 4:
        //按邮编查找
        while (p != NULL && strcmp(p->data.PostCode, s) != 0)
        {
            p = p->next;
        }
        if (p == NULL)
            return NULL;
        else
            return p;
    case 5:
        //按手机号查找
        while (p != NULL && strcmp(p->data.PhoneNumber, s) != 0)
        {
            p = p->next;
        }
        if (p == NULL)
            return NULL;
        else
            return p;
    case 6:
        //按QQ号查找
        while (p != NULL && strcmp(p->data.QQ, s) != 0)
        {
            p = p->next;
        }
        if (p == NULL)
            return NULL;
        else
            return p;    case 7:
        //按Email查找
        while (p != NULL && strcmp(p->data.Email, s) != 0)
        {
            p = p->next;
        }
        if (p == NULL)
            return NULL;
        else
            return p;
    }
}

void DispCon(ConType con)      //输出联系人信息
{
    printf("\n姓名：%s", con.Name);
    printf("\n性别：%s", con.Sex);
    printf("\n城市：%s", con.City);
    printf("\n邮编：%s", con.PostCode);
    printf("\n手机号：%s", con.PhoneNumber);
    printf("\nQQ：%s", con.QQ);
    printf("\nEmail：%s\n", con.Email);
}

void ItemModifyCom(ConList *L, int item)      //单个联系人信息条目修改
{
    ConList *p;
    ConType con;
    p = L;
    while (1)
    {
        switch (item)
        {
        case 0:
            printf("已退出修改！\n");
            system("pause");
            return;
        case 1:
            con = p->data;
            *con.Name = {'\0'};
            printf("\n姓名修改为：");
            scanf("%s", con.Name);
            p->data = con;
            return;
        case 2:
            con = p->data;
            *con.Sex = {'\0'};
            printf("\n性别修改为：");
            scanf("%s", con.Sex);
            p->data = con;
            return;
        case 3:
            con = p->data;
            *con.City = {'\0'};
            printf("\n城市修改为：");
            scanf("%s", con.City);
            p->data = con;
            return;
        case 4:
            con = p->data;
            *con.PostCode = {'\0'};
            printf("\n邮编修改为：");
            scanf("%s", con.PostCode);
            p->data = con;
            return;
        case 5:
            con = p->data;
            *con.PhoneNumber = {'\0'};
            printf("\n手机号修改为：");
            scanf("%s", con.PhoneNumber);
            p->data = con;
            return;
        case 6:
            con = p->data;
            *con.QQ = {'\0'};
            printf("\nQQ号修改为：");
            scanf("%s", con.QQ);
            p->data = con;
            return;
        case 7:
            con = p->data;
            *con.Email = {'\0'};
            printf("\nEmail修改为：");
            scanf("%s", con.Email);
            p->data = con;
            return;
        default:
            printf("提示：输入错误，请重新输入！\n");
            break;
        }
    }
}

void DeleteOne(ConList *&L)       //删除一个联系人
{
    ConList *pre = L, *p = L->next;
    char Name[10];
    printf(">>输入姓名(输入0返回):");
    scanf("%s", &Name);
    if (strcmp(Name, "0") == 0)
        return;    while (p != NULL && strcmp(p->data.Name, Name) != 0)
    {
        pre = p;
        p = p->next;
    }
    if (p == NULL)
        printf("提示：指定的联系人不存在\n");
    else
    {
        pre->next = p->next;
        free(p);
        printf("提示：删除成功\n");
    }
}

void DeleteAll(ConList *&L)      //删除所有联系人，清空通讯录
{
    FILE *fp;
    if ((fp = fopen("contacts.txt", "wb")) == NULL)      //重写清空contacts.txt文件
    {
        printf("  提示：不能打开通讯录\n");
        return;
    }
    fclose(fp);
    DestroyCon(L);
    L = (ConList *)malloc(sizeof(ConList));
    L->next = NULL;
    system("cls");
    printf("  提示：通讯录清空完毕\n");
}

int main()
{
    ConList *L;     //定义链表L
    char s[MAX] = {'\0'};//
    int selection;
    L = (ConList *)malloc(sizeof(ConList));
    L->next = NULL;
    ReadFile(L);
    do
    {
        system("cls");
        system("TITLE 通讯录管理系统");
        system("color 04");
        printf("                          ┏━┓　┏━┓ \n");
        printf("                          ★│┃  ┃│┃ \n");
        printf("                          ┃│┗灬┛│┃ \n");
        printf("                          ┃　　　　　┃\n");
        printf("                          ┃ ^　　 ^  ┃\n");
        printf("                             ﹌ ˇ ﹌  \n");
        printf("                          ┗○━━━○┛ \n");
        printf("-------------------欢迎进入全国富婆通讯录管理系统--------------------\n\n");
        printf("*********************************************************************\n");
        printf("           ☆ 添加联系人请按1            ☆ 浏览通讯录请按2\n");
        printf("           ☆ 删除联系人请按3            ☆ 查询联系人请按4\n");
        printf("           ☆ 修改联系人请按5            ☆ 退出请按0\n");
        printf("*********************************************************************\n");
        printf("\n>>请选择要进行的操作:");
        scanf("%s",s);
        selection = (int)s[0]-48;
        switch (selection)
        {
        case 0:
            SaveFile(L);
            printf("\n");
            system("pause");
            return 0;
        case 1:
            InputCon(L);
            break;
        case 2:
            DisplayCon(L);
            system("pause");
            break;
        case 3:
            DeleteCon(L);
            break;
        case 4:
            LocateCon(L);
            break;
        case 5:
            ModifyCon(L);
            break;
        default:
            printf("\n提示：输入错误，请重新输入\n\n");
            system("pause");
        }
    } while (1);
    return 0;
}
