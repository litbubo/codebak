#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<stdlib.h>

#include<string.h>



typedef struct People
{

    char name[20];

    char sex[4];

    int age;

    int tel[11];

    char add[20];

};

typedef struct List
{
    struct People Peo[1000];
    int count;
};



void menu()

{

    printf("            ��ӭʹ��ͨѶ¼            \n");

    printf("**********1.�����ϵ����Ϣ************\n");

    printf("********2.ɾ��ָ����ϵ����Ϣ**********\n");

    printf("********3.����ָ����ϵ����Ϣ**********\n");

    printf("********4.�޸�ָ����ϵ����Ϣ**********\n");

    printf("********5.��ʾ������ϵ����Ϣ**********\n");

    printf("**********6.�����ϵ����Ϣ************\n");

    printf("******7.����������������ϵ����********\n");

    printf("****** 0.�˳���ǰͨѶ¼ϵͳ ********\n");

}


void add_peo(struct List *L)//�����ϵ����Ϣ

{

    if (L->count > 1000)

    {

        printf("ͨѶ¼����\n");

        return;

    }

    else

    {

        printf("������Ҫ��ӵ���ϵ������\n");

        scanf("%s", &L->Peo[L->count].name);

        printf("������Ҫ��ӵ���ϵ�˵��Ա�\n");

        scanf("%s", &L->Peo[L->count].sex);

        printf("������Ҫ��ӵ���ϵ�˵�����\n");

        scanf("%d", &L->Peo[L->count].age);

        printf("������Ҫ��ӵ���ϵ�˵��ֻ���\n");

        scanf("%s", &L->Peo[L->count].tel);

        printf("������Ҫ��ӵ���ϵ�˵ĵ�ַ\n");

        scanf("%s", &L->Peo[L->count].add);

        L->count++;

        printf("��ϵ��������ӳɹ�\n");



    }

}
int rearch(struct List *L, char *name)

{

    int ret = 0;

    int i = 0;

    for (; i < (L->count); i++)

    {

        if (strcmp(L->Peo[i].name, name) == 0)

            return i;

    }

    return -1;//û�ҵ���ͬ������



}
void del_peo(struct List *L)//ɾ��ָ����ϵ����Ϣ

{

    char name[20];

    int ret = 0;

    int i = 0;

    printf("����������Ҫɾ������ϵ�˵�����\n");

    scanf("%s", &name);

    ret = rearch(L, name);

    if (ret == -1)

    {

        printf("��Ҫɾ������ϵ�˲�����\n");



    }

    else

    {

        for (i = ret; i <= L->count; i++)

        {

            L->Peo[i] = L->Peo[i + 1];

        }

        printf("ɾ���ɹ�\n");

    }



}
void ser_peo(struct List *L)//����ָ����ϵ����Ϣ

{

    char name[20];

    int ret = 0;

    int i = 0;

    printf("����������Ҫɾ������ϵ�˵�����\n");

    scanf("%s", &name);

    ret = rearch(L, name);

    if (ret == -1)

    {

        printf("�����ҵ���ϵ�˲�����\n");

    }

    else

    {

        printf("��ϵ������%s\n", L->Peo[ret].name);

        printf("��ϵ���Ա�%s\n", L->Peo[ret].sex);

        printf("��ϵ������%d\n", L->Peo[ret].age);

        printf("��ϵ���ֻ���%s\n", L->Peo[ret].tel);

        printf("��ϵ�˵�ַ%s\n", L->Peo[ret].add);



    }

}
void mod_peo(struct List *L)//�޸�ָ����ϵ����Ϣ

{

    char name[20];

    int ret = 0;

    int i = 0;

    printf("����������Ҫɾ������ϵ�˵�����\n");

    scanf("%s", &name);

    ret = rearch(L, name);

    if (ret == -1)

    {

        printf("�����ҵ���ϵ�˲�����\n");

    }

    else

    {

        printf("������Ҫ��ӵ���ϵ������\n");

        scanf("%s", &L->Peo[ret].name);

        printf("������Ҫ��ӵ���ϵ�˵��Ա�\n");

        scanf("%s", &L->Peo[ret].sex);

        printf("������Ҫ��ӵ���ϵ�˵�����\n");

        scanf("%d", &L->Peo[ret].age);

        printf("������Ҫ��ӵ���ϵ�˵��ֻ���\n");

        scanf("%s", &L->Peo[ret].tel);

        printf("������Ҫ��ӵ���ϵ�˵ĵ�ַ\n");

        scanf("%s", &L->Peo[ret].add);

        printf("��ϵ�������޸ĳɹ��ɹ�\n");

    }

}
void pri_peo(struct List *L)//��ʾ������ϵ����Ϣ

{

    int i = 0;

    for (; i < L->count; i++)

    {

        printf("��%d����ϵ����Ϣ��\n", i + 1);

        printf("��ϵ������%s\n", L->Peo[i].name);

        printf("��ϵ���Ա�%s\n", L->Peo[i].sex);

        printf("��ϵ������%d\n", L->Peo[i].age);

        printf("��ϵ���ֻ���%s\n", L->Peo[i].tel);

        printf("��ϵ�˵�ַ%s\n", L->Peo[i].add);

        printf("\n");

    }

}
void emp_peo(struct List *L)//.�����ϵ����Ϣ

{

    L->count = 0;

    return ;

}


void sort_peo(struct List *L)//����������������ϵ����

{

    int m = 0;

    int n = 0;

    for (; m < L->count-1; m++)

    {

        n = m;

        for (; n < L->count-1-m; n++)

        {

            if (strcmp(L->Peo[n].name, L->Peo[n + 1].name))

            {

                struct People tmp;

                tmp = L->Peo[n];

                L->Peo[n] = L->Peo[n + 1];

                L->Peo[n + 1] = tmp;



            }

        }

    }

}
int main()

{

    struct List L;

    menu();

    int n = 0;

    printf("��ѡ������Ҫ���еĲ���\n");

    scanf("%d", &n);

    while (n)

    {



        switch (n)

        {

        case 0:

            return 0;

        case 1:

            add_peo(&L);

            break;

        case 2:

            del_peo(&L);

            break;

        case 3:

            ser_peo(&L);

            break;

        case 4:

            mod_peo(&L);

            break;

        case 5:

            pri_peo(&L);

            break;

        case 6:

            emp_peo(&L);

            break;

        case 7:

            sort_peo(&L);

            break;

        default:

            printf("�����������\n");

        }

        printf("\n");

        menu();

        printf("��ѡ������Ҫ���еĲ���\n");

        scanf("%d", &n);



    }





}
