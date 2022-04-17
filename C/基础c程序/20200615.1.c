#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct ListNode
{
    DataType data;
    struct ListNode *next;
} ListNode;
ListNode *phead=NULL;

int InsertList(int i, DataType e);
int DeleteList(int i);
void FindList(DataType e);
void CreatList();
void PrintList();
void LengthList();

void main()
{
    int x,position,judge=1;
    DataType datas;
    printf("\t线性表子系统\n");
    printf("*********************************\n");
    printf("*\t1 ......建表\t\t*\n");
    printf("*\t2 ......插入\t\t*\n");
    printf("*\t3 ......删除\t\t*\n");
    printf("*\t4 ......显示\t\t*\n");
    printf("*\t5 ......查找\t\t*\n");
    printf("*\t6 ......求表长\t\t*\n");
    printf("*\t0 ......返回\t\t*\n");
    printf("*********************************\n");
    while(judge)
    {
        printf("请输入相应序号进行功能选择：");
        fflush(stdin);
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            CreatList();
            printf("创建成功！！\n");
            break;
        case 2:
            printf("请输入插入的位置和数据：");
            fflush(stdin);
            scanf("%d%d",&position,&datas);
            InsertList(position,datas);
            break;
        case 3:
            printf("请输入删除的位置：");
            fflush(stdin);
            scanf("%d",&position);
            DeleteList(position);
            break;
        case 4:
            PrintList();
            break;
        case 5:
            printf("请输入需要查找的数据：");
            fflush(stdin);
            scanf("%d",&datas);
            FindList(datas);
            break;
        case 6:
            LengthList();
            break;
        case 0:
            judge=0;
            printf("返回成功！！\n");
            break;
        default:
            printf("输入错误，请重新输入!\n");
        }
    }
}

void CreatList()
{
    int flag=1;
    ListNode *p=NULL,*pre=NULL;
    if((phead=(ListNode *)malloc(sizeof(ListNode)))==NULL)
    {
        printf("申请失败！");
        exit(-1);
    }
    pre=phead;
    while(flag)
    {
        char judge0;
        printf("输入a创建新结点，输入b则退出：");
        fflush(stdin);
        scanf("%c",&judge0);
        if(judge0=='a')
        {
            DataType x;
            printf("请输入该结点的数据：");
            fflush(stdin);
            scanf("%d",&x);
            if((p=(ListNode *)malloc(sizeof(ListNode)))==NULL)
            {
                printf("申请失败！");
                exit(-1);
            }
            p->data=x;
            pre->next=p;
            p->next=NULL;
            pre=p;
        }
        else
            flag=0;
    }
}

int InsertList(int i, DataType e)
{
    ListNode *p=NULL,*pre=NULL;
    int j=0;
    pre=phead;
    while(pre->next!=NULL&&j<i-1)
    {
        pre=pre->next;
        j++;
    }
    if(j!=i-1)
    {
        printf("插入位置错误！\n");
        return 0;
    }
    if((p=(ListNode *)malloc(sizeof(ListNode)))==NULL)
    {
        printf("申请失败！\n");
        exit(-1);
    }
    p->data=e;
    p->next=pre->next;
    pre->next=p;
    printf("插入成功！！\n");
}

int DeleteList(int i)
{
    ListNode *p=NULL,*pre=NULL;
    int j=0;
    pre=phead;
    while(pre->next!=NULL&&pre->next->next!=NULL&&j<i-1)
    {
        pre=pre->next;
        j++;
    }
    if(j!=i-1)
    {
        printf("删除位置错误！！\n");
        return 0;
    }
    if((p=(ListNode *)malloc(sizeof(ListNode)))==NULL)
    {
        printf("申请失败！！\n");
        exit(-1);
    }
    p=pre->next;
    pre->next=p->next;
    free(p);
    p=NULL;
    printf("删除成功！！\n");
}

void PrintList()
{
    ListNode *p=NULL;
    p=phead;
    //printf("%d",p->next->data);
    if(p->next==NULL)
        //if(p==NULL)
        printf("链表为空。\n");
    else
    {
        printf("已打印链表所有元素：\n");
        while(p->next!=NULL)
        {
            printf("    %d",p->next->data);
            p=p->next;
        }
        printf("\n");
    }
}

void FindList(DataType e)
{
    int count=0,flag=0;
    ListNode *pre=NULL;
    pre=phead->next;
    printf("值为%d的结点:\n",e);
    while(pre!=NULL)
    {
        count++;
        if(e==pre->data)
        {
            flag++;
            printf("在第%d的位置。\n",count);
        }
        pre=pre->next;
    }
    if(flag==0)
        printf("不存在于该链表。\n");
}

void LengthList()
{
    int len=0;
    ListNode *pre=NULL;
    pre=phead->next;
    while(pre!=NULL)
    {
        len++;
        pre=pre->next;
    }
    printf("该链表的表长为%d。\n",len);
}

