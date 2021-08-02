#include<string>
#include<iostream>
#define ElemType int 

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

bool InitList(LinkList &L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL);
	return false;
	L->next = NULL;
	return true;
}

void test() {
	LinkList L;
	InitList(L);
}

bool Empty(LinkList L{
	if (L->next == NULL)
	return true;
	else
	return false;
	}