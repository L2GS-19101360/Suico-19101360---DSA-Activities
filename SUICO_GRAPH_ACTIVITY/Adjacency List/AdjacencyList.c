#include <stdio.h>
#include <stdlib.h>
#include "AdjacencyList.h"

void initAdjacencyList(Graph *adjacencyList, int initialSize) 
{
    adjacencyList->numberVertices = 0;
    adjacencyList->maxVertices = initialSize;
    adjacencyList->array = malloc(sizeof(NodePtr) * adjacencyList->maxVertices);
    int x;
    if (adjacencyList->array != NULL) {
        for (x = 0; x < adjacencyList->maxVertices; x++) {
            adjacencyList->array[x] = NULL;
        }
    }
}

void addVertex(Graph *adjacencyList) 
{
    if (adjacencyList->numberVertices >= adjacencyList->maxVertices) {
        resizeArray(adjacencyList);
    }
    adjacencyList->array[adjacencyList->numberVertices] = NULL;
    adjacencyList->numberVertices++;
}

void resizeArray(Graph *adjacencyList) 
{
    int newMaxVertices = adjacencyList->maxVertices * 2;
    NodePtr *newArray = malloc(sizeof(NodePtr) * newMaxVertices);
    int x;
    if (newArray != NULL) {
        for (x = 0; x < adjacencyList->numberVertices; x++) {
            newArray[x] = adjacencyList->array[x];
        }
        for (x = adjacencyList->numberVertices; x < newMaxVertices; x++) {
            newArray[x] = NULL;
        }
        free(adjacencyList->array);
        adjacencyList->array = newArray;
        adjacencyList->maxVertices = newMaxVertices;
    }
}

NodePtr createNode(int vertex) 
{
    NodePtr temp = (NodePtr)malloc(sizeof(Node));
    if (temp != NULL) {
        temp->vertex = vertex;
        temp->next = NULL;
    }
    return temp;
}

void addEdge(Graph *adjacencyList, int vertex1, int vertex2) 
{
    NodePtr newNode = createNode(vertex2);
    newNode->next = adjacencyList->array[vertex1];
    adjacencyList->array[vertex1] = newNode;

    newNode = createNode(vertex1);
    newNode->next = adjacencyList->array[vertex2];
    adjacencyList->array[vertex2] = newNode;
}

void displayAdjacencyList(Graph adjacencyList) 
{
    printf("Adjacency List:\n");
    int x;
    for (x = 0; x < adjacencyList.numberVertices; x++) {
        printf("Vertex %c: ", 'A' + x);
        NodePtr temp = adjacencyList.array[x];
        for (;temp != NULL; temp = temp->next) {
            printf("%c -> ", 'A' + temp->vertex);
        }
        printf("NULL\n");
    }
    printf("\n");
}

