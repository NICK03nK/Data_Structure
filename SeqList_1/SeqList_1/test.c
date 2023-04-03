#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void Test1()
{
	SL s;
	InitSeqList(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	
	SLPushFront(&s, 10);
	SLPushFront(&s, 20);
	SLPushFront(&s, 30);

	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);

	PrintSeqList(&s);

	DestroySeqList(&s);
}

void Test2()
{
	SL s;
	InitSeqList(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);

	PrintSeqList(&s);

	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);

	PrintSeqList(&s);

	DestroySeqList(&s);
}

void Test3()
{
	SL s;
	InitSeqList(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);

	PrintSeqList(&s);

	int ret = SLFind(&s, 6);
	printf("%d\n", ret);

	DestroySeqList(&s);
}

void Test4()
{
	SL s;
	InitSeqList(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);

	PrintSeqList(&s);

	SLInsert(&s, 4, 20);

	PrintSeqList(&s);

	SLErase(&s, 5);

	PrintSeqList(&s);

	DestroySeqList(&s);
}

int main()
{
	Test4();
	return 0;
}