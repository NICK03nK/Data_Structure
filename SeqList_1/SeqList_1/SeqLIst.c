#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void CheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		SLDataType* tmp = (SLDataType*)realloc(ps->data, ps->capacity * 2 * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc");
			return;
		}
		ps->data = tmp;
		ps->capacity *= 2;
	}
}

void InitSeqList(SL* ps)
{
	assert(ps);
	ps->data = (SLDataType*)malloc(InitCap * sizeof(SLDataType));
	ps->size = 0;
	ps->capacity = InitCap;
}

void PrintSeqList(const SL* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d\n", ps->data[i]);
	}
}

void DestroySeqList(SL* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void PushBack(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->data[ps->size] = x;
	ps->size++;
}

void PopBack(SL* ps)
{
	assert(ps);
	ps->size--;
}

void PushFront(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	ps->data[0] = x;
	ps->size++;
}