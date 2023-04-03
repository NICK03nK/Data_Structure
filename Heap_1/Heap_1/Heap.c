#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

void InitHP(HP* php)
{
	assert(php);

	php->data = (HPDataType*)malloc(InitCap * sizeof(HPDataType));
	if (php->data == NULL)
	{
		perror("InitHP fail");
		exit(-1);
	}

	php->size = 0;
	php->capacity = InitCap;
}

void PrintHP(HP* php)
{
	assert(php);

	int i = 0;
	for (i = 0; i < php->size; i++)
	{
		printf("%d ", php->data[i]);
	}
	printf("\n");
}

void DestroyHP(HP* php)
{
	assert(php);

	free(php->data);
	php->data = NULL;
	php->size = 0;
	php->capacity = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* p, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (p[parent] < p[child])
		{
			Swap(&p[parent], &p[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HPPush(HP* php, HPDataType x)
{
	assert(php);
	
	if (php->size == php->capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(php->data, 2 * php->capacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}

		php->data = tmp;
		php->capacity *= 2;
	}

	php->data[php->size] = x;
	php->size++;

	AdjustUp(php->data, php->size - 1);
}

void AdjustDown(HPDataType* p, int sz, int parent)
{
	int Child = parent * 2 + 1;
	
	while (Child < sz)
	{
		if (Child + 1 < sz && p[Child + 1] > p[Child])
		{
			Child++;
		}

		if (p[Child] > p[parent])
		{
			Swap(&p[Child], &p[parent]);
			parent = Child;
			Child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HPPop(HP* php)
{
	assert(php);
	assert(!IsHPEmpty(php));

	Swap(&php->data[0], &php->data[php->size - 1]);
	php->size--;

	AdjustDown(php->data, php->size, 0);
}

HPDataType HPTop(HP* php)
{
	assert(php);
	assert(!IsHPEmpty(php));

	return php->data[0];
}

bool IsHPEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}

int HPSize(HP* php)
{
	assert(php);

	return php->size;
}