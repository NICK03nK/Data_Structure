#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = (STDataType*)calloc(InitCap, sizeof(STDataType));
	if (ps->a == NULL)
	{
		perror("calloc");
		exit(-1);
	}
	ps->top = 0;
	ps->capacity = InitCap;
}

void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

STDataType StackTop(const ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}

int StackSize(const ST* ps)
{
	assert(ps);
	return ps->top;
}

bool StackEmpty(const ST* ps)
{
	assert(ps);
	return ps->top == 0;
}