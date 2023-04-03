#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

//1.²âÊÔ½¨Ð¡¸ù¶Ñ
void Test1()
{
	HP hp;
	InitHP(&hp);

	int arr[] = { 65,100,70,32,50,60 };

	int i = 0;
	for (i = 0; i < 6; i++)
	{
		HPPush(&hp, arr[i]);
	}

	PrintHP(&hp);
}

//2.²âÊÔ½¨´ó¸ù¶Ñ
void Test2()
{
	HP hp;
	InitHP(&hp);

	int arr[] = { 65,100,70,32,50,60 };

	int i = 0;
	for (i = 0; i < 6; i++)
	{
		HPPush(&hp, arr[i]);
	}

	PrintHP(&hp);
}

//3.²âÊÔ¶ÑÅÅÐò ---- Ð¡¶ÑÅÅÉýÐò£¬´ó¶ÑÅÅ½µÐò
void Test3()
{
	HP hp;
	InitHP(&hp);

	int arr[] = { 65,100,70,32,50,60 };

	int i = 0;
	for (i = 0; i < 6; i++)
	{
		HPPush(&hp, arr[i]);
	}

	while (!IsHPEmpty(&hp))
	{
		printf("%d ", HPTop(&hp));
		HPPop(&hp);
	}

	PrintHP(&hp);
}

int main()
{
	Test3();
	return 0;
}