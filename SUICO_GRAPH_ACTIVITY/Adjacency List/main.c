#include <stdio.h>
#include <stdlib.h>
#include "AdjacencyList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Graph adjacencyList;
    initAdjacencyList(&adjacencyList, 5);

    addVertex(&adjacencyList);
    addVertex(&adjacencyList);
    addVertex(&adjacencyList);
    addVertex(&adjacencyList);
    addVertex(&adjacencyList);
    
    addEdge(&adjacencyList, A, B);
    addEdge(&adjacencyList, A, C);
    addEdge(&adjacencyList, A, D);
    addEdge(&adjacencyList, B, C);
    addEdge(&adjacencyList, B, D);
    addEdge(&adjacencyList, B, E);
    addEdge(&adjacencyList, C, D);
    addEdge(&adjacencyList, D, E);
    
    displayAdjacencyList(adjacencyList);
    
    addVertex(&adjacencyList);
    
	addEdge(&adjacencyList, F, E);
    addEdge(&adjacencyList, F, C);
    
	displayAdjacencyList(adjacencyList);
	return 0;
}
