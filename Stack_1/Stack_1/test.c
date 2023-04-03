#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

//1.≤‚ ‘’ªµƒ»Î’ª
void Test1()
{
	ST s;
	InitST(&s);

	STPush(&s, 1);
	STPush(&s, 2);
	STPush(&s, 3);
	STPush(&s, 4);
	STPush(&s, 5);

	DestroyST(&s);
}

//2.≤‚ ‘’ªµƒ≥ˆ’ª
void Test2()
{
	ST s;
	InitST(&s);

	STPush(&s, 1);
	STPush(&s, 2);
	STPush(&s, 3);

	printf("%d\n", STTop(&s));
	STPop(&s);
	printf("%d\n", STTop(&s));
	STPop(&s);

	STPush(&s, 4);
	STPush(&s, 5);

	while (!IsSTEmpty(&s))
	{
		printf("%d\n", STTop(&s));
		STPop(&s);
	}

	DestroyST(&s);
}

//3.≤‚ ‘’ªµƒ≥ˆ’ª
void Test3()
{
	ST s;
	InitST(&s);

	STPush(&s, 1);
	STPush(&s, 2);
	STPush(&s, 3);

	printf("Top = %d ", STTop(&s));
	STPop(&s);
	printf("Stack_size  = %d\n", STSize(&s));
	printf("Top = %d ", STTop(&s));
	STPop(&s);
	printf("Stack_size  = %d\n", STSize(&s));

	STPush(&s, 4);
	STPush(&s, 5);

	while (!IsSTEmpty(&s))
	{
		printf("Top = %d ", STTop(&s));
		STPop(&s);
		printf("Stack_size  = %d\n", STSize(&s));
	}

	DestroyST(&s);
}

int main()
{
	Test3();
	return 0;
}