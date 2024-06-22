#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FCFSQueue.h"

FCFSQueue createFCFS()
{
	FCFSQueue fq;
	initFCFS(&fq);
	return fq;
}
void initFCFS(FCFSQueue *fq)
{
	fq->front = fq->rear = NULL;
}
void populateFCFS(FCFSQueue *fq)
{
	ProcessData data[] = {
		{'A', 2, 1},
		{'B', 0, 2},
		{'C', 1, 3},
	};
	int x, s = sizeof(data)/sizeof(data[0]);
	
	for (x = 0; x < s; x++) {
		EnqueueProcess(fq, data[x]);
	}
}
void fcfsScheduling(FCFSQueue *fq)
{
	FCFSQueue temp = createFCFS();
	ProcessNodePtr frontNode, checkNode;
	while (!isEmpty(*fq)) {
		checkNode = Front(*fq);
		DequeueProcess(fq);
		frontNode = Front(*fq);
		if (checkNode->process.arrivalTime >= frontNode->process.arrivalTime) {
			
		} else {
			
		}
	}
}
bool EnqueueProcess(FCFSQueue *fq, ProcessData p)
{
	bool retBool = false;
	ProcessNodePtr temp = (ProcessNodePtr)malloc(sizeof(ProcessNode));
	if (temp != NULL) {
		temp->process = p;
		temp->next = NULL;
		if (isEmpty(*fq)) {
			fq->front = fq->rear = temp;
		} else {
			fq->rear->next = temp;
			fq->rear = temp;
		}
		retBool = true;
	}
	return retBool;
}
ProcessNodePtr Front(FCFSQueue fq)
{
	return (!isEmpty(fq)) ? fq.front : NULL;
}
bool DequeueProcess(FCFSQueue *fq)
{
	bool retBool = false;
	ProcessNodePtr temp;
	if (isEmpty(*fq)) {
		temp = fq->front;
		fq->front = temp->next;
		free(temp);
		if (fq->front == NULL) {
			fq->rear = NULL;
		}
		retBool = true;
	}
	return retBool;
}
ProcessNodePtr Rear(FCFSQueue fq)
{
	return (!isEmpty(fq)) ? fq.rear : NULL;
}
bool isEmpty(FCFSQueue fq)
{
	return (fq.front == NULL && fq.rear == NULL);
}

