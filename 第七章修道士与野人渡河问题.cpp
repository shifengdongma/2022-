
#include<stdio.h> 
#include<stdlib.h> 
#include<malloc.h> 

int n, c;
typedef struct
{
	int xiudaoshi;	//�޵�ʿ����
	int yeren;	    //Ұ��������
	int an;	        //��ʾ����
}DataType;
DataType ways[5000];

typedef struct Node
{
	int dest; 		//�ڽӱ�Ļ�ͷ������
	struct Node* next;
}Edge;
//�ڽӱ�����Ľ��ṹ��


typedef struct
{
	DataType data; 	//�������Ԫ��
	int sorce;  		//�ڽӱ�Ļ�β������
	Edge* adj; 		//�ڽӱߵ�ͷָ��
	int pre;   		//ָ��˵�ĵ�����
}AdjLHeight;
//���������Ԫ�����ͽṹ��

typedef struct
{
	AdjLHeight a[10000]; 	//�ڽӱ�����
	int verts;   		//������
	int edges;   		//�ߵĸ���
}AdjLGraph;
//�ڽӱ�ṹ��

void AdjInitiate(AdjLGraph* G)   //ͼ�ĳ�ʼ��
{
	int i;
	G->edges = 0;
	G->verts = 0;
	for (i = 0; i < 10000; i++)
	{
		G->a[i].sorce = i;   //���ڽӱߵĻ�ͷ������
		G->a[i].adj = NULL;  //���ڽӱߵ�����ͷָ���ֵ
		G->a[i].data.an = -1;
		G->a[i].pre = -1;
	}
}

void InsertVertex(AdjLGraph* G, int i, DataType vertex)//��Gͼ�в�����
{
	if (i >= 0 && i < 10000)
	{
		G->a[i].data.xiudaoshi = vertex.xiudaoshi;
		G->a[i].data.yeren = vertex.yeren;
		G->a[i].data.an = vertex.an;
		G->verts++;
	}
	else printf("���Խ��!\n");
}

void InsertEdge(AdjLGraph* G, int v1, int v2) //��Gͼ�в����<v1,v2>
{
	Edge* p;
	if (v1 < 0 || v1 >= G->verts || v2<0 || v2>G->verts)
	{
		printf("����v1��v2Խ�����!");
		exit(0);
	}

	p = (Edge*)malloc(sizeof(Edge));	//�����ڽӱߵ�������ռ�	 
	p->dest = v2;						//���ڽӱ߻�ͷ��� 	 
	p->next = G->a[v1].adj;			//�½����뵥����ı�ͷ
	G->a[v1].adj = p;					//ͷָ��ָ���µĵ������ͷ
	G->edges++;				//��������1
}

void AdjDestroy(AdjLGraph* G) 		//Gͼ�ĳ���
{
	int i;
	Edge* p, * q;
	for (i = 0; i < G->verts; i++)
	{
		p = G->a[i].adj;
		while (p != NULL)
		{
			q = p->next;
			free(p);
			p = q;
		}
	}
}

int check(DataType x) //��鵱ǰ����£��޵�ʿ�Ƿ�ȫ
{
	if
		((x.xiudaoshi >= x.yeren || x.xiudaoshi == 0) && ((n - x.xiudaoshi) >= (n - x.yeren) || x.xiudaoshi == n) && x.xiudaoshi >= 0 && x.xiudaoshi <= n && x.yeren >= 0 && x.yeren <= n)
		return 1;
	else
		return 0;
}

int security(DataType x)	 //�����ڴ����޵�ʿ�԰�ȫ�����
{
	int i = 0, a, b, t = 0;	 //��ʼ����ĩ����״̬
	if (x.an)
	{
		a = 0; b = c - a;
		while (a + b >= 1)
		{
			t++;
			while (b >= 0)
			{
				ways[i].xiudaoshi = a;
				ways[i].yeren = b;
				i++;
				a++;
				b--;
			}
			a = 0;
			b = c - a - t;
		}

	}
	else//��ĩ����ʼ����״̬
	{
		a = 1; b = 0; t = 0;
		while (a + b <= c)
		{
			t++;
			while (a >= 0)
			{
				ways[i].xiudaoshi = a * (-1);
				ways[i].yeren = b * (-1);
				i++;
				a--;
				b++;
			}
			a = ways[0].xiudaoshi * (-1) + t;
			b = 0;
		}

	}
	return i;
}

int print(AdjLGraph* p, int g) //��ӡ��ȫ�ɺӵĹ���
{
	DataType b[1000];
	int i = 0;
	while (g != -1)
	{
		b[i++] = p->a[g].data;
		g = p->a[g].pre;
	}
	while ((--i) > -1)
	{
		printf("( %d %d %d )", b[i].xiudaoshi, b[i].yeren, b[i].an);
		if (!(b[i].xiudaoshi == 0 && b[i].yeren == 0 && b[i].an == 0)) //ĩ״̬
		{
			if (b[i].an == 1)
				printf(" ---->��[�޵�ʿ��Ұ��][%d %d]----> [%d %d 0]\n", b[i].xiudaoshi - b[i - 1].xiudaoshi, b[i].yeren - b[i - 1].yeren, b[i - 1].xiudaoshi, b[i - 1].yeren);
			else
				printf(" ---->��[�޵�ʿ��Ұ��][%d %d]----> [%d %d 1]\n", (b[i].xiudaoshi - b[i - 1].xiudaoshi) * (-1), (-1) * (b[i].yeren - b[i - 1].yeren), b[i - 1].xiudaoshi, b[i - 1].yeren);
		}
		else
			printf("\n");
	}
	printf("\n");
	return 1;
}

void work(AdjLGraph* p) 	//�жϸ÷����Ƿ���Զɺ� 
{
	DataType tem;
	int i, flag, g = 0, j, count = 0, k = 0, t;
	while (p->a[k].data.an != -1)
	{
		j = security(p->a[k].data);
		for (i = 0; i < j; i++)
		{
			tem.xiudaoshi = p->a[k].data.xiudaoshi - ways[i].xiudaoshi;
			tem.yeren = p->a[k].data.yeren - ways[i].yeren;
			tem.an = 1 - p->a[k].data.an;
			if (check(tem))
			{
				flag = 1;
				t = k;
				while (t != -1)
				{
					if (tem.xiudaoshi == p->a[t].data.xiudaoshi && tem.yeren == p->a[t].data.yeren && tem.an == p->a[t].data.an)
					{
						flag = 0;
						break;
					}
					t--;
				}
				if (flag == 1)
				{
					g++;
					p->a[g].pre = k;
					InsertVertex(p, g, tem);
					InsertEdge(p, k, g);
					if (tem.xiudaoshi == 0 && tem.yeren == 0 && tem.an == 0) //ĩ״̬
					{
						count++;
						print(p, g);
					}
				}
			}
		}
		k++;
	}
	if (count == 0)
		printf("���ܳɹ��ɺ�\n");
	else
		printf("��%d�ֶɺӷ�ʽ", count);

}
int main()
{
	AdjLGraph G; //�ڽӱ�ṹ��
	DataType first;
	printf("Ұ�˺��޵�ʿ����N:");
	scanf("%d", &n);
	printf("���ɳ�����C:");
	scanf("%d", &c);
	AdjInitiate(&G);   //ͼ�ĳ�ʼ��
	first.xiudaoshi = n;
	first.yeren = n;
	first.an = 1;
	InsertVertex(&G, 0, first);//��Gͼ�в�����
	work(&G);	    //�жϸ÷����Ƿ���Զɺ�
	AdjDestroy(&G); //Gͼ�ĳ���
	return 0;
}
