#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

void Test1(ST* ps)
{
	StackPush(ps, 1);
	StackPush(ps, 2);
	StackPush(ps, 3);
	printf("%d", StackTop(ps));
	StackPop(ps);
	StackPush(ps, 4);
	StackPush(ps, 5);
	printf("%d", StackTop(ps));
	StackPop(ps);
	StackPush(ps, 6);
	while (!StackEmpty(ps))
	{
		printf("%d", StackTop(ps));
		StackPop(ps);
	}
}

int main()
{
	ST st;
	StackInit(&st);
	Test1(&st);
	return 0;
}