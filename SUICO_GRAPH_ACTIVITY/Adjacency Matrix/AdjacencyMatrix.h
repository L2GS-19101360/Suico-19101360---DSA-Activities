#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX

enum Vertices {
    A, B, C, D, E, F, G, H
};

typedef struct {
    int maxVertices;
    int numberVertices;
    int **array;
} Graph;

void initAdjacencyMatrix(Graph *adjacencyMatrix);
void addEdge(Graph *adjacencyMatrix, int v1, int v2);
void addVertex(Graph *adjacencyMatrix);
void removeVertex(Graph *adjacencyMatrix, int vertex);
void removeEdge(Graph *adjacencyMatrix, int v1, int v2);
void displayAdjacencyMatrix(Graph adjacencyMatrix);

#endif
