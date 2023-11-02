#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<process.h>
#define true 1
#define false 0
#define ok 1
#define error 0
#define infeasible -1
#define overflow -2
typedef int status;
typedef struct QNode{
	int no;
	int time;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
status InitQueue(LinkQueue &Q)
{
	Q.front=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)exit(overflow);
	Q.rear=Q.front;
	Q.front->next=NULL;
}
status EnQueue(LinkQueue &Q,int a,int e)
{
	QueuePtr s;
	s=(QueuePtr)malloc(sizeof(QNode));
	if(!s)exit(overflow);
	Q.rear->next=s;
	s->next=NULL;
	s->no=a;
	s->time=e;
	Q.rear=s;
}
status DeQueue(LinkQueue &Q,int &a,int&e)
{
	QueuePtr s;
	s=Q.front->next;
	if(Q.front->next==Q.rear)
	{
		Q.rear=Q.front;
		Q.front->next=NULL;
	}
	else
	{
		Q.front->next=s->next;
	}
	a=s->no;
	e=s->time;
	free(s);
	return ok;
}
status QueueEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)return ok;
	else return error;
}
int main()
{
	int n,i,a,e,t=0;
	printf("请输入任务数\n");
	while(scanf("%d",&n))
	{ 
	LinkQueue Q;
	InitQueue(Q);
	QueuePtr min,p;
	printf("请输入各个任务完成所需的时间\n"); 
	for(i=0;i<n;i++)
	{
		a=i+1;
		scanf("%d",&e);
		EnQueue(Q,a,e);
	}
	printf("序号\t所需时间等待时间\n");
	while(!QueueEmpty(Q))
	{
		p=min=Q.front->next;
		while(p!=NULL)
		{
			if(min->time>p->time)
			{
				min=p;
			}
			p=p->next;
		} 
		while(Q.front->next!=min)
		{
			DeQueue(Q,a,e);
			EnQueue(Q,a,e);
		}
		DeQueue(Q,a,e);
		printf("%d\t%d\t%d\n",a,e,t);
		t+=e; 
	}
	}
}
