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
	printf("请输入任务数:");
	scanf_s("%d", &rnum);
	printf("按顺序输入cpu时间:");
	for (i = 1; i <= rnum; i++)
	{
		scanf_s("%f", &cputime[i]);
	}
	printf("等待时间:");
	for (i = 1; i <= rnum + 1; i++)
	{
		printf("%.2f ", a);
		a = cputime[i] + a;
	}
	a = 0;
	printf("\n");
	printf("结束时间:");
	for (i = 1; i <= rnum; i++)
	{
		a = cputime[i] + a;
		printf("%.2f ", a);
	}
	a = 0;
	printf("\n");
	printf("开始时间:");
	for (i = 1; i <= rnum + 1; i++)
	{
		printf("%.2f ", a);
		a = cputime[i] + a;
	}
	a = 0;
	printf("\n");
	printf("平均时间:");
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
	printf("请输入任务数:");
	scanf_s("%d", &rnum);
	printf("按顺序输入cpu时间:");
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
	printf("等待时间:");
	for (i = 1; i <= rnum + 1; i++)
	{
		printf("%.2f ", a);
		a = cputime[i] + a;
	}
	a = 0;
	printf("\n");
	printf("结束时间:");
	for (i = 1; i <= rnum; i++)
	{
		a = cputime[i] + a;
		printf("%.2f ", a);
	}
	a = 0;
	printf("\n");
	printf("开始时间:");
	for (i = 1; i <= rnum + 1; i++)
	{
		printf("%.2f ", a);
		a = cputime[i] + a;
	}
	a = 0;
	printf("\n");
	printf("平均时间:");
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
	printf("1.按提交顺序执行\n");
	printf("2.按平均等待时间最短顺序执行\n");
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