#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "BST.h"

void DELETENODE(char findName[], NodePtr *bst)
{
    if (*bst == NULL) {
        return;
    } else {
	    if ((strcmp((*bst)->item.prodName, findName)) > 0) {
	        DELETENODE(findName, &(*bst)->left);
	    } else if ((strcmp((*bst)->item.prodName, findName)) < 0) {
	        DELETENODE(findName, &(*bst)->right);
	    } else {
			NodePtr temp;
	
	        if ((*bst)->left == NULL && (*bst)->right == NULL) {
	            free(*bst);
	            *bst = NULL;
	        }
	        else if ((*bst)->left == NULL) {
	            temp = *bst;
	            *bst = (*bst)->right;
	            free(temp);
	        } else if ((*bst)->right == NULL) {
	            temp = *bst;
	            *bst = (*bst)->left;
	            free(temp);
	        }
	        else {
	            temp = (*bst)->right;
	            while (temp->left != NULL) {
	                temp = temp->left;
	            }
	
	            (*bst)->item = temp->item;
	
	            DELETENODE(temp->item.prodName, &(*bst)->right);
	        }
	    }
	}
}

void PRINTPRODUCT(Product prod)
{
    printf("| %-12s | $%6.2f | %3d | %02d/%02d/%4d |\n", prod.prodName, 
														 prod.prodPrice, 
														 prod.prodQty,
														 prod.expDate.month, 
														 prod.expDate.day, 
														 prod.expDate.year);
}
void BFS(NodePtr bst) {
	QueueBST queue;
	INITIALIZEQUEUE(&queue);
	
	if (bst != NULL) {
		ENQUEUE(bst, &queue);
		while (!ISEMPTY(queue)) {
			NodePtr current = FRONT(queue);
			PRINTPRODUCT(current->item);
			DEQUEUE(&queue);
			if (current->left != NULL) {
				ENQUEUE(current->left, &queue);
			}
			if (current->right != NULL) {
				ENQUEUE(current->right, &queue);
			}
		}
	}
	free(queue.queuePtr);
}

void ENQUEUE(NodePtr item, QueueBST *qbst) {
	if (!ISFULL(*qbst)) {
		qbst->rear = (qbst->rear + 1) % MAX;
		qbst->queuePtr[qbst->rear] = item;
		qbst->count++;
		if (qbst->front == -1) {
			qbst->front = qbst->rear;
		}
	}
}

NodePtr FRONT(QueueBST qbst) {
	return (!ISEMPTY(qbst)) ? qbst.queuePtr[qbst.front] : NULL;
}

void DEQUEUE(QueueBST *qbst) {
	if (!ISEMPTY(*qbst)) {
		qbst->front = (qbst->front + 1) % MAX;
		qbst->count--;
		if (qbst->count == 0) {
			qbst->front = qbst->rear = -1;
		}
	}
}

bool ISEMPTY(QueueBST qbst) {
	return (qbst.count == 0);
}

bool ISFULL(QueueBST qbst) {
	return (qbst.count == MAX);
}

void INITIALIZEQUEUE(QueueBST *qbst) {
	qbst->queuePtr = (NodePtr *)malloc(sizeof(NodePtr) * MAX);
	if (qbst->queuePtr != NULL) {
		qbst->front = qbst->rear = -1;
		qbst->count = 0;
	}
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
        {"Bread", 2.29, 75, {7, 1, 2024}},
        {"Cheese", 4.99, 40, {6, 30, 2024}},
        {"Grape", 2.99, 80, {7, 3, 2024}},
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
