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
    printf("1:输入；2：输出；3：退出\n");
    printf("请输入数字：\n");
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
    printf ("您已选择输入功能。\n");
    printf("请输入编号：\n");
    setbuf(stdin, NULL);
    scanf("%s",&student[count].num);
    printf("请输入姓名：\n");
    setbuf(stdin, NULL);
    scanf("%s",&student[count].name);
    printf("请输入年龄：\n");
    setbuf(stdin, NULL);
    scanf("%s",&student[count].age);
    count++;
    printf("录入结束，输入B则返回主菜单，输入其他字符则继续录入：\n");
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
    printf ("您已选择输出功能。\n");
    for (i=0; i<count; i++)
        printf("编号：%s\n姓名：%s\n年龄：%s\n\n\n",&student[i].num,&student[i].name,&student[i].age);
    printf("输入任意字符返回主菜单：\n");
    setbuf(stdin, NULL);
    scanf("%c",&ch);
    if (1)
        swit();
}
void exits()
{
    printf("退出成功");
}

