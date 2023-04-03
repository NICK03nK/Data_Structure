#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType* data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

typedef BTNode* QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

void InitQueue(Queue* pq);

void DestroyQueue(Queue* pq);

void QueuePush(Queue* pq, QDataType x);

void QueuePop(Queue* pq);

QDataType QueueFront(Queue* pq);

QDataType QueueBack(Queue* pq);

bool IsQueueEmpty(Queue* pq);

int QueueSize(Queue* pq);