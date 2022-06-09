#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

LTNode* BuyNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->prev = newnode->next = NULL;
	return newnode;
}

void ListInit(LTNode** pphead)
{
	assert(pphead);
	*pphead = BuyNode(0);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}

void ListPrint(const LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

LTNode* ListFind(const LTNode* phead, LTDataType x)
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

void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* first = phead->next;
	LTNode* newnode = BuyNode(x);
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;
}

void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* tail = phead->prev;
	LTNode* newnode = BuyNode(x);
	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* first = phead->next;
	LTNode* second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);
	first = NULL;
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* tail = phead->prev;
	LTNode* cur = tail->prev;
	cur->next = phead;
	phead->prev = cur;
	free(tail);
	tail = NULL;
}

void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* cur = pos->prev;
	LTNode* newnode = BuyNode(x);
	cur->next = newnode;
	newnode->prev = cur;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* next = pos->next;
	LTNode* prev = pos->prev;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}

void ListDestroy(LTNode* phead)
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
	phead = NULL;
}