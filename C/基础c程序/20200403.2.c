#include <stdio.h>
#define N 50
struct stu
{
    char num[N];
    char name[N];
    char age[N];
};
struct stu student[N];
int count=0;
char ch;
void input();
void print();
void swit();
void exits();
void main()
{
    swit();
}
void swit()
{
    printf("1:���룻2�������3���˳�\n");
    printf("���������֣�\n");
    setbuf(stdin, NULL);
    int x;
    scanf("%d",&x);
    switch (x)
    {
    case 1 :
        input();
        break;
    case 2 :
        print();
        break;
    case 3 :
        exits() ;
        break;
    }
}
void input()
{
    printf ("����ѡ�����빦�ܡ�\n");
    printf("�������ţ�\n");
    setbuf(stdin, NULL);
    scanf("%s",&student[count].num);
    printf("������������\n");
    setbuf(stdin, NULL);
    scanf("%s",&student[count].name);
    printf("���������䣺\n");
    setbuf(stdin, NULL);
    scanf("%s",&student[count].age);
    count++;
    printf("¼�����������B�򷵻����˵������������ַ������¼�룺\n");
    setbuf(stdin, NULL);
    scanf("%c",&ch);
    switch(ch)
    {
    case 'B':
        swit();
        break;
    default :
        input();
        break;
    }
}
void print()
{
    int i;
    printf ("����ѡ��������ܡ�\n");
    for (i=0; i<count; i++)
        printf("��ţ�%s\n������%s\n���䣺%s\n\n\n",&student[i].num,&student[i].name,&student[i].age);
    printf("���������ַ��������˵���\n");
    setbuf(stdin, NULL);
    scanf("%c",&ch);
    if (1)
        swit();
}
void exits()
{
    printf("�˳��ɹ�");
}

