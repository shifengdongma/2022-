
#include<stdio.h> 
#include<stdlib.h> 
#include<malloc.h> 

int n, c;
typedef struct
{
	int xiudaoshi;	//修道士人数
	int yeren;	    //野蛮人人数
	int an;	        //表示两岸
}DataType;
DataType ways[5000];

typedef struct Node
{
	int dest; 		//邻接表的弧头结点序号
	struct Node* next;
}Edge;
//邻接表单链表的结点结构体


typedef struct
{
	DataType data; 	//结点数据元素
	int sorce;  		//邻接表的弧尾结点序号
	Edge* adj; 		//邻接边的头指针
	int pre;   		//指向此点的点的序号
}AdjLHeight;
//数组的数据元素类型结构体

typedef struct
{
	AdjLHeight a[10000]; 	//邻接表数组
	int verts;   		//结点个数
	int edges;   		//边的个数
}AdjLGraph;
//邻接表结构体

void AdjInitiate(AdjLGraph* G)   //图的初始化
{
	int i;
	G->edges = 0;
	G->verts = 0;
	for (i = 0; i < 10000; i++)
	{
		G->a[i].sorce = i;   //置邻接边的弧头结点序号
		G->a[i].adj = NULL;  //置邻接边单链表头指针初值
		G->a[i].data.an = -1;
		G->a[i].pre = -1;
	}
}

void InsertVertex(AdjLGraph* G, int i, DataType vertex)//在G图中插入结点
{
	if (i >= 0 && i < 10000)
	{
		G->a[i].data.xiudaoshi = vertex.xiudaoshi;
		G->a[i].data.yeren = vertex.yeren;
		G->a[i].data.an = vertex.an;
		G->verts++;
	}
	else printf("结点越界!\n");
}

void InsertEdge(AdjLGraph* G, int v1, int v2) //在G图中插入边<v1,v2>
{
	Edge* p;
	if (v1 < 0 || v1 >= G->verts || v2<0 || v2>G->verts)
	{
		printf("参数v1或v2越界出错!");
		exit(0);
	}

	p = (Edge*)malloc(sizeof(Edge));	//申请邻接边单链表结点空间	 
	p->dest = v2;						//置邻接边弧头序号 	 
	p->next = G->a[v1].adj;			//新结点插入单链表的表头
	G->a[v1].adj = p;					//头指针指向新的单链表表头
	G->edges++;				//边条数加1
}

void AdjDestroy(AdjLGraph* G) 		//G图的撤销
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

int check(DataType x) //检查当前情况下，修道士是否安全
{
	if
		((x.xiudaoshi >= x.yeren || x.xiudaoshi == 0) && ((n - x.xiudaoshi) >= (n - x.yeren) || x.xiudaoshi == n) && x.xiudaoshi >= 0 && x.xiudaoshi <= n && x.yeren >= 0 && x.yeren <= n)
		return 1;
	else
		return 0;
}

int security(DataType x)	 //生成在船上修道士仍安全的情况
{
	int i = 0, a, b, t = 0;	 //从始岸到末岸的状态
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
	else//从末岸到始岸的状态
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

int print(AdjLGraph* p, int g) //打印安全渡河的过程
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
		if (!(b[i].xiudaoshi == 0 && b[i].yeren == 0 && b[i].an == 0)) //末状态
		{
			if (b[i].an == 1)
				printf(" ---->船[修道士，野人][%d %d]----> [%d %d 0]\n", b[i].xiudaoshi - b[i - 1].xiudaoshi, b[i].yeren - b[i - 1].yeren, b[i - 1].xiudaoshi, b[i - 1].yeren);
			else
				printf(" ---->船[修道士，野人][%d %d]----> [%d %d 1]\n", (b[i].xiudaoshi - b[i - 1].xiudaoshi) * (-1), (-1) * (b[i].yeren - b[i - 1].yeren), b[i - 1].xiudaoshi, b[i - 1].yeren);
		}
		else
			printf("\n");
	}
	printf("\n");
	return 1;
}

void work(AdjLGraph* p) 	//判断该方案是否可以渡河 
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
					if (tem.xiudaoshi == 0 && tem.yeren == 0 && tem.an == 0) //末状态
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
		printf("不能成功渡河\n");
	else
		printf("有%d种渡河方式", count);

}
int main()
{
	AdjLGraph G; //邻接表结构体
	DataType first;
	printf("野人和修道士人数N:");
	scanf("%d", &n);
	printf("船可乘人数C:");
	scanf("%d", &c);
	AdjInitiate(&G);   //图的初始化
	first.xiudaoshi = n;
	first.yeren = n;
	first.an = 1;
	InsertVertex(&G, 0, first);//在G图中插入结点
	work(&G);	    //判断该方案是否可以渡河
	AdjDestroy(&G); //G图的撤销
	return 0;
}
