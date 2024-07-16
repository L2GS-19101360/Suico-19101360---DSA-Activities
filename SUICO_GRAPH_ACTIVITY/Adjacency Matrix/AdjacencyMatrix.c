#include <stdio.h>
#include <stdlib.h>
#include "AdjacencyMatrix.h"

void addVertex(Graph *adjacencyMatrix)
{
    if (adjacencyMatrix->numberVertices == adjacencyMatrix->maxVertices) {
        int newMaxVertices = adjacencyMatrix->maxVertices * 2;
        int **newArray = (int **)malloc(sizeof(int*) * newMaxVertices);
        
        if (newArray == NULL) {
            fprintf(stderr, "Memory allocation failed during resize\n");
            exit(EXIT_FAILURE);
        }
        int x, y;
        for (x = 0; x < newMaxVertices; x++) {
            newArray[x] = (int *)malloc(sizeof(int) * newMaxVertices);
        }
        
		for (x = 0; x < adjacencyMatrix->maxVertices; x++) {
            for (y = 0; y < adjacencyMatrix->maxVertices; y++) {
                newArray[x][y] = adjacencyMatrix->array[x][y];
            }
            free(adjacencyMatrix->array[x]);
        }
        free(adjacencyMatrix->array);
        
        for (x = adjacencyMatrix->maxVertices; x < newMaxVertices; x++) {
            for (y = 0; y < newMaxVertices; y++) {
                newArray[x][y] = 0;
            }
        }
        for (x = 0; x < newMaxVertices; x++) {
            for (y = adjacencyMatrix->maxVertices; y < newMaxVertices; y++) {
                newArray[x][y] = 0;
            }
        }
        
        adjacencyMatrix->array = newArray;
        adjacencyMatrix->maxVertices = newMaxVertices;
    }
    
    adjacencyMatrix->numberVertices++;
}

void displayAdjacencyMatrix(Graph adjacencyMatrix)
{
    int x, y;
    printf("Adjacency Matrix:\n");
    printf("  ");
    for (x = 0; x < adjacencyMatrix.numberVertices; x++) {
        printf(" %c ", 'A' + x);
    }
    printf("\n");
    for (x = 0; x < adjacencyMatrix.numberVertices; x++) {
        printf("%c  ", 'A' + x);
        for (y = 0; y < adjacencyMatrix.numberVertices; y++) {
            printf("%d  ", adjacencyMatrix.array[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

void addEdge(Graph *adjacencyMatrix, int v1, int v2)
{
    adjacencyMatrix->array[v1][v2] = 1;
    adjacencyMatrix->array[v2][v1] = 1;
}

void initAdjacencyMatrix(Graph *adjacencyMatrix)
{
    adjacencyMatrix->maxVertices = 5;
    adjacencyMatrix->array = (int **)malloc(sizeof(int*) * adjacencyMatrix->maxVertices);
    int x, y;
    for (x = 0; x < adjacencyMatrix->maxVertices; x++) {
        adjacencyMatrix->array[x] = (int *)malloc(sizeof(int) * adjacencyMatrix->maxVertices);
    }
    for (x = 0; x < adjacencyMatrix->maxVertices; x++) {
        for (y = 0; y < adjacencyMatrix->maxVertices; y++) {
            adjacencyMatrix->array[x][y] = 0;
        }
    }
    adjacencyMatrix->numberVertices = 0;
}

