
//10.9���ͻ��������ֵ�˳������
#include <stdio.h>
#define N 10   //�������鳤�ȣ�ע�⣬�ͻ�����δ�ؾ������鳤��N
struct customer
{
    char name[10];
    char tel[11];//�绰����һ�㲻�����ͣ����ַ������Ǻô���
};
void fun(struct customer *s,int n);
main()
{
    struct customer cus[N];
    int n;
    printf("������ͻ�������");
    scanf("%d",&n);  //����������ͻ�����n��Ӧ��n<=N
    fun(cus,n);
}
void fun(struct customer *s,int n)//sָ���������������е�cus[0]
{
    int i=0,j;
    char ch;
    struct customer *p=s,t;
    getchar();//�������и�scanf���س����������getchar�ǰ�����س����յ�
    while(i<n)//n�ǿͻ����������while��ͨ����������ͻ���Ϣ
    {
        gets(p->name);
        gets(p->tel);
        p++;//pָ����һ��Ԫ��
        i++;
    }
    for(i=0;i<n-1;i++)//ѡ�������μ�
        for(j=i+1;j<n;j++)
            if(strcmp(s[i].name,s[j].name)>0)//һ��Ҫ���Ϊʲô��strcmp��s[i].name>s[j].name���Բ���
            {
                t=s[i];
                s[i]=s[j];
                s[j]=t;
            }
    printf("�����Ŀͻ���Ϣ��\n");
    for(p=s;p<s+n;p++)
        printf("%s\t%s\n",p->name,p->tel);
}
