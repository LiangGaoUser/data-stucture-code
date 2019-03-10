#include "malloc.h"
#include <cstdlib>
#include <stdio.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define Status int
#define SElemType char
typedef struct
{
	SElemType*base;
	SElemType*top;
	int stacksize;//��ǰ�Ѿ�����Ŀռ䣬������ջ�ĳ���
}SqStack;
//��ʼ������ջS������
//�������:��ʼ��ջS
Status InitStack2(SqStack&S)
{
	S.base = (SElemType*)malloc(sizeof(SElemType));
	if (!S.base) return -1;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}
//��ʼ������ջS����
//�������:����ջ�ĳ���
Status StackLength2(SqStack&S)
{
	SElemType *p;
	p = S.top;
	p--;
	int length = 0;
	for (p; p >= S.base; p--)
	{
		length++;
	}
	return length;
}
//��ʼ������ջS����
//�������:��Ԫ��e��ջ
Status Push2(SqStack&S, SElemType e)
{
	//SElemType *p;
	if (StackLength2(S) + 1 > S.stacksize)
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
Status Pop2(SqStack&S, SElemType&e)
{
	if (S.base == S.top) return -1;
	e = *(S.top);
	S.top--;
	return 1;
}
//��ʼ������ջS����
//�������:���ջ
Status ClearStack2(SqStack&S)
{
	S.top = S.base;
	return 1;
}
//��ʼ������ջS����
//�������:����ջ
Status DestoryStack2(SqStack&S)
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
Status StackEmpty2(SqStack&S)
{
	if (S.top = S.base) return true;
	return false;
}
//��ʼ������ջS����
//�������:��e����ջ��Ԫ��
Status GetTop2(SqStack&S, SElemType&e)
{
	SElemType *p = S.top;
	p--;
	e = *(p);
	return 1;
}


//��ʼ������ջS����
//�������:���ջ
Status PrintStack2(SqStack&S)
{
	SElemType *p;
	p = S.top;
	p--;//����pӦ���Ǵ�S.top����һ����ʼ
	for (p; p >= S.base; p--)
	{
		printf("%c", *p);
	}
	return 1;
}
//��ʼ��������
//�������:���������Ƿ�ƥ��
Status bracket()
{
	SqStack S;
	InitStack2(S);
	int m=0;
	char brack;
	char test;
	printf("�������ŵĸ���\n");
	scanf_s("%d", &m);
	printf("ssss%d", m);
	for (int i = 0; i < m; i++)
	{
		scanf_s("%c", &brack,5);/////////
		if (brack == '\n') break;
		Push2(S, brack);
		GetTop2(S, test);
		printf("%c", test);
		printf("%d", i);
	}
	printf("length %d", StackLength2(S));
	PrintStack2(S);
	return true;
}
//int main()
//{
//	/*SqStack L;
//	InitStack2(L);
//	Push2(L, 'a');
//	Push2(L, 'b');
//	PrintStack2(L);
//	SElemType e;
//	GetTop2(L, e);
//	printf("%c", e);*/
//	bracket();
//	system("pause");
//
//
//
//}