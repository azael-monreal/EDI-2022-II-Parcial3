/*
 * Utilizando las funciones de Colas realizadas en clase, indique cual es la
 * salida del siguiente código tomando en cuenta que cuando la función
 * algoritmo_examense llama, la primer cola contiene los valores [2, 3, 9] y la
 * segunda [1, 4, 8, 9].
 */

#include <stdio.h>

#define MAX 10

typedef struct Queue
{
	int data[MAX + 1], start, end;

} Queue;

void initiate(Queue* q);
int isEmpty(Queue q);
int isFull(Queue q);
int enqueue(Queue* q, int data);
int dequeue(Queue* q, int* data);
void printQ(Queue q);
void algorithm(Queue* q1, Queue* q2);

int main(void)
{
	Queue queue1, queue2;

	initiate(&queue1);
	initiate(&queue2);

	enqueue(&queue1, 2);
	enqueue(&queue1, 3);
	enqueue(&queue1, 9);

	enqueue(&queue2, 1);
	enqueue(&queue2, 4);
	enqueue(&queue2, 8);
	enqueue(&queue2, 9);

	algorithm(&queue1, &queue2);

	return 0;
}

void initiate(Queue* q) { q->start = q->end = 0; }

int isEmpty(Queue q) { return q.start == q.end; }
int isFull(Queue q) { return q.start == (q.end + 1) % (MAX + 1); }

int enqueue(Queue* q, int data)
{
	if (isFull(*q))
		return 0;

	q->data[q->end] = data;
	q->end = (q->end + 1) % (MAX + 1);

	return 1;
}

int dequeue(Queue* q, int* data)
{
	if (isEmpty(*q))
		return 0;

	*data = q->data[q->start];
	q->start = (q->start + 1) % (MAX + 1);
	return 1;
}

void printQ(Queue q)
{
	printf("[\t");
	for (int i = q.start; i % (MAX + 1) != q.end; i++)
		printf("%d\t", q.data[i % (MAX + 1)]);
	printf(" ]");
}

void algorithm(Queue* q1, Queue* q2)
{
	int value1, value2;
	int counter = 0;

	while (counter < 3)
	{
		if (dequeue(q1, &value1) == 1)
		{
			if (value1 % 2 == 0)
				enqueue(q2, value1);
			else
				enqueue(q1, value1);
		}

		if (dequeue(q2, &value2) == 1)
		{
			if (value2 % 2 != 0)
				enqueue(q1, value2);
			else
				enqueue(q2, value2);
		}
		counter++;

		printf("\n");
		printQ(*q1);
		printf("\n");
		printQ(*q2);
	}
}
