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
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}

void DestroySeqList(SL* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->data[ps->size] = x;
	ps->size++;
}

void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->size--;
}

void SLPushFront(SL* ps, SLDataType x)
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

void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	int begin = 1;
	while (begin < ps->size)
	{
		ps->data[begin - 1] = ps->data[begin];
		begin++;
	}
	ps->size--;
}

int SLFind(const SL* ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->data[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SLInsert(SL* ps, size_t pos, SLDataType x)
{
	assert(ps);
	assert(pos <= ps->size);
	CheckCapacity(ps);
	size_t end = ps->size;
	while (end > pos)
	{
		ps->data[end] = ps->data[end - 1];
		end--;
	}
	ps->data[pos] = x;
	ps->size++;
}

void SLErase(SL* ps, size_t pos)
{
	assert(ps);
	assert(pos < ps->size);
	size_t begin = pos + 1;
	while (begin < ps->size)
	{
		ps->data[begin - 1] = ps->data[begin];
		begin++;
	}
	ps->size--;
}