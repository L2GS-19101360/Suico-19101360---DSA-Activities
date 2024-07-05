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

#endif
