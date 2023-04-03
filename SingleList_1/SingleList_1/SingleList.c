#define _CRT_SECURE_NO_WARNINGS 1

#include"SingleList.h"

void PrintSLT(SLTNode* phead)
{
	if (phead != NULL)
	{
		SLTNode* cur = phead;
		while (cur != NULL)
		{
			printf("%d->", cur->data);
			cur = cur->next;
		}
	}
	printf("NULL\n");
}

void DestroySLT(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("BuySLTNode fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopFront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLTNode* cur = *pphead;
	*pphead = (*pphead)->next;
	free(cur);
	cur = NULL;
}

void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuySLTNode(x);
	SLTNode* cur = *pphead;
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}

void SLTPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* cur = *pphead;
		SLTNode* prev = NULL;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = NULL;
		free(cur);
		cur = NULL;
	}
}

SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SLTInsertBefore(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	if (*pphead == pos)
	{
		*pphead = newnode;
		newnode->next = pos;
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
			assert(prev);
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}

void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);
	if (*pphead == pos)
	{
		*pphead = pos->next;
		free(pos);
		pos = NULL;
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
			assert(prev);
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}