//#include<iostream>
#include<stdlib.h>
#include<stdio.h>
//using namespace std;
//������ʵ��Լɪ������ ��ѭ������ 
 
typedef struct node  
{
	int data;//������
	struct node* next;//ָ����
}Node;
 
void Josephring(int m,int n)  //�ܹ���n���ˣ���������Ϊm���˳�Ȧ 
{
	//��ʼ��ѭ������
	Node *head = NULL,*p=NULL,*r=NULL;
	head = (Node*)malloc(sizeof(Node)); 
	if(NULL==head)   
	{
		printf("�ڴ��ȡʧ��\n");
			return;
	} //�洢����ʧ��
	head->data=1;      //��1��ʼ���
	head->next=NULL;   //��ָ�� 
    p=head;            					 
	//����ʣ�µ�n-1����� 
	for(int i=2;i<=n;i++)
	{
		r=(Node*)malloc(sizeof(Node)); 
		r->data=i;
		r->next=NULL;
	//������ 
		p->next=r;
		p=r;
	}
	//����ѭ������
	p->next=head;   //���һ������nextָ��ͷ���
	p=head;         //��pָ��ͷ���
	
	//Լɪ��ʵ�� 
	while(p->next!= p)  //���p��next=p��˵��Ŀǰֻ��һ��Ԫ�� 
	{
		for(int i=1;i<m;i++)  //��������Ϊm��ʱ���Ȧ 
		{
			  r=p;       //������Ȧ��ǰһ����� 
			  p=p->next; //pָ���Ȧ�Ľ�㣬��Ҫ����ǰһ�����
		}
		// ���
	printf("%d ",p->data);
		r->next=p->next;    //ɾ��p������  
		p=p->next;          //����p���½��б��� 
	} 
	printf("%d ",p->data);
}

int main()
	{
		int m=0,n=0;
		scanf_s("%d %d",&m,&n);
		if(m<=0||n<=0)
		{
			printf("error");
			return -1;
		}
	Josephring(n,m);
	return 0;
	}
	
