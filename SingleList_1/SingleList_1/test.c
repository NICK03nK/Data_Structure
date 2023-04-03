#define _CRT_SECURE_NO_WARNINGS 1

#include"SingleList.h"

//���Ե�����ͷ��
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

//���Ե�����β��
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

//���Ե�����ͷɾ
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

//���Ե�����βɾ
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

//���Ե�������posǰ����
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
		printf("û�ҵ�\n");
	}

	DestroySLT(&plist);
}

//���Ե�������pos�����
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
		printf("û�ҵ�\n");
	}

	DestroySLT(&plist);
}

//���Ե�����ɾ����pos��������
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
		printf("û�ҵ�\n");
	}

	DestroySLT(&plist);
}

//���Ե�����ɾ����pos���������
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
		printf("û�ҵ�\n");
	}

	DestroySLT(&plist);
}

int main()
{
	Test9();
	return 0;
}