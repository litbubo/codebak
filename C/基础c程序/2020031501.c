#include <stdio.h>
#include <string.h>          //����Ƚϴ�С
#include <stdlib.h>          //�����Ļ
#define N 100
typedef struct    worker    //����ṹ�����  wor
{
    char numb[N];            //Ա�����
    char str[N];           //����
    char name[N];            //����
    char sex[N];             //�Ա�
    char age[N];           //����
    char post[N];            //ְ��
    char dep[N];            //����
    char add[N];           //סַ
} wor;

int count=0;
int i;
char a;
int x=0;

void input(wor abc[]);       //1��¼��ְ����Ϣ
void deleted(wor abc[]);     //2����ְ����Ϣ��ɾ��
void modify(wor abc[]);      //3���޸���Ϣ
void print(wor abc[]);       //4����ʾְ����Ϣ
void query(wor abc[]);       //5����ѯ
void exits(wor abc[]);      //6���˳�

void query1(wor abc[]);        //����������Ա����Ϣ
void query2(wor abc[]);        //���벿�š��Ա�������з�������Ա����¼
void query3(wor abc[]);        //�������䷶Χ���Ա��������з�������Ա����¼
void query4(wor abc[]);        //���벿�ţ�����������з�������Ա����¼������
void swit(wor abc[]);        //ѡ����
void back(wor abc[]);        //�������˵�
void menu();                 //�˵�
int judge();                 //�ж����������Ƿ����Ҫ��

void main()
{
    wor abc[N];              //���������������
    swit(abc);               //���ò˵�
}
int judge()
{
    menu();
    int b;
    printf ("�������Ӧ���ʵ�ֶ�Ӧ���ܣ�");
    fflush(stdin);     //����������뻺����
    scanf("%d",&b);
    if(b<1||b>7)
    {
        system("cls");       //�����Ļ
        printf("\n****************�����������������****************\n");
        judge();             //���������������µ��ú���
    }
    else
        return b;
}
void menu(wor abc[])      //���˵�
{
    printf(" \n");
    printf("   ��ӭʹ��Ա����Ϣ�������\n");
    printf("      (1)¼��ְ����Ϣ\n");
    printf("      (2)ɾ��ְ����Ϣ\n");
    printf("      (3)�޸�ְ����Ϣ\n");
    printf("      (4)��ʾְ����Ϣ\n");
    printf("      (5)��ѯְ����Ϣ\n");
    printf("      (6)�˳�����\n");
}
void back(wor abc[])       //�������˵�
{
    printf("\n���������ַ��������˵���\n");
    char a=getchar();
    if (1)
        swit(abc);
}
void exits(wor abc[])                 //�˳�
{
    printf("\n\n----------------------�˳��ɹ�----------------------\n");
}
void swit(wor abc[])      //ѡ����
{
    system("cls");           //�����Ļ
    printf("������������ʵ�ֶ�Ӧ���ܣ�\n");
    switch(judge())
    {
    case 1:
        input(abc);
        break;
    case 2:
        deleted(abc);
        break;
    case 3:
        modify(abc);
        break;
    case 4:
        print(abc);
        break;
    case 5:
        query(abc);
        break;
    case 6:
        exits(abc);
        break;
    }

}
void input(wor abc[])      //¼��ְ����Ϣ
{
    system("cls");         //�����Ļ
    printf("���ѽ���¼����棺\n");
    printf("������Ա����ţ�\n");
    fflush(stdin);
    scanf("%s",&abc[count].numb);
    printf("������Ա�����䣺\n");
    scanf("%s",&abc[count].str);
    printf("������Ա��������\n");
    scanf("%s",&abc[count].name);
    printf("������Ա���Ա�\n");
    scanf("%s",&abc[count].sex);
    printf("������Ա�����䣺\n");
    scanf("%s",&abc[count].age);
    printf("������Ա��ְ��\n");
    scanf("%s",&abc[count].post);
    printf("������Ա�����ţ�\n");
    scanf("%s",&abc[count].dep);
    printf("������Ա��סַ��\n");
    scanf("%s",&abc[count].add);
    count++;
    printf("¼��ɹ�������0����¼�룬���������ַ��������˵�\n");
    fflush(stdin);
    char a=getchar();
    if(a=='0')
        input(abc);
    else
        back(abc);
}
void deleted(wor abc[])       //ɾ��ְ����Ϣ
{
    system("cls");
    if(count==0)
    {
        printf("��ְ����Ϣ���޷�ɾ��\n");
        back(abc);
    }
    else
    {
        char c[N];
        int m=0,n=count;
        printf("������Ҫɾ����ְ����ţ�\n");
        fflush(stdin);
        gets(c);
        for (i=0; i<count; i++)                      //��ÿ��Ա����Ϣ����ѭ��
        {
            if (strcmp(abc[i].numb,c)==0)           //�ж�Ա������Ƿ���ͬ
            {
                for (i=0; i<count; i++)              //��������Ա����Ϣǰ��
                    abc[i]=abc[i+1];
                count--;
                if (count<n)                         //ɾ��������ɾ��ǰ��ɾ���ɹ�
                    printf("ɾ���ɹ�\n");
            }
            m++;
            if(n==count)
                printf("δ�ҵ���ӦԱ����Ϣ��");
            printf("����0����ɾ�������������ַ��������˵���\n");
            char a=getchar();
            if(a=='0')
                deleted(abc);
            else
                back(abc);
        }

    }
}
void print(wor abc[])
{
    system("cls");
    if(count==0)
        printf("��¼����ϢΪ�ա�");
    else
        for(i=0; i<count; i++)
            printf("\n��ţ� %s\n���䣺 %s\n������ %s\n�Ա� %s\n���䣺 %s\nְ�� %s\n���ţ� %s\nסַ��%s\n\n",&abc[i].numb,&abc[i].str,&abc[i].name,&abc[i].sex,&abc[i].age,abc[i].post,&abc[i].dep,abc[i].add);
    printf("����0�������˵���\n");
    fflush(stdin);
    char a=getchar();
    if(a=='0')
        back(abc);
}
void modify(wor abc[])
{
    system("cls");
    if(count==0)
    {
        printf("��ְ����Ϣ���޷��޸�\n");
        back(abc);
    }
    else
    {
        char c[N];
        int m;
        printf("������Ҫ�޸ĵ�ְ����ţ�\n");
        fflush(stdin);
        gets(c);
        for (i=0; i<count; i++)                      //��ÿ��Ա����Ϣ����ѭ��
        {
            if (strcmp(abc[i].numb,c)==0)
            {
                printf("��Ա����Ϣ���£�\n ��ţ� %s\n���䣺 %s\n������ %s\n�Ա� %s\n���䣺 %s\nְ�� %s\n���ţ� %s\nסַ��%s\n\n",&abc[i].numb,&abc[i].str,&abc[i].name,&abc[i].sex,&abc[i].age,abc[i].post,&abc[i].dep,abc[i].add);
                printf("������1-8��ѡ���޸���Ϣ��\n");
                printf("(1)���\n (2)����\n (3)����\n (4)�Ա�\n (5)����\n (6)ְ��\n (7)����\n (8)סַ\n");
                fflush(stdin);
                scanf("%d",&m);
                fflush(stdin);
                switch(m)
                {
                case 1:
                    printf("�������µ�Ա����ţ�\n");
                    scanf("%s",&abc[i].numb);
                    break;
                case 2:
                    printf("�������µ�Ա�����䣺\n");
                    scanf("%s",&abc[i].str);
                    break;
                case 3:
                    printf("�������µ�Ա��������\n");
                    scanf("%s",&abc[i].name);
                    break;
                case 4:
                    printf("�������µ�Ա���Ա�\n");
                    scanf("%s",&abc[i].sex);
                    break;
                case 5:
                    printf("�������µ�Ա�����䣺\n");
                    scanf("%s",&abc[i].age);
                    break;
                case 6:
                    printf("�������µ�Ա��ְ��\n");
                    scanf("%s",&abc[i].post);
                    break;
                case 7:
                    printf("�������µ�Ա�����ţ�\n");
                    scanf("%s",&abc[i].dep);
                    break;
                case 8:
                    printf("�������µ�Ա��סַ��\n");
                    scanf("%s",&abc[i].add);
                    break;
                }
                printf("�޸ĳɹ�������0�����޸ģ����������ַ��������˵�\n");
            }
            char a=getchar();
            if(a=='0')
                modify(abc);
            else
                back(abc);
        }
    }
}
void query(wor abc[])       //��ѯ
{
    system("cls");
    printf ("\n����ѡ���ѯ���ܡ�\n");
    if (count==0)
    {
        printf("\n��ְ����Ϣ��\n");
        back(abc);
    }
    else
    {
        printf("��ѡ���ѯ��ʽ��\n");
        printf("\n��a������������Ա����Ϣ\n\n��b�����벿�š��Ա�������з�������Ա����¼\n\n(c)�������䷶Χ���Ա��������з�������Ա����¼\n\n(d)���벿�ţ�����������з�������Ա����¼�������\n");
        char c;
        fflush(stdin);
        scanf("%c",&c);
        switch(c)
        {
        case 'a':
            query1(abc);
            break;
        case 'b':
            query2(abc);
            break;
        case 'c':
            query3(abc);
            break;
        case 'd':
            query4(abc);
            break;
        default :
            query(abc);
            break;
        }
    }
}
void query1(wor abc[])       //����������Ա����Ϣ
{
    char c[N];
    printf("\n��������Ҫ��ѯ��Ա��������\n");
    fflush(stdin);
    gets(c);
    for (i=0; i<count; i++)
        if (strcmp(abc[i].name,c)==0)
        {
            printf("����ʾ����Ϊ��%s������Ϣ��\n\n",c);
            printf("��Ա����Ϣ���£�\n ��ţ� %s\n���䣺 %s\n������ %s\n�Ա� %s\n���䣺 %s\nְ�� %s\n���ţ� %s\nסַ��%s\n\n",&abc[i].numb,&abc[i].str,&abc[i].name,&abc[i].sex,&abc[i].age,abc[i].post,&abc[i].dep,abc[i].add);
            x++;
        }
    if (x==0)
            printf("δ�ҵ���Ӧ��Ա����Ϣ��\n");
    printf("\n����0�������ѯ�����������ַ��򷵻����˵���\n");
    fflush(stdin);
    char a=getchar();
    if(a=='0')
        query1(abc);
    else
        back(abc);
}
void query2(wor abc[])        //���벿�š��Ա�������з�������Ա����¼
{
    system("cls");
    char c[N];                //����
    char d[N];                //�Ա�
    printf("\n�����벿�š��Ա�\n");
    fflush(stdin);
    scanf("%s%s",&c,&d);
    for (i=0; i<count; i++)
        if (strcmp(abc[i].dep,c)==0&&strcmp(abc[i].sex,d)==0)
        {
            printf("����ʾ���š��Ա�Ϊ��%s%s����Ա����Ϣ��\n\n",c,d);
            printf("��Ա����Ϣ���£�\n ��ţ� %s\n���䣺 %s\n������ %s\n�Ա� %s\n���䣺 %s\nְ�� %s\n���ţ� %s\nסַ��%s\n\n",&abc[i].numb,&abc[i].str,&abc[i].name,&abc[i].sex,&abc[i].age,abc[i].post,&abc[i].dep,abc[i].add);
            x++;
        }
    if (x==0)
            printf("δ�ҵ���Ӧ��Ա����Ϣ��\n");
    printf("\n����0�������ѯ�����������ַ��򷵻����˵���\n");
    fflush(stdin);
    char a=getchar();
    if(a=='0')
        query2(abc);
    else
        back(abc);
}
void query3(wor abc[])        //�������䷶Χ���Ա��������з�������Ա����¼
{
    system("cls");
    int j;
    char c[N];                //��������
    char d[N];                //��������
    char e[N];                //�Ա�
    printf("\n�������������ޡ��������ޡ��Ա�\n");
    fflush(stdin);
    scanf("%s%s%s",&c,&d,&e);
    for (i=0; i<count; i++)
        for(j=0; j<N; j++)
            if (strcmp(abc[i].age,c)<=0&&strcmp(abc[i].age,d)>=0&&strcmp(abc[i].sex,e)==0)
            {
                printf("����ʾ�������ޡ��������ޡ��Ա�Ϊ��%s%s%s����Ա����Ϣ��\n\n",c,d,e);
                printf("��Ա����Ϣ���£�\n ��ţ� %s\n���䣺 %s\n������ %s\n�Ա� %s\n���䣺 %s\nְ�� %s\n���ţ� %s\nסַ��%s\n\n",&abc[i].numb,&abc[i].str,&abc[i].name,&abc[i].sex,&abc[i].age,abc[i].post,&abc[i].dep,abc[i].add);
                x++;
            }
    if (x==0)
            printf("δ�ҵ���Ӧ��Ա����Ϣ��\n");
    printf("\n����0�������ѯ�����������ַ��򷵻����˵���\n");
    fflush(stdin);
    char a=getchar();
    if(a=='0')
        query3(abc);
    else
        back(abc);
}
void query4(wor abc[])       //���벿�ţ�����������з�������Ա����¼������
{
    system("cls");
    char c[N];
    int j,m,t;
    printf("\n�����벿�ţ�\n");
    fflush(stdin);
    scanf("%s",&c);
    for (i=0; i<count; i++)
        if(strcmp(abc[i].dep,c)==0)
        {
            for(j=0; j<N-1; j++)
                for(m=0; m<N-j; m++)
                {
                    if(abc[count].str[m]<abc[count].str[m+1])                       //�Ƚϴ�С������
                    {
                        t=abc[count].str[m];
                        abc[count].str[m]=abc[count].str[m+1];
                        abc[count].str[m+1]=t;
                    }
                }
        printf("����ʾ����Ϊ��%s����Ա����Ϣ��\n\n",c);
        printf("��Ա����Ϣ���£�\n ��ţ� %s\n���䣺 %s\n������ %s\n�Ա� %s\n���䣺 %s\nְ�� %s\n���ţ� %s\nסַ��%s\n\n",&abc[i].numb,&abc[i].str,&abc[i].name,&abc[i].sex,&abc[i].age,abc[i].post,&abc[i].dep,abc[i].add);
        x++;
        }
    if (x==0)
            printf("δ�ҵ���Ӧ��Ա����Ϣ��\n");
    printf("\n����0�������ѯ�����������ַ��򷵻����˵���\n");
    fflush(stdin);
    char a=getchar();
    if(a=='0')
        query4(abc);
    else
        back(abc);
}
