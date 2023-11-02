//���漰fopen��strcpy����������ȡ��SDL���
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
	int weight;			//����ַ��Ĵ�Ƶ
	char data;			//���ַ� 
	char code[Code_len];//�������ַ���Ӧ�ı��� 
	Node0* leftchild;		//ָ�������� 
	Node0* rightchild;		//ָ�������� 
	Node0* parents;		    //ָ��˫�׽ڵ� 
}Node, * HufTree;			//�����ڵ�ṹ��


//����compare�����������ҵ��ڵ㼯������С���������������±� 
void compare(Node** nodes, int n, int& s1, int& s2, int& weight)
{
	int weight1, weight2;	//��������ڵ�Ĵ�Ƶ 
	s1 = s2 = 0;
	nodes[0]->weight = 200;	//����0��Ԫ�صĴ�Ƶ����Ϊ200���ԱȽ�
	for (int i = 1; i <= n; i++)
	{
		if (nodes[i] && nodes[i]->weight != 0)
		{	/*��ƵΪ0�Ĳ����*/
			if (nodes[i]->weight <= nodes[s1]->weight)
				s1 = i;
		}
	}
	//�ҵ���Ƶ��С�Ľڵ���±�
	weight1 = nodes[s1]->weight;
	nodes[s1]->weight = 0;	//�����Ĵ�Ƶ��Ϊ0�������� 
	for (int i = 1; i <= n; i++)
	{
		if (nodes[i] && nodes[i]->weight != 0)
		{
			if (nodes[i]->weight <= nodes[s2]->weight)
				s2 = i;
		}
	}
	weight2 = nodes[s2]->weight;
	nodes[s2]->weight = 0;	//ͬ���ҵ�s2
	weight = weight1 + weight2;	//�����ڵ�Ĵ�Ƶ֮�ͷ��أ�Ϊ����˫�׽ڵ�Ĵ�Ƶ
}


//�������� 
//������������ 
void BuildTree(HufTree& Huffman, char* Word, int& n)
{
	int length = strlen(Word);
	int count_weight[256];	//��¼�����ַ����ֵĴ��� 
	for (int i = 0; i < 256; ++i)
		count_weight[i] = 0;/*��ʼ����¼����������*/
	for (int i = 0; Word[i] != '\0'; ++i)
	{
		count_weight[int(Word[i])]++;
	}						/*��¼�����ַ����ֵĴ���*/
	//�жϲ�ͬ�ַ��ĸ���
	n = 0;
	for (int i = 0; i < 256; ++i)
	{
		if (count_weight[i] > 0)
			n++;
	}						//n��¼�����˼�����ͬ���ַ� 
	Node* nodes[N];		    //����2*n���ڵ� 
	for (int i = 0; i < 2 * n; ++i)
	{
		nodes[i] = (Node*)malloc(sizeof(Node));
		nodes[i]->weight = 0;
		nodes[i]->data = char(-1);		//��ʼ��
	}						            //����洢�ռ�
	//��ʼ���ڵ�
	int num = 1;
	for (int i = 0; i < 256; i++)
	{
		if (count_weight[i] > 0)
		{
			nodes[num]->data = char(i);
			nodes[num]->weight = count_weight[i];
			nodes[num]->leftchild = (Node*)malloc(sizeof(Node));		//��ʼ�����ӽڵ� 
			nodes[num]->leftchild = NULL;
			nodes[num]->rightchild = (Node*)malloc(sizeof(Node));		//��ʼ���Һ��ӽڵ� 
			nodes[num]->rightchild = NULL;
			nodes[num]->parents = (Node*)malloc(sizeof(Node));
			num++;
		}
	}		//�Խڵ㸳data��weight�����ҳ�ʼ���ڵ㡣 
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
	}//ÿ��ȡ��������С�Ľڵ���ɶ���������ѭ��n-1�Ρ�
	Huffman = nodes[--s];	//��Huffmanָ��ͷָ�� 
}
//������������
//��øù���������Ӧ���ַ��ı���
void TranCode(HufTree Huffman, int num, Node* list)
{
	HufTree p;
	char cd[Code_len];	//�ݴ���� 
	int cdlen = 0;		//��¼����λ�� 
	int Count = 0;		//��¼����˼����ַ��ı��� 
	p = (Node*)malloc(sizeof(Node));
	p = Huffman;
	p->weight = 0;		//����ָ�룬���ҽ�ͷָ���weightΪ0 
	while (Count < num)
	{	//ѭ��num�� 
		if (p->weight == 0) {	//weightΪ0��ȥ������ 
			p->weight = 1;
			if (p->leftchild) {
				p = p->leftchild;
				cd[cdlen++] = '0';
			}
			else if (!p->rightchild) {	//���Ҷ�Ϊ�����ǽڵ� 
				cd[cdlen] = '\0';	//�ַ�����β��־ 
				list[Count].data = p->data;
				strcpy(list[Count++].code, cd);
				strcpy(p->code, cd);		//list��������ַ��ͱ��� 
			}
		}
		else if (p->weight == 1) {	//weightΪ1��ȥ������
			p->weight = 2;
			if (p->rightchild) {
				p = p->rightchild;
				cd[cdlen++] = '1';
			}
		}
		else {		//weightΪ2���˻�˫�׽ڵ� 
			p->weight = 0;
			p = p->parents;
			--cdlen;
		}
	}
}
//��ӡת����õ��ĸ��ַ���01���룬�������ļ�word-code.txt��
void print_code(HufTree Huffman, char* Word, Node* list, int num, char* Code) {
	for (int i = 0; Word[i] != '\0'; i++) {
		for (int j = 0; j < num; j++) {
			if (i == 0 && list[j].data == Word[i])
				strcpy(Code, list[j].code);	/*��һ����strcpy����*/
			else if (list[j].data == Word[i])
				strcat(Code, list[j].code);	/*��������strcat����*/
		}
	}
	//ѹ�������ַ�תΪ���Ӧ��01����,������code.txt��
	Sleep(500);
	printf("\t\n��ѹ������ַ�����Ϊ\"code.txt\"�ļ���\n");
	FILE* fpWrite = fopen("code.txt", "w");
	if (fpWrite == NULL)	exit(0);
	Sleep(300);
	fprintf(fpWrite, "%s", Code);
	Sleep(500);
	printf("\tSUCCESS\n\n");
	fclose(fpWrite);
}
//�������01�����ѹ��Ϊԭ�ַ���
void print_word(HufTree Huffman, char* code_word)
{

	HufTree p;
	char Code[400];	//����ַ���
	int Count = 0;	//��¼��ǰ���ַ���Ŀ
	Sleep(500);
	printf("\t\n����\"code.txt\"�ļ���");
	FILE* fpRead = fopen("code.txt", "r");
	if (fpRead == NULL)	exit(0);	//���ļ� 
	fscanf(fpRead, "%s", Code);	//�����ַ���
	Sleep(300);
	printf("\n%s\n", Code); 	//����ַ��� 
	Sleep(500);
	printf("\tSUCCESS\n\n");
	p = (Node*)malloc(sizeof(Node));
	p = Huffman;
	for (int i = 0; Code[i] != '\0'; i++) {	//��ͷָ�뿪ʼ���� 
		if (Code[i] == '0')	p = p->leftchild;	//0����������ȥ 
		else if (Code[i] == '1')	p = p->rightchild;	//1����������ȥ 
		if (!(p->leftchild || p->rightchild)) {		//������ڵ� 
			code_word[Count] = p->data;
			Count++;
			p = Huffman;					//��¼���������ҽ�ָ������ָ��ͷ���
		}
	}
	code_word[Count] = '\0';
	Sleep(500);
	printf("��\"code.txt\"�Ķ����Ʊ����ѹ����Ϊ��\n");
	Sleep(300);
	printf("%s\n", code_word);
	Sleep(500);
	printf("\tSUCCESS");			//���
}


int main() {
	system("color 0a");
	char Word[Size];
	HufTree Huffman;
	int num;
	int a;
	printf("\n\t��ѡ������ѡ�\n\n�û������ַ���:    ��ʽ��1+���ݡ�\n\n����2����\"word.txt\"�ж�ȡ�ַ�����\n");
	scanf_s("%d", &a);
	switch (a) {
	case 1: {
		gets_s(Word);					//�����ַ��� 
		Sleep(300);
		printf("\n���ַ�����Ϊ\"word.txt\"�ļ���\n");
		FILE* fpWrite = fopen("word.txt", "w");
		if (fpWrite == NULL)	return 0;		//�ļ���ʧ�� 
		fprintf(fpWrite, "%s", Word);
		printf("\tSUCCESS\n\n");
		fclose(fpWrite);		//����Ϊ�ļ� 
		break;
	}
	case 2: {
		Sleep(500);
		printf("\t���ڴ�\"word.txt\"�ļ�...\n");
		FILE* fpRead = fopen("word.txt", "r");
		if (fpRead == NULL)	return 0;			//����ʧ�ܻ����ļ��޷��� 
		fgets(Word, Size, fpRead);
		printf("\tSUCCESS\n\n");
		fclose(fpRead);		//��ȡ�ļ��е��ַ��� 
		printf("\tSUCCESS\n");
		break;
	}
	}


	BuildTree(Huffman, Word, num);	//���� 
	Node list[N];			//�������ַ���Ӧ�ı�������� 

	TranCode(Huffman, num, list);	//��ñ��룬����list�� 
	printf("\t\n���ַ���Ӧ�������\"word_code.txt\"�ļ���\n");
	FILE* fpWrite;
	fpWrite = fopen("word_code.txt", "w");
	if (fpWrite == NULL)	return 0;
	for (int i = 0; i < num; i++)
		fprintf(fpWrite, "  %c : %s\n", list[i].data, list[i].code);
	printf("\tSUCCESS\n\n");
	fclose(fpWrite);		//�����ļ�,�رչ���ָ�� 


	char Code[400];
	print_code(Huffman, Word, list, num, Code);	//��ӡ����


	char code_word[400];
	print_word(Huffman, code_word);		//��ӡ�����Ӧ��ԭ��

}
