#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

#define InitCap 4

typedef int STDataType;

typedef struct Stack
{
	STDataType* data;
	int top;
	int capacity;
}ST;

void InitST(ST* ps);

void DestroyST(ST* ps);

void STPush(ST* ps, STDataType x);

void STPop(ST* ps);

bool IsSTEmpty(ST* ps);

STDataType STTop(ST* ps);

int STSize(ST* ps);