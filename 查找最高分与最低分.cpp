

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
typedef struct {
	int number;
	int goal;
}game_player;
int order(game_player P0[]) {		// ˳����ҷ���
	game_player P[512];
	for (int i = 0; i < 512; i++) {				//��ʼ�� 
		P[i].goal = P0[i].goal;
		P[i].number = i + 1;
	}
	int m = 0;
	for (int i = 0, goal0 = 0; i < 512; i++) {			//����߷� 
		if (P[i].goal > goal0) {
			m = i; goal0 = P[i].goal;
		}
	}
	printf("��߷�:ѡ��%d  �÷�:%d  ", m + 1, P[m].goal);
	P[m].goal = 0; m = 0;
	for (int i = 0, goal0 = 0; i < 512; i++) {				//�Ҵθ߷� 
		if (P[i].goal > goal0) {
			m = i; goal0 = P[i].goal;
		}
	}
	printf("�θ߷�:ѡ��%d  �÷�:%d  ", m + 1, P[m].goal);
	return 0;
}
int jinbiaosai(game_player P0[]) {			// ���������ҷ���
	game_player P[512];
	for (int i = 0; i < 512; i++) {				//��ʼ�� 
		P[i].goal = P0[i].goal;
		P[i].number = i + 1;
	}
	int competition = 9;					//512�˹�����9�ֱ��� 
	while (competition) {
		int num = pow(2, competition - 1);
		for (int i = 0; i < num; i++) {				//�����Ƚ�֮��õ�ʤ�ߣ�������һ�ֱ��� 
			if (P[i].goal < P[i + num].goal) {
				int number0, goal0;
				number0 = P[i].number; goal0 = P[i].goal;
				P[i].number = P[i + num].number; P[i].goal = P[i + num].goal;
				P[i + num].number = number0; P[i + num].goal = goal0;
			}
		}
		competition--;
	}
	printf("��߷�:ѡ��%d  �÷�:%d  ", P[0].number, P[0].goal);
	competition = 9;
	int lose[9];						//9��������9���������� 
	int first = P[0].number - 1;
	while (competition) { 					//�ҵ��������߷ֵ�9���� 
		int num = pow(2, competition - 1);
		lose[competition - 1] = first % num + num;
		first = first % num;
		competition--;
	}
	int m = 0, goal0 = 0;
	for (int i = 0; i < 9; i++) {			//�Ƚ�9�˷������ҵ��θ߷� 
		if (P[lose[i]].goal > goal0) {
			m = P[lose[i]].number; goal0 = P[lose[i]].goal;
		}
	}
	printf("�θ߷�:ѡ��%d  �÷�:%d  ", m, goal0);
	return 0;
}
void tiaozheng(int s, game_player P[]) {				// �ѵ�������  
	int g = P[s].goal;
	int num0 = P[s].number;
	for (int j = 2 * s + 2; j <= 512; j *= 2) {			//�ط����ϴ�ĺ��ӽڵ�����ɸѡ 
		if (j < 512 && P[j - 1].goal < P[j].goal)j++;
		if (g > P[j - 1].goal)break;
		P[s].goal = P[j - 1].goal;				//����λ�� 
		P[s].number = P[j - 1].number;   s = j - 1;
	}
	P[s].goal = g; P[s].number = num0;
}
int duipaixu(game_player P0[]) {				//���Ų��ҷ���
	game_player P[512];
	for (int i = 0; i < 512; i++) {				//��ʼ�� 
		P[i].goal = P0[i].goal;
		P[i].number = i + 1; 
	}
	for (int i = 255; i >= 0; i--) {			//��������� 
		tiaozheng(i, P);
	}
	printf("��߷�:ѡ��:%d  �÷�:%d  ", P[0].number, P[0].goal);		//�����߷� 
	if (P[1].goal > P[2].goal) {							//�ҵ��θ߷� 
		printf("�θ߷�:ѡ��%d  �÷�:%d  ", P[1].number, P[1].goal);
	}
	else {
		printf("�θ߷�:ѡ��%d  �÷�:%d  ", P[2].number, P[2].goal);
	}
	return 0;
}
int main() {
	time_t seed = 0;                //������������㷨
	srand(time(&seed));				//Ϊ�����������׼�� 
	game_player player[512];
	int c;
	for (int i = 0; i < 512; i++) {			//Ϊ��Ϸ�����߷����ţ���������ɷ��� 
		player[i].number = i;
		player[i].goal = rand() % 1000;
	}
	printf("\n1.ѡ�ַ���\n2.˳������\n3.������\n4.������\n0.�˳�\n");
	scanf_s("%d", &c);
	while (c)
	{
		switch (c)
		{
		case 1:
		{
			for (int i = 0; i < 512; i++) {							// ���������Ϸ�����߼���÷�
				printf("ѡ��:%d�÷�:%d  ", i + 1, player[i].goal);
				if (i % 6 == 5)printf("\n");
			}
			printf("\n");
			break;
		}
		case 2:
		{
			printf("˳����ҷ�����\n");
			order(player);
			break;
		}
		case 3:
		{
			printf("���������ҷ�����\n");
			jinbiaosai(player);
			break;
		}
		case 4:
		{
			printf("���Ų��ҷ�����\n");
			duipaixu(player);
			break;
		}
		case 0: return 0;
		}
		printf("\n1.ѡ�ַ���\n2.˳������\n3.������\n4.������\n0.�˳�\n");
		scanf_s("%d", &c);
	}
	return 0;
}

