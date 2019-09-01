
#include"stdio.h"
#include"stdlib.h"

//����������������
struct node
{
	int data;
	struct node* next;
};
//�����ʼ��
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

//������ڵ�ĸ���
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


//��������
struct node* createlist(struct node* L, int n)
{
	int i;
	struct node* p = NULL;
	for (i = n; i > 0; i--)
	{
		//�������ɵĽڵ����������
		p = (struct node*)malloc(sizeof(struct node));
		scanf_s("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
	return L;
}

//��������
struct node* listinsert(struct node* L, int i, int e)
{
	int j = 0;
	struct node* s = NULL, * p = NULL;
	p = L;
	while (!p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
	{
		printf("not  \n");
		return L;
	}
	//�����µĽڵ�
	s = (struct node*)malloc(sizeof(struct node));
	s->data = e;
	//���µĽڵ��������
	s->next = p->next;
	p->next = s;
	return L;
}


//ɾ������Ľ��
struct node* listdelete(struct node* L, int i)
{
	int j=0;
	struct node* q = NULL, * p = NULL;
	p = L;
	//��ѯ�ڵ�λ��
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
	//ɾ��ָ���Ľڵ�
	q = p->next;
	p->next = q->next;
	free(q);
	return L;
}
//��ѯ����Ľڵ�
struct node* getelem(struct node* L, int i)
{
	int j, e;
	struct node* p = NULL;
	if (i<1 || i>listlength(L))
	{
		printf("�������");
		return 0;
	}
	p = L->next;
	j = 1;
	while (j < i)
	{
		p = p->next;
		j++;
	}
	e = p->data;
	printf("��Ԫ��Ϊ%d", e);
}


//�������

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



//������
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
				printf("%d->", p->data);
				p = p->next;
			}
			printf("\b\b\b\b");
			printf("\n");
			break;
		
		case 2:
			printf("�����������Ԫ�ص�λ�ú����ݣ��ո������\n");
			scanf_s("%d %d", &i, &e);
			listinsert(L, i, e);
			break;

		case 3:
			printf("����ɾ��Ԫ�ص�λ��\n");
			scanf_s("%d", &i);
			listdelete(L, i);
			break;

		case 4:
			printf(" �����ѯ�ڵ��λ��\n");
			scanf_s("%d", &i);
			getelem(L, i);
			break;

		case 0:
			printf("�˳�\n");
			break;

		default:
			printf("�������");
		}
	} while (m != 0);

}
