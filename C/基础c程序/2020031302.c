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
    printf("\t\t**********С��ͨѶ¼�˵�**********\n");
    printf("\t\t                                  \n");
    printf("\t\t           1.��Ϣ¼��             \n");
    printf("\t\t                                  \n");
    printf("\t\t           2.��Ϣ�޸�             \n");
    printf("\t\t                                  \n");
    printf("\t\t           3.��Ϣɾ��             \n");
    printf("\t\t                                  \n");
    printf("\t\t           4.��Ϣ��ѯ             \n");
    printf("\t\t                                  \n");
    printf("\t\t           5.��Ϣ��ʾ             \n");
    printf("\t\t                                  \n");
    printf("\t\t           6.�˳�����             \n");
    printf("\t\t                                  \n");
    printf("\t\t**********************************\n");

}
void input()
{
    char c[2];
    printf("������ϵ����Ϣ\n");
    do
    {
        printf("������");
        scanf("%s",&p[i].name);
        printf("�Ա�: ");
        scanf("%s",&p[i].name);
        printf("�绰��");
        scanf("%s",&p[i].tel);
        printf("email:");
        scanf("%s",&p[i].email);
        printf("��ϵ:");
        scanf("%s",&p[i].relate);
        i++;
        printf("�������");
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
        printf("������Ҫ�޸ĵ�λ��");
        scanf("%d",&a);
        scanf("%s,%s,%s,%s,%s",name,sex,tel,email,relate);
        strcpy(p[a-1].name,name);
        strcpy(p[a-1].sex,sex);
        strcpy(p[a-1].tel,tel);
        strcpy(p[a-1].email,email);
        strcpy(p[a-1].relate,relate);
        printf("������0����������1����!\n");
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
    printf("��������");
    scanf("%s",&name);
    add=-1;
    for(w=0; w<i; w++)
    {
        if(strcmp(name,p[w].name)==0)
        {
            printf("������Ҫɾ������ϵ�ˣ�\n");
            printf("������%s\n",p[w].name);
            printf("�Ա�: %s\n",p[w].sex);
            printf("�绰��%s\n",p[w].tel);
            printf("�����ʼ���%s\n",p[w].email);
            printf("��ϵ��%s\n",p[w].relate);
            add=w;
            t++;
            break;
        }
    }
    if (add==-1)
    {
        printf("�޴���\n");
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
        printf("\n\t\t��ǰ��û����ϵ����Ϣ   ");
        printf("\n\n\t\t");
        system("cls");
        getchar();
        return;
    }
    printf("\n1.����������\n");
    printf("\n2.���Ա����\n");
    printf("\n3.���뱾�˵Ĺ�ϵ����\n");
    printf("\n  ��ѡ��\n");
    scanf("%d",&num);
    system("cls");
    switch (num)
    {
    case 1:
        printf("1.����������\n");
        printf("����������:");
        scanf("%s",&name);
        for(k=0; k<i; k++)
        {
            if(strcmp(p[k].name,name)==0)
            {
                printf("������ %s\n",p[k].name);
                printf("�Ա�:  %s\n",p[k].sex);
                printf("�绰�� %s\n",p[k].tel);
                printf("E-mail�� %s\n",p[k].email);
                printf("�뱾�˹�ϵ�� %s\n",p[k].relate);
            }
            else
                printf("\n\t��������Ĺ�ϵ����򲻴���! ");
        }
    case 2:
        printf("2.���Ա����\n");
        printf("�������Ա�");
        scanf("%s",&sex);
        for(k=0; k<i; k++)
        {
            if(strcmp(p[k].sex,sex)==0)
            {
                printf("������ %s\n",p[k].name);
                printf("�Ա�:  %s\n",p[k].sex);
                printf("�绰�� %s\n",p[k].tel);
                printf("E-mail�� %s\n",p[k].email);
                printf("�뱾�˹�ϵ�� %s\n",p[k].relate);
            }
            else
                printf("\n\t��������Ĺ�ϵ����򲻴���! ");
        }
    case 3:
        printf("3.���뱾�˵Ĺ�ϵ����\n");
        printf("�������뱾�˵Ĺ�ϵ");
        scanf("%s",&relate);
        for(k=0; k<i; k++)
        {
            if(strcmp(p[k].relate,relate)==0)
            {
                printf("������ %s\n",p[k].name);
                printf("�Ա�:  %s\n",p[k].sex);
                printf("�绰�� %s\n",p[k].tel);
                printf("E-mail�� %s\n",p[k].email);
                printf("�뱾�˹�ϵ�� %s\n",p[k].relate);
            }
            else
                printf("\n\t��������Ĺ�ϵ����򲻴���! ");
        }
    }
}
void show()
{
    int w;
    if(i=0)
    {
        printf("\n\t\t��ǰ��û����ϵ�˼�¼      ");
        printf("\n\n\t\t");
        system("cls");
        getchar();
        return;
    }
    printf("\n������ϵ�˼�¼����: \n");
    for(w=0; w<i-1; w++)
    {
        printf("������ %s\n",p[w].name);
        printf("�Ա�:  %s\n",p[w].sex);
        printf("�绰�� %s\n",p[w].tel);
        printf("E-mail�� %s\n",p[w].email);
        printf("relate�� %s\n",p[w].relate);
    }
}
void esc()
{
    printf("\n\n\t\t  �˳�ϵͳ!  \n");
    printf("\n\n\t\t��л��ʹ�ñ�ϵͳ!\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
void main()
{
    while(1)
    {
        int num;
        menu();
        printf("��ѡ��\n");
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
            printf("\n\n\t\t ��������밴�������������ѡ��\n\n\t\t");
            system("pause");
            system("cls");
            getchar();
        }
    }
}
