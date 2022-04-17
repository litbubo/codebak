#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30
#define MIN 15
typedef struct
{
    char Name[MIN]={'\0'};    //����
    char Sex[MIN]={'\0'};       //�Ա�
    char City[MIN]={'\0'};       //����
    char PostCode[MIN]={'\0'};      //�ʱ�
    char PhoneNumber[MIN]={'\0'};      //�ֻ���
    char QQ[MIN]={'\0'};          //QQ��
    char Email[MAX]={'\0'};   //����
} ConType;
typedef struct node
{
    ConType data;         //�����ϵ����Ϣ
    struct node *next;        //ָ����һ���ڵ��ָ��
} ConList;       //��ϵ�˵�����ڵ�����

void ModifyCon(ConList *L);
void ReadFile(ConList *&L);
void SaveFile(ConList *L);
void InputCon(ConList *&L);
void DeleteCon(ConList *&L);
void DisplayCon(ConList *&L);
void LocateCon(ConList *L);
void DestroyCon(ConList *&L);
ConList *LocateAll(ConList *L, int select, char s[MAX]);
void DispCon(ConType con);
void ItemModifyCom(ConList *L, int item);
void DeleteOne(ConList *&L);
void DeleteAll(ConList *&L);

void ModifyCon(ConList *L)     //�޸���ϵ����Ϣ
{
    system("cls");
    ConList *p;
    ConType con;
    char s[MIN] = {'\0'};      //����ѡ��
    char search[MIN] = {'\0'};     //����Ҫ���ҵ���ϵ��
    int item = 9;     //ѡ���޸���ϵ����Ŀ
    int select;      //����ѡ��
    int i = 0;
    while (i < 100)
    {
        system("cls");
        printf("\t       �޸�\n");
        printf("\t******************** \n");
        printf("\t�� �����������밴1\n");
        printf("\t�� ���ֻ��Ų����밴2\n");
        printf("\t�� ��QQ�Ų����밴3\n");
        printf("\t�� ��Email�����밴4\n");
        printf("\t�� �˳��밴0\n");
        printf("\t********************\n");
        printf("\n>>���������ѡ��");
        scanf("%s", &s);         //����ѡ��
        select = (int)s[0] - 48;       //����ѡ��
        p = (ConList *)malloc(sizeof(ConList));
        switch (select)
        {
        case 1:
            //����������
            printf("\n>>��������޸��˵�������");
            scanf("%s", search);
            p = LocateAll(L, 1, search);      //���������ҵ�������������ָ��
            if (p == NULL)
            {
                printf("\n��ʾ���޴���ϵ�ˣ������²���\n\n");
                system("pause");
            }
            else
            {
                DispCon(p->data);
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n�ɹ��޸ĵ���Ŀ���£�\n");
                printf("\t1. ����");
                printf("\t\t2. �Ա�\n");
                printf("\t3. ����");
                printf("\t\t4. �ʱ�\n");
                printf("\t5. �ֻ���");
                printf("\t6. QQ��\n");
                printf("\t7. Email");
                printf("\t0. �˳�\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                while (1)
                {
                    printf("\n\n>>��ѡ����Ҫ�޸ĵ����ݣ�");
                    scanf("%d", &item);
                    if (item == 0)
                        break;
                    ItemModifyCom(p, item);
                }
            }
            break;        case 2:
            //���ֻ��Ų���
            printf(">>��������޸��˵��ֻ��ţ�");
            scanf("%s", search);
            p = LocateAll(L, 1, search);
            if (p == NULL)
            {
                printf("��ʾ���޴���ϵ�ˣ������²���\n");
                system("pause");
            }
            else
            {
                DispCon(p->data);
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n�ɹ��޸ĵ���Ŀ���£�\n");
                printf("\t1. ����");
                printf("\t\t2. �Ա�\n");
                printf("\t3. ����");
                printf("\t\t4. �ʱ�\n");
                printf("\t5. �ֻ���");
                printf("\t6. QQ��\n");
                printf("\t7. Email");
                printf("\t0. �˳�\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                while (1)
                {
                    printf("\n\n>>��ѡ����Ҫ�޸ĵ����ݣ�");
                    scanf("%d", &item);
                    if (item == 0)
                        break;
                    ItemModifyCom(p, item);
                }
            }
            break;
        case 3:
            //��QQ�Ų���
            printf(">>��������޸��˵�QQ�ţ�");
            scanf("%s", search);
            p = LocateAll(L, 1, search);
            if (p == NULL)
            {
                printf("��ʾ���޴���ϵ�ˣ������²���\n");
                system("pause");
            }
            else
            {
                DispCon(p->data);
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n�ɹ��޸ĵ���Ŀ���£�\n");
                printf("\t1. ����");
                printf("\t\t2. �Ա�\n");
                printf("\t3. ����");
                printf("\t\t4. �ʱ�\n");
                printf("\t5. �ֻ���");
                printf("\t6. QQ��\n");
                printf("\t7. Email");
                printf("\t0. �˳�\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                while (1)
                {
                    printf("\n\n>>��ѡ����Ҫ�޸ĵ����ݣ�");
                    scanf("%d", &item);
                    if (item == 0)
                        break;
                    ItemModifyCom(p, item);
                }
            }
            break;
        case 4:
            //��Email����
            printf("����Email��");
            scanf("%s", search);
            p = LocateAll(L, 1, search);
            if (p == NULL)
            {
                printf("��ʾ���޴���ϵ�ˣ������²���\n");
                system("pause");
            }
            else
            {
                DispCon(p->data);
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n�ɹ��޸ĵ���Ŀ���£�\n");
                printf("\t1. ����");
                printf("\t\t2. �Ա�\n");
                printf("\t3. ����");
                printf("\t\t4. �ʱ�\n");
                printf("\t5. �ֻ���");
                printf("\t6. QQ��\n");
                printf("\t7. Email");
                printf("\t0. �˳�\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                while (1)
                {
                    printf("\n\n>>��ѡ����Ҫ�޸ĵ����ݣ�");
                    scanf("%d", &item);
                    if (item == 0)
                        break;
                    ItemModifyCom(p, item);
                }
            }
            break;        case 0:
            //0
            return;
        default:
            printf("\n��ʾ������������������룡\n\n");
            system("pause");
            break;
        }
        ++i;
    }
}

void ReadFile(ConList *&L)       //��ȡ�ļ���������ϵ�˵�����L
{
    FILE *fp;
    ConType con;
    ConList *p, *r;
    int n = 0;
    L = (ConList *)malloc(sizeof(ConList));       //����ͷ���
    r = L;
    if ((fp = fopen("contacts.txt", "rb")) == NULL)       //������contacts.txt�ļ�
    {
        if ((fp = fopen("contacts.txt", "wb")) == NULL)
            printf("  ��ʾ�����ܴ���contacts.txt�ļ�\n");
        printf("ʧ��");
    }
    else      //������contacts.txt�ļ�
    {
        fseek(fp, 0, SEEK_SET);
        while (fread(&con, sizeof(ConType), 1, fp) == 1)
        { //����β�巨����������L
            p = (ConList *)malloc(sizeof(ConList));
            p->data = con;
            r->next = p;
            r = p;
            n++;
        }
    }
    r->next = NULL;
    printf("��ʾ��ͨѶ¼�й���%d����ϵ��\n", n);
    fclose(fp);
}

void SaveFile(ConList *L)     //�����ļ�
{
    ConList *p = L->next;
    int n = 0;
    FILE *fp;
    if ((fp = fopen("contacts.txt", "wb")) == NULL)
    {
        printf("  ��ʾ�����ܴ����ļ�contacts.txt\n");
        return;
    }
    fseek(fp,0, SEEK_END);
    while (p != NULL)
    {
        fwrite(&p->data, sizeof(ConType), 1, fp);
        p = p->next;
        n++;
    }
    fclose(fp);
    DestroyCon(L);      //�ͷ���ϵ�˵�����L
    if (n > 0)
        printf("��ʾ���ɹ����%d����ϵ��\n", n);
    else
        printf("��ʾ��û������κ���ϵ��\n");
}

void InputCon(ConList *&L)       //���һ����ϵ��
{
    system("cls");
    ConType p;
    ConList *s;
    printf("\t          ���\n");
    printf("\t************************\n");
    printf("\t      �� ����������0\n");
    printf("\t************************\n\n");
    printf(">>����������");
    scanf("%s", &p.Name);
    if (strcmp(p.Name, "0") == 0)
        return;
    printf(">>�����Ա�");
    scanf("%s", &p.Sex);
    printf(">>������У�");
    scanf("%s", &p.City);
    printf(">>�����ʱࣺ");
    scanf("%s", &p.PostCode);
    printf(">>�����ֻ��ţ�");
    scanf("%s", &p.PhoneNumber);
    printf(">>����QQ��");
    scanf("%s", &p.QQ);
    printf(">>����Email��");
    scanf("%s", &p.Email);
    s = (ConList *)malloc(sizeof(ConList));
    s->data = p;
    s->next = L->next;      //����ͷ�巨����ڵ�s
    L->next = s;
    printf("\n��ʾ����ӳɹ�\n\n");
    system("pause");
}

void DeleteCon(ConList *&L)       //ɾ����ϵ��
{
    system("cls");
    int selection;
    while (1)
    {
        printf("\t          ɾ��\n");
        printf("\t************************\n");
        printf("\t�� ɾ��ĳһ����ϵ���밴1\n");
        printf("\t�� ɾ��ȫ����ϵ���밴2\n");
        printf("\t�� �����밴0\n");
        printf("\t************************\n\n");
        printf(">>���������ѡ��");
        scanf("%d", &selection);
        switch (selection)
        {
        case 0:
            return;
        case 1:
            DeleteOne(L);
            break;
        case 2:
            DeleteAll(L);
            break;
        default:
            printf("  ��ʾ��������������������");
        }
    }
}

void DisplayCon(ConList *&L)       //���ͨѶ¼��������ϵ�˵���Ϣ
{
    system("cls");
    printf("\t\t\t\t          ���\n");
    printf("\t\t\t\t************************\n");
    printf("\t\t\t\t    �� �����밴�����\n");
    printf("\t\t\t\t************************\n\n");
    ConList *p = L->next;
    if (p == NULL)
        printf("  ��ʾ��ͨѶ¼��û���κ���ϵ��\n");
    else
    {
        printf("\n\t����\t�Ա�\t����\t�ʱ�\t�ֻ���\t\tQQ��\t\tEmail\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        while (p != NULL)
        {
            printf("\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", p->data.Name, p->data.Sex, p->data.City, p->data.PostCode, p->data .PhoneNumber
    , p->data.QQ, p->data.Email);
            p = p->next;
        }
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    }
}

void LocateCon(ConList *L)      //ͨ���������ֻ��Ų�����ϵ��
{
    system("cls");
    ConList *p;
    char s[MAX] = {'\0'};
    char select[MAX] = {'\0'};
    p = (ConList *)malloc(sizeof(ConList));
    printf("\t            ��ѯ\n");
    printf("\t**************************\n");
    printf("\t�� ��������ѯ�밴1\n\t�� ���绰�����ѯ�밴2\n\t�� �˳��밴0\n ");
    printf("\t**************************\n");
    while (1)
    {
        printf("\n>>��������ҷ�ʽ��");
        scanf("%s", select);
        int t = (int)select[0];
        if (t - 48 == 1) //��������
        {
            printf("\n>>������Ҫ���ҵ�������");
            scanf("%s", s, MAX);
            p = LocateAll(L, 1, s);       //1��ӦLocateAll�е���������
            if (p != NULL)
            {
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~");
                DispCon(p->data); //������ҵ���ϵ����Ϣ
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            }
            else
            {
                printf("\n��ʾ����������������ϵ�˲����ڣ� ����������ѡ����ҷ�ʽ\n");
            }
        }
        else if (t - 48 == 2) //�ֻ��������
        {
            printf("\n>>������Ҫ���ҵ��ֻ��ţ�");
            scanf("%s", s);
            p = LocateAll(L, 5, s);       //5��ӦLocateAll�е��ֻ��Ų���
            if (p != NULL)
            {
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~");
                DispCon(p->data); //������ҵ���ϵ����Ϣ
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            }            else
            {
                printf("�����Һ������ϵ�˲����ڣ� ����������ѡ����ҷ�ʽ\n");
            }
        }
        else if (t - 48 == 0)
        {
            printf("��0���ң�");
            return;
        }
        else
        {
            printf("����������������룡\n");
        }
    }
}

void DestroyCon(ConList *&L)       //�ͷ���ϵ�˵�����L
{
    ConList *pre = L, *p = pre->next;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

ConList *LocateAll(ConList *L, int select, char s[MAX])       //�ṩȫ�����ҹ���
{
    ConType con;
    ConList *p;
    p = L->next;
    if (p == NULL)
    {
        return NULL;
    }
    switch (select)
    {
    case 1:
        //����������
        while (p != NULL && (strcmp(p->data.Name, s)) != 0)
        {
            p = p->next;
        }
        if (p == NULL)
            return NULL;
        else
            return p;
    case 2:
        //���Ա����
        while (p != NULL && strcmp(p->data.Sex, s) != 0)
        {
            p = p->next;
        }
        if (p == NULL)
            return NULL;
        else
            return p;
    case 3:
        //�����в���
        while (p != NULL && strcmp(p->data.City, s) != 0)
        {
            p = p->next;
        }
        if (p == NULL)
            return NULL;
        else
            return p;
    case 4:
        //���ʱ����
        while (p != NULL && strcmp(p->data.PostCode, s) != 0)
        {
            p = p->next;
        }
        if (p == NULL)
            return NULL;
        else
            return p;
    case 5:
        //���ֻ��Ų���
        while (p != NULL && strcmp(p->data.PhoneNumber, s) != 0)
        {
            p = p->next;
        }
        if (p == NULL)
            return NULL;
        else
            return p;
    case 6:
        //��QQ�Ų���
        while (p != NULL && strcmp(p->data.QQ, s) != 0)
        {
            p = p->next;
        }
        if (p == NULL)
            return NULL;
        else
            return p;    case 7:
        //��Email����
        while (p != NULL && strcmp(p->data.Email, s) != 0)
        {
            p = p->next;
        }
        if (p == NULL)
            return NULL;
        else
            return p;
    }
}

void DispCon(ConType con)      //�����ϵ����Ϣ
{
    printf("\n������%s", con.Name);
    printf("\n�Ա�%s", con.Sex);
    printf("\n���У�%s", con.City);
    printf("\n�ʱࣺ%s", con.PostCode);
    printf("\n�ֻ��ţ�%s", con.PhoneNumber);
    printf("\nQQ��%s", con.QQ);
    printf("\nEmail��%s\n", con.Email);
}

void ItemModifyCom(ConList *L, int item)      //������ϵ����Ϣ��Ŀ�޸�
{
    ConList *p;
    ConType con;
    p = L;
    while (1)
    {
        switch (item)
        {
        case 0:
            printf("���˳��޸ģ�\n");
            system("pause");
            return;
        case 1:
            con = p->data;
            *con.Name = {'\0'};
            printf("\n�����޸�Ϊ��");
            scanf("%s", con.Name);
            p->data = con;
            return;
        case 2:
            con = p->data;
            *con.Sex = {'\0'};
            printf("\n�Ա��޸�Ϊ��");
            scanf("%s", con.Sex);
            p->data = con;
            return;
        case 3:
            con = p->data;
            *con.City = {'\0'};
            printf("\n�����޸�Ϊ��");
            scanf("%s", con.City);
            p->data = con;
            return;
        case 4:
            con = p->data;
            *con.PostCode = {'\0'};
            printf("\n�ʱ��޸�Ϊ��");
            scanf("%s", con.PostCode);
            p->data = con;
            return;
        case 5:
            con = p->data;
            *con.PhoneNumber = {'\0'};
            printf("\n�ֻ����޸�Ϊ��");
            scanf("%s", con.PhoneNumber);
            p->data = con;
            return;
        case 6:
            con = p->data;
            *con.QQ = {'\0'};
            printf("\nQQ���޸�Ϊ��");
            scanf("%s", con.QQ);
            p->data = con;
            return;
        case 7:
            con = p->data;
            *con.Email = {'\0'};
            printf("\nEmail�޸�Ϊ��");
            scanf("%s", con.Email);
            p->data = con;
            return;
        default:
            printf("��ʾ������������������룡\n");
            break;
        }
    }
}

void DeleteOne(ConList *&L)       //ɾ��һ����ϵ��
{
    ConList *pre = L, *p = L->next;
    char Name[10];
    printf(">>��������(����0����):");
    scanf("%s", &Name);
    if (strcmp(Name, "0") == 0)
        return;    while (p != NULL && strcmp(p->data.Name, Name) != 0)
    {
        pre = p;
        p = p->next;
    }
    if (p == NULL)
        printf("��ʾ��ָ������ϵ�˲�����\n");
    else
    {
        pre->next = p->next;
        free(p);
        printf("��ʾ��ɾ���ɹ�\n");
    }
}

void DeleteAll(ConList *&L)      //ɾ��������ϵ�ˣ����ͨѶ¼
{
    FILE *fp;
    if ((fp = fopen("contacts.txt", "wb")) == NULL)      //��д���contacts.txt�ļ�
    {
        printf("  ��ʾ�����ܴ�ͨѶ¼\n");
        return;
    }
    fclose(fp);
    DestroyCon(L);
    L = (ConList *)malloc(sizeof(ConList));
    L->next = NULL;
    system("cls");
    printf("  ��ʾ��ͨѶ¼������\n");
}

int main()
{
    ConList *L;     //��������L
    char s[MAX] = {'\0'};//
    int selection;
    L = (ConList *)malloc(sizeof(ConList));
    L->next = NULL;
    ReadFile(L);
    do
    {
        system("cls");
        system("TITLE ͨѶ¼����ϵͳ");
        system("color 04");
        printf("                          �������������� \n");
        printf("                          �辶��  ������ \n");
        printf("                          �������᩿���� \n");
        printf("                          ��������������\n");
        printf("                          �� ^���� ^  ��\n");
        printf("                             �k �� �k  \n");
        printf("                          ���𩥩����� \n");
        printf("-------------------��ӭ����ȫ������ͨѶ¼����ϵͳ--------------------\n\n");
        printf("*********************************************************************\n");
        printf("           �� �����ϵ���밴1            �� ���ͨѶ¼�밴2\n");
        printf("           �� ɾ����ϵ���밴3            �� ��ѯ��ϵ���밴4\n");
        printf("           �� �޸���ϵ���밴5            �� �˳��밴0\n");
        printf("*********************************************************************\n");
        printf("\n>>��ѡ��Ҫ���еĲ���:");
        scanf("%s",s);
        selection = (int)s[0]-48;
        switch (selection)
        {
        case 0:
            SaveFile(L);
            printf("\n");
            system("pause");
            return 0;
        case 1:
            InputCon(L);
            break;
        case 2:
            DisplayCon(L);
            system("pause");
            break;
        case 3:
            DeleteCon(L);
            break;
        case 4:
            LocateCon(L);
            break;
        case 5:
            ModifyCon(L);
            break;
        default:
            printf("\n��ʾ�������������������\n\n");
            system("pause");
        }
    } while (1);
    return 0;
}
