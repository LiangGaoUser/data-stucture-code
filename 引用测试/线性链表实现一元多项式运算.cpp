#include "malloc.h"
#include <cstdlib>
#include <stdio.h>

#define Status int
typedef struct ploynomial
{
	float coef;//系数
	int expn;//指数
	ploynomial*next;
}*LinkList;
//初始条件：链表存在
//操作结果：在链表中寻找和指数e是否有相等的项，如果有返回false，否则返回该元素应该插入的前一个元素的指针
Status LocateElem(LinkList L,LinkList&p, int e)
{
	LinkList S = L->next;
	p = L;
	while (NULL!=S)
	{
		if (S->expn == e)
		{
			return true;
		}
		if (S->expn < e) p = S;
		S = S->next;
	}
	return false;
}
Status CreatePloyn(LinkList&P,int m)
{
	P = (LinkList)malloc(sizeof(ploynomial));
	if (!P) return -1;
	P->coef = 0.0;
	P->expn = -1;
	P->next = NULL;
	LinkList S,L,p;
	L = P;
	for (int i = 0; i < m; i++)
	{
		S= (LinkList)malloc(sizeof(ploynomial));
		if (!S) return -1;
		printf("请输入系数\n");
		scanf_s("%f", &S->coef);
		printf("请输入指数\n");
		scanf_s("%d", &S->expn);
		while (LocateElem(P, p,S->expn))
		{
			printf("该多项式已经存在指数为%d的项，请重新输入指数\n", S->expn);
			scanf_s("%d", &S->expn);
		} 
		S->next = p->next;
		p->next = S;
	}
	return 1;
}

Status PrintPloyn(LinkList &P)
{
	LinkList S;
	S = P->next;
	while (S)
	{
		if (S->expn > 0)
		{
			printf("%.2fx的%d次方\n", S->coef,S->expn);
		}
		else
		{
			printf("%.2f\n", S->coef);
		}
		S = S->next;
	}
	return 1;
}
int main()
{
	LinkList L;
	CreatePloyn(L, 4);
	PrintPloyn(L);
	system("pause");
}