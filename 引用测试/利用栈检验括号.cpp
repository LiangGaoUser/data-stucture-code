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
	int stacksize;//当前已经分配的空间，并不是栈的长度
}SqStack;
//初始条件：栈S不存在
//操作结果:初始化栈S
Status InitStack2(SqStack&S)
{
	S.base = (SElemType*)malloc(sizeof(SElemType));
	if (!S.base) return -1;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}
//初始条件：栈S存在
//操作结果:返回栈的长度
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
//初始条件：栈S存在
//操作结果:将元素e入栈
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
//初始条件：栈S存在
//操作结果:出栈，返回栈顶元素
Status Pop2(SqStack&S, SElemType&e)
{
	if (S.base == S.top) return -1;
	e = *(S.top);
	S.top--;
	return 1;
}
//初始条件：栈S存在
//操作结果:清空栈
Status ClearStack2(SqStack&S)
{
	S.top = S.base;
	return 1;
}
//初始条件：栈S存在
//操作结果:销毁栈
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
//初始条件：栈S存在
//操作结果:空栈ture,否则返回false
Status StackEmpty2(SqStack&S)
{
	if (S.top = S.base) return true;
	return false;
}
//初始条件：栈S存在
//操作结果:用e返回栈顶元素
Status GetTop2(SqStack&S, SElemType&e)
{
	SElemType *p = S.top;
	p--;
	e = *(p);
	return 1;
}


//初始条件：栈S存在
//操作结果:输出栈
Status PrintStack2(SqStack&S)
{
	SElemType *p;
	p = S.top;
	p--;//这里p应该是从S.top的下一个开始
	for (p; p >= S.base; p--)
	{
		printf("%c", *p);
	}
	return 1;
}
//初始条件：无
//操作结果:检验括号是否匹配
Status bracket()
{
	SqStack S;
	InitStack2(S);
	int m=0;
	char brack;
	char test;
	printf("输入括号的个数\n");
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