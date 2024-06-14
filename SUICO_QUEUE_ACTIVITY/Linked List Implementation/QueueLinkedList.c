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
	return q.front->data;
}
bool Dequeue(Queue *q)
{
	int retBool = false;
	NodePtr temp;
	if (!isEmpty(*q)) {
		temp = q->front;
		q->front = temp->next;
		free(temp);
		
		if (q->front == q->rear) {
			q->front = q->rear = NULL;
		}	
	}
	return retBool;
}
int Rear(Queue q)
{
	return q.rear->data;
}

bool isEmpty(Queue q)
{
	return (q.front == NULL && q.rear == NULL) ? true : false;
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
