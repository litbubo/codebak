#include <stdlib.h>
typedef struct node   //�������ṹ
{
    char data;
    struct node *lc,*rc;  //��������
} bt,*list;
int  creat(list*root)  //����һ�ö�������rootʹ�õ��Ƕ�άָ��
{
    char n;
    scanf(" %c",&n);
    if (n=='0')  //0Ϊ���
    {
        *root=NULL;
        return 0;  //�������
    }
    *root=(list)malloc(sizeof(bt));
    if (!*root)
        return 0;
    (*root)->data=n;
    creat(&(*root)->lc);
    creat(&(*root)->rc);
    return 1;
}
int pre(list root)  //�������
{
    if (!root)
        return 0;
    printf("%c",root->data);
    pre(root->lc);
    pre(root->rc);
    return 1;
}
int mid(list root)  //�������
{
    if (!root)
        return 0;
    mid(root->lc);
    printf("%c",root->data);
    mid(root->rc);
    return 1;
}
int	 bh(list root)  //�������
{
    if (!root)
        return 0;
    bh(root->lc);
    bh(root->rc);
    printf("%c",root->data);
    return 1;
}
void main()
{
    list b;
    printf("input a tree(int):\n");
    b=NULL; //�������ĳ�ʼ��
    creat(&b);//�����ֱ������������
    printf("\npre ");
    pre(b);
    printf("\nmid ");
    mid(b);
    printf("\nbh  ");
    bh(b);
    printf("\n");
}
