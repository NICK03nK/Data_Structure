#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

void ListInit(LTNode** pphead);

void ListPrint(const LTNode* phead);

void ListPushFront(LTNode* phead, LTDataType x);

void ListPushBack(LTNode* phead, LTDataType x);

void ListPopFront(LTNode* phead);

void ListPopBack(LTNode* phead);

LTNode* ListFind(const LTNode* phead, LTDataType x);

void ListInsert(LTNode* pos, LTDataType x);

void ListErase(LTNode* pos);

void ListDestroy(LTNode* phead);