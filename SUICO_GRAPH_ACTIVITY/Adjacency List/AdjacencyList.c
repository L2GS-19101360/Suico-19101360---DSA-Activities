#include <stdio.h>
#include <stdlib.h>
#include "AdjacencyList.h"

void removeVertex(Graph *adjacencyList, int vertex) 
{
    // Step 1: Remove all edges connected to the vertex
    NodePtr temp = adjacencyList->array[vertex];
    while (temp != NULL) {
        removeEdge(adjacencyList, vertex, temp->vertex);
        temp = adjacencyList->array[vertex];
    }
    // Step 2: Shift all vertices after the removed vertex
    int i;
    for (i = vertex; i < adjacencyList->numberVertices - 1; i++) {
        adjacencyList->array[i] = adjacencyList->array[i + 1];
    }
    adjacencyList->array[adjacencyList->numberVertices - 1] = NULL;
    // Step 3: Update all adjacency lists
    for (i = 0; i < adjacencyList->numberVertices - 1; i++) {
        temp = adjacencyList->array[i];
        while (temp != NULL) {
            if (temp->vertex > vertex) {
                temp->vertex--;
            }
            temp = temp->next;
        }
    }

    adjacencyList->numberVertices--;
}
void removeEdge(Graph *adjacencyList, int vertex1, int vertex2) 
{
    // Remove vertex2 from the adjacency list of vertex1
    NodePtr temp = adjacencyList->array[vertex1];
    NodePtr prev = NULL;
    while (temp != NULL && temp->vertex != vertex2) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        if (prev == NULL) {
            adjacencyList->array[vertex1] = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
    // Remove vertex1 from the adjacency list of vertex2
    temp = adjacencyList->array[vertex2];
    prev = NULL;
    while (temp != NULL && temp->vertex != vertex1) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        if (prev == NULL) {
            adjacencyList->array[vertex2] = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
}
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
