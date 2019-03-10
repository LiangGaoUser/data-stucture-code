#include "malloc.h"
#include <cstdlib>
#include <stdio.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define Status int
#define SElemType int
typedef struct
{
	SElemType*base;
	SElemType*top;
	int stacksize;//��ǰ�Ѿ�����Ŀռ䣬������ջ�ĳ���
}SqStack;
//��ʼ������ջS������
//�������:��ʼ��ջS
Status InitStack(SqStack&S)
{
	S.base = (SElemType*)malloc(sizeof(SElemType));
	if (!S.base) return -1;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}
//��ʼ������ջS����
//�������:����ջ�ĳ���
Status StackLength(SqStack&S)
{
	SElemType *p;
	p = S.top;
	int length = 0;
	for (p; p >=S.base; p--)
	{
		length++;
	}
	return length;
}
//��ʼ������ջS����
//�������:��Ԫ��e��ջ
Status Push(SqStack&S, SElemType e)
{
	//SElemType *p;
	if (StackLength(S) + 1 > S.stacksize)
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
	}
	if (!S.base) return -1;
	S.stacksize = S.stacksize + STACKINCREMENT;
	*(S.top) = e;
	S.top++;
	return 1;
}
//��ʼ������ջS����
//�������:��ջ������ջ��Ԫ��
Status Pop(SqStack&S, SElemType&e)
{
	if (S.base == S.top) return -1;
	e = *(S.top);
	S.top--;
	return 1;
}
//��ʼ������ջS����
//�������:���ջ
Status ClearStack(SqStack&S)
{
	S.top = S.base;
	return 1;
}
//��ʼ������ջS����
//�������:����ջ
Status DestoryStack(SqStack&S)
{
	for (S.base; S.base < S.top; S.base++)
	{
		free(S.base);
	}
	S.base = S.top = NULL;
	S.stacksize = 0;
	return 1;
}
//��ʼ������ջS����
//�������:��ջture,���򷵻�false
Status StackEmpty(SqStack&S)
{
	if (S.top = S.base) return true;
	return false;
}
//��ʼ������ջS����
//�������:��e����ջ��Ԫ��
Status GetTop(SqStack&S,SElemType&e)
{
	SElemType *p= S.top;
	p--;
	e = *(p);
	return 1;
}


//��ʼ������ջS����
//�������:���ջ
Status PrintStack(SqStack&S)
{
	SElemType *p;
	p = S.top;
	p--;//����pӦ���Ǵ�S.top����һ����ʼ
	for (p; p >= S.base; p--)
	{
		printf("%d", *p);
	}
	return 1;
}
//��ʼ��������
//�������:����Ǹ�ʮ���������������Ӧ�İ˽�����
void conversion()
{
	SqStack S;
	InitStack(S);
	int N,M;
	printf("������Ǹ�ʮ��������\n");
	scanf_s("%d", &N);
	M = N;
	while (N)
	{
		Push(S, N % 8);
		N = N / 8;
	}
	printf("(%d)10=(",M);
	PrintStack(S);
	printf(")8\n");
}
//int main()
//{
//	//SqStack L;
//	//InitStack(L);
//	//Push(L, 4);
//	//Push(L, 5);
//	//PrintStack(L);
//	//SElemType e;
//	//GetTop(L, e);
//	//printf("%d", e);
//	conversion();
//	system("pause");
//
//
//
//}