#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void Test1()
{
	SL s;
	InitSeqList(&s);
	PushBack(&s, 1);
	PushBack(&s, 2);
	PushBack(&s, 3);
	PushBack(&s, 4);
	PushBack(&s, 5);
	PushBack(&s, 6);
	
	PushFront(&s, 10);
	PushFront(&s, 20);
	PushFront(&s, 30);

	PrintSeqList(&s);

	DestroySeqList(&s);
}

int main()
{
	Test1();
	return 0;
}