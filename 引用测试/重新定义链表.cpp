//��ʱ��ʵ�֣��Ƚϸ���
#include "malloc.h"
#define Status int
#define ElemType int
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}*Link,*Position;

typedef struct
{
	Link head, tail;//����ָ�������ͷ�������һ������
	int len;//��������ĳ��ȣ��ڵ���������û��
}LinkList;
Status InitList(LinkList&L)//�������ͷ���Ŀձ�
{
	//L = (LinkList)malloc(sizeof(LinkList));
	return 1;
}