#if 1
#include"stdio.h"
#include"stdlib.h"
#include"malloc.h"
#include"string.h"
void tijiao()
{
	int rnum, i, j, ren[100];
	float cputime[100], a = 0, b;
	cputime[0] = 0;
	printf("������������:");
	scanf_s("%d", &rnum);
	printf("��˳������cpuʱ��:");
	for (i = 1; i <= rnum; i++)
	{
		scanf_s("%f", &cputime[i]);
	}
	printf("�ȴ�ʱ��:");
	for (i = 1; i <= rnum + 1; i++)
	{
		printf("%.2f ", a);
		a = cputime[i] + a;
	}
	a = 0;
	printf("\n");
	printf("����ʱ��:");
	for (i = 1; i <= rnum; i++)
	{
		a = cputime[i] + a;
		printf("%.2f ", a);
	}
	a = 0;
	printf("\n");
	printf("��ʼʱ��:");
	for (i = 1; i <= rnum + 1; i++)
	{
		printf("%.2f ", a);
		a = cputime[i] + a;
	}
	a = 0;
	printf("\n");
	printf("ƽ��ʱ��:");
	for (i = 1; i <= rnum; i++)
	{
		a = cputime[i] + a;
		b = a / rnum;
	}
	printf("%.1f ", b);
}

void pingjun()
{
	int i, j, k, t, ren[100], rnum;
	float cputime[100], a = 0, b;
	cputime[0] = 0;
	printf("������������:");
	scanf_s("%d", &rnum);
	printf("��˳������cpuʱ��:");
	for (i = 1; i <= rnum; i++)
	{
		scanf_s("%f", &cputime[i]);
	}
	for (i = 1; i <= rnum - 1; i++)
	{
		k = i;
		for (j = i + 1; j <= rnum; j++)
		{
			if (cputime[k] > cputime[j])k = j;
		}
		if (k != i)
		{
			t = cputime[k]; cputime[k] = cputime[i]; cputime[i] = t;
		}
	}
	printf("�ȴ�ʱ��:");
	for (i = 1; i <= rnum + 1; i++)
	{
		printf("%.2f ", a);
		a = cputime[i] + a;
	}
	a = 0;
	printf("\n");
	printf("����ʱ��:");
	for (i = 1; i <= rnum; i++)
	{
		a = cputime[i] + a;
		printf("%.2f ", a);
	}
	a = 0;
	printf("\n");
	printf("��ʼʱ��:");
	for (i = 1; i <= rnum + 1; i++)
	{
		printf("%.2f ", a);
		a = cputime[i] + a;
	}
	a = 0;
	printf("\n");
	printf("ƽ��ʱ��:");
	for (i = 1; i <= rnum; i++)
	{
		a = cputime[i] + a;
		b = a / rnum;
	}
	printf("%.2f ", b);
}
int main()
{
	int num;
	printf("1.���ύ˳��ִ��\n");
	printf("2.��ƽ���ȴ�ʱ�����˳��ִ��\n");
	scanf_s("%d", &num);
	switch (num)
	{
	case 1:tijiao(); break;
	case 2:pingjun(); break;
	}


}
#endif

#if 0
#endif