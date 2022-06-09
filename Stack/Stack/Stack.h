#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define InitCap 4

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);

void StackDestroy(ST* ps);

void StackPush(ST* ps, STDataType x);

void StackPop(ST* ps);

STDataType StackTop(const ST* ps);

int StackSize(const ST* ps);

bool StackEmpty(const ST* ps);