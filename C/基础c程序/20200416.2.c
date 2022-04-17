#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node//�ṹ��
{
    char data;
    struct Node *LChild;
    struct Node *RChild;
} BiTNode,*BiTree;

void InitList(BiTree *l)//��ʼ��
{
    *l= (BiTree)malloc(sizeof(BiTNode));
    (*l)->LChild = NULL;
    (*l)->RChild = NULL;
}

void CreateBiTree(BiTree *bt) //���򴴽�������
{
    char ch;
    ch = getchar();
    if (ch == ' ')
        *bt = NULL;
    else
    {
        *bt = (BiTree)malloc(sizeof(BiTNode));
        (*bt)->data = ch;
        CreateBiTree(&((*bt)->LChild));
        CreateBiTree(&((*bt)->RChild));
    }
}

void PreOrder(BiTree root)//�������
{
    if (root != NULL)
    {
        printf("%c", root->data);
        PreOrder(root->LChild);
        PreOrder(root->RChild);
    }
}

void InOrder(BiTree root)//�������
{
    if (root != NULL)
    {
        InOrder(root->LChild);
        printf("%c", root->data);
        InOrder(root->RChild);
    }
}

void PostOrder(BiTree root)//�������
{
    if (root != NULL)
    {
        PostOrder(root->LChild);
        PostOrder(root->RChild);
        printf("%c", root->data);
    }
}

int main()
{

    BiTree bt;
    InitList(&bt);
    CreateBiTree(&bt);
    PreOrder(bt);
    printf("\n");
    InOrder(bt);
    printf("\n");
    PostOrder(bt);
    printf("\n");
}
