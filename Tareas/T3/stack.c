#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Stack* s_new()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->root = NULL;

	return s;
}

int s_isEmpty(Stack* s) { return !s->root; }

void s_push(Stack* s, int data)
{
	SNode* sNode = (SNode*)malloc(sizeof(SNode));

	sNode->data = data;
	sNode->next = s->root;

	s->root = sNode;
}

void s_pop(Stack* s)
{
	if(s_isEmpty(s))
		return;

	SNode* temp = s->root;
	s->root = (s->root)->next;
	free(temp);
}

int s_peek(Stack* s)
{
	if(s_isEmpty(s))
		return INT_MIN;

	return s->root->data;
}

void s_display(Stack* s)
{
	SNode* sNode = s->root;

	printf("[\t");
	while(sNode)
	{
		printf("%d\t", sNode->data);

		sNode = sNode->next;
	}
	printf("]\n");
}
