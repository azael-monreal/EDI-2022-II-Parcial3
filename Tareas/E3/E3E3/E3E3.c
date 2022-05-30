#include <stdio.h>
#include <string.h>

#include "queue.h"
#include "stack.h"

#define G_MXSIZE 10

typedef struct
{
	int edges[G_MXSIZE][G_MXSIZE];
	char vertices[G_MXSIZE][20];
	int visited[G_MXSIZE];
	int size;
} UGraph;

void g_init(UGraph*);

int g_addVertex(UGraph*, char*);
int g_addEdge(UGraph*, char*, char*);

void g_BFT(UGraph, char*);

int main(void)
{
	UGraph graph;
	g_init(&graph);
	g_addVertex(&graph, "A");
	g_addVertex(&graph, "B");
	g_addVertex(&graph, "C");
	g_addVertex(&graph, "D");
	g_addVertex(&graph, "E");
	g_addVertex(&graph, "G");
	g_addVertex(&graph, "H");
	g_addEdge(&graph, "A", "B");
	g_addEdge(&graph, "A", "D");
	g_addEdge(&graph, "A", "E");
	g_addEdge(&graph, "A", "G");
	g_addEdge(&graph, "B", "E");
	g_addEdge(&graph, "B", "C");
	g_addEdge(&graph, "D", "H");
	g_addEdge(&graph, "G", "H");
	g_BFT(graph, "A");
	printf("\n");
	return 0;
}

void g_init(UGraph* graph)
{
	graph->size = 0;
	memset(graph->visited, 0, sizeof graph->visited);
}

int g_isFull(UGraph graph) { return graph.size == G_MXSIZE; }
int g_isEmpty(UGraph graph) { return graph.size == 0; }

int g_findVertex(UGraph graph, char* vert)
{
	for(int i = 0; i < graph.size; i++)
		if(strcmp(graph.vertices[i], vert) == 0)
			return i;

	return -1;
}

int g_addVertex(UGraph* g, char* v)
{
	if(g_isFull(*g))
		return -1;

	if(g_findVertex(*g, v) != -1)
		return 0;

	strcpy(g->vertices[g->size], v);
	g->size++;

	for(int i = 0; i < g->size; i++)
		g->edges[g->size - 1][i] = g->edges[i][g->size - 1] = 0;

	return 1;
}

int g_edgeExists(UGraph g, int pos1, int pos2)
{
	if(pos1 < 0 || pos2 < 0)
		return -1;

	if(g.edges[pos1][pos2])
		return 1;

	return 0;
}

int g_addEdge(UGraph* graph, char* vertA, char* vertB)
{
	if(g_isEmpty(*graph))
		return -1;

	int pos1 = g_findVertex(*graph, vertA);
	int pos2 = g_findVertex(*graph, vertB);

	int exists = g_edgeExists(*graph, pos1, pos2);

	if(exists == -1)
		return -1;

	if(exists == 1)
		return 0;

	graph->edges[pos1][pos2] = graph->edges[pos2][pos1] = 1;

	return 1;
}

void g_BFT(UGraph g, char* v)
{
	int pos = g_findVertex(g, v);
	if(pos == -1)
		return;

	int visited[G_MXSIZE] = {0};
	Queue* q = q_new();

	visited[pos] = 1;
	q_enqueue(q, pos);

	while(!q_isEmpty(q))
	{
		int temp = q_peekFront(q);
		if(temp != pos)
			printf(" -> ");
		printf("%s", g.vertices[temp]);
		q_dequeue(q);

		for(int i = 0; i < g.size; i++)
		{
			if(g_edgeExists(g, temp, i) && !visited[i])
			{
				visited[i] = 1;
				q_enqueue(q, i);
			}
		}
	}
}
