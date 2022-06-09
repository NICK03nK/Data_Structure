#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define InitCap 4

typedef int DataType;

typedef struct SeqList
{
	DataType* a;
	int sz;
	int capacity;
}SL;

void InitSeqList(SL* ps);

void SeqlistPushFront(SL* ps, DataType x);

void SeqListPushBack(SL* ps, DataType x);

void SeqListPopFront(SL* ps);

void SeqListPopBack(SL* ps);

void SeqListInsert(SL* ps, DataType x);

void SeqListErase(SL* ps);

void SeqListSearch(const SL* ps);

void SeqListModify(SL* ps, DataType x);

void SeqListDestroy(SL* ps);

void SeqListPrint(const SL* ps);