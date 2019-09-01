
#include"stdio.h"
#include"stdlib.h"

//构造链表数据类型
struct node
{
	int data;
	struct node* next;
};
//链表初始化
struct node* initlist(struct node* L)
{
	struct node* head = NULL;
	head = (struct node*)malloc(sizeof(struct node));
	if (!head)
	{
		return 0;
	}
	head->next = NULL;
	return L = head;
}

//求链表节点的个数
int listlength(struct node* L)
{
	struct node* p = NULL;
	int count = 0;
	p = L;
	while (p->next)
	{
		count++;
		p = p->next;
	}
	return count;
}


//创建链表
struct node* createlist(struct node* L, int n)
{
	int i;
	struct node* p = NULL;
	for (i = n; i > 0; i--)
	{
		//把新生成的节点插如链表中
		p = (struct node*)malloc(sizeof(struct node));
		scanf_s("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
	return L;
}

//插入链表
struct node* listinsert(struct node* L, int i, int e)
{
	int j = 0;
	struct node* s = NULL, * p = NULL;
	p = L;
	while (!p && j < i - 1)		//!!!!!!!!redundant exclamation symbol!!!!!!
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
	{
		printf("not  \n");
		return L;
	}
	//生成新的节点
	s = (struct node*)malloc(sizeof(struct node));
	s->data = e;
	//把新的节点插入链表
	s->next = p->next;
	p->next = s;
	return L;
}


//删除链表的结点
struct node* listdelete(struct node* L, int i)
{
	int j=0;
	struct node* q = NULL, * p = NULL;
	p = L;
	//查询节点位置
	while (p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1)
	{
		printf("not  \n");
		return L;
	}
	//删除指定的节点
	q = p->next;
	p->next = q->next;
	free(q);
	return L;
}
//查询链表的节点
void getelem(struct node* L, int i)
{
	int j, e;
	struct node* p = NULL;
	if (i<1 || i>listlength(L))
	{
		printf("输入错误");
		return;
	}
	p = L->next;
	j = 1;
	while (j < i)
	{
		p = p->next;
		j++;
	}
	e = p->data;
	printf("该元素为%d", e);
}


//链表操作

void menu()
{
	printf("-------------directory-------------\n");
	printf("input list------------------------1\n");
	printf("insert a new node-----------------2\n");
	printf("delete node-----------------------3\n");
	printf("query node------------------------4\n");
	printf("exit------------------------------0\n");
	printf("-----------------------------------\n");
}



//主程序
int main()
{
	int n, m, i, e;
	struct node* L = NULL, * p = NULL;
	L = initlist(L);
	printf("input number of elements\n");
	scanf_s("%d", &n);
	printf("please input %d number\n", n);
	L = createlist(L,n);
	do
	{
		printf("\n\n");
		menu();
		printf("input your choose\n");
		scanf_s("%d", &m);
		switch (m)
		{
		case 1:
			printf("this is list\n");
			p = L->next;
			while (p != NULL)
			{
				printf("%d->", p->data);	//there will be a redundant '->' at the end.
				p = p->next;
			}
			printf("\b\b\b\b");	//what's this???
			printf("\n");
			break;
		
		case 2:
			printf("依次输入插入元素的位置和数据（空格隔开）\n");
			scanf_s("%d %d", &i, &e);
			listinsert(L, i, e);
			break;

		case 3:
			printf("输入删除元素的位置\n");
			scanf_s("%d", &i);
			listdelete(L, i);
			break;

		case 4:
			printf(" 输入查询节点的位置\n");
			scanf_s("%d", &i);
			getelem(L, i);
			break;

		case 0:
			printf("退出\n");
			break;

		default:
			printf("输入错误");
		}
	} while (m != 0);

}
