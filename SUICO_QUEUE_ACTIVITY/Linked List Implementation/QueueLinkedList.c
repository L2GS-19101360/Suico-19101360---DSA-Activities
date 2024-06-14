#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QueueLinkedList.h"

void initQueue(Queue *q)
{
	q->front = q->rear = NULL;
}
Queue createQueue()
{
	Queue createQueue;
	initQueue(&createQueue);
	return createQueue;
}

bool Enqueue(Queue *q, int elem)
{
	int retBool = false;
	Node *temp = (Node *)malloc(sizeof(Node));
	if (temp != NULL) {
		temp->data = elem;
		temp->next = NULL;
		
		if (isEmpty(*q)) {
			q->front = q->rear = temp;
		} else {
			q->rear->next = temp;
			q->rear = temp;
		}
		retBool = true;
	}
	return retBool;
}
int Front(Queue q)
{
	return (!isEmpty(q)) ? q.front->data : -1;
}
bool Dequeue(Queue *q)
{
	bool retBool = false;
    NodePtr temp;
    if (!isEmpty(*q)) {
        temp = q->front;
        q->front = temp->next;
        free(temp);
        
        if (q->front == NULL) {
            q->rear = NULL;
        }
        retBool = true;
    }
    return retBool;
}
int Rear(Queue q)
{
	return (!isEmpty(q)) ? q.rear->data : -1;
}

bool isEmpty(Queue q)
{
	return (q.front == NULL && q.rear == NULL);
}

void displayQueue(Queue q)
{
	NodePtr trav;
	
	printf("Front -> ");
	for (trav = q.front; trav != NULL; trav = trav->next) {
		printf("%d -> ", trav->data);
	}
	printf("Rear");
}
