#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
typedef struct {
	int number;				//ѧ�� 
	char Class[10];			//�༶ 
	int grade;				//�ɼ� 
	struct {
		int bianhao;		    //�γ̱�� 
		int mark0;			//�γ̳ɼ� 
	} course[10];
} student;
typedef struct Lnode {       //������Ҫ������ṹ��
	int bh;
	struct Lnode* next;
} Lnode, * Linklist;
void create(student S[]) {
	time_t seed = 0;                          
	srand(time(&seed));					    //������������� 
	for (int i = 0; i < 10; i++) {			//��������༶
		S[i].number = 2021065101 + i;
		strcpy_s(S[i].Class, "one");        //���༶˳�򸳸���ϵͳʱ��������������ֵ
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
	for (int i = 0; i < 10; i++) {				//���༶��ѧ��˳�����ȫ��ѧ���Լ��γ̳ɼ� 
		printf("�ƿ�%d��ɼ�ͳ�ƣ�\n", i + 1);
		for (int j = 0; j < 10; j++) {
			printf("ѧ�ţ�%d", S[10 * i + j].number);
			printf("   �γ�%d:   %d", S[10 * i + j].course[0].bianhao, S[10 * i + j].course[0].mark0);
			printf("   �γ�%d:   %d", S[10 * i + j].course[1].bianhao, S[10 * i + j].course[1].mark0);
			printf("   �γ�%d:   %d", S[10 * i + j].course[2].bianhao, S[10 * i + j].course[2].mark0);
			printf("   �ܷ֣�%d\n", S[10 * i + j].grade);
		}
	}
}
void general(student Q[]) {              //��ѧ���ܷ�����
	student t;
	student S[100];
	for (int i = 0; i < 100; i++)S[i] = Q[i];			//��ʼ�� 
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 99 - i; j++) {
			if (S[j].grade < S[j + 1].grade) {			//ð������������� 
				t = S[j];
				S[j] = S[j + 1];
				S[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		printf("ѧ�ţ�%d   �ܷ֣�%d\n", S[i].number, S[i].grade);
	}
}
void  Class(student Q[]) {             //���༶����
	student S[100];
	for (int i = 0; i < 100; i++)S[i] = Q[i];		//��ʼ�� 
	for (int k = 0; k < 10; k++) {
		printf("�ƿ�%d��ɼ���\n", k + 1);
		for (int i = 0; i < 9; i++) {				//ð������������� 
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
			printf("ѧ�ţ�%d   �ܷ֣�%d\n", S[i].number, S[i].grade);
		}
	}
}
void plan(student S[]) {            //�γ̿��԰���
	int map[10][10];					//��ͻ���� 
	for (int i = 0; i < 10; i++) {				//��ʼ�� 
		for (int j = 0; j < 10; j++) {
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < 100; i += 10) {			//������ͻ���� 
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
	Linklist L, r, p, q;                       //����ṹ��
	L = (Linklist)malloc(sizeof(Lnode));
	r = L;
	for (int i = 0; i < 10; i++) {						//��ʼ������ 
		p = (Linklist)malloc(sizeof(Lnode));
		p->next = NULL;
		r->next = p;
		p->bh = i;
		r = r->next;
	}
	int term = 1;
	while (L->next != NULL) {							//���п��԰��� 
		printf("��%d�쿼�԰��ţ�\n", term);
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
			printf("�γ�%d  \n", a[i]);
		}
		printf("\n");
	}
	printf("\n\n");
}
int search(student S[]) {                 //�γ̳ɼ���ѯ
	printf("����Ҫ��ѯ�Ŀγ̱�ţ�");
	int c, num = 0, k;
	scanf_s("%d", &c);
	struct STU {
		int number;
		int grade;
	}Q[64];
	for (int i = 0; i < 100; i += 10) {
		for (k = 0; k < 3; k++) {						//�ҵ��д˿εİ༶ 
			if (S[i].course[k].bianhao == c)
				break;
		}
		if (k != 3) {							//��¼ѧ��ѧ�źͳɼ� 
			int x;
			for (x = i; x < i + 10; x++) {
				Q[num].number = S[x].number;
				Q[num].grade = S[x].course[k].mark0;
				num++;
			}
		}
	}
	for (int i = 0; i < num; i++) {				//ð������Կγ̳ɼ��������� 
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
		printf("ѧ�ţ�%d    �ɼ���%d\n", Q[i].number, Q[i].grade);
	}
	return 0;
}
int main() {
	student S[100];			//���ýṹ������洢ѧ����Ϣ 
	int c;
	printf("����ѡ����1����ø�����ϸ�ɼ�\n1.����ɼ�\n");
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
		printf("\n1.����ɼ�\n2.���԰���\n3.�ܷ�����\n4.�༶����\n5.��ѯ\n");
		scanf_s("%d", &c);
	}
	return 0;
}
