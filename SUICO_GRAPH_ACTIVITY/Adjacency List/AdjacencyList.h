#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST

enum Vertices {
    A, B, C, D, E, F, G, H
};

typedef struct node {
    int vertex;
    struct node *next;
} Node, *NodePtr;

typedef struct {
    int numberVertices;
    int maxVertices;
    NodePtr *array;
} Graph;

void initAdjacencyList(Graph *adjacencyList, int initialSize);
void addVertex(Graph *adjacencyList);
NodePtr createNode(int vertex);
void addEdge(Graph *adjacencyList, int vertex1, int vertex2);
void displayAdjacencyList(Graph adjacencyList);
void resizeArray(Graph *adjacencyList);

#endif
