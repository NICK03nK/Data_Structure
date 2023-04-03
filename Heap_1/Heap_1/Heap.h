#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

#define InitCap 4

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* data;
	int size;
	int capacity;
}HP;

void InitHP(HP* php);

void PrintHP(HP* php);

void DestroyHP(HP* php);

void HPPush(HP* php, HPDataType x);

void HPPop(HP* php);

HPDataType HPTop(HP* php);

bool IsHPEmpty(HP* php);

int HPSize(HP* php);