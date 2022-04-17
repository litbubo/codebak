#include <stdio.h>
#include <string.h>          //����Ƚϴ�С
#include <stdlib.h>          //�����Ļ
#define N 50
typedef struct violation     //����ṹ�����VIO
{
    char numb[N];            //���
    char brand[N];           //���ƺ�
    char name[N];            //��������
    char sex[N];             //�Ա�
    char viol[N];            //Υ�����
    char time[N];            //Υ��ʱ��
    char place[N];           //�ص�
} VIO;

int count=0;                 //�Ѵ洢�Ľṹ����������
int i;                       //ȫ�� ����ѭ��
char ch;                     //ȫ��

void input(VIO tra[]);       //1��¼��
void deleted(VIO tra[]);     //2��ɾ��
void modify(VIO tra[]);      //3���޸�
void print(VIO tra[]);       //4����ʾ
void query(VIO tra[]);       //5����ѯ
void statistics(VIO tra[]);  //6��ͳ��
void exits();                //7���˳�

void fun0(VIO tra[]);        //�����ƺŲ�ѯΥ��
void fun1(VIO tra[]);        //������������ѯΥ��
void swit(VIO tra[]);        //ѡ����
void back(VIO tra[]);        //�������˵�
void menu();                 //�˵�
int judge();                 //�ж������Ƿ���

void main()
{
    VIO tra[N];              //���������������
    swit(tra);               //����ѡ��˵�
}

void swit(VIO tra[])         //ѡ��˵����������ֽ�����Ӧ����
{
    system("cls");           //�����Ļ
    switch (judge())
    {
    case 1 :
        input(tra);
        break;
    case 2 :
        deleted(tra);
        break;
    case 3 :
        modify(tra);
        break;
    case 4 :
        print(tra);
        break;
    case 5 :
        query(tra);
        break;
    case 6 :
        statistics(tra);
        break;
    case 7 :
        exits();
        break;
    }
}

int judge()                  //�ж������Ƿ���Ϲ���
{
    int x;
    menu();
    printf ("�������Ӧ���ʵ����ع��ܣ�");
    setbuf(stdin, NULL);     //����������뻺����
    scanf ("%d",&x);
    if (x<1||x>7)
    {
        system("cls");       //�����Ļ
        printf("\n****************�����������������****************\n");
        judge();             //���������������µ��ú���
    }
    else
        return x;
}

void menu()                  //��ӡ�˵�
{
    printf ("\n");
    printf ("----------------������ͨΥ�¹������----------------\n\n");
    printf ("\t��1��¼��Υ����Ϣ��\n");
    printf ("\t��2��ɾ��Υ����Ϣ��\n");
    printf ("\t��3���޸��Ѿ�¼������ݡ�\n");
    printf ("\t��4����ʾ����Υ�µ���Ϣ��\n");
    printf ("\t��5����ѯ��\n");
    printf ("\t��6��ͳ�ơ�\n");
    printf ("\t��7���˳�����\n\n");
    printf ("----------------------------------------------------\n");
}

void back(VIO tra[])       //�������˵�
{
    printf("\n���������ַ��������˵���\n");
    setbuf(stdin, NULL);
    scanf("%c",&ch);
    if (1)
        swit(tra);
}

void input(VIO tra[])       //¼��
{
    system("cls");
    printf ("\n����ѡ��¼�빦�ܡ�\n");
    printf("\n��������������ɵ�6λ��ţ�\n");
    setbuf(stdin, NULL);
    scanf("%s",&tra[count].numb);
    printf("�����복�ƺţ�\n");
    setbuf(stdin, NULL);
    scanf("%s",&tra[count].brand);
    printf("�����복��������\n");
    setbuf(stdin, NULL);
    scanf("%s",&tra[count].name);
    printf("�������Ա�\n");
    setbuf(stdin, NULL);
    scanf("%s",&tra[count].sex);
    printf("������Υ�������\n");
    setbuf(stdin, NULL);
    scanf("%s",&tra[count].viol);
    printf("������Υ��ʱ�䣺\n");
    setbuf(stdin, NULL);
    scanf("%s",&tra[count].time);
    printf("������ص㣺\n");
    setbuf(stdin, NULL);
    scanf("%s",&tra[count].place);
    count++;
    printf("¼�����������B�򷵻����˵������������ַ������¼�룺\n");
    setbuf(stdin, NULL);
    scanf("%c",&ch);
    switch(ch)
    {
    case 'B':
        swit(tra);
        break;
    default :
        input(tra);
        break;
    }
}

void deleted(VIO tra[])     //ɾ��
{
    system("cls");
    printf ("\n����ѡ��ɾ�����ܡ�\n");
    if (count==0)            //�ж��Ƿ����Ѵ洢�ļ�¼
    {
        printf("\n�Ѵ洢��Υ�¼�¼Ϊ�գ��޷�ɾ����\n");
        back(tra);
    }
    else
    {
        int m=0,n=count;
        char bi[N];
        printf("\n��������Ҫɾ����Υ�±�ţ�\n");
        setbuf(stdin, NULL);
        scanf("%s",bi);
        for (i=0; i<count; i++)                      //��ÿ��Υ�¼�¼����ѭ��
        {
            if (strcmp(tra[i].numb,bi)==0)           //�ж�Υ�±���Ƿ���ͬ
            {
                for (i=m; i<count; i++)              //����ɾ��Υ�¼�¼��ļ�¼��ǰ�ƶ�
                    tra[i]=tra[i+1];
                count--;
                if (count<n)                         //ɾ�����Υ�¼�¼����ɾ��ǰ��ɾ���ɹ�
                    printf("ɾ���ɹ���\n");
            }
            m++;
        }
        if (n==count)                                //ɾ�����Υ�¼�¼����ɾ��ǰ��δɾ��
            printf("δ�ҵ���Ӧ��ŵ�Υ�¼�¼��\n");
        printf("\n����B�򷵻����˵������������ַ������ɾ����\n");
        setbuf(stdin, NULL);
        scanf("%c",&ch);
        switch(ch)
        {
        case 'B':
            swit(tra);
            break;
        default :
            deleted(tra);
            break;
        }
    }

}

void modify(VIO tra[])      //�޸�
{
    system("cls");
    printf ("\n����ѡ���޸Ĺ��ܡ�\n");
    if (count==0)
    {
        printf("\n�Ѵ洢��Υ�¼�¼Ϊ�գ��޷��޸ġ�\n");
        back(tra);
    }
    else
    {
        char bi[N];
        int x,y=1;
        printf("\n��������Ҫ�޸ĵ�Υ�±�ţ�\n");
        setbuf(stdin, NULL);
        scanf("%s",bi);
        for (i=0; i<count; i++)
            if (strcmp(tra[i].numb,bi)==0)
            {
                printf("����ʾ��š�%s����Υ����Ϣ��\n\n",bi);
                printf("��ţ�      %s\n",&tra[i].numb);
                printf("���ƺţ�    %s\n",&tra[i].brand);
                printf("����������  %s\n",&tra[i].name);
                printf("�Ա�      %s\n",&tra[i].sex);
                printf("Υ�������  %s\n",&tra[i].viol);
                printf("Υ��ʱ�䣺  %s\n",tra[i].time);
                printf("�ص㣺      %s\n",&tra[i].place);
                printf("\nѡ����Ҫ�޸ĵ���Ϣ:\n\n");
                printf("��1����� ��2�����ƺ� ��3���������� ��4���Ա� ��5��Υ����� ��6��Υ��ʱ�� ��7���ص㡣");
                printf("�������볬�ޣ��������²��ҡ���\n");
                setbuf(stdin, NULL);
                scanf("%d",&x);
                printf("�������޸ĺ�����ݣ�\n");
                setbuf(stdin, NULL);
                switch(x)                                  //�����������޸���Ӧ����
                {
                case 1:
                    scanf("%s",&tra[i].numb);
                    break;
                case 2:
                    scanf("%s",&tra[i].brand);
                    break;
                case 3:
                    scanf("%s",&tra[i].name);
                    break;
                case 4:
                    scanf("%s",&tra[i].sex);
                    break;
                case 5:
                    scanf("%s",&tra[i].viol);
                    break;
                case 6:
                    scanf("%s",&tra[i].time);
                    break;
                case 7:
                    scanf("%s",&tra[i].place);
                    break;
                default:
                    modify(tra);
                    break;
                }
                printf("�޸ĳɹ�����\n");
                y=0;
            }
        if (y)
            printf("δ�ҵ���Ӧ��ŵ�Υ�¼�¼��\n");
        printf("\n����B�򷵻����˵������������ַ�������޸ģ�\n");
        setbuf(stdin, NULL);
        scanf("%c",&ch);
        switch(ch)
        {
        case 'B':
            swit(tra);
            break;
        default :
            modify(tra);
            break;
        }
    }

}

void print(VIO tra[])       //��ʾ
{
    system("cls");
    printf ("\n����ѡ����ʾ����Υ�¹��ܡ�\n");
    if (count==0)
        printf("\n�Ѵ洢��Υ�¼�¼Ϊ�ա�\n");
    else
        for (i=0; i<count; i++)                        //��ÿ������ѭ���������ӡ
               {
                printf("��ţ�      %s\n",&tra[i].numb);
                printf("���ƺţ�    %s\n",&tra[i].brand);
                printf("����������  %s\n",&tra[i].name);
                printf("�Ա�      %s\n",&tra[i].sex);
                printf("Υ�������  %s\n",&tra[i].viol);
                printf("Υ��ʱ�䣺  %s\n",tra[i].time);
                printf("�ص㣺      %s\n\n",&tra[i].place);
               }
    back(tra);
}

void query(VIO tra[])       //��ѯ
{
    system("cls");
    printf ("\n����ѡ���ѯ���ܡ�\n");
    if (count==0)
    {
        printf("\n�Ѵ洢��Υ�¼�¼Ϊ�ա�\n");
        back(tra);
    }
    else
    {
        printf("��������ѡ��Ĳ�ѯ��ʽ��\n");
        printf("\n��a�������ƺŲ���Υ�¼�¼\n\n��b����������������Υ�¼�¼");
        printf("�������볬�ޣ��������²��ҡ���\n");
        char c;
        setbuf(stdin, NULL);
        scanf("%c",&c);
        switch(c)
        {
        case 'a':
            fun0(tra);
            break;
        case 'b':
            fun1(tra);
            break;
        default :
            query(tra);
            break;
        }
    }
}

void statistics(VIO tra[])  //ͳ��
{
    system("cls");
    printf ("\n����ѡ��ͳ�ƹ��ܡ�\n");
    if (count==0)
    {
        printf("\n�Ѵ洢��Υ�¼�¼Ϊ�ա�\n");
        back(tra);
    }
    else
    {
        char date[N];
        int y=1;
        printf("\n��������Ҫͳ�Ƶ����ڣ�����20201231����\n");
        setbuf(stdin, NULL);
        scanf("%s",date);
        for (i=0; i<count; i++)
            if (strcmp(tra[i].time,date)==0)
            {
                printf("����ʾ����Ϊ��%s����Υ����Ϣ��\n\n",date);
                printf("��ţ�      %s\n",&tra[i].numb);
                printf("���ƺţ�    %s\n",&tra[i].brand);
                printf("����������  %s\n",&tra[i].name);
                printf("�Ա�      %s\n",&tra[i].sex);
                printf("Υ�������  %s\n",&tra[i].viol);
                printf("Υ��ʱ�䣺  %s\n",tra[i].time);
                printf("�ص㣺      %s\n",&tra[i].place);
                y=0;
            }
        if (y)
            printf("δ�ҵ���Ӧ���ڵ�Υ�¼�¼��\n");
        printf("\n����B�򷵻����˵������������ַ������ͳ�ƣ�\n");
        setbuf(stdin, NULL);
        scanf("%c",&ch);
        switch(ch)
        {
        case 'B':
            swit(tra);
            break;
        default :
            statistics(tra);
            break;
        }
    }
}

void exits()                 //�˳�
{
    printf("\n\n----------------------�˳��ɹ�----------------------\n");
    printf("\n\n------------��лʹ�ó�����ͨΥ�¹������------------\n\n");
}

void fun0(VIO tra[])        //�����ƺŲ�ѯΥ��
{
    char pai[N];
    int j=0,y=1;
    printf("\n��������Ҫ��ѯ��Υ�³��ƺţ�\n");
    setbuf(stdin, NULL);
    scanf("%s",pai);
    for (i=0; i<count; i++)
        if (strcmp(tra[i].brand,pai)==0)
        {
            printf("����ʾ���ƺ�Ϊ��%s����Υ����Ϣ��\n\n",pai);
            printf("��ţ�      %s\n",&tra[i].numb);
                printf("���ƺţ�    %s\n",&tra[i].brand);
                printf("����������  %s\n",&tra[i].name);
                printf("�Ա�      %s\n",&tra[i].sex);
                printf("Υ�������  %s\n",&tra[i].viol);
                printf("Υ��ʱ�䣺  %s\n",tra[i].time);
                printf("�ص㣺      %s\n",&tra[i].place);
            j++;                              //ͳ��ͬһ���ƺŵ�Υ�´���
            y=0;
            if (j>5)
                printf("\n���棺�ѳ������Υ�£���\n");
        }
    if (y)
        printf("δ�ҵ���Ӧ���ƺŵ�Υ�¼�¼��\n");
    printf("\n����B�򷵻����˵������������ַ��������ѯ��\n");
    setbuf(stdin, NULL);
    scanf("%c",&ch);
    switch(ch)
    {
    case 'B':
        swit(tra);
        break;
    default :
        query(tra);
        break;
    }
}

void fun1(VIO tra[])        //������������ѯΥ��
{
    char na[N];
    int y=1;
    printf("\n��������Ҫ��ѯ�ĳ���������\n");
    setbuf(stdin, NULL);
    scanf("%s",na);
    for (i=0; i<count; i++)
        if (strcmp(tra[i].name,na)==0)
        {
            printf("����ʾ����Ϊ��%s����Υ����Ϣ��\n\n",na);
            printf("��ţ�      %s\n",&tra[i].numb);
                printf("���ƺţ�    %s\n",&tra[i].brand);
                printf("����������  %s\n",&tra[i].name);
                printf("�Ա�      %s\n",&tra[i].sex);
                printf("Υ�������  %s\n",&tra[i].viol);
                printf("Υ��ʱ�䣺  %s\n",tra[i].time);
                printf("�ص㣺      %s\n",&tra[i].place);
            y=0;
        }
    if (y)
        printf("δ�ҵ�������Υ�¼�¼��\n");
    printf("\n����B�򷵻����˵������������ַ��������ѯ��\n");
    setbuf(stdin, NULL);
    scanf("%c",&ch);
    switch(ch)
    {
    case 'B':
        swit(tra);
        break;
    default :
        query(tra);
        break;
    }
}
