/*
 */

#include <stdio.h>
#include "stack.h"
#include "cqueue.h"

void initStudents(CQueue* queue, int size);
void initSandwiches(SNode** stack, int size);

int countStudents(SNode** sandwiches, CQueue* students, int size);

int main(void)
{
	int number;
	printf("Number of sandwiches and students: ");
	scanf("%d", &number);

	SNode* sandwiches = NULL;
	initSandwiches(&sandwiches, number);
	printf("Sandwiches: ");
	displayStack(sandwiches);

	CQueue* students = newCQueue();
	initStudents(students, number);
	printf("Students: ");
	displayQueue(students);
	// displayQueue2(students->front, students->front);

	printf("Remaining students: %d\n", countStudents(&sandwiches, students, number));
	displayQueue(students);

	printf("\n");
	return 0;
}

void initSandwiches(SNode** stack, int size)
{
	for (int i = 0; i < size; i++)
	{
		int type;
		printf("Sandwich %d: ", i + 1);
		scanf("%d", &type);
		push(stack, type);
	}
}

void initStudents(CQueue* queue, int size)
{
	for (int i = 0; i < size; i++)
	{
		Student temp;

		printf("*** Student %d ***\n", i + 1);
		printf("Name: ");
		scanf("%s", temp.name);
		printf("Sandwich type: ");
		scanf("%d", &temp.type);

		enqueue(queue, temp);
	}
}

int countStudents(SNode** sandwiches, CQueue* students, int size)
{
	int cycle = 0;

	while (cycle < size)
	{
		if ((*sandwiches)->data == students->front->data.type)
		{
			size--;
			pop(sandwiches);
			dequeue(students);
			cycle = 0;
		}
		else
		{
			cycle++;
			cycleQueue(students);
		}
	}

	return size;
}
