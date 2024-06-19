#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QueueArray.h"

void initQueue(CircularArray *q)
{
	q->front = q->rear = -1;
}
CircularArray createQueue()
{
	CircularArray q;
	initQueue(&q);
	return q;
}

bool Enqueue(CircularArray *q, int elem)
{
	bool retBool = false;
	if (!isFull(*q)) {
		q->rear = (q->rear + 1)%MAX;
		q->data[q->rear] = elem;
		if (q->front == -1) {
			q->front = q->rear;
		}
		retBool = true;
	} else {
		printf("Queue is Full\n");
	}
	return retBool;
}
int Front(CircularArray q)
{
	return (!isEmpty(q)) ? q.data[q.front] : -1;
}
bool Dequeue(CircularArray *q)
{
	bool retBool = false;
	if (!isEmpty(*q)) {
		q->front = (q->front + 1)%MAX;
		if (q->front == q->rear) { 
			q->front = q->rear = -1;
		}
		retBool = true;
	} else {
		printf("Queue is Empty\n");
	}
	return retBool;
}
int Rear(CircularArray q)
{
	return (!isEmpty(q)) ? q.data[q.rear] : -1;
}

bool isEmpty(CircularArray q)
{
	return (q.front == (q.rear + 1)%MAX) || q.front == -1;
}
bool isFull(CircularArray q)
{
	return (q.front == (q.rear + 2)%MAX);
}

void displayQueue(CircularArray q)
{
	CircularArray temp = createQueue();
	int i;
	for (i = q.front; i != q.rear; i = (i + 1) % MAX) {
        Enqueue(&temp, q.data[i]);
    }
    Enqueue(&temp, q.data[q.rear]);
	
	printf("\nDisplay Queue:\n");
	for (i = temp.front; i != temp.rear; i = (i + 1) % MAX) {
        printf("%d ", temp.data[i]);
    }
    printf("%d ", temp.data[temp.rear]);
}
void visualizeQueue(CircularArray q)
{
	printf("Queue Visualization");
    printf("\n%-7s %-7s %-5s\n", "Index", "Data", "Status");
    printf("=======================\n");
    
    int x, i;
    for (x = 0, i = q.front; i != q.rear; x++, i = (i + 1) % MAX) {
        printf("%-7d %-7d %-5s\n", x, q.data[i], i == q.front ? "Head" : "");
    }
    printf("%-7d %-7d %-5s\n", x, q.data[q.rear], "Rear");
}

CircularArray getAllEvenNumbers(CircularArray *q)
{
	CircularArray evenQueue = createQueue();
    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % MAX) {
        if (q->data[i] % 2 == 0) {
            Enqueue(&evenQueue, q->data[i]);
        }
    }
    if (q->data[q->rear] % 2 == 0) {
        Enqueue(&evenQueue, q->data[q->rear]);
    }
    return evenQueue;
}
