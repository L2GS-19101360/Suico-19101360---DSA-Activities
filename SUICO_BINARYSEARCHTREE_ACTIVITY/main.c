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
    printf("After Adding Milk Product:\n");
    Product data[] = {
        {"Milk", 0.79, 120, {7, 4, 2024}},
        {"Yogurt", 1.79, 60, {6, 29, 2024}},
        {"Ham", 5.49, 30, {7, 15, 2024}}
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
    
	printf("After Adding Yogurt and Ham Products:\n");
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
    
    //After Deleting Bread Node
    printf("After Deleting Apple Products:\n");
    DELETENODE("Apple", trav);
    printf("BFS Traversal:\n");
	BFS(bst);
	printf("\nPreorder traversal:\n");
    DFSPREORDER(bst);
    printf("\nInorder traversal:\n");
    DFSINORDER(bst);
    printf("\nPostorder traversal:\n");
    DFSPOSTORDER(bst);
    getchar(); system("cls");
	
	//After Deleting Grape Node
    printf("After Deleting Grape Products:\n");
    DELETENODE("Grape", trav);
    printf("BFS Traversal:\n");
	BFS(bst);
	printf("\nPreorder traversal:\n");
    DFSPREORDER(bst);
    printf("\nInorder traversal:\n");
    DFSINORDER(bst);
    printf("\nPostorder traversal:\n");
    DFSPOSTORDER(bst);
    getchar(); system("cls");
    
    //After Deleting Ham Node
    printf("After Deleting Ham Products:\n");
    DELETENODE("Ham", trav);
    printf("BFS Traversal:\n");
	BFS(bst);
	printf("\nPreorder traversal:\n");
    DFSPREORDER(bst);
    printf("\nInorder traversal:\n");
    DFSINORDER(bst);
    printf("\nPostorder traversal:\n");
    DFSPOSTORDER(bst);
	return 0;
}
