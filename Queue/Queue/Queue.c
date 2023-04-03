#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	//当队列里只有一个数据时，直接free
	//会导致下一次如果再push的话，tail
	//会变成野指针
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

QDataType QueueFront(const Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}

QDataType QueueBack(const Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->tail->data;
}

int QueueSize(const Queue* pq)
{
	assert(pq);
	int size = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

bool QueueEmpty(const Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}