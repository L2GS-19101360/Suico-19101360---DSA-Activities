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
	int inputs, x;
	ProcessData p;
	printf("Enter Number of Process: "); scanf("%d", &inputs); printf("\n");
	for (x = 0; x < inputs; x++) {
		printf("Process %c\n", 'A' + x); p.processId = 'A' + x;
		printf("Burst Time: "); scanf("%d", &p.burstTime);
		printf("Arrival Time: "); scanf("%d", &p.arrivalTime);
		EnqueueProcess(fq, p);
		printf("\n");
	}
}
void fcfsScheduling(FCFSQueue *fq)
{
	FCFSQueue temp = createFCFS();
    ProcessNodePtr checkNode, frontNode;
    while (!isEmpty(*fq)) {
        checkNode = Front(*fq);
        frontNode = checkNode->next;
        if (frontNode == NULL || checkNode->process.arrivalTime < frontNode->process.arrivalTime) {
            EnqueueProcess(&temp, checkNode->process);
            DequeueProcess(fq);
        } else {
            EnqueueProcess(fq, checkNode->process);
            DequeueProcess(fq);
        }
    }
    *fq = temp;
}
void displayFCFS(FCFSQueue fq) 
{
    if (!isEmpty(fq)) {
        FCFSQueue fcfs = fq;
        printf("FCFS Queue Visualization\n");
        printf("+------------+------------+--------------+----------------+--------------+-----------------+\n");
        printf("| Process ID | Burst Time | Arrival Time | Execution Time | Waiting Time | Turnaround Time |\n");
        printf("+------------+------------+--------------+----------------+--------------+-----------------+\n");

        int count = 0, currentTime = 0, executionTime, waitingTime, turnaroundTime, totalWaitingTime = 0, totalTurnoverTime = 0;
        ProcessNodePtr temp;
        ProcessData p;

        while (!isEmpty(fcfs)) {
            temp = Front(fcfs);
            p = temp->process;
	
	        if (currentTime < p.arrivalTime) {
	            currentTime = p.arrivalTime;
	        }
	
	        waitingTime = currentTime - p.arrivalTime;
	        executionTime = currentTime;
	        turnaroundTime = executionTime + p.burstTime;
	        currentTime += p.burstTime;
	        
	        totalWaitingTime += waitingTime;
	        totalTurnoverTime += turnaroundTime;
            count++;

            printf("| %-10c | %-10d | %-12d | %-14d | %-12d | %-15d |\n", p.processId, 
                                                                          p.burstTime, 
                                                                          p.arrivalTime, 
                                                                          executionTime, 
                                                                          waitingTime, 
                                                                          turnaroundTime);

            DequeueProcess(&fcfs);
        }
        printf("+------------+------------+--------------+----------------+--------------+-----------------+\n");
        printf("| %-10s | %-10s | %-12s | %-14s | %-12d | %-15d |\n", "", "", "", "Total ", totalWaitingTime, totalTurnoverTime);
        printf("| %-10s | %-10s | %-12s | %-14s | %-12.2f | %-15.2f |\n", "", "", "", "Average ", (float)totalWaitingTime / count, (float)totalTurnoverTime / count);
        printf("+------------+------------+--------------+----------------+--------------+-----------------+\n");
    } else {
        printf("FCFS is Empty!\n");
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
	if (!isEmpty(*fq)) {
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
