#include <stdio.h>

#include "stack.h"

typedef struct
{
	int w, h;
	int obstacles[100][100];
} Field;

void initField(Field*);
void findPath(Field);

int main()
{
	Field field;

	initField(&field);

	/*
	printf("%d, %d\n", field.w, field.h);
	for(int i = 0; i < field.h; i++)
	{
		for(int j = 0; j < field.w; j++)
			printf("[%d, %d]: %d \t", j, i, field.obstacles[j][i]);
		printf("\n");
	}
	*/

	findPath(field);

	printf("\n");

	return 0;
}

void initField(Field* f)
{
	FILE* fptr = fopen("field.txt", "r");

	if(fptr == NULL)
	{
		printf("Error opening file");
		return;
	}

	char temp;
	for(int i = 0, j = 0; fscanf(fptr, "%d%c", &f->obstacles[j][i], &temp) != EOF; j++)
	{
		if(!f->h)
			f->w++;
		if(temp == '\n')
		{
			f->h++;
			i++;
			j = -1;
		}
	}

	if(fclose(fptr) == EOF)
		printf("Error closing file");
}

void findPath(Field f)
{
	int x = f.w - 1, y = f.h - 1;
	int visited[100][100] = {0};

	Stack* s = s_new();
	s_push(s, x + (y * f.h));

	while(x != 0 || y != 0)
	{
		if(s_isEmpty(s))
		{
			printf("no path");
			return;
		}
		int pos = s_peek(s);
		x = pos % f.h;
		y = pos / f.h;
		visited[x][y] = 1;
		if(y - 1 >= 0 && !f.obstacles[x][y - 1] && !visited[x][y - 1])
		{
			y--;
			s_push(s, x + (y * f.h));
		}
		else
		{
			if(x - 1 >= 0 && !f.obstacles[x - 1][y] && !visited[x - 1][y])
			{
				x--;
				s_push(s, x + (y * f.h));
			}
			else
				s_pop(s);
		}
	}

	SNode* sNode = s->root;

	while(sNode)
	{
		int pos = sNode->data;
		printf("(%d, %d)", pos % f.h, pos / f.h);

		sNode = sNode->next;
		if(sNode)
			printf(" -> ");
	}
}
