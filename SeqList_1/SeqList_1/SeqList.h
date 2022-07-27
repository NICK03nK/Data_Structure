#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define InitCap 4

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* data;
	int size;
	int capacity;
}SL;

void InitSeqList(SL* ps);

void PrintSeqList(const SL* ps);

void DestroySeqList(SL* ps);

void PushFront(SL* ps, SLDataType x);

void PushBack(SL* ps, SLDataType x);

void PopBack(SL* ps);