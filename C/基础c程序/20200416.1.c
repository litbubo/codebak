#include <stdlib.h>
typedef struct node   //二叉树结构
{
    char data;
    struct node *lc,*rc;  //左右子树
} bt,*list;
int  creat(list*root)  //创建一棵二叉树，root使用的是二维指针
{
    char n;
    scanf(" %c",&n);
    if (n=='0')  //0为间隔
    {
        *root=NULL;
        return 0;  //输入结束
    }
    *root=(list)malloc(sizeof(bt));
    if (!*root)
        return 0;
    (*root)->data=n;
    creat(&(*root)->lc);
    creat(&(*root)->rc);
    return 1;
}
int pre(list root)  //先序遍历
{
    if (!root)
        return 0;
    printf("%c",root->data);
    pre(root->lc);
    pre(root->rc);
    return 1;
}
int mid(list root)  //中序遍历
{
    if (!root)
        return 0;
    mid(root->lc);
    printf("%c",root->data);
    mid(root->rc);
    return 1;
}
int	 bh(list root)  //后序遍历
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
    b=NULL; //二叉树的初始化
    creat(&b);//按三种遍历输出二叉树
    printf("\npre ");
    pre(b);
    printf("\nmid ");
    mid(b);
    printf("\nbh  ");
    bh(b);
    printf("\n");
}
