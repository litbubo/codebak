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
    printf("\t���Ա���ϵͳ\n");
    printf("*********************************\n");
    printf("*\t1 ......����\t\t*\n");
    printf("*\t2 ......����\t\t*\n");
    printf("*\t3 ......ɾ��\t\t*\n");
    printf("*\t4 ......��ʾ\t\t*\n");
    printf("*\t5 ......����\t\t*\n");
    printf("*\t6 ......���\t\t*\n");
    printf("*\t0 ......����\t\t*\n");
    printf("*********************************\n");
    while(judge)
    {
        printf("��������Ӧ��Ž��й���ѡ��");
        fflush(stdin);
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            CreatList();
            printf("�����ɹ�����\n");
            break;
        case 2:
            printf("����������λ�ú����ݣ�");
            fflush(stdin);
            scanf("%d%d",&position,&datas);
            InsertList(position,datas);
            break;
        case 3:
            printf("������ɾ����λ�ã�");
            fflush(stdin);
            scanf("%d",&position);
            DeleteList(position);
            break;
        case 4:
            PrintList();
            break;
        case 5:
            printf("��������Ҫ���ҵ����ݣ�");
            fflush(stdin);
            scanf("%d",&datas);
            FindList(datas);
            break;
        case 6:
            LengthList();
            break;
        case 0:
            judge=0;
            printf("���سɹ�����\n");
            break;
        default:
            printf("�����������������!\n");
        }
    }
}

void CreatList()
{
    int flag=1;
    ListNode *p=NULL,*pre=NULL;
    if((phead=(ListNode *)malloc(sizeof(ListNode)))==NULL)
    {
        printf("����ʧ�ܣ�");
        exit(-1);
    }
    pre=phead;
    while(flag)
    {
        char judge0;
        printf("����a�����½�㣬����b���˳���");
        fflush(stdin);
        scanf("%c",&judge0);
        if(judge0=='a')
        {
            DataType x;
            printf("������ý������ݣ�");
            fflush(stdin);
            scanf("%d",&x);
            if((p=(ListNode *)malloc(sizeof(ListNode)))==NULL)
            {
                printf("����ʧ�ܣ�");
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
        printf("����λ�ô���\n");
        return 0;
    }
    if((p=(ListNode *)malloc(sizeof(ListNode)))==NULL)
    {
        printf("����ʧ�ܣ�\n");
        exit(-1);
    }
    p->data=e;
    p->next=pre->next;
    pre->next=p;
    printf("����ɹ�����\n");
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
        printf("ɾ��λ�ô��󣡣�\n");
        return 0;
    }
    if((p=(ListNode *)malloc(sizeof(ListNode)))==NULL)
    {
        printf("����ʧ�ܣ���\n");
        exit(-1);
    }
    p=pre->next;
    pre->next=p->next;
    free(p);
    p=NULL;
    printf("ɾ���ɹ�����\n");
}

void PrintList()
{
    ListNode *p=NULL;
    p=phead;
    //printf("%d",p->next->data);
    if(p->next==NULL)
        //if(p==NULL)
        printf("����Ϊ�ա�\n");
    else
    {
        printf("�Ѵ�ӡ��������Ԫ�أ�\n");
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
    printf("ֵΪ%d�Ľ��:\n",e);
    while(pre!=NULL)
    {
        count++;
        if(e==pre->data)
        {
            flag++;
            printf("�ڵ�%d��λ�á�\n",count);
        }
        pre=pre->next;
    }
    if(flag==0)
        printf("�������ڸ�����\n");
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
    printf("������ı�Ϊ%d��\n",len);
}

