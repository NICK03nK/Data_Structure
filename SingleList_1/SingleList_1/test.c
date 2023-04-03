#define _CRT_SECURE_NO_WARNINGS 1

#include"SingleList.h"

//测试单链表头插
void Test1()
{
	SLTNode* plist = NULL;

	SLTPushFront(&plist, 1);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 4);
	SLTPushFront(&plist, 5);

	PrintSLT(plist);

	DestroySLT(&plist);
}

//测试单链表尾插
void Test2()
{
	SLTNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);

	PrintSLT(plist);

	DestroySLT(&plist);
}

//测试单链表头删
void Test3()
{
	SLTNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);

	PrintSLT(plist);

	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);

	PrintSLT(plist);

	DestroySLT(&plist);
}

//测试单链表尾删
void Test5()
{
	SLTNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);

	PrintSLT(plist);

	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);

	PrintSLT(plist);

	DestroySLT(&plist);
}

//测试单链表在pos前插入
void Test6()
{
	SLTNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);

	PrintSLT(plist);

	SLTNode* pos = SLTFind(plist, 1);
	if (pos)
	{
		SLTInsertBefore(&plist, pos, 17);

		PrintSLT(plist);
	}
	else
	{
		printf("没找到\n");
	}

	DestroySLT(&plist);
}

//测试单链表在pos后插入
void Test7()
{
	SLTNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);

	PrintSLT(plist);

	SLTNode* pos = SLTFind(plist, 3);
	if (pos)
	{
		SLTInsertAfter(pos, 7);

		PrintSLT(plist);
	}
	else
	{
		printf("没找到\n");
	}

	DestroySLT(&plist);
}

//测试单链表删除在pos处的数据
void Test8()
{
	SLTNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);

	PrintSLT(plist);

	SLTNode* pos = SLTFind(plist, 1);
	if (pos)
	{
		SLTErase(&plist, pos);

		PrintSLT(plist);
	}
	else
	{
		printf("没找到\n");
	}

	DestroySLT(&plist);
}

//测试单链表删除在pos后面的数据
void Test9()
{
	SLTNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);

	PrintSLT(plist);

	SLTNode* pos = SLTFind(plist, 5);
	if (pos)
	{
		SLTEraseAfter(pos);

		PrintSLT(plist);
	}
	else
	{
		printf("没找到\n");
	}

	DestroySLT(&plist);
}

int main()
{
	Test9();
	return 0;
}