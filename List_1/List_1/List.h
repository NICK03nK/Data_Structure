#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

LTNode* InitLT();

void PrintLT(LTNode* phead);

void DestroyLT(LTNode* phead);

bool EmptyLT(LTNode* phead);

void LTPushFront(LTNode* phead, LTDataType x);

void LTPopFront(LTNode* phead);

void LTPushBack(LTNode* phead, LTDataType x);

void LTPopBack(LTNode* phead);

LTNode* LTFind(LTNode* phead, LTDataType x);

void LTInsertBefor(LTNode* pos, LTDataType x);

void LTErase(LTNode* pos);