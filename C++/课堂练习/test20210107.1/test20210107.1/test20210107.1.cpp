// test20210107.1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include   <stdio.h>
void NONO();
void  fun(int  *a, int  *b, int  *c, int  *d)
{
	int temp, temp2, temp3, temp4;
	if (*a>*b)
	{
		temp2 = *b;
		temp = *a;
	}
	else
	{
		temp = *b;
		temp2 = *a;
	}
	if (*c>*d)
	{
		temp4 = *d;
		temp3 = *c;
	}
	else
	{
		temp3 = *d;
		temp4 = *c;
	}
	if (temp>temp3)
		*a = temp;
	else
		*a = temp3;
	if (temp2<temp4)
		*d = temp2;
	else
		*d = temp4;
}
void main()
{
	int  a, b, c, d;
	printf("������4������:    ");  scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("ԭʼ˳��:    %d,%d,%d,%d\n", a, b, c, d);
	fun(&a, &b, &c, &d);
	printf("�����:      %d,%d,%d,%d\n", a, b, c, d);
	NONO();
}

void NONO()
{/* ���������ڴ��ļ����������ݣ����ú�����������ݣ��ر��ļ��� */
	FILE *fp, *wf;
	int i, a, b, c, d;

	fp = fopen("in.dat", "r");
	wf = fopen("out.dat", "w");
	for (i = 0; i<5; i++)
	{
		fscanf(fp, "%d %d %d %d", &a, &b, &c, &d);
		fun(&a, &b, &c, &d);
		fprintf(wf, "a=%d,d=%d\n", a, d);
	}
	fclose(fp);
	fclose(wf);
}
