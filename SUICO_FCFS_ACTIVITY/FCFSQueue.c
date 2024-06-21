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
ProcessData emptyProcess() 
{
    ProcessData p;
    p.processId = p.arrivalTime = -1, p.burstTime = p.executionTime = -1;
    return p;
}

void populateFCFSQueue(FCFSQueue *fq)
{
	int inputs, x;
	ProcessData p;
	printf("Enter Number of Process: "); scanf("%d", &inputs); printf("\n");
	for (x = 0; x < inputs; x++) {
		printf("Process %c\n", 'A' + x); p.processId = 'A' + x;
		printf("Arrival Time: "); scanf("%d", &p.arrivalTime);
		printf("Burst Time: "); scanf("%d", &p.burstTime);
		EnqueueProcess(fq, p);
		printf("\n");
	}
}
void displayFCFSQueue(FCFSQueue fq)
{
	if (!isEmpty(fq)) {
		printf("FCFS Queue Visualization\n");
	    printf("\n%-10s %-13s %-10s %-15s %-13s %-15s\n", "Process ID", "Arrival Time", "Burst Time", "Execution Time", "Waiting Time", "Turnaround Time");
	    printf("==========================================================================\n");
	
	    
	} else {
		printf("FCFS Queue is Empty!"); 
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
ProcessData Front(FCFSQueue fq)
{
	return (!isEmpty(fq)) ? fq.front->process : emptyProcess();
}
bool DequeueProcess(FCFSQueue *fq)
{
	bool retBool = false;
	ProcessNodePtr temp;
	if (!isEmpty(*fq)) {
		temp = fq->front;
		fq->front = temp->next;
		free(temp);
		if (fq->front == NULL) {
			fq->rear = NULL;
		}
		return retBool;
	}
	return retBool;
}
ProcessData Rear(FCFSQueue fq)
{
	return (!isEmpty(fq)) ? fq.rear->process : emptyProcess();
}

bool isEmpty(FCFSQueue fq)
{
	return (fq.front == NULL && fq.rear == NULL);
}

