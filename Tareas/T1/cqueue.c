#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "cqueue.h"

CQueue* newCQueue()
{
	CQueue* q = (CQueue*)malloc(sizeof(CQueue));
	q->front = q->rear = NULL;

	return q;
}

int qIsEmpty(CQueue* q) { return !q->front; }

void enqueue(CQueue* q, Student data)
{
	QNode* qNode = (QNode*)malloc(sizeof(QNode));

	qNode->data = data;

	if (qIsEmpty(q))
		q->front = qNode;
	else
		q->rear->next = qNode;

	q->rear = qNode;
	q->rear->next = q->front;
}

void dequeue(CQueue* q)
{
	if (qIsEmpty(q))
		return;

	QNode* temp = q->front;

	if (temp == temp->next)
	{
		free(temp);
		q->front = q->rear = NULL;
		return;
	}

	q->front = q->rear->next = q->front->next;

	free(temp);
}

Student* peekFront(CQueue* q)
{
	if (!q->front)
		return NULL;
	return &(q->front->data);
}

Student* peekRear(CQueue* q)
{
	if (!q->rear)
		return NULL;
	return &(q->rear->data);
}

void cycleQueue(CQueue* q)
{
	q->front = q->front->next;
	q->rear = q->rear->next;
}

void displayQueue2(QNode* front, QNode* qNode)
{
	if (!qNode)
		return;

	printf("%s, %d\n", qNode->data.name, qNode->data.type);
	if (qNode->next == front)
		return;
	displayQueue2(front, qNode->next);
}

void displayQueue(CQueue* q)
{
	QNode* front = q->front;

	if (qIsEmpty(q))
	{
		printf("Empty");
		return;
	}

	QNode* node = front;

	printf("[\t");
	do
	{
		printf("%s: %d\t\t", node->data.name, node->data.type);
		node = node->next;
	} while (node != front);
	printf("]\n");
}
