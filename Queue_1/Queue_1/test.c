#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void Test1()
{
	Queue q;
	InitQueue(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	printf("Front = %d ", QueueFront(&q));
	QueuePop(&q);
	printf("Queue_size = %d\n", QueueSize(&q));
	printf("Front = %d ", QueueFront(&q));
	QueuePop(&q);
	printf("Queue_size = %d\n", QueueSize(&q));

	printf("Back = %d ", QueueBack(&q));

	DestroyQueue(&q);
}

int main()
{
	Test1();
	return 0;
}