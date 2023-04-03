#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void InitQueue(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

void DestroyQueue(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	pq->head = NULL;
	pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
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
		pq->tail = pq->tail->next;
	}
	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!IsQueueEmpty(pq));
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = NULL;
		pq->tail = NULL;
	}
	else
	{
		QNode* del = pq->head;
		pq->head = pq->head->next;
		free(del);
		del = NULL;
	}
	pq->size--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!IsQueueEmpty(pq));
	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!IsQueueEmpty(pq));
	return pq->tail->data;
}

bool IsQueueEmpty(Queue* pq)
{
	assert(pq);
	return (pq->head == NULL && pq->tail == NULL);
}

int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}