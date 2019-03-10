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
	int stacksize;//当前已经分配的空间，并不是栈的长度
}SqStack;
//初始条件：栈S不存在
//操作结果:初始化栈S
Status InitStack(SqStack&S)
{
	S.base = (SElemType*)malloc(sizeof(SElemType));
	if (!S.base) return -1;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}
//初始条件：栈S存在
//操作结果:返回栈的长度
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
//初始条件：栈S存在
//操作结果:将元素e入栈
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
//初始条件：栈S存在
//操作结果:出栈，返回栈顶元素
Status Pop(SqStack&S, SElemType&e)
{
	if (S.base == S.top) return -1;
	e = *(S.top);
	S.top--;
	return 1;
}
//初始条件：栈S存在
//操作结果:清空栈
Status ClearStack(SqStack&S)
{
	S.top = S.base;
	return 1;
}
//初始条件：栈S存在
//操作结果:销毁栈
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
//初始条件：栈S存在
//操作结果:空栈ture,否则返回false
Status StackEmpty(SqStack&S)
{
	if (S.top = S.base) return true;
	return false;
}
//初始条件：栈S存在
//操作结果:用e返回栈顶元素
Status GetTop(SqStack&S,SElemType&e)
{
	SElemType *p= S.top;
	p--;
	e = *(p);
	return 1;
}


//初始条件：栈S存在
//操作结果:输出栈
Status PrintStack(SqStack&S)
{
	SElemType *p;
	p = S.top;
	p--;//这里p应该是从S.top的下一个开始
	for (p; p >= S.base; p--)
	{
		printf("%d", *p);
	}
	return 1;
}
//初始条件：无
//操作结果:输入非负十进制整数，输出对应的八进制数
void conversion()
{
	SqStack S;
	InitStack(S);
	int N,M;
	printf("请输入非负十进制整数\n");
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