#include "malloc.h"
#include <cstdlib>
#include <stdio.h>

#define Status int
typedef struct ploynomial
{
	float coef;//ϵ��
	int expn;//ָ��
	ploynomial*next;
}*LinkList;
//��ʼ�������������
//�����������������Ѱ�Һ�ָ��e�Ƿ�����ȵ������з���false�����򷵻ظ�Ԫ��Ӧ�ò����ǰһ��Ԫ�ص�ָ��
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
		printf("������ϵ��\n");
		scanf_s("%f", &S->coef);
		printf("������ָ��\n");
		scanf_s("%d", &S->expn);
		while (LocateElem(P, p,S->expn))
		{
			printf("�ö���ʽ�Ѿ�����ָ��Ϊ%d�������������ָ��\n", S->expn);
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
			printf("%.2fx��%d�η�\n", S->coef,S->expn);
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