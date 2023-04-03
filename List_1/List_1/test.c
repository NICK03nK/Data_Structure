#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

//1.����˫����ڱ�ͷ�����β��
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

//2.����˫����ڱ�ͷ�����ͷ��
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

//3.����˫����ڱ�ͷ�����βɾ
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

//4.����˫����ڱ�ͷ�����ͷɾ
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

//5.����˫����ڱ�ͷ����Ĳ��Ҽ��޸�
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

//6.����˫����ڱ�ͷ������posλ��ǰ��������
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

//7.����˫����ڱ�ͷ����ɾ��posλ�õ�����
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