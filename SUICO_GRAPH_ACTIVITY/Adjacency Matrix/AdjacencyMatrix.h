#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX

enum Vertices {
	A, B, C, D, E
};

#define MAX 5

void initAdjacencyMatrix(int adjacencyMatrix[][MAX]);
void addEdge(int adjacencyMatrix[][MAX], int vertex1, int vertex2);
void displayAdjacencyMatrix(int adjacencyMatrix[][MAX]);

#endif
