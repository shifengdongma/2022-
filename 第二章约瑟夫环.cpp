//#include<iostream>
#include<stdlib.h>
#include<stdio.h>
//using namespace std;
//用链表实现约瑟夫环问题 （循环链表） 
 
typedef struct node  
{
	int data;//数据域
	struct node* next;//指针域
}Node;
 
void Josephring(int m,int n)  //总共有n个人，报到数字为m的人出圈 
{
	//初始化循环链表
	Node *head = NULL,*p=NULL,*r=NULL;
	head = (Node*)malloc(sizeof(Node)); 
	if(NULL==head)   
	{
		printf("内存获取失败\n");
			return;
	} //存储分配失败
	head->data=1;      //从1开始编号
	head->next=NULL;   //空指针 
    p=head;            					 
	//创建剩下的n-1个结点 
	for(int i=2;i<=n;i++)
	{
		r=(Node*)malloc(sizeof(Node)); 
		r->data=i;
		r->next=NULL;
	//插入结点 
		p->next=r;
		p=r;
	}
	//创建循环链表
	p->next=head;   //最后一个结点的next指向头结点
	p=head;         //将p指向头结点
	
	//约瑟夫环实验 
	while(p->next!= p)  //如果p的next=p，说明目前只有一个元素 
	{
		for(int i=1;i<m;i++)  //报到数字为m的时候出圈 
		{
			  r=p;       //保留出圈的前一个结点 
			  p=p->next; //p指向出圈的结点，需要保留前一个结点
		}
		// 输出
	printf("%d ",p->data);
		r->next=p->next;    //删除p的数据  
		p=p->next;          //更新p重新进行报数 
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
	
