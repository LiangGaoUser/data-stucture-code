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
Status PrintPloyn(LinkList &P);

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
//初始条件：链表不存在
//操作结果：创建带有头结点的多项式链表，并插入m个元素
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
//初始条件：链表P存在
//操作结果：删除并释放指针S指向的结点
Status DeleteNode(LinkList&P,LinkList&S)
{
	LinkList la = P->next;
	while (NULL != la)
	{
		if (la->next == S)
		{
			la->next = S->next;
			free(S);
			S = NULL;
			return true;
		}
		la = la->next;
	}
	return false;
}
//初始条件：链表Pa,Pb存在
//操作结果：将多项式Pa和Pb相加,Pa,Pb分别是头指针,Pc是指向新多项式
Status AddPolyn(LinkList&Pa, LinkList&Pb,LinkList&Pc)
{
	printf("----\n");
	LinkList la, lb,lc;
	LinkList freela, freelb;
	lc=Pc = Pa;
	la = Pa->next;
	lb = Pb->next;
	while (NULL != la && NULL != lb)
	{
		printf("begin\n");
		if (la->expn < lb->expn)
		{
			lc->next = la;
			lc = lc->next;
			la = la->next;
			printf("----1\n");
		}
		else if (la->expn > lb->expn)
		{
			lc->next = lb;
			lc = lc->next;
			lb = lb->next;
			printf("----2\n");
		}
		else if (la->expn = lb->expn)
		{
			if (la->coef + lb->coef == 0)
			{		
				printf("----3\n");
				freela = la;
				freelb = lb;
				la = la->next;
				lb = lb->next;
				DeleteNode(Pa, freela);
				DeleteNode(Pb, freelb);
				/*DeleteNode(Pa, freela);
				DeleteNode(Pb, freelb);
				free(freela);
				free(freelb);
				freela = NULL;
				freelb = NULL;*/
				
				
			}
			else
			{
				printf("----4\n");
				freelb = lb;
				lc->next = la;
				lc = lc->next;
				la->coef = la->coef + lb->coef;
				la = la->next;
				lb = lb->next;
				DeleteNode(Pb, freelb);
				/*DeleteNode(Pb, freelb);
				free(lb);
				freelb = NULL;*/
			
			}
			
		}
	}
	lc->next = la ? la : lb;

	printf("----5555555\n");
	//PrintPloyn(Pa);

	return 1;
	//Pc->next = NULL;
}
//初始条件：链表P存在
//操作结果：返回链表的长度
Status PrintLength(LinkList&P)
{
	LinkList S = P->next;
	int number = 0;
	while (NULL != S)
	{
		number++;
		S = S->next;
	}
	return number;
}
//初始条件：链表存在
//操作结果：打印多项式，P指向头结点
Status PrintPloyn(LinkList &P)
{
	LinkList S;
	S = P->next;
	while (NULL!=S)
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
//int main()
//{
//	LinkList pa, pb,pc;
//	CreatePloyn(pa, 4);
//	PrintPloyn(pa);
//	printf("lengthA %d", PrintLength(pa));
//	CreatePloyn(pb, 4);
//	PrintPloyn(pb);
//	printf("lengthB %d", PrintLength(pb));
//	AddPolyn(pa, pb, pc);
////	printf("lengthA %d", PrintLength(pa));
////	printf("lengthB %d", PrintLength(pb));
//	PrintPloyn(pc);
////	PrintPloyn(pa);
////	PrintPloyn(pb);
//	system("pause");
//}