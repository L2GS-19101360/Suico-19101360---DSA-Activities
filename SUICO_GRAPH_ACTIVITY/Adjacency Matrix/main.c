#include <stdio.h>
#include <stdlib.h>
#include "AdjacencyMatrix.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int adjacencyMatrix[MAX][MAX];
	initAdjacencyMatrix(adjacencyMatrix);
	
	addEdge(adjacencyMatrix, A, B);
	addEdge(adjacencyMatrix, A, C);
	addEdge(adjacencyMatrix, A, D);
	
	addEdge(adjacencyMatrix, B, A);
	addEdge(adjacencyMatrix, B, C);
	addEdge(adjacencyMatrix, B, D);
	addEdge(adjacencyMatrix, B, E);
	
	addEdge(adjacencyMatrix, C, A);
	addEdge(adjacencyMatrix, C, B);
	addEdge(adjacencyMatrix, C, D);
	
	addEdge(adjacencyMatrix, D, A);
	addEdge(adjacencyMatrix, D, B);
	addEdge(adjacencyMatrix, D, C);
	addEdge(adjacencyMatrix, D, E);
	
	addEdge(adjacencyMatrix, E, B);
	addEdge(adjacencyMatrix, E, D);
	
	displayAdjacencyMatrix(adjacencyMatrix);
	return 0;
}
