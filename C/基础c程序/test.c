#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
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
    printf("\t二叉树子系统\n");
    printf("*********************************\n");
    printf("*\t1 ......建二叉树\t*\n");
    printf("*\t2 ......先序遍历\t*\n");
    printf("*\t3 ......中序遍历\t*\n");
    printf("*\t4 ......后序遍历\t*\n");
    printf("*\t5 ......求叶子数\t*\n");
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
            printf("按提示输入二叉树中结点的值,输入0表示为空。\n");
            printf("请输入根：\n");
            T=CreatBiTree();
            printf("创建成功！共创建了%d个结点。\n",total);
            break;
        case 2:
            printf("先序遍历（递归）：\n");
            PreOrderTraverse(T);
            printf("\n");
            break;
        case 3:
            printf("中序遍历（递归）：\n");
            InOrderTraverse(T);
            printf("\n");
            break;
        case 4:
            printf("后序遍历（非递归）：\n");
            PostOrderTraverse(T);
            printf("\n");
            break;
        case 5:
            CountLeaves(T);
            printf("该二叉树共有%d个叶子结点。\n",count);
            count=0;
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
        printf("请输入%d的左孩子：",bt->data);
        bt->lchild=CreatBiTree();
        printf("请输入%d的右孩子：",bt->data);
        bt->rchild=CreatBiTree();
        total++;
    }
    return bt;
}

void PreOrderTraverse(BiTree *T)
{
    if(total==0)
    {
        printf("树为空或请先创建树。\n");
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
        printf("树为空或请先创建树。\n");
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
    BiTree *Seqstack[MAXSIZE];
    int top=-1;
    int flag=1;
    BiTree *pre;
    if(T!=NULL)
    {
        do
        {
            while(T!=NULL)                    // 循环，将所有最左结点压栈
            {
                top++;
                Seqstack[top]=T;
                T=T->lchild;
            }
            flag=1;                           // 辅助变量flag为1表示当前结点的左孩子为空或者已被访问
            pre=NULL;                           // 指针变量p指向当前结点的前驱结点
            while(top>-1&&flag==1)
            {
                T=Seqstack[top];              // 注意：这里只是获取栈顶元素，而并没有出栈
                if(T->rchild==pre)              // 如果当前结点右孩子为空，或者已经被访问过，则访问当前结点
                {
                    top--;                     // 当前结点出栈
                    printf("%d->",T->data);
                    pre=T;                      // 指针变量指向当前结点
                }
                else                            // 如果当前结点右孩子不为空，则先去处理右孩子
                {
                    T=T->rchild;              // 处理右孩子
                    flag=0;                   // *t的左孩子未被访问，flag置为0
                }
            }
        }
        while(top>-1);
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
