#include <stdio.h>
#include <string.h>
#include "stack.h"

#define MAX 30

int main(void)
{
	Stack* stack;
	char string[MAX] = "Tercer Examen";
	char character;
	int length;

	stack = s_new();

	length = strlen(string);

	for(int i = 0; i < length; i++)
	{
		s_push(stack, string[i]);
	}

	while(!s_isEmpty(stack))
	{
		character = s_pop(stack);

		printf("%c", character);
	}

	printf("\n");
	return 0;
}
