#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	NodePtr bst;
	INITIALIZEBST(&bst);
	POPULATEBST(&bst);
	
	//Initial Product List
	printf("Initial Product List:\n");
	printf("BFS Traversal:\n");
	BFS(bst);
	printf("\nPreorder traversal:\n");
    DFSPREORDER(bst);
    printf("\nInorder traversal:\n");
    DFSINORDER(bst);
    printf("\nPostorder traversal:\n");
    DFSPOSTORDER(bst);
    getchar(); system("cls");
    
    //Adding More Product Data
    printf("After Adding Bread Product:\n");
    Product data[] = {
	    {"Bread", 2.29, 75, {7, 1, 2024}},
        {"Cheese", 4.99, 40, {6, 30, 2024}},
        {"Yogurt", 1.79, 60, {6, 29, 2024}}
	};
	NodePtr *trav = &bst;
	INSERTNODE(data[0], trav);
	printf("BFS Traversal:\n");
	BFS(bst);
	printf("\nPreorder traversal:\n");
    DFSPREORDER(bst);
    printf("\nInorder traversal:\n");
    DFSINORDER(bst);
    printf("\nPostorder traversal:\n");
    DFSPOSTORDER(bst);
    getchar(); system("cls");
    printf("After Adding Cheese and Yogurt Products:\n");
    
	INSERTNODE(data[1], trav);
	INSERTNODE(data[2], trav);
	printf("BFS Traversal:\n");
	BFS(bst);
	printf("\nPreorder traversal:\n");
    DFSPREORDER(bst);
    printf("\nInorder traversal:\n");
    DFSINORDER(bst);
    printf("\nPostorder traversal:\n");
    DFSPOSTORDER(bst);
    getchar(); system("cls");
    
	//Deleting Product Data
	return 0;
}
