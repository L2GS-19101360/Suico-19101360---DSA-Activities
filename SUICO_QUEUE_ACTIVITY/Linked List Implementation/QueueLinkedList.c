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
    Queue tempQueue = createQueue();
    while (!isEmpty(q)){
        Enqueue(&tempQueue, Front(q));
        Dequeue(&q);
    }
    
    printf("\nDisplay Queue:\n");
    while (!isEmpty(tempQueue)){
        printf("%d ", Front(tempQueue));
        Enqueue(&q, Front(tempQueue));
        Dequeue(&tempQueue);
    }
    printf("\n");
}

void visualizeQueue(Queue q)
{
    printf("Queue Visualization");
    printf("\n%-7s %-7s %-5s\n", "Index", "Data", "Status");
    printf("=======================\n");
    
    int x;
    NodePtr trav;
    for (x = 0, trav = q.front; trav != NULL; x++, trav = trav->next) {
        printf("%-7d %-7d %-5s\n", x, trav->data, trav == q.front ? "Head" : (trav == q.rear ? "Rear" : ""));
    }
}

Queue getAllEvenNumbers(Queue *q)
{
	Queue tempQueue = createQueue();
    while (!isEmpty(*q)){
        Enqueue(&tempQueue, Front(*q));
        Dequeue(q);
    }
    return tempQueue;
}
