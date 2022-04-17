#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct BtNode
{
    DataType data;
    struct BtNode *lchild;
    struct BtNode *rchild;
} BiTree;

int count=0,total=0;

BiTree *CreatBiTree();
void PreOrderTraverse(BiTree *T);
void InOrderTraverse(BiTree *T);
void PostOrderTraverse(BiTree *T);
void CountLeaves(BiTree *T);

void main()
{
    int x,judge=1;
    BiTree *T=NULL;
    printf("\t��������ϵͳ\n");
    printf("*********************************\n");
    printf("*\t1 ......��������\t*\n");
    printf("*\t2 ......�������\t*\n");
    printf("*\t3 ......�������\t*\n");
    printf("*\t4 ......�������\t*\n");
    printf("*\t5 ......��Ҷ����\t*\n");
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
            printf("����ʾ����������н���ֵ,����0��ʾΪ�ա�\n");
            printf("���������\n");
            T=CreatBiTree();
            printf("�����ɹ�����������%d����㡣\n",total);
            break;
        case 2:
            printf("����������ݹ飩��\n");
            PreOrderTraverse(T);
            printf("\n");
            break;
        case 3:
            printf("����������ݹ飩��\n");
            InOrderTraverse(T);
            printf("\n");
            break;
        case 4:
            printf("����������ǵݹ飩��\n");
            PostOrderTraverse(T);
            printf("\n");
            break;
        case 5:
            CountLeaves(T);
            printf("�ö���������%d��Ҷ�ӽ�㡣\n",count);
            count=0;
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

BiTree *CreatBiTree()
{
    BiTree *bt=NULL;
    DataType datas;
    fflush(stdin);
    scanf("%d",&datas);
    if(datas==0)
    {
        bt==NULL;
    }
    else
    {
        bt=(BiTree *)malloc(sizeof(BiTree));
        bt->data=datas;
        printf("������%d�����ӣ�",bt->data);
        bt->lchild=CreatBiTree();
        printf("������%d���Һ��ӣ�",bt->data);
        bt->rchild=CreatBiTree();
        total++;
    }
    return bt;
}

void PreOrderTraverse(BiTree *T)
{
    if(total==0)
    {
        printf("��Ϊ�ջ����ȴ�������\n");
        return;
    }
    if(T==NULL)
        return;
    else
    {
        printf("%d->",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void InOrderTraverse(BiTree *T)
{
    if(total==0)
    {
        printf("��Ϊ�ջ����ȴ�������\n");
        return;
    }
    if(T==NULL)
        return;
    else
    {
        InOrderTraverse(T->lchild);
        printf("%d->",T->data);
        InOrderTraverse(T->rchild);
    }
}

void PostOrderTraverse(BiTree *T)
{
    BiTree *stack[20];
    BiTree *stack0[20];
    int top = -1, top0=-1;
    stack[++top] = T;
    while(top!=-1)
    {
        T = stack[top--];
        stack0[++top0] = T;
        if(T->lchild!=NULL)
        {
            stack[++top] = T->lchild;
        }
        if(T->rchild!=NULL)
        {
            stack[++top] = T->rchild;
        }
    }
    while(top0!=-1)
    {
        T = stack0[top0--];
        printf("%d->",T->data);
    }

}

void CountLeaves(BiTree *T)
{
    if(T==NULL)
        return;
    else
    {
        if(T->lchild==NULL&&T->rchild==NULL)
            count++;
        CountLeaves(T->lchild);
        CountLeaves(T->rchild);
    }
}
