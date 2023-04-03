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

void SLPushFront(SL* ps, SLDataType x);

void SLPopFront(SL* ps);

void SLPushBack(SL* ps, SLDataType x);

void SLPopBack(SL* ps);

int SLFind(const SL* ps, SLDataType x);

void SLInsert(SL* ps, size_t pos, SLDataType x);

void SLErase(SL* ps, size_t pos);