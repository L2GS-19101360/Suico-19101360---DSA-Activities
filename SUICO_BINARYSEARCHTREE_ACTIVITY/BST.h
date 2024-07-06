#ifndef BST
#define BST
#include "stdbool.h"

#define MAX 10

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

typedef struct {
	NodePtr *queuePtr;
	int front;
	int rear;
	int count;
}QueueBST;

void INITIALIZEBST (NodePtr *bst);
bool ISNULLBST(NodePtr bst);
void POPULATEBST(NodePtr *bst);
void INSERTNODE(Product item, NodePtr *bst);
void DELETENODE(char find[], NodePtr *bst);

void BFS(NodePtr bst);

void INITIALIZEQUEUE(QueueBST *qbst);
void ENQUEUE(NodePtr item, QueueBST *qbst);
void DEQUEUE(QueueBST *qbst);
NodePtr FRONT(QueueBST qbst);
bool ISEMPTY(QueueBST qbst);
bool ISFULL(QueueBST qbst);

void DFSPREORDER(NodePtr bst);
void DFSINORDER(NodePtr bst);
void DFSPOSTORDER(NodePtr bst);

void PRINTPRODUCT(Product prod);

#endif
