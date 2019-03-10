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
	int stacksize;//��ǰ�Ѿ�����Ŀռ䣬������ջ�ĳ���
}SqStack;
//��ʼ������ջS������
//�������:��ʼ��ջS
Status InitStack3(SqStack&S)
{
	S.base = (SElemType*)malloc(sizeof(SElemType));
	if (!S.base) return -1;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}
//��ʼ������ջS����
//�������:����ջ�ĳ���
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
//��ʼ������ջS����
//�������:��Ԫ��e��ջ
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
//��ʼ������ջS����
//�������:��ջ������ջ��Ԫ��
Status Pop3(SqStack&S, SElemType&e)
{
	if (S.base == S.top) return -1;
	e = *(S.top);
	S.top--;
	return 1;
}
//��ʼ������ջS����
//�������:���ջ
Status ClearStack3(SqStack&S)
{
	S.top = S.base;
	return 1;
}
//��ʼ������ջS����
//�������:����ջ
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
//��ʼ������ջS����
//�������:��ջture,���򷵻�false
Status StackEmpty3(SqStack&S)
{
	if (S.top = S.base) return true;
	return false;
}
//��ʼ������ջS����
//�������:��e����ջ��Ԫ��
Status GetTop3(SqStack&S, SElemType&e)
{
	SElemType *p = S.top;
	p--;
	e = *(p);
	return 1;
}


//��ʼ������ջS����
//�������:��ջ����ʼ���ջ�����ݣ��൱������
Status PrintStack3(SqStack&S)
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
//��ʼ������ջS����
//�������:��ջ�׿�ʼ���ջ������
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
//��ʼ������ջS����
//�������:�����ַ�ջ�����ն˽���һ�в����������ù��̵�������,��дһ�����һ��
void LineEdit()
{
	SqStack S;
	char topelement;
	InitStack3(S);
	//printf("����һ���ַ�1:\n");
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
			//printf("����һ���ַ�2:\n");
			ch = getchar();
		}
		PrintStackBottom3(S);
		ClearStack3(S);
		if (ch != EOF)
		{
			//printf("����һ���ַ�3:\n");
			ch = getchar();
		}
		

	}

}




int main()
{
	LineEdit();
	system("pause");
}