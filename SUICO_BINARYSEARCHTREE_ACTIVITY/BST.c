#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "BST.h"

void PRINTPRODUCT(Product prod)
{
    printf("| %-12s | $%6.2f | %3d | %02d/%02d/%4d |\n", prod.prodName, 
														 prod.prodPrice, 
														 prod.prodQty,
														 prod.expDate.month, 
														 prod.expDate.day, 
														 prod.expDate.year);
}
void BFS(NodePtr bst)
{
	
}
void DFSPREORDER(NodePtr bst)
{
	if (bst != NULL) {
		PRINTPRODUCT(bst->item);
		DFSPREORDER(bst->left);
		DFSPREORDER(bst->right);
	}
}
void DFSINORDER(NodePtr bst)
{
	if (bst != NULL) {
		DFSINORDER(bst->left);
		PRINTPRODUCT(bst->item);
		DFSINORDER(bst->right);
	}
}
void DFSPOSTORDER(NodePtr bst)
{
	if (bst != NULL) {
		DFSPOSTORDER(bst->left);
		DFSPOSTORDER(bst->right);
		PRINTPRODUCT(bst->item);
	}
}
void POPULATEBST(NodePtr *bst)
{
	Product data[] = {
	    {"Apple", 0.99, 100, {7, 5, 2024}},
	    {"Banana", 0.49, 150, {7, 6, 2024}},
	    {"Orange", 0.79, 120, {7, 4, 2024}},
	    {"Grapes", 2.99, 80, {7, 3, 2024}},
	    {"Milk", 3.49, 50, {7, 2, 2024}}
	};
    int x, size = sizeof(data)/sizeof(data[0]);
    NodePtr *trav;
    
	for (x = 0; x < size; x++) {
    	trav = bst;
    	INSERTNODE(data[x], trav);
	}
}
void INSERTNODE(Product item, NodePtr *bst)
{
	if (*bst == NULL) {
		NodePtr temp = (NodePtr)malloc(sizeof(NodeType));
		if (temp != NULL) {
			temp->item = item;
			temp->left = temp->right = NULL;
			*bst = temp;
		}		
	} else {
		if (strcmp((*bst)->item.prodName, item.prodName) > 0) {
			INSERTNODE(item, &(*bst)->left);
		} else {
			INSERTNODE(item, &(*bst)->right);
		}
	}
}
void INITIALIZEBST (NodePtr *bst)
{
	*bst = NULL;
}
bool ISNULLBST(NodePtr bst)
{
	return (bst == NULL);
}
