

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
typedef struct {
	int number;
	int goal;
}game_player;
int order(game_player P0[]) {		// 顺序查找方法
	game_player P[512];
	for (int i = 0; i < 512; i++) {				//初始化 
		P[i].goal = P0[i].goal;
		P[i].number = i + 1;
	}
	int m = 0;
	for (int i = 0, goal0 = 0; i < 512; i++) {			//找最高分 
		if (P[i].goal > goal0) {
			m = i; goal0 = P[i].goal;
		}
	}
	printf("最高分:选手%d  得分:%d  ", m + 1, P[m].goal);
	P[m].goal = 0; m = 0;
	for (int i = 0, goal0 = 0; i < 512; i++) {				//找次高分 
		if (P[i].goal > goal0) {
			m = i; goal0 = P[i].goal;
		}
	}
	printf("次高分:选手%d  得分:%d  ", m + 1, P[m].goal);
	return 0;
}
int jinbiaosai(game_player P0[]) {			// 锦标赛查找方法
	game_player P[512];
	for (int i = 0; i < 512; i++) {				//初始化 
		P[i].goal = P0[i].goal;
		P[i].number = i + 1;
	}
	int competition = 9;					//512人共进行9轮比赛 
	while (competition) {
		int num = pow(2, competition - 1);
		for (int i = 0; i < num; i++) {				//两两比较之后得到胜者，进行下一轮比赛 
			if (P[i].goal < P[i + num].goal) {
				int number0, goal0;
				number0 = P[i].number; goal0 = P[i].goal;
				P[i].number = P[i + num].number; P[i].goal = P[i + num].goal;
				P[i + num].number = number0; P[i + num].goal = goal0;
			}
		}
		competition--;
	}
	printf("最高分:选手%d  得分:%d  ", P[0].number, P[0].goal);
	competition = 9;
	int lose[9];						//9场比赛有9人输给最高者 
	int first = P[0].number - 1;
	while (competition) { 					//找到输给了最高分的9个人 
		int num = pow(2, competition - 1);
		lose[competition - 1] = first % num + num;
		first = first % num;
		competition--;
	}
	int m = 0, goal0 = 0;
	for (int i = 0; i < 9; i++) {			//比较9人分数，找到次高分 
		if (P[lose[i]].goal > goal0) {
			m = P[lose[i]].number; goal0 = P[lose[i]].goal;
		}
	}
	printf("次高分:选手%d  得分:%d  ", m, goal0);
	return 0;
}
void tiaozheng(int s, game_player P[]) {				// 堆调整函数  
	int g = P[s].goal;
	int num0 = P[s].number;
	for (int j = 2 * s + 2; j <= 512; j *= 2) {			//沿分数较大的孩子节点向下筛选 
		if (j < 512 && P[j - 1].goal < P[j].goal)j++;
		if (g > P[j - 1].goal)break;
		P[s].goal = P[j - 1].goal;				//调整位置 
		P[s].number = P[j - 1].number;   s = j - 1;
	}
	P[s].goal = g; P[s].number = num0;
}
int duipaixu(game_player P0[]) {				//堆排查找方法
	game_player P[512];
	for (int i = 0; i < 512; i++) {				//初始化 
		P[i].goal = P0[i].goal;
		P[i].number = i + 1; 
	}
	for (int i = 255; i >= 0; i--) {			//构建大根堆 
		tiaozheng(i, P);
	}
	printf("最高分:选手:%d  得分:%d  ", P[0].number, P[0].goal);		//输出最高分 
	if (P[1].goal > P[2].goal) {							//找到次高分 
		printf("次高分:选手%d  得分:%d  ", P[1].number, P[1].goal);
	}
	else {
		printf("次高分:选手%d  得分:%d  ", P[2].number, P[2].goal);
	}
	return 0;
}
int main() {
	time_t seed = 0;                //产生随机整数算法
	srand(time(&seed));				//为生成随机数做准备 
	game_player player[512];
	int c;
	for (int i = 0; i < 512; i++) {			//为游戏参与者分配编号，并随机生成分数 
		player[i].number = i;
		player[i].goal = rand() % 1000;
	}
	printf("\n1.选手分数\n2.顺序排序\n3.锦标赛\n4.堆排序\n0.退出\n");
	scanf_s("%d", &c);
	while (c)
	{
		switch (c)
		{
		case 1:
		{
			for (int i = 0; i < 512; i++) {							// 输出所有游戏参与者及其得分
				printf("选手:%d得分:%d  ", i + 1, player[i].goal);
				if (i % 6 == 5)printf("\n");
			}
			printf("\n");
			break;
		}
		case 2:
		{
			printf("顺序查找方法：\n");
			order(player);
			break;
		}
		case 3:
		{
			printf("锦标赛查找方法：\n");
			jinbiaosai(player);
			break;
		}
		case 4:
		{
			printf("堆排查找方法：\n");
			duipaixu(player);
			break;
		}
		case 0: return 0;
		}
		printf("\n1.选手分数\n2.顺序排序\n3.锦标赛\n4.堆排序\n0.退出\n");
		scanf_s("%d", &c);
	}
	return 0;
}

