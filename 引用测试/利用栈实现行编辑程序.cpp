#include "malloc.h"
#include <cstdlib>
#include <stdio.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define Status int
#define SElemType char
#define EOF '$'
typedef struct
{
	SElemType*base;
	SElemType*top;
	int stacksize;//当前已经分配的空间，并不是栈的长度
}SqStack;
//初始条件：栈S不存在
//操作结果:初始化栈S
Status InitStack3(SqStack&S)
{
	S.base = (SElemType*)malloc(sizeof(SElemType));
	if (!S.base) return -1;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}
//初始条件：栈S存在
//操作结果:返回栈的长度
Status StackLength3(SqStack&S)
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
Status Push3(SqStack&S, SElemType e)
{
	//SElemType *p;
	if (StackLength3(S) + 1 > S.stacksize)
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
Status Pop3(SqStack&S, SElemType&e)
{
	if (S.base == S.top) return -1;
	e = *(S.top);
	S.top--;
	return 1;
}
//初始条件：栈S存在
//操作结果:清空栈
Status ClearStack3(SqStack&S)
{
	S.top = S.base;
	return 1;
}
//初始条件：栈S存在
//操作结果:销毁栈
Status DestoryStack3(SqStack&S)
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
Status StackEmpty3(SqStack&S)
{
	if (S.top = S.base) return true;
	return false;
}
//初始条件：栈S存在
//操作结果:用e返回栈顶元素
Status GetTop3(SqStack&S, SElemType&e)
{
	SElemType *p = S.top;
	p--;
	e = *(p);
	return 1;
}


//初始条件：栈S存在
//操作结果:从栈顶开始输出栈的内容，相当于逆序
Status PrintStack3(SqStack&S)
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
//初始条件：栈S存在
//操作结果:从栈底开始输出栈的内容
Status PrintStackBottom3(SqStack&S)
{
	SElemType *p;
	p = S.base;
	for (p; p < S.top; p++)
	{
		printf("%c", *p);
	}
	return 1;
}
//初始条件：栈S存在
//操作结果:利用字符栈，从终端接收一行并传送至调用过程的数据区,即写一行输出一行
void LineEdit()
{
	SqStack S;
	char topelement;
	InitStack3(S);
	//printf("输入一个字符1:\n");
	char ch;
	//scanf("%c", &ch);
	ch=getchar();
	while (ch != EOF)
	{
		while (ch!=EOF&&ch != '\n')
		{
			switch ( ch)
			{
			case '#':
				Pop3(S, topelement);
				break;
			case '@':
				ClearStack3(S);
				break;
			default:
				Push3(S, ch);
				break;
			}
			//printf("输入一个字符2:\n");
			ch = getchar();
		}
		PrintStackBottom3(S);
		ClearStack3(S);
		if (ch != EOF)
		{
			//printf("输入一个字符3:\n");
			ch = getchar();
		}
		

	}

}




int main()
{
	LineEdit();
	system("pause");
}