//10.8������ƽ����˵�Ĳ������������һ��ͬѧ���ſε�ƽ���֣�Ҳ������һ�ſε�����ͬѧƽ���֣�Ҳ����������ͬѧ���гɼ���ƽ���֣������ǵ�һ�����
#include <stdio.h>
#define N 10   //�������鳤�ȣ�ע�⣬ѧ������δ�ؾ������鳤��N
struct student
{
    int num;
    float math;
    float english;
    float c_language;
};

void fun(struct student *p,int n);//��������
main()
{
    struct student str[N];
    int n;
    printf("������ѧ��������");
    scanf("%d",&n);  //����������ѧ������n��Ӧ�ñ�֤n<=N
    fun(str,n);     //ע�⣺����������ʵ�Σ�����������ʵ�Σ�ѧ������Ҳ��ʵ��
}
void fun(struct student *p,int n)//pָ���������������е�str[0]Ԫ��
{
    struct student *s;
    float ave=0;
    int i=0;//������ʾѧ���ı��
    s=p;
    while(s<p+n)//ѭ������һ����ѧ���ĸ���n
    {
        s->num=i++;//���0����0��Ԫ�ص�num��Ա
        printf("�������%d��ѧ���ɼ���\n",s->num+1);//+1��Ϊ�˷������
        scanf("%f%f%f",&s->math,&s->english,&s->c_language);//�ɼ��ÿո�ָ����س�������ǰ����
        ave=(s->math+s->english+s->c_language)/3.0;
        printf("������ƽ���ɼ�Ϊ��%.2f\n",ave);
        ave=0;//Ϊ��һ��ͬѧ��ƽ��ֵ����
        s++;//sָ����һ��Ԫ��
    }
}
