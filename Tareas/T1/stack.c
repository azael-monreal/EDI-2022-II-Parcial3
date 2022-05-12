#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int sIsEmpty(SNode* root) { return !root; }

void push(SNode** root, int data)
{
	SNode* newNode = (SNode*)malloc(sizeof(SNode));

	newNode->data = data;
	newNode->next = *root;

	*root = newNode;
}

void pop(SNode** root)
{
	if (sIsEmpty(*root))
		return;

	SNode* temp = *root;
	*root = (*root)->next;
	free(temp);
}

int peek(SNode* root)
{
	if (sIsEmpty(root))
		return INT_MIN;

	return root->data;
}

void displayStack(SNode* root)
{
	SNode* sNode = root;

	printf("[\t");
	while (sNode)
	{
		printf("%d\t", sNode->data);

		sNode = sNode->next;
	}
	printf("]\n");
}

void displayR(SNode* root)
{
	if (root)
	{
		displayR(root->next);
		printf("%c", root->data);
	}
}
