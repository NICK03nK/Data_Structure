#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

LTNode* BuyLTNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("BuyLTNode fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}

LTNode* InitLT()
{
	LTNode* guard = (LTNode*)malloc(sizeof(LTNode));
	if (guard == NULL)
	{
		perror("BuyLTNode fail");
		exit(-1);
	}
	guard->prev = guard;
	guard->next = guard;
	return guard;
}

void PrintLT(LTNode* phead)
{
	assert(phead);
	printf("guard<=>");
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void DestroyLT(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}

bool EmptyLT(LTNode* phead)
{
	assert(phead);
	return phead->next == phead;
}

void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode* first = phead->next;
	LTNode* newnode = BuyLTNode(x);
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;*/

	LTInsertBefor(phead->next, x);
}

void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(!EmptyLT(phead));
	/*LTNode* first = phead->next;
	LTNode* second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);
	first = NULL;*/

	LTErase(phead->next);
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode* tail = phead->prev;
	LTNode* newnode = BuyLTNode(x);
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/

	LTInsertBefor(phead, x);
}

void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(!EmptyLT(phead));
	/*LTNode* tail = phead->prev;
	LTNode* prev = tail->prev;
	phead->prev = prev;
	prev->next = phead;
	free(tail);
	tail = NULL;*/

	LTErase(phead->prev);
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void LTInsertBefor(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* newnode = BuyLTNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void LTErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}