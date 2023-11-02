#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
typedef struct {
	int number;				//学号 
	char Class[10];			//班级 
	int grade;				//成绩 
	struct {
		int bianhao;		    //课程编号 
		int mark0;			//课程成绩 
	} course[10];
} student;
typedef struct Lnode {       //快排需要的链表结构体
	int bh;
	struct Lnode* next;
} Lnode, * Linklist;
void create(student S[]) {
	time_t seed = 0;                          
	srand(time(&seed));					    //生成随机数种子 
	for (int i = 0; i < 10; i++) {			//逐个创建班级
		S[i].number = 2021065101 + i;
		strcpy_s(S[i].Class, "one");        //按班级顺序赋根据系统时间随机生成随机数值
		S[i].course[0].bianhao = 1;
		S[i].course[0].mark0 = rand() % 101;
		S[i].course[1].bianhao = 4;
		S[i].course[1].mark0 = rand() % 101;
		S[i].course[2].bianhao = 8;
		S[i].course[2].mark0 = rand() % 101;
		S[i].grade = (S[i].course[0].mark0 + S[i].course[1].mark0 + S[i].course[2].mark0);
	}
	for (int i = 10; i < 20; i++) {
		S[i].number =2021065201 + i - 10;
		strcpy_s(S[i].Class, "two");
		S[i].course[0].bianhao = 1;
		S[i].course[0].mark0 = rand() % 101;
		S[i].course[1].bianhao = 3;
		S[i].course[1].mark0 = rand() % 101;
		S[i].course[2].bianhao = 7;
		S[i].course[2].mark0 = rand() % 101;
		S[i].grade = (S[i].course[0].mark0 + S[i].course[1].mark0 + S[i].course[2].mark0);
	}
	for (int i = 20; i < 30; i++) {
		S[i].number = 2021065301 + i - 20;
		strcpy_s(S[i].Class, "three");
		S[i].course[0].bianhao = 8;
		S[i].course[0].mark0 = rand() % 101;
		S[i].course[1].bianhao = 2;
		S[i].course[1].mark0 = rand() % 101;
		S[i].course[2].bianhao = 4;
		S[i].course[2].mark0 = rand() % 101;
		S[i].grade = (S[i].course[0].mark0 + S[i].course[1].mark0 + S[i].course[2].mark0);
	}
	for (int i = 30; i < 40; i++) {
		S[i].number = 2021065401 + i - 30;
		strcpy_s(S[i].Class, "four");
		S[i].course[0].bianhao = 1;
		S[i].course[0].mark0 = rand() % 101;
		S[i].course[1].bianhao = 0;
		S[i].course[1].mark0 = rand() % 101;
		S[i].course[2].bianhao = 5;
		S[i].course[2].mark0 = rand() % 101;
		S[i].grade = (S[i].course[0].mark0 + S[i].course[1].mark0 + S[i].course[2].mark0);
	}
	for (int i = 40; i < 50; i++) {
		S[i].number = 2021065501 + i - 40;
		strcpy_s(S[i].Class, "five");
		S[i].course[0].bianhao = 2;
		S[i].course[0].mark0 = rand() % 101;
		S[i].course[1].bianhao = 6;
		S[i].course[1].mark0 = rand() % 101;
		S[i].course[2].bianhao = 9;
		S[i].course[2].mark0 = rand() % 101;
		S[i].grade = (S[i].course[0].mark0 + S[i].course[1].mark0 + S[i].course[2].mark0);
	}
	for (int i = 50; i < 60; i++) {
		S[i].number = 2021065601 + i - 50;
		strcpy_s(S[i].Class, "six");
		S[i].course[0].bianhao = 3;
		S[i].course[0].mark0 = rand() % 101;
		S[i].course[1].bianhao = 0;
		S[i].course[1].mark0 = rand() % 101;
		S[i].course[2].bianhao = 8;
		S[i].course[2].mark0 = rand() % 101;
		S[i].grade = (S[i].course[0].mark0 + S[i].course[1].mark0 + S[i].course[2].mark0);
	}
	for (int i = 60; i < 70; i++) {
		S[i].number = 2021065701 + i - 60;
		strcpy_s(S[i].Class, "seven");
		S[i].course[0].bianhao = 4;
		S[i].course[0].mark0 = rand() % 101;
		S[i].course[1].bianhao = 5;
		S[i].course[1].mark0 = rand() % 101;
		S[i].course[2].bianhao = 9;
		S[i].course[2].mark0 = rand() % 101;
		S[i].grade = (S[i].course[0].mark0 + S[i].course[1].mark0 + S[i].course[2].mark0);
	}
	for (int i = 70; i < 80; i++) {
		S[i].number = 2021065801 + i - 70;
		strcpy_s(S[i].Class, "eight");
		S[i].course[0].bianhao = 2;
		S[i].course[0].mark0 = rand() % 101;
		S[i].course[1].bianhao = 9;
		S[i].course[1].mark0 = rand() % 101;
		S[i].course[2].bianhao = 7;
		S[i].course[2].mark0 = rand() % 101;
		S[i].grade = (S[i].course[0].mark0 + S[i].course[1].mark0 + S[i].course[2].mark0);
	}
	for (int i = 80; i < 90; i++) {
		S[i].number = 2021065901 + i - 80;
		strcpy_s(S[i].Class, "nine");
		S[i].course[0].bianhao = 6;
		S[i].course[0].mark0 = rand() % 101;
		S[i].course[1].bianhao = 0;
		S[i].course[1].mark0 = rand() % 101;
		S[i].course[2].bianhao = 3;
		S[i].course[2].mark0 = rand() % 101;
		S[i].grade = (S[i].course[0].mark0 + S[i].course[1].mark0 + S[i].course[2].mark0);
	}
	for (int i = 90; i < 100; i++) {
		S[i].number = 2021066001 + i - 90;
		strcpy_s(S[i].Class, "ten");
		S[i].course[0].bianhao = 5;
		S[i].course[0].mark0 = rand() % 101;
		S[i].course[1].bianhao = 6;
		S[i].course[1].mark0 = rand() % 101;
		S[i].course[2].bianhao = 9;
		S[i].course[2].mark0 = rand() % 101;
		S[i].grade = (S[i].course[0].mark0 + S[i].course[1].mark0 + S[i].course[2].mark0);
	}
	for (int i = 0; i < 10; i++) {				//按班级和学号顺序输出全部学生以及课程成绩 
		printf("计科%d班成绩统计：\n", i + 1);
		for (int j = 0; j < 10; j++) {
			printf("学号：%d", S[10 * i + j].number);
			printf("   课程%d:   %d", S[10 * i + j].course[0].bianhao, S[10 * i + j].course[0].mark0);
			printf("   课程%d:   %d", S[10 * i + j].course[1].bianhao, S[10 * i + j].course[1].mark0);
			printf("   课程%d:   %d", S[10 * i + j].course[2].bianhao, S[10 * i + j].course[2].mark0);
			printf("   总分：%d\n", S[10 * i + j].grade);
		}
	}
}
void general(student Q[]) {              //对学生总分排名
	student t;
	student S[100];
	for (int i = 0; i < 100; i++)S[i] = Q[i];			//初始化 
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 99 - i; j++) {
			if (S[j].grade < S[j + 1].grade) {			//冒泡排序进行排序 
				t = S[j];
				S[j] = S[j + 1];
				S[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		printf("学号：%d   总分：%d\n", S[i].number, S[i].grade);
	}
}
void  Class(student Q[]) {             //按班级排名
	student S[100];
	for (int i = 0; i < 100; i++)S[i] = Q[i];		//初始化 
	for (int k = 0; k < 10; k++) {
		printf("计科%d班成绩：\n", k + 1);
		for (int i = 0; i < 9; i++) {				//冒泡排序进行排序 
			for (int j = 10 * k; j < 9 + 10 * k - i; j++) {
				if (S[j].grade < S[j + 1].grade) {
					student t;
					t = S[j];
					S[j] = S[j + 1];
					S[j + 1] = t;
				}
			}
		}
		for (int i = 10 * k; i < 10 + 10 * k; i++) {
			printf("学号：%d   总分：%d\n", S[i].number, S[i].grade);
		}
	}
}
void plan(student S[]) {            //课程考试安排
	int map[10][10];					//冲突矩阵 
	for (int i = 0; i < 10; i++) {				//初始化 
		for (int j = 0; j < 10; j++) {
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < 100; i += 10) {			//构建冲突矩阵 
		int x, y, z;
		x = S[i].course[0].bianhao;
		y = S[i].course[1].bianhao;
		z = S[i].course[2].bianhao;
		map[x][y] = 1;
		map[x][z] = 1;
		map[y][x] = 1;
		map[y][z] = 1;
		map[z][x] = 1;
		map[z][y] = 1;
	}
	Linklist L, r, p, q;                       //链表结构体
	L = (Linklist)malloc(sizeof(Lnode));
	r = L;
	for (int i = 0; i < 10; i++) {						//初始化链表 
		p = (Linklist)malloc(sizeof(Lnode));
		p->next = NULL;
		r->next = p;
		p->bh = i;
		r = r->next;
	}
	int term = 1;
	while (L->next != NULL) {							//进行考试安排 
		printf("第%d天考试安排：\n", term);
		int a[4];
		for (int i = 0; i < 4; a[i++] = 10);
		r = L;
		while (r->next) {
			int i = 0;
			for (i; a[i] != 10; i++) {
				if (map[r->next->bh][a[i]])
					break;
			}
			if (a[i] == 10) {
				a[i] = r->next->bh;
				q = r->next;
				r->next = q->next;
				free(q);
				continue;
			}
			r = r->next;
		}
		term++;
		for (int i = 0; a[i] != 10; i++) {
			printf("课程%d  \n", a[i]);
		}
		printf("\n");
	}
	printf("\n\n");
}
int search(student S[]) {                 //课程成绩查询
	printf("输入要查询的课程编号：");
	int c, num = 0, k;
	scanf_s("%d", &c);
	struct STU {
		int number;
		int grade;
	}Q[64];
	for (int i = 0; i < 100; i += 10) {
		for (k = 0; k < 3; k++) {						//找到有此课的班级 
			if (S[i].course[k].bianhao == c)
				break;
		}
		if (k != 3) {							//记录学生学号和成绩 
			int x;
			for (x = i; x < i + 10; x++) {
				Q[num].number = S[x].number;
				Q[num].grade = S[x].course[k].mark0;
				num++;
			}
		}
	}
	for (int i = 0; i < num; i++) {				//冒泡排序对课程成绩进行排名 
		for (int j = 0; j < num - 1 - i; j++) {
			if (Q[j].grade < Q[j + 1].grade) {
				STU t;
				t = Q[j];
				Q[j] = Q[j + 1];
				Q[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < num; i++) {
		printf("学号：%d    成绩：%d\n", Q[i].number, Q[i].grade);
	}
	return 0;
}
int main() {
	student S[100];			//利用结构体数组存储学生信息 
	int c;
	printf("请先选择功能1，获得各班详细成绩\n1.各班成绩\n");
	scanf_s("%d", &c);
	while (c) {

		switch (c)
		{

		case 1:
		{
			create(S);
			break;
		}
		case 2:
		{
			plan(S);
			break;
		}
		case 3:
		{
			general(S);
			break;
		}
		case 4:
		{
			Class(S);
			break;
		}
		case 5:
		{
			search(S);
			break;
		}
		default: return 0;

		}
		printf("\n1.各班成绩\n2.考试安排\n3.总分排名\n4.班级排名\n5.查询\n");
		scanf_s("%d", &c);
	}
	return 0;
}
