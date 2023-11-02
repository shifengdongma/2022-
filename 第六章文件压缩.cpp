//因涉及fopen，strcpy函数，建议取消SDL检查
# if 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<iostream>
using namespace std;
#define Size 200
#define Code_len 400
const int N = 600;
typedef struct Node0
{
	int weight;			//存放字符的词频
	char data;			//存字符 
	char code[Code_len];//用来存字符对应的编码 
	Node0* leftchild;		//指向左子树 
	Node0* rightchild;		//指向右子树 
	Node0* parents;		    //指向双亲节点 
}Node, * HufTree;			//建立节点结构体


//定义compare函数，用以找到节点集合中最小的两个数，返回下标 
void compare(Node** nodes, int n, int& s1, int& s2, int& weight)
{
	int weight1, weight2;	//存放两个节点的词频 
	s1 = s2 = 0;
	nodes[0]->weight = 200;	//将第0个元素的词频定义为200用以比较
	for (int i = 1; i <= n; i++)
	{
		if (nodes[i] && nodes[i]->weight != 0)
		{	/*词频为0的不检测*/
			if (nodes[i]->weight <= nodes[s1]->weight)
				s1 = i;
		}
	}
	//找到词频最小的节点的下标
	weight1 = nodes[s1]->weight;
	nodes[s1]->weight = 0;	//把它的词频令为0，不检索 
	for (int i = 1; i <= n; i++)
	{
		if (nodes[i] && nodes[i]->weight != 0)
		{
			if (nodes[i]->weight <= nodes[s2]->weight)
				s2 = i;
		}
	}
	weight2 = nodes[s2]->weight;
	nodes[s2]->weight = 0;	//同理，找到s2
	weight = weight1 + weight2;	//将两节点的词频之和返回，为他们双亲节点的词频
}


//建树函数 
//建立哈夫曼树 
void BuildTree(HufTree& Huffman, char* Word, int& n)
{
	int length = strlen(Word);
	int count_weight[256];	//记录各个字符出现的次数 
	for (int i = 0; i < 256; ++i)
		count_weight[i] = 0;/*初始化记录次数的数组*/
	for (int i = 0; Word[i] != '\0'; ++i)
	{
		count_weight[int(Word[i])]++;
	}						/*记录各个字符出现的次数*/
	//判断不同字符的个数
	n = 0;
	for (int i = 0; i < 256; ++i)
	{
		if (count_weight[i] > 0)
			n++;
	}						//n记录出现了几个不同的字符 
	Node* nodes[N];		    //建立2*n个节点 
	for (int i = 0; i < 2 * n; ++i)
	{
		nodes[i] = (Node*)malloc(sizeof(Node));
		nodes[i]->weight = 0;
		nodes[i]->data = char(-1);		//初始化
	}						            //分配存储空间
	//初始化节点
	int num = 1;
	for (int i = 0; i < 256; i++)
	{
		if (count_weight[i] > 0)
		{
			nodes[num]->data = char(i);
			nodes[num]->weight = count_weight[i];
			nodes[num]->leftchild = (Node*)malloc(sizeof(Node));		//初始化左孩子节点 
			nodes[num]->leftchild = NULL;
			nodes[num]->rightchild = (Node*)malloc(sizeof(Node));		//初始化右孩子节点 
			nodes[num]->rightchild = NULL;
			nodes[num]->parents = (Node*)malloc(sizeof(Node));
			num++;
		}
	}		//对节点赋data和weight，并且初始化节点。 
	int m = 2 * n - 1;
	int s1, s2, weight;
	Huffman = (Node*)malloc((m + 1) * sizeof(Node));
	int s = n + 1;
	for (int i = 0; i < n - 1; i++)
	{
		compare(nodes, 2 * n - 1, s1, s2, weight);
		nodes[s]->weight = weight;
		nodes[s]->leftchild = nodes[s1];
		nodes[s]->rightchild = nodes[s2];
		nodes[s1]->parents = nodes[s2]->parents = nodes[s];
		s++;
	}//每次取出两个最小的节点组成二叉树，共循环n-1次。
	Huffman = nodes[--s];	//将Huffman指向头指针 
}
//遍历哈夫曼树
//获得该哈夫曼树对应各字符的编码
void TranCode(HufTree Huffman, int num, Node* list)
{
	HufTree p;
	char cd[Code_len];	//暂存编码 
	int cdlen = 0;		//记录编码位数 
	int Count = 0;		//记录完成了几个字符的编码 
	p = (Node*)malloc(sizeof(Node));
	p = Huffman;
	p->weight = 0;		//定义指针，并且将头指针的weight为0 
	while (Count < num)
	{	//循环num次 
		if (p->weight == 0) {	//weight为0，去左子树 
			p->weight = 1;
			if (p->leftchild) {
				p = p->leftchild;
				cd[cdlen++] = '0';
			}
			else if (!p->rightchild) {	//左右都为空则是节点 
				cd[cdlen] = '\0';	//字符串结尾标志 
				list[Count].data = p->data;
				strcpy(list[Count++].code, cd);
				strcpy(p->code, cd);		//list用来存放字符和编码 
			}
		}
		else if (p->weight == 1) {	//weight为1，去右子树
			p->weight = 2;
			if (p->rightchild) {
				p = p->rightchild;
				cd[cdlen++] = '1';
			}
		}
		else {		//weight为2，退回双亲节点 
			p->weight = 0;
			p = p->parents;
			--cdlen;
		}
	}
}
//打印转换后得到的各字符的01编码，保存至文件word-code.txt中
void print_code(HufTree Huffman, char* Word, Node* list, int num, char* Code) {
	for (int i = 0; Word[i] != '\0'; i++) {
		for (int j = 0; j < num; j++) {
			if (i == 0 && list[j].data == Word[i])
				strcpy(Code, list[j].code);	/*第一个用strcpy函数*/
			else if (list[j].data == Word[i])
				strcat(Code, list[j].code);	/*后续的用strcat函数*/
		}
	}
	//压缩，将字符转为相对应的01编码,保存在code.txt中
	Sleep(500);
	printf("\t\n将压缩后的字符串存为\"code.txt\"文件：\n");
	FILE* fpWrite = fopen("code.txt", "w");
	if (fpWrite == NULL)	exit(0);
	Sleep(300);
	fprintf(fpWrite, "%s", Code);
	Sleep(500);
	printf("\tSUCCESS\n\n");
	fclose(fpWrite);
}
//将存入的01编码解压缩为原字符串
void print_word(HufTree Huffman, char* code_word)
{

	HufTree p;
	char Code[400];	//存放字符串
	int Count = 0;	//记录当前的字符数目
	Sleep(500);
	printf("\t\n读出\"code.txt\"文件：");
	FILE* fpRead = fopen("code.txt", "r");
	if (fpRead == NULL)	exit(0);	//读文件 
	fscanf(fpRead, "%s", Code);	//读入字符串
	Sleep(300);
	printf("\n%s\n", Code); 	//输出字符串 
	Sleep(500);
	printf("\tSUCCESS\n\n");
	p = (Node*)malloc(sizeof(Node));
	p = Huffman;
	for (int i = 0; Code[i] != '\0'; i++) {	//从头指针开始遍历 
		if (Code[i] == '0')	p = p->leftchild;	//0，向左子树去 
		else if (Code[i] == '1')	p = p->rightchild;	//1，向右子树去 
		if (!(p->leftchild || p->rightchild)) {		//到达根节点 
			code_word[Count] = p->data;
			Count++;
			p = Huffman;					//记录下来，并且将指针重新指回头结点
		}
	}
	code_word[Count] = '\0';
	Sleep(500);
	printf("将\"code.txt\"的二进制编码解压缩后为：\n");
	Sleep(300);
	printf("%s\n", code_word);
	Sleep(500);
	printf("\tSUCCESS");			//输出
}


int main() {
	system("color 0a");
	char Word[Size];
	HufTree Huffman;
	int num;
	int a;
	printf("\n\t请选择输入选项：\n\n用户输入字符串:    格式：1+内容。\n\n输入2将从\"word.txt\"中读取字符串。\n");
	scanf_s("%d", &a);
	switch (a) {
	case 1: {
		gets_s(Word);					//输入字符串 
		Sleep(300);
		printf("\n将字符串存为\"word.txt\"文件：\n");
		FILE* fpWrite = fopen("word.txt", "w");
		if (fpWrite == NULL)	return 0;		//文件打开失败 
		fprintf(fpWrite, "%s", Word);
		printf("\tSUCCESS\n\n");
		fclose(fpWrite);		//保存为文件 
		break;
	}
	case 2: {
		Sleep(500);
		printf("\t正在打开\"word.txt\"文件...\n");
		FILE* fpRead = fopen("word.txt", "r");
		if (fpRead == NULL)	return 0;			//查找失败或者文件无法打开 
		fgets(Word, Size, fpRead);
		printf("\tSUCCESS\n\n");
		fclose(fpRead);		//读取文件中的字符串 
		printf("\tSUCCESS\n");
		break;
	}
	}


	BuildTree(Huffman, Word, num);	//建树 
	Node list[N];			//申请存放字符对应的编码的数组 

	TranCode(Huffman, num, list);	//获得编码，存在list中 
	printf("\t\n将字符对应编码存入\"word_code.txt\"文件：\n");
	FILE* fpWrite;
	fpWrite = fopen("word_code.txt", "w");
	if (fpWrite == NULL)	return 0;
	for (int i = 0; i < num; i++)
		fprintf(fpWrite, "  %c : %s\n", list[i].data, list[i].code);
	printf("\tSUCCESS\n\n");
	fclose(fpWrite);		//存入文件,关闭工作指针 


	char Code[400];
	print_code(Huffman, Word, list, num, Code);	//打印编码


	char code_word[400];
	print_word(Huffman, code_word);		//打印编码对应的原文

}
