#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

//1.测试双向带哨兵头链表的尾插
void Test1()
{
	LTNode* plist = NULL;
	plist = InitLT();

	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);

	PrintLT(plist);

	DestroyLT(plist);
	plist = NULL;
}

//2.测试双向带哨兵头链表的头插
void Test2()
{
	LTNode* plist = NULL;
	plist = InitLT();

	LTPushFront(plist, 1);
	LTPushFront(plist, 2);
	LTPushFront(plist, 3);
	LTPushFront(plist, 4);
	LTPushFront(plist, 5);

	PrintLT(plist);

	DestroyLT(plist);
	plist = NULL;
}

//3.测试双向带哨兵头链表的尾删
void Test3()
{
	LTNode* plist = NULL;
	plist = InitLT();

	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);

	PrintLT(plist);

	LTPopBack(plist);
	LTPopBack(plist);
	LTPopBack(plist);

	PrintLT(plist);

	DestroyLT(plist);
	plist = NULL;
}

//4.测试双向带哨兵头链表的头删
void Test4()
{
	LTNode* plist = NULL;
	plist = InitLT();

	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);

	PrintLT(plist);

	LTPopFront(plist);
	LTPopFront(plist);
	LTPopFront(plist);

	PrintLT(plist);

	DestroyLT(plist);
	plist = NULL;
}

//5.测试双向带哨兵头链表的查找及修改
void Test5()
{
	LTNode* plist = NULL;
	plist = InitLT();

	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);

	PrintLT(plist);

	LTNode* pos = LTFind(plist, 3);
	if (pos)
	{
		pos->data *= 10;
		PrintLT(plist);
	}
	else
	{
		printf("fail\n");
	}

	DestroyLT(plist);
	plist = NULL;
}

//6.测试双向带哨兵头链表在pos位置前插入数据
void Test6()
{
	LTNode* plist = NULL;
	plist = InitLT();

	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);

	PrintLT(plist);

	LTNode* pos = LTFind(plist, 3);
	if (pos)
	{
		LTInsertBefor(pos, 80);
		PrintLT(plist);
	}
	else
	{
		printf("fail\n");
	}

	DestroyLT(plist);
	plist = NULL;
}

//7.测试双向带哨兵头链表删除pos位置的数据
void Test7()
{
	LTNode* plist = NULL;
	plist = InitLT();

	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);

	PrintLT(plist);

	LTNode* pos = LTFind(plist, 3);
	if (pos)
	{
		LTErase(pos);
		PrintLT(plist);
	}
	else
	{
		printf("fail\n");
	}

	DestroyLT(plist);
	plist = NULL;
}

int main()
{
	Test3();
	return 0;
}