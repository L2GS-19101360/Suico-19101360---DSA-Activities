#include <stdio.h>
#include <stdlib.h>
#include "AdjacencyMatrix.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Graph adjacencyMatrix;
    initAdjacencyMatrix(&adjacencyMatrix);
    
    addVertex(&adjacencyMatrix);
    addVertex(&adjacencyMatrix);
    addVertex(&adjacencyMatrix);
    addVertex(&adjacencyMatrix);
    addVertex(&adjacencyMatrix);
    
    addEdge(&adjacencyMatrix, A, B);
    addEdge(&adjacencyMatrix, A, C);
    addEdge(&adjacencyMatrix, A, D);
    addEdge(&adjacencyMatrix, B, C);
    addEdge(&adjacencyMatrix, B, D);
    addEdge(&adjacencyMatrix, B, E);
    addEdge(&adjacencyMatrix, C, D);
    addEdge(&adjacencyMatrix, D, E);
    
    displayAdjacencyMatrix(adjacencyMatrix);
    
    addVertex(&adjacencyMatrix);
    
    addEdge(&adjacencyMatrix, F, E);
    addEdge(&adjacencyMatrix, F, C);
    
    displayAdjacencyMatrix(adjacencyMatrix);

    removeVertex(&adjacencyMatrix, C);

    displayAdjacencyMatrix(adjacencyMatrix);
    
    removeEdge(&adjacencyMatrix, A, D);
    removeEdge(&adjacencyMatrix, E, B);
    
    displayAdjacencyMatrix(adjacencyMatrix);
    
    return 0;
}
