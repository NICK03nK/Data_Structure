#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLTDataType;

typedef struct SingleListNode
{
	SLTDataType data;
	struct SingleListNode* next;
}SLTNode;

void PrintSLT(SLTNode* phead);

void DestroySLT(SLTNode** pphead);

void SLTPushFront(SLTNode** pphead, SLTDataType x);

void SLTPopFront(SLTNode** pphead);

void SLTPushBack(SLTNode** pphead, SLTDataType x);

void SLTPopBack(SLTNode** pphead);

SLTNode* SLTFind(SLTNode* phead, SLTDataType x);

void SLTInsertBefore(SLTNode** pphead, SLTNode* pos, SLTDataType x);

void SLTInsertAfter(SLTNode* pos, SLTDataType x);

void SLTErase(SLTNode** pphead, SLTNode* pos);

void SLTEraseAfter(SLTNode* pos);