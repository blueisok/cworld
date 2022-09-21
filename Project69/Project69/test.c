#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
//typedef struct node
//{
//	int date;
//	struct node* next;
//}node,*linklist;
//linklist create_linklist(linklist* L,int n,int c)
//{
//	 linklist r,s;//rΪǰһ��Ԫ�أ�sΪ��һ��Ԫ��
//	int i=1;
//	L =(linklist) malloc(sizeof(node));
//	r = L;
//	while (i <= n)
//	{
//		s = (linklist)malloc(sizeof(node));
//		s->date = c;
//		s->next = NULL;
//		r->next = s;
//		r = s;
//		i++;
//	}
//	return L;
//
//}
//int main()
//{
//
//	return 0;
//}


typedef struct node
{
	int data;
	struct node* next;
}node,*linklist;
//typedef struct node* linklist;
void initlinklist(linklist L)
{
	//����һ���յ����Ա�
	L = (linklist)malloc(sizeof(node));
	if (!L)
		printf("�����յ����Ա�ʧ��\n");
	L->next = NULL;
}
void destroylinklist(linklist L)//�������Ա�
{
	linklist p;//�洢��һ���ڵ�
	while(L)//���������Ա�ֱ�����ΪNULL
	{
		p = L->next;
		free(L);
		L = p;

	}
}
void clearlinklist(linklist L)//���������Ա�˼·����һ�£�������ͷ�ڵ�
{
	linklist p, q;
	p = L->next;//ָ���һ���ڵ�
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;//��ͷ�ڵ��ָ�����ÿ�
}
int linklistlength(linklist L)
{
	linklist p;
	p = L->next;
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}
int getlinklist(linklist L, int e, int i)//���Ԫ�طŵ�e
{
	int j = 1;
	linklist p = L->next;//ָ���һ���ڵ�
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	e = p->data;
	return OK;//�ҵ�Ԫ��Ϊe��ֵ
}
int locatelinklist(linklist L, int e)//�ҵ�Ԫ��e�����Ա��λ��i
{
	int i = 0;
	linklist p = L->next;
	while (p)
	{
		i++;
		if (p->data == e)
			return i;
		p = p->next;
	}
	return ERROR;
}
int priorlinklist(linklist L, int pri, int e)//�ҵ�Ԫ��e ��ǰ����ͨ��pri����
{
	linklist q;
	linklist p = L->next;
	while (p->next)//����һ���ڵ�ĺ�̽ڵ����
	{
		q = p->next;//qΪp�ĺ��
		if (q->data == e)
		{
			pri = p->data;//ͨ��pri����ǰ���ڵ������
			return OK;
		}
		p = q;//��p����ƶ�һλ
	}
	return ERROR;
}
int nextlinklist(linklist L, int next, int e)//����Ԫ��e�ĺ�̽ڵ�
{
	linklist n;
	linklist p = L->next;
	while (p->next)
	{
		if (p->data == e)
		{
			next= p->next->data;
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}
int insertlinklist(linklist L, int i, int e)
{
	int j = 0;
	linklist p=L;//ָ��ͷ�ڵ�
	linklist s;
	while (p || j < i - 1)//��λ��i-1��λ��
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		return ERROR;
	s = (linklist)malloc(sizeof(node));
	s->data = e;
	s->next = p->next;//λ�ò����Ը���
	p->next = s;
	return OK;
}

int main()
{
	int j;
	linklist L;
	initlinklist(L);
	for (j = 1; j <= 5; j++)
		insertlinklist(L, j, j);
	return 0;
}