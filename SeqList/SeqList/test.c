#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void menu()
{
	printf("******************************************\n");
	printf("****   1.PushFront       2.PushBack   ****\n");
	printf("****   3.PopFront        4.PopBack    ****\n");
	printf("****   5.Insert          6.Erase      ****\n");
	printf("****   7.Search          8.Modify     ****\n");
	printf("****   9.Print           0.Exit       ****\n");
	printf("******************************************\n");
}

enum Option
{
	Exit,
	PushFront,
	PushBack,
	PopFront,
	PopBack,
	Insert,
	Erase,
	Search,
	Modify,
	Print
};

int main()
{
	SL s;
	InitSeqList(&s);
	int input = 0;
	DataType x = 0;
	do
	{
		menu();
		printf("请选择程序>>");
		scanf("%d", &input);
		switch (input)
		{
		case PushFront:
			SeqlistPushFront(&s, x);
			break;
		case PushBack:
			SeqListPushBack(&s, x);
			break;
		case PopFront:
			SeqListPopFront(&s);
			break;
		case PopBack:
			SeqListPopBack(&s);
			break;
		case Insert:
			SeqListInsert(&s, x);
			break;
		case Erase:
			SeqListErase(&s);
			break;
		case Search:
			SeqListSearch(&s);
			break;
		case Modify:
			SeqListModify(&s, x);
			break;
		case Print:
			SeqListPrint(&s);
			break;
		case Exit:
			SeqListDestroy(&s);
			printf("\n<退出程序>\n\n");
			break;
		default:
			printf("\n<选择错误，请重新选择>\n\n");
			break;
		}
	} while (input);
	return 0;
}