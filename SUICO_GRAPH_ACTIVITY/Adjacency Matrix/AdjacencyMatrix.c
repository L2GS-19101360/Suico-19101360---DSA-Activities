#include <stdio.h>
#include <stdlib.h>
#include "AdjacencyMatrix.h"

void displayAdjacencyMatrix(int adjacencyMatrix[][MAX])
{
	int x, y;
	printf("Adjacency Matrix:\n\n");
	printf("  ");
	for (x = 0; x < MAX; x++) {
		printf(" %c ", 'A' + x);
	}
	printf("\n");
	for (x = 0; x < MAX; x++) {
		printf("%c  ", 'A' + x);
		for (y = 0; y < MAX; y++) {
			printf("%d  ", adjacencyMatrix[x][y]);
		}
		printf("\n");
	}
}
void addEdge(int adjacencyMatrix[][MAX], int vertex1, int vertex2)
{
	adjacencyMatrix[vertex1][vertex2] = 1;
	adjacencyMatrix[vertex2][vertex1] = 1;
}
void initAdjacencyMatrix(int adjacencyMatrix[][MAX])
{
	int x, y;
	for (x = 0; x < MAX; x++) {
		for (y = 0; y < MAX; y++) {
			adjacencyMatrix[x][y] = 0;
		}
	}
}
