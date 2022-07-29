#define _CRT_SECURE_NO_WARNINGS 1

#include"SingleList.h"

void PrintSLT(SLTNode* phead)
{
	if (phead != NULL)
	{
		SLTNode* cur = phead;
		while (cur != NULL)
		{
			printf("%d->", cur->data);
			cur = cur->next;
		}
	}
	printf("NULL\n");
}