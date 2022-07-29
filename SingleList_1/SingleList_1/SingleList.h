#pragma once

#include<stdio.h>

typedef int SLTDataType;

typedef struct SingleListNode
{
	SLTDataType data;
	struct SingleListNode* next;
}SLTNode;

void PrintSLT(SLTNode* phead);