#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

int main()
{
	LTNode* plist = NULL;
	ListInit(&plist);
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);
	ListPushFront(plist, 6);
	ListPushFront(plist, 7);
	ListPushFront(plist, 8);
	ListPrint(plist);
	ListPopFront(plist);
	ListPrint(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);
	LTNode* pos = ListFind(plist, 6);
	/*ListInsert(pos, 60);
	ListPrint(plist);*/
	if (pos)
	{
		ListInsert(pos, 60);
		ListPrint(plist);
	}
	else
	{
		printf("pos is NULL");
	}
	pos = ListFind(plist, 6);
	if (pos)
	{
		ListErase(pos);
		ListPrint(plist);
	}
	else
	{
		printf("pos is NULL");
	}
	ListDestroy(plist);
	return 0;
}