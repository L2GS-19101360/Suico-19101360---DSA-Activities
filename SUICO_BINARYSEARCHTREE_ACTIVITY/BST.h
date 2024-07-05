#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE
#include <stdbool.h>

typedef struct {
	int month, day, year;
}Date;

typedef struct {
	char prodName[20];
	float prodPrice;
	int prodQty;
	Date expDate;
}Product;

typedef struct node {
	Product item;
	struct node *left, *right;
}NodeType, *NodePtr;

void INITIALIZEBST (NodePtr *bst);
bool ISNULLBST(NodePtr bst);
void POPULATEBST(NodePtr *bst);
void INSERTNODE(Product item, NodePtr *bst);

void BFS(NodePtr bst);

void DFSPREORDER(NodePtr bst);
void DFSINORDER(NodePtr bst);
void DFSPOSTORDER(NodePtr bst);

void PRINTPRODUCT(Product prod);

#endif
