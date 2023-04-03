#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

void InitST(ST* ps)
{
	assert(ps);
	ps->data = (STDataType*)malloc(InitCap * sizeof(STDataType));
	if (ps->data == NULL)
	{
		perror("InitST fail");
		exit(-1);
	}
	ps->top = 0;
	ps->capacity = InitCap;
}

void DestroyST(ST* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void STPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->data, 2 * ps->capacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->data = tmp;
		ps->capacity *= 2;
	}
	ps->data[ps->top] = x;
	ps->top++;
}

void STPop(ST* ps)
{
	assert(ps);
	assert(!IsSTEmpty(ps));
	ps->top--;
}

bool IsSTEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

STDataType STTop(ST* ps)
{
	assert(ps);
	assert(!IsSTEmpty(ps));
	return ps->data[ps->top - 1];
}

int STSize(ST* ps)
{
	assert(ps);
	return ps->top;
}