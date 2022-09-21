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
//	 linklist r,s;//r为前一个元素，s为后一个元素
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
	//构建一个空的线性表
	L = (linklist)malloc(sizeof(node));
	if (!L)
		printf("创建空的线性表失败\n");
	L->next = NULL;
}
void destroylinklist(linklist L)//销毁线性表
{
	linklist p;//存储下一个节点
	while(L)//逐步销毁线性表，直到最后为NULL
	{
		p = L->next;
		free(L);
		L = p;

	}
}
void clearlinklist(linklist L)//与销毁线性表思路基本一致，但保留头节点
{
	linklist p, q;
	p = L->next;//指向第一个节点
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;//将头节点的指针域置空
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
int getlinklist(linklist L, int e, int i)//获得元素放到e
{
	int j = 1;
	linklist p = L->next;//指向第一个节点
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	e = p->data;
	return OK;//找到元素为e赋值
}
int locatelinklist(linklist L, int e)//找到元素e在线性表的位置i
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
int priorlinklist(linklist L, int pri, int e)//找到元素e 的前驱并通过pri返回
{
	linklist q;
	linklist p = L->next;
	while (p->next)//当第一个节点的后继节点存在
	{
		q = p->next;//q为p的后继
		if (q->data == e)
		{
			pri = p->data;//通过pri返回前驱节点的数据
			return OK;
		}
		p = q;//将p向后移动一位
	}
	return ERROR;
}
int nextlinklist(linklist L, int next, int e)//返回元素e的后继节点
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
	linklist p=L;//指向头节点
	linklist s;
	while (p || j < i - 1)//定位到i-1的位置
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		return ERROR;
	s = (linklist)malloc(sizeof(node));
	s->data = e;
	s->next = p->next;//位置不可以更换
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