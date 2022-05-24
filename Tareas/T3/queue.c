#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

Queue* q_new()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->front = q->rear = NULL;

	return q;
}

int q_isEmpty(Queue* q) { return !q->front; }

void q_enqueue(Queue* q, int data)
{
	QNode* qNode = (QNode*)malloc(sizeof(QNode));

	qNode->data = data;
	qNode->next = NULL;

	if(q_isEmpty(q))
		q->front = qNode;
	else
		q->rear->next = qNode;

	q->rear = qNode;
}

void q_dequeue(Queue* q)
{
	if(q_isEmpty(q))
		return;

	QNode* temp = q->front;

	q->front = q->front->next;

	if(q_isEmpty(q))
		q->rear = NULL;

	free(temp);
}

int q_peekFront(Queue* q)
{
	if(!q->front)
		return INT_MIN;
	return (q->front->data);
}

int q_peekRear(Queue* q)
{
	if(!q->rear)
		return INT_MIN;
	return (q->rear->data);
}

void q_display(Queue* q)
{
	QNode* node = q->front;
	if(!node)
		return;

	while(node)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
}
